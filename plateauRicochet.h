#ifndef PLATEAU_H
#define PLATEAU_H
#include "Case.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "plateauRicochet.h"
#include "Robot.h"
#include "Objectif.h"
#include <map>
class plateauRicochet
{
    private:
     int Max_X;
     int Max_Y;
     //vector<std::vector<Case*>> Plateau;
     std::vector<std::vector<Case*>> Plateau;
     std::vector<Objectif*> Objectifs; // Vecteur d'objectifs
     //std::vector<std::vector<int>> Coin;
     std::vector<std::vector<Case*>> Plateau; 
     std::vector<std::pair<int, int>> obstaclesPlaces;
    public:
        plateauRicochet(int x, int y);
        std::vector<std::vector<Case*>> getPlateau();
        ~plateauRicochet();
        void InitRobot(Robot* robotRed, Robot* robotGreen, Robot* robotBlue, Robot* robotYellow);
        void setObstacle(int x1, int x2, int y1, int y2);
        void setBordsBas(int X, int Y);
        void setBordsHaut(int X, int Y);
        void setBordsGauche(int X, int Y);
        void setBordsDroit(int X, int Y);
        void DeplacerRobot(Robot* robot, char direction);
        std::vector<Objectif*> getObjectifs();// Accesseur pour les objectifs
        //void Afficher();   
};

#endif