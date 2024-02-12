#ifndef SLAB_H
#define SLAB_H

#include <include/list.h>

/*
=======
4k page
-------
struct mcache
struct mcache
struct mcache
(...)
struct mcache_page
=======
*/

struct mcache_page {
  // int refcnt;
  struct list_head freelist;
  struct list_head pagelist;
};

struct mcache {
  struct list_head freelist;
  struct mcache_page* page;

  /* where users will use */
  void* memory;
};

struct mcache_page* mcache_create(__uint32_t size, void (* ctor)(void*), void (* dtor)());
void* mcache_alloc(struct mcache_page* mp);
void mcache_free(struct mcache_page* mp, void* mem);

#endif /* SLAB_H */