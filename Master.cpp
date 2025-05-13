#include "Case.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "plateauRicochet.h"
#include "Master.h"
#include <cstdlib> // Pour srand() et rand()
#include <ctime>   // Pour time()
#include <limits>  // Pour std::numeric_limits
#include "Joueur.h"

using namespace std;

Master::Master(int X, int Y)
{
    Max_X = X;
    Max_Y = Y;
    // Robot
    Plateau = new plateauRicochet(Max_X, Max_Y);
    robotRed = new Robot("rouge");
    robotGreen = new Robot("vert");
    robotBlue = new Robot("bleu");
    robotYellow = new Robot("jaune");

    Joueur1 = new Joueur("Rouge");
    Joueur2 = new Joueur("Bleu");
    Joueur3 = new Joueur("Jaune");
    Joueur4 = new Joueur("Vert");

    // robotYellow = new Robot("jaune", 4, 7);
    // robotYellow->GenereRobot();
    Plateau->InitRobot(robotRed, robotGreen, robotBlue, robotYellow);
    Afficher();
}
Master::~Master()
{
    delete robotRed; // Suppression du robot rouge
    delete Plateau;  // Suppression du plateau
}

char Master::select_Robot()
{
    char Rob;
    std::cout << "Sélection du robot: Red, Green, Blue, Yellow" << std::endl;
    std::cout << "R/G/B/Y" << endl;
    std::cin >> Rob;
    return Rob;
}

bool Master::SelectionRobot(char Rob, int nbCoups, bool ObjectifOK)
{
    if (Rob == 'R')
    {
        robotRed->SetNbDeplacement(nbCoups); // Ajout du nb de coups au robot
        std::cout << "Nombre de coups annoncés : " << robotRed->GetNbDeplacement() << endl;

        // Sauvegarde des coordonnées du robot
        Plateau->DeplacerRobot(robotRed, robotRed->RecupereInfo());
        cout << "Robot position end : " << robotRed->GetX() << ", " << robotRed->GetY() << endl;
        Afficher();

        // On modifie la variable ObjectifOK si l'objectif a été atteint
        if (true) // TODO : à modifier en fonction de l'objectif (rajouter)
        {
            ObjectifOK = true;
            return true;
        }
        else
        {
            ObjectifOK = false;
            return false;
        }
    }
    else if (Rob == 'G')
    {
        Plateau->DeplacerRobot(robotGreen, robotGreen->RecupereInfo());
        cout << "Robot position end: " << robotGreen->GetX() << ", " << robotGreen->GetY() << endl;
        return true;
    }
    else if (Rob == 'B')
    {

        Plateau->DeplacerRobot(robotBlue, robotBlue->RecupereInfo());
        cout << "Robot position end: " << robotBlue->GetX() << ", " << robotBlue->GetY() << endl;
        return true;
    }
    else if (Rob == 'Y')
    {
        Plateau->DeplacerRobot(robotYellow, robotYellow->RecupereInfo());
        cout << "Robot position end: " << robotYellow->GetX() << ", " << robotYellow->GetY() << endl;
        return true;
    }
}

void Master::Tour()
{
    char ok;                 // Annonce du nombre de coups
    int nbCoups;             // Nombre de coups
    bool ObjectifOK = false; // Variable d'acquittement d'objectif

    // En attente du joueur
    std::cout << "Appuyez sur O pour annoncer." << endl;
    std::cout << "Appuyez sur S pour afficher les scores." << endl;
    while (ok != 'O')
    {
        // Affichage des scores - option
        if (ok == 'S')
        {
            cout << "Scores actuels : " << endl;
            cout << "    Joueur 1 : " << Joueur1->getScore() << endl;
            cout << "    Joueur 2 : " << Joueur2->getScore() << endl;
            cout << "    Joueur 3 : " << Joueur3->getScore() << endl;
            cout << "    Joueur 4 : " << Joueur4->getScore() << endl;
        }
        cin >> ok;
    }

    // choisir le robot entre les 4
    char Rob;
    int tour = 4; // Variable de jeu lorsque le nombre de coups a été annoncé

    // Sauvegarde des coordonnées initiales des robots
    // robot rouge
    int getXR;
    int getYR;

    // robot vert
    int getXV;
    int getYV;

    // robot bleu
    int getXB;
    int getYB;

    // robot jaune
    int getXJ;
    int getYJ;

    // On enregistre la position initiale de chaque robot
    getXR = robotRed->GetX();
    getYR = robotRed->GetY();

    getXV = robotGreen->GetX();
    getYV = robotGreen->GetY();

    getXB = robotBlue->GetX();
    getYB = robotBlue->GetY();

    getXJ = robotYellow->GetX();
    getYJ = robotYellow->GetY();

    // Annonce du nombre de coups, on exclu tout les caractères qui ne sont pas des entiers
    std::cout << "Nombre de coups annoncés ?" << endl;
    while (!(std::cin >> nbCoups)) // Vérifie si l'entrée est un entier valide
    {
        std::cin.clear();                                                   // Réinitialise le flux en cas d'erreur
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore les caractères invalides
        std::cout << "Entrée invalide. Veuillez entrer un nombre : " << std::endl;
    }

    // Gestion sablier et annonce des coups des autres joueurs ici

    Rob = select_Robot();

    // SelectionRobot(Rob, nbCoups);
    //  while (SelectionRobot(Rob, nbCoups) == false)
    //  {
    //      ObjectifOK = false;
    //  }

    while (nbCoups != 0 || ObjectifOK != true)
    {
        if (SelectionRobot(Rob, nbCoups, ObjectifOK) == true) {
            ObjectifOK = true;
        } else {
            ObjectifOK = false;
        }
        nbCoups--;
    }

    if (ObjectifOK == true) // Condition validation objectif
    {
        // Les objectifs sont atteints, on incrémente le score du joueur
        cout << "Félicitations !" << endl;
        Joueur1->setScore(Joueur1->getScore() + 1); // à modifier en fct d'un vecteur
        cout << "Score du robot Rouge :" << Joueur1->getScore() << endl;
    }
    else
    {
        // L'objectif n'est pas atteint, on remet le robot à sa position initiale
        robotRed->SetX(getXR);
        robotRed->SetY(getYR);

        robotGreen->SetX(getXV);
        robotGreen->SetY(getYV);

        robotBlue->SetX(getXB);
        robotBlue->SetY(getYB);

        robotYellow->SetX(getXJ);
        robotYellow->SetY(getYJ);

        Plateau->DeplacerRobotPos(robotRed, getXR, getYR); // Remise à la position initiale
        Plateau->DeplacerRobotPos(robotGreen, getXV, getYV);
        Plateau->DeplacerRobotPos(robotBlue, getXB, getYB);
        Plateau->DeplacerRobotPos(robotYellow, getXJ, getYJ);

        // Affichage de la position initiale - ancien plateau
        Afficher();
        // Insulte
        cout << "Skill Issue + gênant" << endl
             << endl;
    }

    // Afficher();
    Tour();
}

void Master::Afficher()
{
    std::vector<std::vector<Case *>> Grille = Plateau->getPlateau();

    // Code ANSI pour fond gris clair
    string fondGris = "\033[100m"; // Remplacé \033[47m (blanc) par \033[100m (gris clair)
    string resetColor = "\033[0m";

    for (int i = 0; i < Max_X; ++i)
    {
        // Affiche les murs du haut
        cout << fondGris << (i == 0 ? "╔" : (Grille[i][0]->getBordHaut() ? "╠" : "║")) << resetColor;

        for (int j = 0; j < Max_Y; ++j)
        {
            cout << fondGris << (Grille[i][j]->getBordHaut() ? "════" : "    ") << resetColor;
            if (j < Max_Y - 1)
            {
                if (i == 0)
                {
                    if (Grille[i][j + 1]->getBordGauche())
                    {
                        cout << fondGris << "╦" << resetColor;
                    }
                    else
                    {
                        cout << fondGris << "═" << resetColor;
                    }
                }
                else if (Grille[i][j]->getBordHaut() && Grille[i][j + 1]->getBordHaut() &&
                         Grille[i][j]->getBordDroit() && Grille[i][j + 1]->getBordGauche())
                {
                    cout << fondGris << "╬" << resetColor;
                }
                else if (Grille[i][j]->getBordHaut() && Grille[i][j + 1]->getBordGauche())
                {
                    cout << fondGris << "╗" << resetColor; // OK
                }
                else
                {
                    cout << fondGris << "." << resetColor;
                }
            }
        }

        cout << fondGris << (i == 0 ? "╗" : (Grille[i][Max_Y - 1]->getBordHaut() ? "╣" : "║")) << resetColor << endl;

        // Affiche les murs gauche et le contenu de la case
        for (int j = 0; j < Max_Y; ++j)
        {
            cout << fondGris << (Grille[i][j]->getBordGauche() ? "║" : " ") << resetColor;

            // Version avec smileys robots colorés SUR FOND COLORÉ (inchangée)
            if (robotRed->GetX() == i && robotRed->GetY() == j)
                cout << "\033[1;41m" << " 🤖 " << "\033[0m";
            else if (robotGreen->GetX() == i && robotGreen->GetY() == j)
                cout << "\033[1;42m" << " 🤖 " << "\033[0m";
            else if (robotBlue->GetX() == i && robotBlue->GetY() == j)
                cout << "\033[1;44m" << " 🤖 " << "\033[0m";
            else if (robotYellow->GetX() == i && robotYellow->GetY() == j)
                cout << "\033[1;43m" << " 🤖 " << "\033[0m";

            // Afficher les objectifs
            else
            {
                bool objectifTrouve = false;
                for (auto objectif : Plateau->getObjectifs())
                {
                    if (objectif->getX() == i && objectif->getY() == j)
                    {
                        string forme;

                        if (objectif->getForme() == "cercle"){
                            forme = " ⚪ ";
                        }
                        else if (objectif->getForme() == "carre"){
                            forme = " ⬜ ";
                        }
                        else if (objectif->getForme() == "triangle"){
                            forme = " ▲  ";
                        }
                        else{
                            forme = " ✖️  ";
                        }

                        // char initiale = objectif->getForme()[0]; // Récupère l'initiale de la couleur
                        switch(objectif->getCouleur()[0]){
                            case 'r':
                                cout << "\033[1;41m" << forme << "\033[0m"; // Rouge
                                break;
                            case 'v':
                                cout << "\033[1;42m" << forme << "\033[0m"; // Vert
                                break;
                            case 'b':
                                cout << "\033[1;44m" << forme << "\033[0m"; // Bleu
                                break;
                            case 'j':
                                cout << "\033[1;43m" << forme << "\033[0m"; // Jaune
                                break;
                        }
                        
                        // Ajouter fond gris pour l'objectif
                        // cout << fondGris << " " << initiale << "  " << resetColor;
                        objectifTrouve = true;
                        break;
                    }
                }
                if (!objectifTrouve)
                {
                    // La case vide doit aussi avoir le fond gris
                    cout << fondGris << "    " << resetColor; // Case vide
                }
            }
        }
        cout << fondGris << (Grille[i][Max_Y - 1]->getBordDroit() ? "║" : " ") << resetColor << endl;
    }

    // Affiche la dernière ligne de murs bas
    cout << fondGris << "╚" << resetColor;
    for (int j = 0; j < Max_Y; ++j)
    {
        cout << fondGris << (Grille[Max_X - 1][j]->getBordBas() ? "════" : "    ") << resetColor;
        if (j < Max_Y - 1)
        {
            if (Grille[Max_X - 1][j]->getBordBas() || Grille[Max_X - 1][j + 1]->getBordBas() ||
                Grille[Max_X - 1][j]->getBordDroit() || Grille[Max_X - 1][j + 1]->getBordGauche())
            {
                if (Grille[Max_X - 1][j + 1]->getBordGauche())
                {
                    cout << fondGris << "╩" << resetColor;
                }
                else
                {
                    cout << fondGris << "═" << resetColor;
                }
            }
            else
            {
                cout << fondGris << "." << resetColor;
            }
        }
    }
    cout << fondGris << "╝" << resetColor << endl;
}
