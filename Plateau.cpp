#include <string>
#include "Plateau.h"
using namespace std;

/**
 * @brief Constructeur de la classe Plateau
 */
plateauRicochet::plateauRicochet(int x, int y) {
    Max_X = x;
    Max_Y = y;
    //Initialisation du plateau
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
    
    //Initialisation des robots todo
}
