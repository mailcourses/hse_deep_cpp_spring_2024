CC=g++
FLAGS=-std=c++20 -Wall -Wextra -Werror -fmodules-ts

all: main

main: main.o mexample.pcm
	$(CC) $(FLAGS) main.o mexample.pcm -o main

main.o: mexample.pcm main.cpp
	$(CC) $(FLAGS) -c main.cpp

mexample.pcm: mexample.cpp
	$(CC) $(FLAGS) -c mexample.cpp -o mexample.pcm

clear:
	rm -rf *.o mexample.pcm main gcm.cache
