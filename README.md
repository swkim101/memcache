# User-level SLAB

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

## Performance