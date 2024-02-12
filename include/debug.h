#ifndef DEBUG_H
#define DEBUG_H

#include <execinfo.h>
#include <stdio.h>
#include <stdlib.h>

#if 0

#define DBG(fmt, ...) fprintf(stdout, "%s: " fmt "\n", __func__, ##__VA_ARGS__)
#define ERR(fmt, ...) fprintf(stderr, "%s: " fmt "\n", __func__, ##__VA_ARGS__)

#else

#define DBG(fmt, ...) ((void*)0)
#define ERR(fmt, ...) ((void*)0)

#endif

/* Obtain a backtrace and print it to stdout. */
static inline void print_trace(void)
{
  void *array[10];
  char **strings;
  int size, i;

  size = backtrace (array, 10);
  strings = backtrace_symbols (array, size);
  if (strings != NULL)
  {

    fprintf (stderr, "Obtained %d stack frames.\n", size);
    for (i = 0; i < size; i++)
      fprintf (stderr, "%s\n", strings[i]);
  }

  free (strings);
}

static inline void panic(char* err)
{
  fprintf(stderr, "[PANIC] %s\n", err);
  print_trace();
  exit(-1);
}

#endif /* DEBUG_H */