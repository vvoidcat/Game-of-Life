#include "gameoflife.h"

int getMatrixFromFile(int **field, char **argv) {
  int out = 1;
  int c = 0;

  FILE *file = NULL;
  file = fopen(argv[2], "r");

  if (file) {
    for (int i = 0; i < NHEIGHT; i++) {
      for (int j = 0; j < NWIDTH; j++) {
        c = getc(file);

        if (strchr(argv[1], c)) {
          field[i][j] = ALIVE;
        } else if ((i != NHEIGHT - 1 && j != NWIDTH - 1) && c == EOF) {
          out = 0;
          break;
        } else {
          field[i][j] = DEAD;
        }
      }
    }
    fclose(file);
  } else {
    out = 0;
  }

  return out;
}

void drawField(int **field, char *filename) {
  printf("\e[H\e[2J\e[3J");
  printf(" [w]" COLOR_MAGENTA " = speed up;" COLOR_RESET " [s]" COLOR_MAGENTA
         " = speed down;" COLOR_RESET " [q]" COLOR_MAGENTA
         " = quit\n" COLOR_RESET);
  printf(COLOR_MAGENTA " source file:" COLOR_RESET " %s\n", filename);
  printf("\n\n\n\n");

  for (int i = 0; i < NHEIGHT; i++) {
    printf("\t");
    for (int j = 0; j < NWIDTH; j++) {
      if (field[i][j] == ALIVE) {
        printf("▄");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }

  printf("\n");
}

void delay(int milliseconds) {
  milliseconds = milliseconds * 1000;
  clock_t start = clock();
  while (clock() < start + milliseconds) {
  }
}

int countNeighbours(int **field, int x, int y) {
  int counter = 0;
  for (int i = x - 1; i <= x + 1; i++) {
    for (int j = y - 1; j <= y + 1; j++) {
      if (!((i == x) && (j == y))) {
        if (field[(i + NHEIGHT) % NHEIGHT][(j + NWIDTH) % NWIDTH] == 1) {
          counter++;
        }
      }
    }
  }
  return counter;
}

int **step(int **field) {
  int **field_new = NULL;
  int error = 0;

  field_new = allocatePointerArray(NWIDTH, NHEIGHT);

  if (field_new) {
    for (int i = 0; i < NHEIGHT; i++) {
      for (int j = 0; j < NWIDTH; j++) {
        int state = field[i][j];
        int count = countNeighbours(field, i, j);
        if (state == ALIVE) {
          if ((count < 2) || (count > 3)) {
            field_new[i][j] = DEAD;
          } else {
            field_new[i][j] = ALIVE;
          }
        } else {
          if (count == 3) {
            field_new[i][j] = ALIVE;
          } else {
            field_new[i][j] = DEAD;
          }
        }
      }
    }

    for (int i = 0; i < NHEIGHT; i++) {
      for (int j = 0; j < NWIDTH; j++) {
        field[i][j] = field_new[i][j];
      }
    }
  } else {
    error = 1;
  }

  freePointerArray(field_new, NHEIGHT);
  return (error) ? NULL : field;
}

int getBytes() {
  int out_bytes;
  ioctl(1, FIONREAD, &out_bytes);
  return out_bytes;
}

int getInput(int *speed) {
  int out = 0;

  system("/bin/stty raw");

  if (getBytes() != 0) {
    int c = getchar();
    if (c == 'w' || c == 'W') {
      if (*speed >= 50) {
        *speed -= 225;
      }
    }
    if (c == 's' || c == 'S') {
      if (*speed <= 1450) {
        *speed += 225;
      }
    }
    if (c == 'q' || c == 'Q') {
      out = 1;
    }
  }

  system("/bin/stty cooked");

  return out;
}
