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

void drawField(int **field) {
  system("clear");
  printf("[w] = speed up; [s] = speed down; [q] = quit");
  printf("\n\n\n\n");

  for (int i = 0; i < NHEIGHT; i++) {
    for (int j = 0; j < NWIDTH; j++) {
      if (field[i][j] == ALIVE) {
        printf("#");
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

  field_new = allocateMem(NHEIGHT, NWIDTH);

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

  freeMem(field_new);
  return (error) ? NULL : field;
}

int getbytes() {
  int out_bytes;
  ioctl(1, FIONREAD, &out_bytes);
  return out_bytes;
}

int getInput(int *speed) {
  int out = 0;

  system("/bin/stty raw");

  if (getbytes() != 0) {
    int c = getchar();
    if (c == 'w' || c == 'W') {
      if (*speed >= 150) {
        *speed -= 300;
      }
    }
    if (c == 's' || c == 'S') {
      if (*speed <= 1450) {
        *speed += 300;
      }
    }
    if (c == 'q' || c == 'Q') {
      out = 1;
    }
  }

  system("/bin/stty cooked");

  return out;
}

int **allocateMem(int height, int width) {
  int **result = NULL;
  int error = 0;

  result = malloc((height) * sizeof(int *));

  if (result) {
    for (int i = 0; i < height; i++) {
      result[i] = malloc((width) * sizeof(int));
      if (!result[i]) {
        error = 1;
        break;
      }
    }
  } else {
    error = 1;
  }

  if (error) {
    freeMem(result);
  }

  return (error) ? NULL : result;
}

void freeMem(int **pointer_array) {
  for (int i = 0; i < NHEIGHT; i++) {
    if (pointer_array[i]) {
      free(pointer_array[i]);
    }
  }
  if (pointer_array) {
    free(pointer_array);
  }
}

void printError(int index) {
  switch (index) {
    case 1:
      fprintf(stderr,
              "gameoflife: error[1]: usage: ./gameoflife [CHARACTERS] "
              "[FILENAME]\n");
      break;
    case 2:
      fprintf(stderr, "gameoflife: error[2]: invalid file\n");
      break;
    case 3:
      fprintf(stderr, "gameoflife: error[3]: freopen() failure\n");
      break;
    case 4:
      fprintf(stderr, "gameoflife: error[4]: memory allocation failure\n");
      break;
    default:
      break;
  }
}
