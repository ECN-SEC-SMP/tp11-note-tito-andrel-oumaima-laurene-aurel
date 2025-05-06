all: main.out

main.out: main.o Sablier.o Case.o plateauRicochet.o Robot.o Master.o
	g++ -std=c++11 -pthread -o main.out main.o Sablier.o Case.o plateauRicochet.o Robot.o Master.o

main.o: main.cpp
	g++ -std=c++11 -pthread -c main.cpp

Sablier.o: Sablier.cpp Sablier.h
	g++ -std=c++11 -pthread -c Sablier.cpp

Case.o: Case.cpp Case.h
	g++ -std=c++11 -pthread -c Case.cpp

Objectif.o: Objectif.cpp Objectif.h
	g++ -std=c++11 -pthread -c Objectif.cpp

plateauRicochet.o: plateauRicochet.cpp plateauRicochet.h
	g++ -std=c++11 -pthread -c plateauRicochet.cpp

Robot.o: Robot.cpp Robot.h
	g++ -std=c++11 -pthread -c Robot.cpp

Master.o: Master.cpp Master.h
	g++ -std=c++11 -pthread -c Master.cpp

clean:
	rm -f *.o main.out