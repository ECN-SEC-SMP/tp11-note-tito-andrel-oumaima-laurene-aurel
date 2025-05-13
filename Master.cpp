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

bool Master::SelectionRobot(char Rob, int nbCoups)
{
    if (Rob == 'R')
    {
        // Sauvegarde des coordonnées du robot
        Plateau->DeplacerRobot(robotRed, robotRed->RecupereInfo());
        cout << "Robot position end : " << robotRed->GetX() << ", " << robotRed->GetY() << endl;
        Afficher();

        // Décrémente le nb de déplacements
        nbCoups--;
        robotRed->SetNbDeplacement(nbCoups);
        cout << "Déplacements restants :" << robotRed->GetNbDeplacement() << endl;
        return true;
        // Si les objectifs ont été remplit, alors on augmente le score du joueur associé
        // if (true) // à modifier en fonction de l'objectif (rajouter)
        // {
        //     return true;
        // }
        // else
        // {
        //     return false;
        // }
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

    int getXR;
    int getYR;
    getXR = robotRed->GetX();
    getYR = robotRed->GetY();

    // Annonce du nombre de coups, on exclu tout les caractères qui ne sont pas des entiers
    std::cout << "Nombre de coups annoncés ?" << endl;
    while (!(std::cin >> nbCoups)) // Vérifie si l'entrée est un entier valide
    {
        std::cin.clear();                                                   // Réinitialise le flux en cas d'erreur
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore les caractères invalides
        std::cout << "Entrée invalide. Veuillez entrer un nombre : " << std::endl;
    }

    robotRed->SetNbDeplacement(nbCoups); // Ajout du nb de coups au robot
    std::cout << "Nombre de coups annoncés : " << robotRed->GetNbDeplacement() << endl;

    // Gestion sablier et annonce des coups des autres joueurs ici

    Rob = select_Robot();

    //SelectionRobot(Rob, nbCoups);
    // while (SelectionRobot(Rob, nbCoups) == false)
    // {
    //     ObjectifOK = false;
    // }

    if (SelectionRobot(Rob,nbCoups) == true) { ObjectifOK = true; }

    if (ObjectifOK == true) // Condition validation objectif
    {
        // Les objectifs sont atteints, on incrémente le score du joueur
        cout << "Félicitations !" << endl;
        Joueur1->setScore(Joueur1->getScore() + 1); // à modifier en fct d'un vecteur
        cout << "Score du robot Rouge :" << Joueur1->getScore() << endl;
    }
    else
    {
        // Tout les objectifs ne sont pas atteints
        robotRed->SetX(getXR);
        robotRed->SetY(getYR);
        Plateau->DeplacerRobotPos(robotRed, getXR, getYR); // Remise à la position initiale
        Afficher();
        // Insulte
        cout << "Skill Issue + gênant" << endl
             << endl; // Affichage de l'ancien plateau
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
