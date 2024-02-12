#include "include/list.h"
#include "include/slab.h"
#include "include/alloc.h"

enum {
  CACHE_8,
  CACHE_16,
  CACHE_32,
  CACHE_48,
  CACHE_64,
  CACHE_96,
  CACHE_128,
  CACHE_144,
  CACHE_160,
  CACHE_192,
  CACHE_256,

  CACHE_HEAD_SIZE
};
long g_cache_size_map[CACHE_HEAD_SIZE] = {
  /* CACHE_8 */
  8,
  /* CACHE_16 */
  16,
  /* CACHE_32 */
  32,
  /* CACHE_48 */
  48,
  /* CACHE_64 */
  64,
  /* CACHE_96 */
  96,
  /* CACHE_128 */
  128,
  /* CACHE_144 */
  144,
  /* CACHE_160 */
  160,
  /* CACHE_192 */
  192,
  /* CACHE_256 */
  256,
};
struct cache_head {
  struct list_head list;
} g_cache_list[CACHE_HEAD_SIZE];

#define CACHE_MAX_SIZE (g_cache_size_map[CACHE_HEAD_SIZE-1])

struct cache_head* cache_head_by_size_gte(long size) {
  for (int i = 0; i < CACHE_HEAD_SIZE; i++) {
    if (size <= g_cache_size_map[i]) {
      return &g_cache_list[i];
    }
  }
  return 0;
}

struct cache_head* cache_head_by_size_eq(long size) {
  for (int i = 0; i < CACHE_HEAD_SIZE; i++) {
    if (g_cache_size_map[i] == size) {
      return &g_cache_list[i];
    }
  }
  return 0;
}

void my_alloc_init() {
  for (int i = 0; i < CACHE_HEAD_SIZE; i++) {
    int cache_size = g_cache_size_map[i];
    struct mcache_page *page = mcache_create(cache_size, NULL, NULL);

    INIT_LIST_HEAD(&g_cache_list[i].list);
    list_add(&page->pagelist, &g_cache_list[i].list);
  }
}

void* my_alloc(long size) {
  if (CACHE_MAX_SIZE < size) {
    ERR("got %d. cannot alloc more than %d", size, CACHE_MAX_SIZE);
    return 0;
  }
  struct mcache_page *page;
  struct cache_head* cache;

  cache = cache_head_by_size_gte(size);

  /* fastpath */
  page = list_first_entry(&cache->list, struct mcache_page, pagelist);
  
  if (page != &cache->list) {
    void* addr = mcache_alloc(page);
    if (addr) {
      return addr;
    }
  }


  DBG("slowpath");
  /* slowpath */
  page = mcache_create(size, NULL, NULL);
  list_add(&page->pagelist, &cache->list);
  return mcache_alloc(page);
}

void my_free(void* mem) {
  struct mcache *mc = container_of(mem, struct mcache, memory);
  return mcache_free(mc->page, mem);
}