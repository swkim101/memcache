#include <stdlib.h>
#include <include/list.h>
#include <include/slab.h>
#include <include/debug.h>

#define PAGE_SIZE 4096

struct mcache_page* mcache_create(__uint32_t size, void (* ctor)(void*), void (* dtor)())
{
  struct mcache_page* mp;
  void* page = malloc(PAGE_SIZE);

  /* locate at the tail */
  mp = page + PAGE_SIZE - sizeof(struct mcache_page);
  int mc_size = sizeof(struct mcache) + size;
  INIT_LIST_HEAD(&mp->freelist);
  INIT_LIST_HEAD(&mp->pagelist);

  for (void* pos = page; pos + mc_size < mp; pos += mc_size) {
    struct mcache* mc = (struct mcache*)pos;
    if (ctor) { ctor(&mc->memory); }
    mc->page = mp;
    INIT_LIST_HEAD(&mc->freelist);
    list_add_tail(&mc->freelist, &mp->freelist);
  }

  return mp;
}

void* mcache_alloc(struct mcache_page* page)
{
  struct mcache* mc;

  mc = list_first_entry(&page->freelist, struct mcache, freelist);
  if (mc == &page->freelist) {
    return 0;
  }

  list_del_init(&mc->freelist);
  
  DBG("mp(%p) mc(%p) mem(%p)", page, mc, &mc->memory);
  return &mc->memory;
}

void mcache_free(struct mcache_page* mp, void* mem)
{
  struct mcache* mc = container_of(mem, struct mcache, memory);
  list_add(&mc->freelist, &mp->freelist);
}
