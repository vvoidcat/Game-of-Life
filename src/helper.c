#include "helper.h"

int **allocatePointerArray(int size_x, int size_y) {
  int **result = NULL;
  int error = 0;
  result = malloc(sizeof(int *) * size_y);

  if (result) {
    for (int i = 0; i < size_y; i++) {
      result[i] = malloc(sizeof(int) * size_x);
      if (!result[i]) {
        error = 1;
        break;
      }
    }
  } else {
    error = 1;
  }

  if (error) {
    freePointerArray(result, size_y);
  }
  return (error) ? NULL : result;
}

void freePointerArray(int **parray, int size_y) {
  if (parray) {
    for (int i = 0; i < size_y; i++) {
      freeArray(parray[i]);
    }
    free(parray);
  }
}

void freeArray(int *array) {
  if (array) {
    free(array);
  }
}

void printError(int index) {
  if (index != 0 && index < NERRORS) {
    char errors[][300] = ERRORLIST;
    fprintf(stderr, "%s", errors[index - 1]);
    fprintf(stderr, "\n");
  }
}
