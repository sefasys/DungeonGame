CC = gcc
CFLAGS = -Wall -g
OBJ = main.o player.o room.o game.o

all: RPGGame

RPGGame: $(OBJ)
	$(CC) $(CFLAGS) -o RPGGame $(OBJ)

main.o: main.c player.h room.h game.h
	$(CC) $(CFLAGS) -c main.c

player.o: player.c player.h room.h
	$(CC) $(CFLAGS) -c player.c

room.o: room.c room.h
	$(CC) $(CFLAGS) -c room.c

game.o: game.c game.h player.h room.h
	$(CC) $(CFLAGS) -c game.c

clean:
	rm -f RPGGame $(OBJ)
