#ifndef SRC_GAMEOFLIFE_H_
#define SRC_GAMEOFLIFE_H_

#include <string.h>
#include <sys/ioctl.h>
#include <time.h>

#include "helper.h"

#define NHEIGHT 25
#define NWIDTH 80

#define DEAD 0
#define ALIVE 1

#define COLOR_MAGENTA "\x1B[35m"
#define COLOR_RESET "\033[0m"

int getMatrixFromFile(int **field, char **argv);
void drawField(int **field, char *filename);
void delay(int milliseconds);
int **step(int **field);
int countNeighbours(int **field, int x, int y);
int getBytes();
int getInput();

#endif  // SRC_GAMEOFLIFE_H_
