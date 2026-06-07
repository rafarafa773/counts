all: compile
compile:
	g++ server.cpp -lgmp -lgmpxx -O3 -march=native -o server
