# Game-of-Life
John Conway's Game of Life cellular automaton, a recreation in C.

to compile, use either:
1) ```make```
2) ```gcc src/gameoflife_main.c src/gameoflife.c -o gameoflife```

to launch, use either:
1) ```make launch```
2) ```./gameoflife 123 maps/spaceship.txt```,  where

    - "gameoflife" = name of the executable
    - "123" = character(s) that will be found in the source file and will represent the living cells at the start of the automaton
    - "maps/spaceship.txt" = path to the source file
