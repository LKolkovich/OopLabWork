CXX = g++

all: main

main: main.o Player.o PlayerController.o Cell.o Field.o
	g++ main.o Player.o PlayerController.o Cell.o Field.o -o game

main.o: main.cpp
	g++ -c main.cpp

Player.o: player/source/Player.cpp
	g++ -c player/source/Player.cpp

PlayerController.o: player/source/PlayerController.cpp
	g++ -c player/source/PlayerController.cpp

Cell.o: field/source/Cell.cpp
	g++ -c field/source/Cell.cpp

Field.o: field/source/Field.cpp
	g++ -c field/source/Field.cpp

clean:
	rm -rf *.o main
