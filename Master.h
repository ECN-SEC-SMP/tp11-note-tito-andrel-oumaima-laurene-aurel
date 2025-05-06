#ifndef MASTER_H
#define MASTER_H

#include <string>
#include <iostream>
#include <string>
#include "stdlib.h"
#include "Case.h"
#include "Sablier.h"
#include "plateauRicochet.h"
#include <vector>
#include <cstdlib> // Pour srand() et rand()
#include <ctime>   // Pour time()
#include "Robot.h"


class Master {
    protected:
        // Attributs
        int Max_X;
        int Max_Y;
        //std::vector<std::vector<Case*>> Plateau;
        plateauRicochet* Plateau;
        //robots
        Robot* robotRed; 
        Robot* robotGreen;
        Robot* robotBlue;
        Robot* robotYellow;
        //class objectif??
        //std::vector<std::vector<Case*>> Plateau;
    public:
        // Constructeurs
        Master(int X, int Y);
        // Destructeur
        ~Master();
        void Tour();
        char select_Robot();
        //void Afficher();
        //void InitPlateau();
};

#endif