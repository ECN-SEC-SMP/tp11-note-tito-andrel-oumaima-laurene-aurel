all: main.out

main.out: main.o Sablier.o Case.o Loup.o Pierre.o Ours.o
	g++ -o main.out main.o Attaque.o Animal.o Loup.o Pierre.o Ours.o

main.o: main.cpp
	g++ -c main.cpp

Attaque.o: Attaque.cpp Attaque.h
	g++ -c Attaque.cpp

Animal.o: Animal.cpp Animal.h
	g++ -c Animal.cpp

Loup.o:	Loup.cpp Loup.h
	g++ -c Loup.cpp 

Ours.o:	Ours.cpp Ours.h
	g++ -c Ours.cpp 

Pierre.o:	Pierre.cpp Pierre.h
	g++ -c Pierre.cpp 