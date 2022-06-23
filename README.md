# Game-of-Life
an attempt at John Conway's Game of Life cellular automaton

to compile, use either:
    - "make"
    - "gcc src/gameoflife_main.c src/gameoflife.c -o gameoflife"

to launch, use either:
    - "make launch"
    - "./gameoflife 1 maps/spaceship.txt", where
                    "gameoflife" = name of the executable file
                    "1" = can be replaced by any character(s); the matching characters will be found in a file
                          and will represent the living cells at the start of the automaton
                    "maps/spaceship.txt" = path to the file
