CC=gcc
CFLAGS= -Wall -lm

all: binary_matrix_driver coordinate_driver conways_game_of_life_driver list_driver

clean:
	 rm -f *.o
	 rm -f *_driver

binary_matrix_driver: binary_matrix_driver.o binary_matrix.o
	$(CC) $(CFLAGS) -o binary_matrix_driver binary_matrix_driver.o binary_matrix.o

binary_matrix_driver.o: binary_matrix_driver.c
	$(CC) $(CFLAGS) -c binary_matrix_driver.c

binary_matrix.o: binary_matrix.c
	$(CC) $(CFLAGS) -c binary_matrix.c

coordinate_driver: coordinate_driver.o coordinate.o
	$(CC) $(CFLAGS) -o coordinate_driver coordinate_driver.o coordinate.o

coordinate_driver.o: coordinate_driver.c
	$(CC) $(CFLAGS) -c coordinate_driver.c

coordinate.o: coordinate.c
	$(CC) $(CFLAGS) -c coordinate.c

conways_game_of_life_driver: conways_game_of_life_driver.o conways_game_of_life.o binary_matrix.o coordinate.o list.o
	$(CC) $(CFLAGS) -o conways_game_of_life_driver conways_game_of_life_driver.o conways_game_of_life.o binary_matrix.o coordinate.o list.o

conways_game_of_life_driver.o: conways_game_of_life_driver.c
	$(CC) $(CFLAGS) -c conways_game_of_life_driver.c

conways_game_of_life.o: conways_game_of_life.c
	$(CC) $(CFLAGS) -c conways_game_of_life.c

list_driver: list_driver.o list.o coordinate.o
	$(CC) $(CFLAGS) -o list_driver list_driver.o list.o coordinate.o

list_driver.o: list_driver.c
	$(CC) $(CFLAGS) -c list_driver.c

list.o: list.c
	$(CC) $(CFLAGS) -c list.c
