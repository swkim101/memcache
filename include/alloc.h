#ifndef ALLOC_H
#define ALLOC_H

void my_alloc_init();
void* my_alloc(long size);
void my_free(void* addr);

#endif /* ALLOC_H */