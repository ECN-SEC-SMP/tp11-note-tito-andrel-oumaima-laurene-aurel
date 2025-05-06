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
    //Robot
    Plateau = new plateauRicochet(Max_X, Max_Y);

    robotRed = new Robot("rouge", 0, 0);
    robotRed->GenereRobot();

    //generation ne fonctionne pas

    
    // robotGreen = new Robot("vert", 12, 10);
    // robotGreen->GenereRobot();
    // robotBlue = new Robot("bleu", 8, 3);
    // robotBlue->GenereRobot();
    // robotYellow = new Robot("jaune", 4, 7);
    // robotYellow->GenereRobot();

    Plateau->Afficher();

}
Master::~Master() {
    delete robotRed; // Suppression du robot rouge
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
        //Déplacer le robot avec la direction choisie
        Plateau->DeplacerRobot(robotRed, robotRed->RecupereInfo());
        cout << "Robot position end: " << robotRed->GetX() << ", " << robotRed->GetY() << endl;
        //Vérifier si l'objectif est atteint

    } else if (Rob == 'G') {
        Plateau->DeplacerRobot(robotGreen, robotGreen->RecupereInfo());
        cout << "Robot position end: " << robotGreen->GetX() << ", " << robotGreen->GetY() << endl;
    } else if (Rob == 'B') {

        Plateau->DeplacerRobot(robotBlue, robotBlue->RecupereInfo());
        cout << "Robot position end: " << robotBlue->GetX() << ", " << robotBlue->GetY() << endl;
    } else if (Rob == 'Y') {
        Plateau->DeplacerRobot(robotYellow, robotYellow->RecupereInfo());
        cout << "Robot position end: " << robotYellow->GetX() << ", " << robotYellow->GetY() << endl;
    } else {
        std::cout << "Robot non valide" << std::endl;
        Tour();
        

    }
    
    //deplacement
    //Objectif atteint?//Next player
    //afficher le plateau
    //next Turn
    //fin si tout les objectif sont atteint
}
