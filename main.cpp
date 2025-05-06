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

using namespace std;
// void game() {

// }
int main() {
    int x = 0;
    int y = 0;
    int x1 = 1;
    int y1 = 0;
    // while(Animaux.size()!=1){
    //     cout << "Appuyez sur Entrée pour continuer au tour suivant...";
    //     cin.ignore(numeric_limits<streamsize>::max(), '\n');
    // }
    //seed
    srand(time(0));
    plateauRicochet* plateau = new plateauRicochet(16, 16);
    plateau->Afficher();
    //cout << plateau[7][8]->getBordHaut() << endl;
    //delete plateau;
        // Séquence ANSI pour fond blanc (47) et texte noir (30)
        // std::cout << "\033[47;30m   \033[0m";
        // std::cout << std::endl;

    return 0;
}