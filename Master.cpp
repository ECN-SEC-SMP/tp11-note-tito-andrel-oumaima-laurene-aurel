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

    robotRed = new Robot("rouge");
    robotGreen = new Robot("vert");
    //robotBlue = new Robot("bleu");
    //robotYellow = new Robot("jaune");

    // robotYellow = new Robot("jaune", 4, 7);
    // robotYellow->GenereRobot();
    Plateau->InitRobot(robotRed, robotGreen);
    Afficher();

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
    
    //Objectif atteint?//Next player
    //afficher le plateau
    //next Turn
    //fin si tout les objectif sont atteint
    Afficher();
}

void Master::Afficher() {
    std::vector<std::vector<Case*>> Grille = Plateau->getPlateau();
    //cote haut de la case à afficher
    for (int i = 0; i < Max_X; ++i) {
        // Affiche les murs du haut
        for (int j = 0; j < Max_Y; ++j) {
            cout << "+";
            if (Grille[i][j]->getBordHaut()) cout << "----";
            else cout << "    ";
        }
        cout << "+" << endl;
        // Affiche les murs gauche et le contenu de la case
        for (int j = 0; j < Max_Y; ++j) {
            if (Grille[i][j]->getBordGauche()) cout << "|";
            else cout << " ";
            if(robotRed->GetX() == i && robotRed->GetY() == j) cout << " R  "; // Ici tu peux afficher un symbole pour le robot// Affiche la couleur de la case
            else if(robotGreen->GetX() == i && robotGreen->GetY() == j) cout << " G  ";
            // else if(robotBlue->GetX() == i && robotBlue->GetY() == j) cout << " B  ";
            // else if(robotYellow->GetX() == i && robotYellow->GetY() == j) cout << " Y  ";


            //rajouter affichage objectif/ case de couleurs ...
            else cout << "    "; // Ici tu peux afficher un symbole pour robot/obstacle/couleur
        }
        if (Grille[i][Max_Y-1]->getBordDroit()) cout << "|";
        cout << endl;
        // Mur droit de la dernière case
    }
    // Affiche la dernière ligne de murs bas
    for (int j = 0; j < Max_Y; ++j) {
        cout << "+";
        if (Grille[Max_X-1][j]->getBordBas()) cout << "----";
        else cout << "    ";
    }
    cout << "+" << endl;
}
