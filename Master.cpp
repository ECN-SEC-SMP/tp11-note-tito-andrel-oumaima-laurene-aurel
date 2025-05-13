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
    std::cout << "R/G/B/Y" << std::endl;
    std::cin >> Rob;
    return Rob;
}

void Master::Tour()
{
    char ok;     // Annonce du nombre de coups
    int nbCoups; // Nombre de coups
    // En attente du joueur
    std::cout << "En attente..." << endl;
    while (ok != 'O')
    {
        cin >> ok;
    }

    std::cout << "Nombre de coups annoncés ?" << endl;
    while (!(std::cin >> nbCoups)) // Vérifie si l'entrée est un entier valide
    {
        std::cin.clear();                                                   // Réinitialise le flux en cas d'erreur
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore les caractères invalides
        std::cout << "Entrée invalide. Veuillez entrer un nombre : " << std::endl;
    }
    std::cout << "Nombre de coups annoncés : " << nbCoups << endl;

    // choisir le robot entre les 4
    char Rob = select_Robot();
    if (Rob == 'R')
    {
        while (nbCoups != 0) {
        // choisir la direction
        // Déplacer le robot avec la direction choisie
        // Déplacer le robot avec la direction choisie
        Plateau->DeplacerRobot(robotRed, robotRed->RecupereInfo());
        cout << "Robot position end: " << robotRed->GetX() << ", " << robotRed->GetY() << endl;
        // Vérifier si l'objectif est atteint
        nbCoups --;
        }
    }
    else if (Rob == 'G')
    {
        Plateau->DeplacerRobot(robotGreen, robotGreen->RecupereInfo());
        cout << "Robot position end: " << robotGreen->GetX() << ", " << robotGreen->GetY() << endl;
    }
    else if (Rob == 'B')
    {

        Plateau->DeplacerRobot(robotBlue, robotBlue->RecupereInfo());
        cout << "Robot position end: " << robotBlue->GetX() << ", " << robotBlue->GetY() << endl;
    }
    else if (Rob == 'Y')
    {
        Plateau->DeplacerRobot(robotYellow, robotYellow->RecupereInfo());
        cout << "Robot position end: " << robotYellow->GetX() << ", " << robotYellow->GetY() << endl;
    }
    else
    {
        std::cout << "Robot non valide" << std::endl;
        Tour();
    }

    // Objectif atteint?//Next player
    // afficher le plateau
    // next Turn
    // fin si tout les objectif sont atteint
    Afficher();
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
                        char initiale = objectif->getCouleur()[0]; // Récupère l'initiale de la couleur
                        // Ajouter fond gris pour l'objectif
                        cout << fondGris << " " << initiale << "  " << resetColor;
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
