const sizes = [
  8,
  16,
  32,
  48,
  64,
  96,
  128,
  144,
  160,
  192,
  256,
]

const iteration = 150000000

const gen = size => {
  return `
void test_my_alloc_and_free_${size}()
{
  for (int i = 0; i < ${iteration}; i++) {
    volatile char* m = my_alloc(${size});
    if (!m) {
      panic("alloc failure");
    }
    memset(m, 0, ${size});
    my_free(m);
  }
}

void test_malloc_and_free_${size}()
{
  for (int i = 0; i < ${iteration}; i++) {
    volatile char* m = malloc(${size});
    if (!m) {
      panic("alloc failure");
    }
    memset(m, 0, ${size});
    free(m);
  }
}

void test_my_alloc_and_free_${size}_after_1000_alloc()
{
  char *m[1000];
  int cnt = 0;
  for (int i = 0; i < ${iteration}; i++) {
    m[cnt] = my_alloc(${size});
    if (!m) {
      panic("alloc failure");
    }
    for (int i = 0; i < ${size}; i++) {
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

void test_malloc_and_free_${size}_after_1000_alloc()
{
  char *m[1000];
  int cnt = 0;
  for (int i = 0; i < ${iteration}; i++) {
    m[cnt] = malloc(${size});
    if (!m) {
      panic("alloc failure");
    }
    for (int i = 0; i < ${size}; i++) {
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
  `
}

console.log(`
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <include/debug.h>
#include <include/alloc.h>
`)

sizes.map(s => console.log(gen(s)))

console.log(
`
int main()
{
  my_alloc_init();
`
)

sizes.map(s => console.log(`
  test_my_alloc_and_free_${s}();
  test_malloc_and_free_${s}();
`))

console.log(`
  return 0;
}
`)