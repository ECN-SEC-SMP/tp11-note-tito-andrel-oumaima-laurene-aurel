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

        // Objectif
        Objectif* objectifCourant;
        int indiceObjectifCourant = 0;

        // Robots
        Robot* robotRed; 
        Robot* robotGreen;
        Robot* robotBlue;
        Robot* robotYellow;

        // Joueurs
        std::vector<Joueur*> Joueurs;
        int nbJoueurs;

        // Sablier
        Sablier* sablier;

        //std::vector<std::vector<Case*>> Plateau;
    public:
        // Constructeurs
        Master(int X, int Y);
        // Destructeur
        ~Master();
        void Tour();
        void TourdeJeu();
        char select_Robot();
        void Afficher();
        void tirerObjectif();
        bool getObjectifAtteint();
        void afficherObjectif();
        bool SelectionRobot(char Rob, int nbCoups);
        void initJoueurs();
        Joueur* selectJoueur();
        void AfficherScores();
        //void InitPlateau();
};

#endif