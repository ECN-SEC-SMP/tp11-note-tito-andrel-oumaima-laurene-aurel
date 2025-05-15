#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>
#include <thread>
#include <chrono>
#include <vector>
#include <cstdlib> // Pour srand() et rand()
#include <ctime>   // Pour time()

#include "Case.h"
#include "Sablier.h"
#include "stdlib.h"
#include "plateauRicochet.h"
#include "Robot.h" // Pour time()
#include "Master.h"
#include "Joueur.h"

using namespace std;

int main()
{
    srand(time(0));

    // delete robot;
    Master *jeux = new Master(16, 16);
    jeux->Tour();
    return 0;
}