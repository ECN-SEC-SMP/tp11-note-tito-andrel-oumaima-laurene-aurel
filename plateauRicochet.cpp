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
std::vector<std::vector<Case*>> plateauRicochet::getPlateau() {
    return Plateau;
}
void plateauRicochet::setBordsBas(int X, int Y ) {
    if (X < 0 || X >= Max_X || Y < 0 || Y >= Max_Y) return; // Sécurité: Vérifie les indices
    Plateau[X][Y]->setBordsBas(true);
    if (X + 1 < Max_X) { // Vérifie qu'on ne dépasse pas en bas
        Plateau[X + 1][Y]->setBordsHaut(true); // Met le bord HAUT de la case EN DESSOUS
    }
}

void plateauRicochet::setBordsHaut(int X, int Y) {
    if (X < 0 || X >= Max_X || Y < 0 || Y >= Max_Y) return; // Sécurité: Vérifie les indices
    Plateau[X][Y]->setBordsHaut(true);
    if (X - 1 >= 0) { // Vérifie qu'on ne dépasse pas en haut
        Plateau[X - 1][Y]->setBordsBas(true); // Met le bord BAS de la case AU DESSUS
    }
}

void plateauRicochet::setBordsGauche(int X, int Y) {
    if (X < 0 || X >= Max_X || Y < 0 || Y >= Max_Y) return; // Sécurité: Vérifie les indices
    Plateau[X][Y]->setBordsGauche(true);
    if (Y - 1 >= 0) { // Vérifie qu'on ne dépasse pas à gauche
        Plateau[X][Y - 1]->setBordsDroit(true); // Met le bord DROIT de la case A GAUCHE
    }
}

void plateauRicochet::setBordsDroit(int X, int Y) {
    if (X < 0 || X >= Max_X || Y < 0 || Y >= Max_Y) return; // Sécurité: Vérifie les indices
    Plateau[X][Y]->setBordsDroit(true);
    if (Y + 1 < Max_Y) { // Vérifie qu'on ne dépasse pas à droite
        Plateau[X][Y + 1]->setBordsGauche(true); // Met le bord GAUCHE de la case A DROITE
    }
}

void plateauRicochet::setObstacle(int min_x, int max_x, int min_y,int max_y) {
    // Initialisation des obstacles
    // Partie haute gauche du tableau
    // obstacles sur le plateau
    int i=0;
    string couleurs[4] = {"rouge", "vert", "jaune", "bleu"};
    while(i<4){
        int k = rand() % 4;
        int x = min_x + rand() % (max_x - min_x );
        int y = min_y + rand() % (max_y - min_y );
        switch(k) {
            case 0:
                //coin haut gauche
                if (Plateau[x][y]->getBordHaut() == false && Plateau[x][y]->getBordBas() == false 
                && Plateau[x][y]->getBordGauche() == false && Plateau[x][y]->getBordDroit() == false) {
                    //Plateau[x][y]->setBordsHaut(true);
                    setBordsHaut(x,y);
                    //Plateau[x][y]->setBordsGauche(true);
                    setBordsGauche(x,y);
                    Plateau[x][y]->setCouleur(couleurs[i]);
                    i++;
                }
                break;
            case 1:


                if (Plateau[x][y]->getBordHaut() == false && Plateau[x][y]->getBordBas() == false 
                && Plateau[x][y]->getBordGauche() == false && Plateau[x][y]->getBordDroit() == false) {
                    //Plateau[x][y]->setBordsHaut(true);
                    setBordsHaut(x,y);
                    //Plateau[x][y]->setBordsDroit(true);
                    setBordsDroit(x,y);
                    Plateau[x][y]->setCouleur(couleurs[i]);
                    i++;
                }
                break;
            case 2:


                if (Plateau[x][y]->getBordHaut() == false && Plateau[x][y]->getBordBas() == false 
                && Plateau[x][y]->getBordGauche() == false && Plateau[x][y]->getBordDroit() == false) {
                    //Plateau[x][y]->setBordsBas(true);
                    setBordsBas(x,y);
                    //Plateau[x][y]->setBordsGauche(true);
                    setBordsGauche(x,y);
                    Plateau[x][y]->setCouleur(couleurs[i]);
                    i++;
                }
                break;
            case 3:
                if (Plateau[x][y]->getBordHaut() == false && Plateau[x][y]->getBordBas() == false 
                && Plateau[x][y]->getBordGauche() == false && Plateau[x][y]->getBordDroit() == false) {
                    Plateau[x][y]->setBordsBas(true);
                    Plateau[x][y]->setBordsDroit(true);
                    Plateau[x][y]->setCouleur(couleurs[i]);
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
            else {
                // //autre case
                // bool Haut;
                // bool Gauche;
                // if(Plateau[i][j-1]->getBordBas()){
                //     Haut = true;
                // }
                // else{
                //     Haut = false;
                // }
                // if(Plateau[i-1][j]->getBordDroit()){
                //     Gauche = true;
                // }
                // else{
                //     Gauche = false;
                // }
                // Plateau[i][j] = new Case(i, j, Haut, false, Gauche, false);
                Plateau[i][j] = new Case(i, j);
            }
            
        }
    }
   
    }
    
    //Initialisation des obstacles
    //Initialisation du carré centrale
        //Initilasation du centre : un carré avec bordures
    //Coin gauche
    setBordsHaut(Max_X/2 -1,Max_Y/2-1);
    setBordsGauche(Max_X/2-1,Max_Y/2-1);
    //Coin droit  
    setBordsHaut(Max_X/2-1,Max_Y/2);   
    setBordsDroit(Max_X/2-1,Max_Y/2);    
    //Coin bas gauche
    setBordsBas(Max_X/2,Max_Y/2-1);
    setBordsGauche(Max_X/2,Max_Y/2-1);
    //Coin bas droit
    setBordsBas(Max_X/2,Max_Y/2);
    setBordsDroit(Max_X/2,Max_Y/2);
    
    //Partie haute gauche du tableau
    //obstacles collés au bord 

    setBordsDroit(0,rand() % (Max_Y/2-1));
    setBordsBas(rand() % (Max_X/2-1),0);
    
    //Partie haute droite du tableau
    setBordsGauche(0,Max_Y/2 + rand() % (Max_Y/2-1));
    setBordsBas(rand() % (Max_X/2-1),Max_Y-1);
    
    //Partie basse gauche du tableau
    setBordsDroit(Max_X-1,rand() % (Max_Y/2-1));     
    setBordsBas(rand() % (Max_X/2-1)+Max_X/2,0);
    //Partie basse droite du tableau
    setBordsGauche(Max_Y-1,Max_X/2 + rand() % (Max_X/2));
    setBordsHaut(Max_Y/2+rand() % (Max_Y/2),Max_X-1);
    
    //obstacles sur le plateau
    setObstacle(0, Max_X/2, 0, Max_Y/2);
    
    setObstacle(Max_X/2,Max_X-1,0,Max_Y/2);

    setObstacle(Max_X/2,Max_X-1,Max_Y/2,Max_Y);

    setObstacle(0, Max_X/2,Max_Y/2,Max_Y);

    // Placer l'objectif multicolore
    int multi_x = rand() % Max_X;
    int multi_y = rand() % Max_Y;

    while(Plateau[multi_x][multi_y]->getBordHaut() == false && Plateau[multi_x][multi_y]->getBordBas() == false 
    && Plateau[multi_x][multi_y]->getBordGauche() == false && Plateau[multi_x][multi_y]->getBordDroit() == false){
        multi_x = rand() % Max_X;
        multi_y = rand() % Max_Y;
    }

    Plateau[multi_x][multi_y]->setCouleur("incolore");
    
    int k = rand()%4;

    switch(k) {
        case 0:
            //coin haut gauche
            Plateau[multi_x][multi_y]->setBordsHaut(true);
            Plateau[multi_x][multi_y]->setBordsGauche(true);
            break;
        case 1:
            Plateau[multi_x][multi_y]->setBordsHaut(true);
            Plateau[multi_x][multi_y]->setBordsDroit(true);
            break;
        case 2:
            Plateau[multi_x][multi_y]->setBordsBas(true);
            Plateau[multi_x][multi_y]->setBordsGauche(true);
            break;
        case 3:
            Plateau[multi_x][multi_y]->setBordsBas(true);
            Plateau[multi_x][multi_y]->setBordsDroit(true);
            break;
    }

    //Initialisation des robots
    for (int k = 0; k < 2; k++) { // Example for initializing 2 robots
        // Code to initialize robots goes here
        //rand() % maxX;
    }
}

void plateauRicochet::Afficher() {
    for (int i = 0; i < Max_X; ++i) {
        
        // Affiche les murs du haut
        for (int j = 0; j < Max_Y; ++j) {
            cout << "╦";
            if (Plateau[i][j]->getBordHaut()) cout << "════";
            else cout << "    ";
        }
        cout << "╣" << endl;

        // Affiche les murs gauche et le contenu de la case
        for (int j = 0; j < Max_Y; ++j) {
            if (Plateau[i][j]->getBordGauche()) cout << "║";
            else cout << " ";
            cout << "    "; // Ici tu peux afficher un symbole pour robot/obstacle/couleur
        }
        if (Plateau[i][Max_Y-1]->getBordDroit()) cout << "║";
        cout << endl;
        // Mur droit de la dernière case
    }
    // Affiche la dernière ligne de murs bas
    for (int j = 0; j < Max_Y; ++j) {
        cout << "╩";
        if (Plateau[Max_X-1][j]->getBordBas()) cout << "════";
        else cout << "    ";
    }
    cout << "╝" << endl;
}

// void plateauRicochet::initialisationGrille() {
//     // Constructeur par défaut
//     Max_X = 0;
//     Max_Y = 0;
//     Plateau.resize(Max_X, std::vector<Case*>(Max_Y));
// }
// Destructeur
plateauRicochet::~plateauRicochet() {
    for (int i = 0; i < Max_X; ++i) { 
        for (int j = 0; j < Max_Y; ++j) { 
            delete Plateau[i][j]; 
        
    }
    // Vectors themselves are automatically destroyed
}
}

void plateauRicochet::DeplacerRobot(Robot* robot, char direction) {
    // Code pour déplacer le robot sur le plateau
    
    int Pos_X = robot->GetX();
    int Pos_Y = robot->GetY();

    int Deplacement = robot->GetNbDeplacement();
    robot->SetNbDeplacement(Deplacement + 1);
    cout << "Robot position: " << Pos_X << ", " << Pos_Y << endl;
    switch (direction) {

        // Vérifier si la case est libre avant de déplacer
        
        case 'U'://Up
            while(1) {
               if (Plateau[Pos_X][Pos_Y]->getBordHaut()){
                robot->SetPosition(Pos_X, Pos_Y);
                cout << "Robot moved to Up: " << Pos_X << ", " << Pos_Y << endl;
                break;
               }
               else{
                     Pos_X--;
               }
            }
            break;
            
        case 'D': // Down
            while(1) {
               if (Plateau[Pos_X][Pos_Y]->getBordBas()){
                robot->SetPosition(Pos_X, Pos_Y);
                cout << "Robot moved to Down: " << Pos_X << ", " << Pos_Y << endl;
                break;
               }
               else{
                     Pos_X++;
               }
            }
        cout<<"end Down"<<endl;
            break;
            
        case 'L':  // Left
            while(1) {
                if (Plateau[Pos_X][Pos_Y]->getBordGauche()){
                robot->SetPosition(Pos_X, Pos_Y);
                cout << "Robot moved to: Left " << Pos_X << ", " << Pos_Y << endl;
                break;
                }
                else{
                    Pos_Y--;
                }
            }
            break;
        case 'R':  // Right
            while(1) {
                if (Plateau[Pos_X][Pos_Y]->getBordDroit()){
                robot->SetPosition(Pos_X, Pos_Y);
                cout << "Robot moved to Right: " << Pos_X << ", " << Pos_Y << endl;
                break;
                }
                else{
                    Pos_Y++;
                }
            }
            break;
    
}
    
}