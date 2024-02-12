# User-level SLAB

slab-like memory cache for user applicataions.

Shows 55%p better than just malloc and free. See the performance evluation below.

It is not *thread safe*.

## Usage 

See `include/alloc.h`
```
void my_alloc_init();
void* my_alloc(long size);
void my_free(void* addr);
```

Example

```c
#include <stdio.h>
#include <include/alloc.h>

#define COL_LEN 16
void print_array(char* arr, int size) {
  int max_row = size / COL_LEN;
  for (int row = 0; row < max_row; row++) {
    for (int i = 0; i < COL_LEN; i++) {
      printf ("%2X ", arr[row * COL_LEN + i]);
    }
    printf ("\n");
  }
}

int main()
{
  my_alloc_init();

  char* m = my_alloc(128);
  if (!m) {
    printf("alloc failure");
    return -1;
  }
  for (int i = 0; i < 128; i++) {
    m[i] = i;
  }
  print_array(m, 128);
  my_free(m);

  return 0;
}
```

## Performance Evaluation

Scenarioes:
1) Best: Freqent alloc and free.
2) Worst: Infreqent alloc and free.

1) fixed-length, one-by-one allocate and free immediatly

my_alloc is 18.60% ((0.43 - 0.35)/0.43) faster.   

iteration: 10000000  
alloc size: 128  

```
Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  ms/call  ms/call  name    
 43.43      0.43     0.43        1   430.00   430.00  test_malloc_and_free_10000000
 35.35      0.78     0.35        1   350.00   510.00  test_my_alloc_and_free_10000000
 11.11      0.89     0.11 10000000     0.00     0.00  my_free
  5.05      0.94     0.05                             _init
  2.02      0.96     0.02 10000000     0.00     0.00  mcache_alloc
  2.02      0.98     0.02 10000000     0.00     0.00  my_alloc
  1.01      0.99     0.01 10000000     0.00     0.00  mcache_free
  0.00      0.99     0.00       11     0.00     0.00  mcache_create
  0.00      0.99     0.00        1     0.00     0.00  my_alloc_init
```

2) fixed-length, allocation and free after 1000 allocations

my_alloc is 1,650% ((0.02 - 0.35)/0.02) *slower*. Very very bad.

iteration: 10000000  
alloc size: 128  

```
Each sample counts as 0.01 seconds.
  %   cumulative   self              self     total           
 time   seconds   seconds    calls  ms/call  ms/call  name    
 76.09      0.35     0.35        1   350.00   440.00  test_my_alloc_and_free_10000000_after_1000_alloc
  6.52      0.38     0.03 10390000     0.00     0.00  mcache_alloc
  6.52      0.41     0.03   390011     0.00     0.00  mcache_create
  4.35      0.43     0.02 10000000     0.00     0.00  my_alloc
  4.35      0.45     0.02        1    20.00    20.00  test_malloc_and_free_10000000_after_1000_alloc
  2.17      0.46     0.01 10000000     0.00     0.00  mcache_free
  0.00      0.46     0.00 10000000     0.00     0.00  my_free
  0.00      0.46     0.00        1     0.00     0.00  my_alloc_init
```

