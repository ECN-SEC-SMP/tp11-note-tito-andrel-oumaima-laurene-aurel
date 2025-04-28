all: main.out

main.out: main.o Sablier.o Case.o Tableau.o Robot.o 
	g++ -o main.out main.o Sablier.o Case.o Tableau.o Robot.o

main.o: main.cpp
	g++ -c main.cpp

Attaque.o: Sablier.cpp Sablier.h
	g++ -c Sablier.cpp

Animal.o: Case.cpp Case.h
	g++ -c Case.cpp

Loup.o:	Tableau.cpp Tableau.h
	g++ -c Tableau.cpp 

Ours.o:	Robot.cpp Robot.h
	g++ -c Robot.cpp 