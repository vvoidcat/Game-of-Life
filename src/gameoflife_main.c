#include "gameoflife.h"

int main(int argc, char *argv[]) {
  int **field = NULL;
  int speed = 500;
  int error = 0;

  field = allocateMem(NHEIGHT, NWIDTH);

  if (field) {
    if (argc != 3) {
      error = 1;
    } else if (!getMatrixFromFile(field, argv)) {
      error = 2;
    } else if (!freopen("/dev/tty", "r", stdin)) {
      error = 3;
    }

    if (error == 0) {
      drawField(field, argv[2]);
      delay(speed);

      while (1) {
        field = step(field);

        if (field) {
          drawField(field, argv[2]);
          if (getInput(&speed)) {
            break;
          }
          delay(speed);
        } else {
          error = 4;
          break;
        }
      }
    }
  } else {
    error = 4;
  }

  printError(error);
  freeMem(field);

  return 0;
}
