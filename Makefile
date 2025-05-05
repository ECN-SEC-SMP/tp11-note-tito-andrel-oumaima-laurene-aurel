all: main.out

main.out: main.o Sablier.o Case.o plateauRicochet.o
	g++ -std=c++11 -pthread -o main.out main.o Sablier.o Case.o plateauRicochet.o

main.o: main.cpp
	g++ -std=c++11 -pthread -c main.cpp

Sablier.o: Sablier.cpp Sablier.h
	g++ -std=c++11 -pthread -c Sablier.cpp

Case.o: Case.cpp Case.h
	g++ -std=c++11 -pthread -c Case.cpp

plateauRicochet.o: plateauRicochet.cpp plateauRicochet.h
	g++ -std=c++11 -pthread -c plateauRicochet.cpp

clean:
	rm -f *.o main.out