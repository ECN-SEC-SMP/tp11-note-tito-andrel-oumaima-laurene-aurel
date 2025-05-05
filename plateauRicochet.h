#ifndef PLATEAU_H
#define PLATEAU_H
#include "Case.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "plateauRicochet.h"
class plateauRicochet
{
    private:
     int Max_X;
     int Max_Y;
     //vector<std::vector<Case*>> Plateau;
     std::vector<std::vector<Case*>> Plateau; 
    public:
        plateauRicochet(int x, int y);
        ~plateauRicochet();
        void setObstacle(int x1, int x2, int y1, int y2);
        //void Afficher();   
};

#endif