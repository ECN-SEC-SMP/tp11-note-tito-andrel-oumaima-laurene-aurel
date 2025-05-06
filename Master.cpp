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

char Master::select_Robot(){
    char Rob;
    std::cout<<"Sélection du robot: Red, Green, Blue, Yellow"<<std::endl;
    std::cout<<"R/G/B/Y"<<std::endl;
    std::cin>>Rob;
    return Rob;
}
void Master:: Tour() {
    //Joueurs Selection du joueurs

    //choisir le robot entre les 4
    char Rob=select_Robot();
    if(Rob=='R'){
        //choisir la direction   
        robotRouge->Deplacement(robotRouge->RecupereInfo());
    }
    //deplacement
    //Objectif atteint?//Next player
    //afficher le plateau
    //next Turn
    //fin si tout les objectif sont atteint
}
