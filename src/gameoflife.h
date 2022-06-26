#ifndef SRC_GAMEOFLIFE_H_
#define SRC_GAMEOFLIFE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <time.h>

#define NHEIGHT 25
#define NWIDTH 80

#define DEAD 0
#define ALIVE 1

#define COLOR_MAGENTA "\x1B[35m"
#define COLOR_RESET "\033[0m"

#define NERRORS 4
#define ERRORLIST                                                       \
  {"gameoflife: error[1]: usage: ./gameoflife [CHARACTERS] [FILENAME]", \
   "gameoflife: error[2]: invalid file",                                \
   "gameoflife: error[3]: freopen() failure",                           \
   "gameoflife: error[4]: memory allocation failure"};

int getMatrixFromFile(int **field, char **argv);
void drawField(int **field, char *filename);
void delay(int milliseconds);
int **step(int **field);
int countNeighbours(int **field, int x, int y);
int getBytes();
int getInput();

int **allocateMem(int height, int width);
void freeMem(int **pointer_array);

void printError(int index);

#endif  // SRC_GAMEOFLIFE_H_
