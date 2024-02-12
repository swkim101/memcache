#ifndef LIST_H
#define LIST_H

#include <include/debug.h>

struct list_head {
  struct list_head *next;
  struct list_head *prev;
};

#define offsetof(type, member) ((size_t)&(((type*) 0)->member))
#define container_of(ptr, type, member) ({				\
  void *__mptr = (void *)(ptr);					\
 ((type *)(__mptr - offsetof(type, member))); \
})

#define list_entry(ptr, type, member) container_of(ptr, type, member)
#define list_entry_next(pos, member) list_entry((pos)->member.next, typeof(*(pos)), member)
#define list_entry_prev(pos, member) list_entry((pos)->member.prev, typeof(*(pos)), member)
#define list_first_entry(ptr, type, member) list_entry((ptr)->next, type, member)
#define list_for_each_entry(pos, head, member) \
  for (pos = list_first_entry(head, typeof(*(pos)), member); \
    &pos->member != head; \
    pos = list_entry_next(pos, member) \
  )
#define list_for_each_entry_inverse(pos, head, member) \
  for (pos = list_first_entry(head, typeof(*(pos)), member); \
    &pos->member != head; \
    pos = list_entry_prev(pos, member) \
  )

inline void INIT_LIST_HEAD(struct list_head *list)
{
  list->next = list;
  list->prev = list;
}

inline void __list_add( struct list_head *new_entry,
                        struct list_head *prev,
                        struct list_head *next
)
{
  if (!new_entry || !prev || !next) {
    if (!new_entry) { panic("empty new entry"); }
    if (!new_entry) { panic("empty prev"); }
    panic("empty next");
  }
  next->prev = new_entry;
  new_entry->next = next;
  new_entry->prev = prev;
  prev->next = new_entry;
}

inline void list_add(struct list_head *new_entry, struct list_head *head)
{
  __list_add(new_entry, head, head->next);
}

inline void list_add_tail(struct list_head *new_entry, struct list_head *head)
{
  __list_add(new_entry, head->prev, head);
}

inline void __list_del(struct list_head *entry)
{
  struct list_head* prev = entry->prev;
  struct list_head* next = entry->next;
  prev->next = next;
  next->prev = prev;
}

inline void list_del_init(struct list_head *entry) {
  __list_del(entry);
  INIT_LIST_HEAD(entry);
}


#endif /* LIST_H */