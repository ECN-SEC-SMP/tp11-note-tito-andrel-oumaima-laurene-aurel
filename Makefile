all: main.out

main.out: main.o Sablier.o Case.o 
	g++ -o main.out main.o Sablier.o Case.o 

main.o: main.cpp
	g++ -c main.cpp

Sablier.o: Sablier.cpp Sablier.h
	g++ -c Sablier.cpp

Case.o: Case.cpp Case.h
	g++ -c Case.cpp