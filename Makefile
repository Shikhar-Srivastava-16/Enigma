FLAGS := -Wall -Wno-sizeof-array-argument

all: build run

build:
	clear
	gcc $(FLAGS) *.c -o Enigma

run:
	./Enigma