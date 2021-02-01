all: compile run

compile:
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/Iterator.o -c ./src/Iterator.cpp
	g++ -I ./include/ -o ./lib/CircularDoublyLinkedList.o -c ./src/CircularDoublyLinkedList.cpp
	g++ -I ./include/ -o ./lib/MainList.o -c ./src/MainList.cpp
	g++ -I ./include/ -o ./bin/program ./lib/MainList.o ./lib/CircularDoublyLinkedList.o ./lib/Iterator.o ./lib/Node.o ./src/program.cpp
run:
	./bin/program