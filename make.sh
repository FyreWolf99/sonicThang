#!/bin/sh

g++ -c src/*.c* -g -Wall -I include/ || exit
g++ *.o -lSDL2 -lSDL2main -o bin/debug -L lib/ || exit

./bin/debug