#include "Case.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "plateauRicochet.h"
#include "Master.h"
using namespace std;
// Master::Master() {
//     Max_X = 0;
//     Max_Y = 0;
//     plateau = nullptr;
//     robotRouge = nullptr;
//     InitPlateau();
// }
Master::Master(int X, int Y) {
    Max_X = X;
    Max_Y = Y;
    Plateau = new plateauRicochet(Max_X, Max_Y);
    robotRouge = new Robot("rouge", 0, 0);
    robotRouge->GenereRobot();
}
Master::~Master() {
    delete robotRouge; // Suppression du robot rouge
    delete Plateau;    // Suppression du plateau
}
void Master:: Tour() {
    //choisir le robot
    //choisir la direction
    //deplacement
    //Objectif atteint?
    //afficher le plateau
    //next Turn
    //fin si tout les objectif sont atteint
}