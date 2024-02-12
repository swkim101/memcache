
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <include/debug.h>
#include <include/alloc.h>


void test_my_alloc_and_free_8()
{
  for (int i = 0; i < 150000000; i++) {
    volatile char* m = my_alloc(8);
    if (!m) {
      panic("alloc failure");
    }
    memset(m, 0, 8);
    my_free(m);
  }
}

void test_malloc_and_free_8()
{
  for (int i = 0; i < 150000000; i++) {
    volatile char* m = malloc(8);
    if (!m) {
      panic("alloc failure");
    }
    memset(m, 0, 8);
    free(m);
  }
}

void test_my_alloc_and_free_8_after_1000_alloc()
{
  char *m[1000];
  int cnt = 0;
  for (int i = 0; i < 150000000; i++) {
    m[cnt] = my_alloc(8);
    if (!m) {
      panic("alloc failure");
    }
    for (int i = 0; i < 8; i++) {
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

void test_malloc_and_free_8_after_1000_alloc()
{
  char *m[1000];
  int cnt = 0;
  for (int i = 0; i < 150000000; i++) {
    m[cnt] = malloc(8);
    if (!m) {
      panic("alloc failure");
    }
    for (int i = 0; i < 8; i++) {
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
  

void test_my_alloc_and_free_16()
{
  for (int i = 0; i < 150000000; i++) {
    volatile char* m = my_alloc(16);
    if (!m) {
      panic("alloc failure");
    }
    memset(m, 0, 16);
    my_free(m);
  }
}

void test_malloc_and_free_16()
{
  for (int i = 0; i < 150000000; i++) {
    volatile char* m = malloc(16);
    if (!m) {
      panic("alloc failure");
    }
    memset(m, 0, 16);
    free(m);
  }
}

void test_my_alloc_and_free_16_after_1000_alloc()
{
  char *m[1000];
  int cnt = 0;
  for (int i = 0; i < 150000000; i++) {
    m[cnt] = my_alloc(16);
    if (!m) {
      panic("alloc failure");
    }
    for (int i = 0; i < 16; i++) {
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

void test_malloc_and_free_16_after_1000_alloc()
{
  char *m[1000];
  int cnt = 0;
  for (int i = 0; i < 150000000; i++) {
    m[cnt] = malloc(16);
    if (!m) {
      panic("alloc failure");
    }
    for (int i = 0; i < 16; i++) {
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
  

void test_my_alloc_and_free_32()
{
  for (int i = 0; i < 150000000; i++) {
    volatile char* m = my_alloc(32);
    if (!m) {
      panic("alloc failure");
    }
    memset(m, 0, 32);
    my_free(m);
  }
}

void test_malloc_and_free_32()
{
  for (int i = 0; i < 150000000; i++) {
    volatile char* m = malloc(32);
    if (!m) {
      panic("alloc failure");
    }
    memset(m, 0, 32);
    free(m);
  }
}

void test_my_alloc_and_free_32_after_1000_alloc()
{
  char *m[1000];
  int cnt = 0;
  for (int i = 0; i < 150000000; i++) {
    m[cnt] = my_alloc(32);
    if (!m) {
      panic("alloc failure");
    }
    for (int i = 0; i < 32; i++) {
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

void test_malloc_and_free_32_after_1000_alloc()
{
  char *m[1000];
  int cnt = 0;
  for (int i = 0; i < 150000000; i++) {
    m[cnt] = malloc(32);
    if (!m) {
      panic("alloc failure");
    }
    for (int i = 0; i < 32; i++) {
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
  

void test_my_alloc_and_free_48()
{
  for (int i = 0; i < 150000000; i++) {
    volatile char* m = my_alloc(48);
    if (!m) {
      panic("alloc failure");
    }
    memset(m, 0, 48);
    my_free(m);
  }
}

void test_malloc_and_free_48()
{
  for (int i = 0; i < 150000000; i++) {
    volatile char* m = malloc(48);
    if (!m) {
      panic("alloc failure");
    }
    memset(m, 0, 48);
    free(m);
  }
}

void test_my_alloc_and_free_48_after_1000_alloc()
{
  char *m[1000];
  int cnt = 0;
  for (int i = 0; i < 150000000; i++) {
    m[cnt] = my_alloc(48);
    if (!m) {
      panic("alloc failure");
    }
    for (int i = 0; i < 48; i++) {
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

void test_malloc_and_free_48_after_1000_alloc()
{
  char *m[1000];
  int cnt = 0;
  for (int i = 0; i < 150000000; i++) {
    m[cnt] = malloc(48);
    if (!m) {
      panic("alloc failure");
    }
    for (int i = 0; i < 48; i++) {
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
  

void test_my_alloc_and_free_64()
{
  for (int i = 0; i < 150000000; i++) {
    volatile char* m = my_alloc(64);
    if (!m) {
      panic("alloc failure");
    }
    memset(m, 0, 64);
    my_free(m);
  }
}

void test_malloc_and_free_64()
{
  for (int i = 0; i < 150000000; i++) {
    volatile char* m = malloc(64);
    if (!m) {
      panic("alloc failure");
    }
    memset(m, 0, 64);
    free(m);
  }
}

void test_my_alloc_and_free_64_after_1000_alloc()
{
  char *m[1000];
  int cnt = 0;
  for (int i = 0; i < 150000000; i++) {
    m[cnt] = my_alloc(64);
    if (!m) {
      panic("alloc failure");
    }
    for (int i = 0; i < 64; i++) {
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

void test_malloc_and_free_64_after_1000_alloc()
{
  char *m[1000];
  int cnt = 0;
  for (int i = 0; i < 150000000; i++) {
    m[cnt] = malloc(64);
    if (!m) {
      panic("alloc failure");
    }
    for (int i = 0; i < 64; i++) {
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
  

void test_my_alloc_and_free_96()
{
  for (int i = 0; i < 150000000; i++) {
    volatile char* m = my_alloc(96);
    if (!m) {
      panic("alloc failure");
    }
    memset(m, 0, 96);
    my_free(m);
  }
}

void test_malloc_and_free_96()
{
  for (int i = 0; i < 150000000; i++) {
    volatile char* m = malloc(96);
    if (!m) {
      panic("alloc failure");
    }
    memset(m, 0, 96);
    free(m);
  }
}

void test_my_alloc_and_free_96_after_1000_alloc()
{
  char *m[1000];
  int cnt = 0;
  for (int i = 0; i < 150000000; i++) {
    m[cnt] = my_alloc(96);
    if (!m) {
      panic("alloc failure");
    }
    for (int i = 0; i < 96; i++) {
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

void test_malloc_and_free_96_after_1000_alloc()
{
  char *m[1000];
  int cnt = 0;
  for (int i = 0; i < 150000000; i++) {
    m[cnt] = malloc(96);
    if (!m) {
      panic("alloc failure");
    }
    for (int i = 0; i < 96; i++) {
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
  

void test_my_alloc_and_free_128()
{
  for (int i = 0; i < 150000000; i++) {
    volatile char* m = my_alloc(128);
    if (!m) {
      panic("alloc failure");
    }
    memset(m, 0, 128);
    my_free(m);
  }
}

void test_malloc_and_free_128()
{
  for (int i = 0; i < 150000000; i++) {
    volatile char* m = malloc(128);
    if (!m) {
      panic("alloc failure");
    }
    memset(m, 0, 128);
    free(m);
  }
}

void test_my_alloc_and_free_128_after_1000_alloc()
{
  char *m[1000];
  int cnt = 0;
  for (int i = 0; i < 150000000; i++) {
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

void test_malloc_and_free_128_after_1000_alloc()
{
  char *m[1000];
  int cnt = 0;
  for (int i = 0; i < 150000000; i++) {
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
  

void test_my_alloc_and_free_144()
{
  for (int i = 0; i < 150000000; i++) {
    volatile char* m = my_alloc(144);
    if (!m) {
      panic("alloc failure");
    }
    memset(m, 0, 144);
    my_free(m);
  }
}

void test_malloc_and_free_144()
{
  for (int i = 0; i < 150000000; i++) {
    volatile char* m = malloc(144);
    if (!m) {
      panic("alloc failure");
    }
    memset(m, 0, 144);
    free(m);
  }
}

void test_my_alloc_and_free_144_after_1000_alloc()
{
  char *m[1000];
  int cnt = 0;
  for (int i = 0; i < 150000000; i++) {
    m[cnt] = my_alloc(144);
    if (!m) {
      panic("alloc failure");
    }
    for (int i = 0; i < 144; i++) {
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

void test_malloc_and_free_144_after_1000_alloc()
{
  char *m[1000];
  int cnt = 0;
  for (int i = 0; i < 150000000; i++) {
    m[cnt] = malloc(144);
    if (!m) {
      panic("alloc failure");
    }
    for (int i = 0; i < 144; i++) {
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
  

void test_my_alloc_and_free_160()
{
  for (int i = 0; i < 150000000; i++) {
    volatile char* m = my_alloc(160);
    if (!m) {
      panic("alloc failure");
    }
    memset(m, 0, 160);
    my_free(m);
  }
}

void test_malloc_and_free_160()
{
  for (int i = 0; i < 150000000; i++) {
    volatile char* m = malloc(160);
    if (!m) {
      panic("alloc failure");
    }
    memset(m, 0, 160);
    free(m);
  }
}

void test_my_alloc_and_free_160_after_1000_alloc()
{
  char *m[1000];
  int cnt = 0;
  for (int i = 0; i < 150000000; i++) {
    m[cnt] = my_alloc(160);
    if (!m) {
      panic("alloc failure");
    }
    for (int i = 0; i < 160; i++) {
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

void test_malloc_and_free_160_after_1000_alloc()
{
  char *m[1000];
  int cnt = 0;
  for (int i = 0; i < 150000000; i++) {
    m[cnt] = malloc(160);
    if (!m) {
      panic("alloc failure");
    }
    for (int i = 0; i < 160; i++) {
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
  

void test_my_alloc_and_free_192()
{
  for (int i = 0; i < 150000000; i++) {
    volatile char* m = my_alloc(192);
    if (!m) {
      panic("alloc failure");
    }
    memset(m, 0, 192);
    my_free(m);
  }
}

void test_malloc_and_free_192()
{
  for (int i = 0; i < 150000000; i++) {
    volatile char* m = malloc(192);
    if (!m) {
      panic("alloc failure");
    }
    memset(m, 0, 192);
    free(m);
  }
}

void test_my_alloc_and_free_192_after_1000_alloc()
{
  char *m[1000];
  int cnt = 0;
  for (int i = 0; i < 150000000; i++) {
    m[cnt] = my_alloc(192);
    if (!m) {
      panic("alloc failure");
    }
    for (int i = 0; i < 192; i++) {
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

void test_malloc_and_free_192_after_1000_alloc()
{
  char *m[1000];
  int cnt = 0;
  for (int i = 0; i < 150000000; i++) {
    m[cnt] = malloc(192);
    if (!m) {
      panic("alloc failure");
    }
    for (int i = 0; i < 192; i++) {
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
  

void test_my_alloc_and_free_256()
{
  for (int i = 0; i < 150000000; i++) {
    volatile char* m = my_alloc(256);
    if (!m) {
      panic("alloc failure");
    }
    memset(m, 0, 256);
    my_free(m);
  }
}

void test_malloc_and_free_256()
{
  for (int i = 0; i < 150000000; i++) {
    volatile char* m = malloc(256);
    if (!m) {
      panic("alloc failure");
    }
    memset(m, 0, 256);
    free(m);
  }
}

void test_my_alloc_and_free_256_after_1000_alloc()
{
  char *m[1000];
  int cnt = 0;
  for (int i = 0; i < 150000000; i++) {
    m[cnt] = my_alloc(256);
    if (!m) {
      panic("alloc failure");
    }
    for (int i = 0; i < 256; i++) {
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

void test_malloc_and_free_256_after_1000_alloc()
{
  char *m[1000];
  int cnt = 0;
  for (int i = 0; i < 150000000; i++) {
    m[cnt] = malloc(256);
    if (!m) {
      panic("alloc failure");
    }
    for (int i = 0; i < 256; i++) {
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


  test_my_alloc_and_free_8();
  test_malloc_and_free_8();


  test_my_alloc_and_free_16();
  test_malloc_and_free_16();


  test_my_alloc_and_free_32();
  test_malloc_and_free_32();


  test_my_alloc_and_free_48();
  test_malloc_and_free_48();


  test_my_alloc_and_free_64();
  test_malloc_and_free_64();


  test_my_alloc_and_free_96();
  test_malloc_and_free_96();


  test_my_alloc_and_free_128();
  test_malloc_and_free_128();


  test_my_alloc_and_free_144();
  test_malloc_and_free_144();


  test_my_alloc_and_free_160();
  test_malloc_and_free_160();


  test_my_alloc_and_free_192();
  test_malloc_and_free_192();


  test_my_alloc_and_free_256();
  test_malloc_and_free_256();


  return 0;
}

