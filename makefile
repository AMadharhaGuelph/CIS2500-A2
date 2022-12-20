CC=gcc 
CFLAGS=-Wall -std=c99

noStringsAttached: src/madharhaAnkushA2.o src/main.o
	$(CC) $(CFLAGS) src/madharhaAnkushA2.o src/main.o -o bin/noStringsAttached
madharhaAnkush.o: src/madharhaAnkushA2.c include/madharhaAnkushA2.h
	$(CC) $(CFLAGS) -c src/madharhaAnkushA2.c
main.o: src/main.c include/madharhaAnkushA2.h
	$(CC) $(CFLAGS) -c src/main.c
clean:
	rm src/*.o bin/noStringsAttached
