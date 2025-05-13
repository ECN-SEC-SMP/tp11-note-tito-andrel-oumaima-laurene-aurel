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
#include "Joueur.h"


class Master {
    protected:
        // Attributs
        int Max_X;
        int Max_Y;
        //std::vector<std::vector<Case*>> Plateau;
        plateauRicochet* Plateau;

        // Robots
        Robot* robotRed; 
        Robot* robotGreen;
        Robot* robotBlue;
        Robot* robotYellow;

        // Joueurs
        // Joueur* Joueur1;
        // Joueur* Joueur2;
        // Joueur* Joueur3;
        // Joueur* Joueur4;

        //
        std::vector<Joueur*> Joueurs;
        int nbJoueurs;
        //std::vector<std::vector<Case*>> Plateau;
    public:
        // Constructeurs
        Master(int X, int Y);
        // Destructeur
        ~Master();
        void Tour();
        char select_Robot();
        void Afficher();
        void initJoueur();
        Joueur* selectJoueur();
        void AfficherScores();
        //void InitPlateau();
};

#endif