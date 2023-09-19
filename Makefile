CXX = g++
CXXFLAGS = -Wall -Werror -Wextra -pedantic -std=c++17 -g -fsanitize=address
LDFLAGS =  -fsanitize=address

SRC = 
OBJ = $(SRC:.cc=.o)
EXEC = main

all: main

main: main.o Player.o PlayerController.o
	g++ main.o Player.o PlayerController.o -o main

main.o: source/main.cpp
	g++ -c source/main.cpp

Player.o: source/Player.cpp
	g++ -c source/Player.cpp

PlayerController.o: source/PlayerController.cpp
	g++ -c source/PlayerController.cpp



clean:
	rm -rf *.o main