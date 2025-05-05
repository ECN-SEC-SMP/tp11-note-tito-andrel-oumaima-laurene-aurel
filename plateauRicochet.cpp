#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "plateauRicochet.h"
using namespace std;

/**
 * @brief Constructeur de la classe Plateau
 */
void plateauRicochet::setObstacle(int min_x, int max_x, int min_y,int max_y) {
    // Initialisation des obstacles
    // Partie haute gauche du tableau
    // obstacles sur le plateau
    int i=0;
    while(i<3){
        int k = rand() % 4;
        int x = min_x + rand() % (max_x - min_x + 1);
        int y = min_y + rand() % (max_y - min_y + 1);
        switch(k) {
            case 0:
                //coin haut gauche
                if (Plateau[x][y]->getBordHaut() == false && Plateau[x][y]->getBordBas() == false 
                && Plateau[x][y]->getBordGauche() == false && Plateau[x][y]->getBordDroit() == false) {
                
                    Plateau[x][y]->setBordsHaut(true);
                    Plateau[x][y]->setBordsGauche(true);
                    i++;
                }
                break;
            case 1:


                if (Plateau[x][y]->getBordHaut() == false && Plateau[x][y]->getBordBas() == false 
                && Plateau[x][y]->getBordGauche() == false && Plateau[x][y]->getBordDroit() == false) {
                    Plateau[x][y]->setBordsHaut(true);
                    Plateau[x][y]->setBordsDroit(true);
                    i++;
                }
                break;
            case 2:


                if (Plateau[x][y]->getBordHaut() == false && Plateau[x][y]->getBordBas() == false 
                && Plateau[x][y]->getBordGauche() == false && Plateau[x][y]->getBordDroit() == false) {
                    Plateau[x][y]->setBordsBas(true);
                    Plateau[x][y]->setBordsGauche(true);
                    i++;
                }
                break;
            case 3:
                if (Plateau[x][y]->getBordHaut() == false && Plateau[x][y]->getBordBas() == false 
                && Plateau[x][y]->getBordGauche() == false && Plateau[x][y]->getBordDroit() == false) {
                    Plateau[x][y]->setBordsBas(true);
                    Plateau[x][y]->setBordsDroit(true);
                    i++;
                }
                break;
        }
        

    }

    }
plateauRicochet::plateauRicochet(int x, int y) {
    Max_X = x;
    Max_Y = y;
    //Initialisation du plateau
    //Initialisation de chaque case
    Plateau.resize(Max_X, std::vector<Case*>(Max_Y));
    //Initialisation des coins
    Plateau[0][0] = new Case(0, 0, true, false, true, false);
    Plateau[0][Max_Y-1] = new Case(0, Max_Y-1, true, false, false, true);
    Plateau[Max_X-1][0] = new Case(Max_X-1, 0, false, true, true, false);
    Plateau[Max_X-1][Max_Y-1] = new Case(Max_X-1, Max_Y-1, false, true, false, true);
    //Initilasation du centre : un carré avec bordures
        Plateau[Max_X/2 -1][Max_Y/2+1] = new Case(Max_X/2 -1, Max_Y/2+1, true, false, true, false);
        Plateau[Max_X/2 +1][Max_Y/2+1] = new Case(Max_X/2 +1, Max_Y/2+1, true, false, false, true);
        Plateau[Max_X/2-1][Max_Y/2-1] = new Case(Max_X/2-1, Max_Y/2-1, false, true, true, false);
        Plateau[Max_X/2+1][Max_Y/2-1] = new Case(Max_X/2+1, Max_Y/2-1, false, true, false, true);
    
    for (int i = 0; i < Max_X; i++) {
        for (int j = 0; j < Max_Y; j++) {
            //case vide
            if(Plateau[i][j] == nullptr) {
            
            //Bordure haut
            if (i==0 and j!=0 and j!=Max_X-1) {
                Plateau[i][j]=new Case(i, j, true,false,false,false);
            //bordure gauche
            } 
            else if(j==0 and i!=0 and i!=Max_X-1) {
                Plateau[i][j] = new Case(i, j, false, false, true, false);
            }
            //bordure droite
            else if(j==Max_Y-1 and i!=0 and i!=Max_X-1) {
                Plateau[i][j] = new Case(i, j, false, false, false, true);
            }
            //bordure bas
            else if(i==Max_X-1 and j!=0 and j!=Max_Y-1) {
                Plateau[i][j] = new Case(i, j, false, true, false, false);
            }
            //autre case
            else {
                Plateau[i][j] = new Case(i, j);
            }
            
        }
    }
   
    }
    
    //Initialisation des obstacles
    
    //Partie haute gauche du tableau
    //obstacles collés au bord 
    Plateau[rand() % (Max_X/2)][0]->setBordsBas(true);
    Plateau[0][rand() % (Max_Y/2)]->setBordsGauche(true);
    //obstacles sur le plateau
    setObstacle(0, Max_X/2, 0, Max_Y/2);

    //Partie haute droite du tableau
    Plateau[Max_X/2 + rand() % (Max_X/2)][0]->setBordsBas(true);
    Plateau[Max_X-1][rand() % (Max_Y/2)]->setBordsDroit(true);
    
    setObstacle(Max_X/2,Max_X,0,Max_Y/2);

    //Partie basse gauche du tableau
        Plateau[0][Max_Y/2+rand() % (Max_Y/2)]->setBordsBas(true);
        Plateau[Max_X-1][rand() % (Max_Y/2)]->setBordsDroit(true);
        
        setObstacle(Max_X/2,Max_X,0,Max_Y/2);
    //Partie basse droite du tableau

    Plateau[Max_X/2 + rand() % (Max_X/2)][Max_Y/2 + rand() % (Max_Y/2)]->setBordsBas(true);
    Plateau[Max_X-1][Max_Y/2 + rand() % (Max_Y/2)]->setBordsDroit(true);
    
    setObstacle(Max_X/2,Max_X,Max_Y/2,Max_Y);
    //Initialisation des robots
    for (int k = 0; k < 2; k++) { // Example for initializing 2 robots
        // Code to initialize robots goes here
        //rand() % maxX;
    }
}
// Destructeur
plateauRicochet::~plateauRicochet() {
    for (int i = 0; i < Max_X; ++i) { 
        for (int j = 0; j < Max_Y; ++j) { 
            delete Plateau[i][j]; 
        
    }
    // Vectors themselves are automatically destroyed
}
}