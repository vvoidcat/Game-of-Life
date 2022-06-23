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

int getMatrixFromFile(int **field, char **argv);
void drawField(int **field);
void delay(int milliseconds);
int **step(int **field);
int countNeighbours(int **field, int x, int y);
int getbytes();
int getInput();

int **allocateMem(int height, int width);
void freeMem(int **pointer_array);

void printError(int index);

#endif  // SRC_GAMEOFLIFE_H_
