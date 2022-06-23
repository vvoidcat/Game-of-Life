# Game-of-Life
John Conway's Game of Life cellular automaton created in 1970, a recreation in C.

to compile, use either:
1) ```make```
2) ```gcc src/gameoflife_main.c src/gameoflife.c -o gameoflife```

to launch, use either:
1) ```make launch```
2) ```./gameoflife 1 maps/spaceship.txt```,  where

    - "gameoflife" = name of the executable file
    - "1" = can be replaced by any character(s); the matching characters will be found in a file and will represent the living cells at the start of the automaton
    - "maps/spaceship.txt" = path to the file
