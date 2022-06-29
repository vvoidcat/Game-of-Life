#ifndef SRC_HELPER_H_
#define SRC_HELPER_H_

#include <stdio.h>
#include <stdlib.h>

#define NERRORS 4
#define ERRORLIST                                                       \
  {"gameoflife: error[1]: usage: ./gameoflife [CHARACTERS] [FILENAME]", \
   "gameoflife: error[2]: invalid file",                                \
   "gameoflife: error[3]: freopen() failure",                           \
   "gameoflife: error[4]: memory allocation failure"};

int **allocatePointerArray(int size_x, int size_y);
void freePointerArray(int **parray, int size_y);
void freeArray(int *array);

void printError(int index);

#endif  // SRC_HELPER_H_