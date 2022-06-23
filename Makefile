OUTNAME = "gameoflife"
CC = gcc -Wall -Werror -Wextra -std=c11


all: cleanall build clean

build: src/gameoflife_main.c src/gameoflife.c
	$(CC) src/gameoflife_main.c src/gameoflife.c -o $(OUTNAME)

rebuild: cleanall build


launch:
	./$(OUTNAME) 'daenerys' maps/loremipsum.txt
	./$(OUTNAME) '1' maps/spaceship.txt


clean:
	/bin/rm -rf *.o

cleanall:
	/bin/rm -rf *.o $(OUTNAME)
