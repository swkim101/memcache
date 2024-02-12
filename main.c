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

void test_my_alloc_and_free_10000000_after_1000_alloc()
{
  char *m[1000];
  int cnt = 0;
  for (int i = 0; i < 10000000; i++) {
    m[cnt] = my_alloc(128);
    if (!m) {
      panic("alloc failure");
    }
    for (int i = 0; i < 128; i++) {
      m[cnt][i] = i;
    }
    cnt++;
    if (cnt == 1000) {
      for (int i = 0; i < 1000; i++) {
        my_free(m[i]);
      }
      cnt = 0;
    }
  }
}

void test_malloc_and_free_10000000_after_1000_alloc()
{
  char *m[1000];
  int cnt = 0;
  for (int i = 0; i < 10000000; i++) {
    m[cnt] = malloc(128);
    if (!m) {
      panic("alloc failure");
    }
    for (int i = 0; i < 128; i++) {
      m[cnt][i] = i;
    }
    cnt++;
    if (cnt == 1000) {
      for (int i = 0; i < 1000; i++) {
        free(m[i]);
      }
      cnt = 0;
    }
  }
}

int main()
{
  my_alloc_init();
  test_my_alloc_and_free_10000000_after_1000_alloc();
  test_malloc_and_free_10000000_after_1000_alloc();

  return 0;
}