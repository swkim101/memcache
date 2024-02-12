#include <stdio.h>
#include <stdlib.h>
#include <include/debug.h>
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

void test_my_alloc_and_free_10000000()
{
  for (int i = 0; i < 10000000; i++) {
    char* m = my_alloc(128);
    if (!m) {
      panic("alloc failure");
    }
    for (int i = 0; i < 128; i++) {
      m[i] = i;
    }
    // print_array(m, 128);
    my_free(m);
  }
}

void test_malloc_and_free_10000000()
{
  for (int i = 0; i < 10000000; i++) {
    char* m = malloc(128);
    if (!m) {
      panic("alloc failure");
    }
    for (int i = 0; i < 128; i++) {
      m[i] = i;
    }
    // print_array(m, 128);
    free(m);
  }
}

int main()
{
  my_alloc_init();
  test_my_alloc_and_free_10000000();
  test_malloc_and_free_10000000();

  return 0;
}