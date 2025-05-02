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
plateauRicochet::plateauRicochet(int x, int y) {
    Max_X = x;
    Max_Y = y;
    //Initialisation du plateau
    //Initialisation de chaque case
    Plateau.resize(Max_X-1, std::vector<Case*>(Max_Y-1));

    for (int i = 0; i < Max_X; i++) {
        for (int j = 0; j < Max_Y; j++) {
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
    //Initialisation des coins
    Plateau[0][0] = new Case(0, 0, true, false, true, false);
    Plateau[0][Max_Y-1] = new Case(0, Max_Y-1, true, false, false, true);
    Plateau[Max_X-1][0] = new Case(Max_X-1, 0, false, true, true, false);
    Plateau[Max_X-1][Max_Y-1] = new Case(Max_X-1, Max_Y-1, false, true, false, true);
    
    //Initialisation des obstacles
    //Coin en haut à gauche du tableau
    for(int i=0; i<(Max_X-1)/2; i++) {
        for(int j=0; j<Max_Y; j++) {
            // if(Plateau[i][j]->GetObstacle()) {
            //     Plateau[i][j]->SetObstacle(true);
            }
        }
    
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