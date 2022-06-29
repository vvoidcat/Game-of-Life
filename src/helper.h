#ifndef SRC_HELPER_H_
#define SRC_HELPER_H_

#include <stdio.h>
#include <stdlib.h>

#define NERRORS 3
#define ERRORLIST                         \
  {"error[1]: memory allocation failure", \
   "gameoflife: error[2]: freopen() failure", "Unknown error "};

int **allocatePointerArray(int size_x, int size_y);
void freePointerArray(int **parray, int size_y);
void freeArray(int *array);

void printError(int index);

#endif  // SRC_HELPER_H_