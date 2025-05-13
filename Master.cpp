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
#include "Sablier.h"
#include <thread>

using namespace std;

// Initialisation du plateau et des éléments le constituant
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

    initJoueurs();

    sablier = new Sablier(10); // 60 secondes

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

// Touches d'entrée
char Master::select_Robot()
{
    char Rob;
    std::cout << "Sélection du robot: Red, Green, Blue, Yellow" << std::endl;
    std::cout << "R/G/B/Y" << endl;
    std::cin >> Rob;
    return Rob;
}

// Manipulation du robot sur le plateau et acquittement objectif, en foncion de la couleur
bool Master::SelectionRobot(char Rob, int nbCoups)
{
    if (Rob == 'R')
    {
        robotRed->SetNbDeplacement(nbCoups); // Ajout du nb de coups au robot

        // Sauvegarde des coordonnées du robot
        Plateau->DeplacerRobot(robotRed, robotRed->RecupereInfo());
        cout << "Robot position end : " << robotRed->GetX() << ", " << robotRed->GetY() << endl;
        Afficher();

        // On modifie la variable ObjectifOK si l'objectif de la même a été atteint
        if (true) // TODO : à modifier en fonction de l'objectif (rajouter)
        {
            return false;
        }
        else
        {
            return false;
        }
    }
    else if (Rob == 'G')
    {
        robotGreen->SetNbDeplacement(nbCoups); // Ajout du nb de coups au robot

        Plateau->DeplacerRobot(robotGreen, robotGreen->RecupereInfo());
        cout << "Robot position end: " << robotGreen->GetX() << ", " << robotGreen->GetY() << endl;
        Afficher();

        // On modifie la variable ObjectifOK si l'objectif a été atteint
        if (true) // TODO : à modifier en fonction de l'objectif (rajouter)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (Rob == 'B')
    {
        robotBlue->SetNbDeplacement(nbCoups); // Ajout du nb de coups au robot

        Plateau->DeplacerRobot(robotBlue, robotBlue->RecupereInfo());
        cout << "Robot position end: " << robotBlue->GetX() << ", " << robotBlue->GetY() << endl;
        Afficher();

        // On modifie la variable ObjectifOK si l'objectif a été atteint
        if (true) // TODO : à modifier en fonction de l'objectif (rajouter)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (Rob == 'Y')
    {
        robotYellow->SetNbDeplacement(nbCoups); // Ajout du nb de coups au robot

        Plateau->DeplacerRobot(robotYellow, robotYellow->RecupereInfo());
        cout << "Robot position end: " << robotYellow->GetX() << ", " << robotYellow->GetY() << endl;
        Afficher();

        // On modifie la variable ObjectifOK si l'objectif a été atteint
        if (true) // TODO : à modifier en fonction de l'objectif (rajouter)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void Master::TourdeJeu()
{
    int jeu = 0;     // Nombre de joueurs -> à modifier
    char Rob;        // Sélection robot
    int nbCoups;     // Nombre de coups
    bool ObjectifOK; // Variable d'acquittement d'objectif

    // On enregistre la position initiale de chaque robot
    int getXR = robotRed->GetX();
    int getYR = robotRed->GetY();

    int getXV = robotGreen->GetX();
    int getYV = robotGreen->GetY();

    int getXB = robotBlue->GetX();
    int getYB = robotBlue->GetY();

    int getXJ = robotYellow->GetX();
    int getYJ = robotYellow->GetY();

    while (jeu < nbJoueurs) // à modifier (?)
    {
        // Annonce du nombre de coups, on exclu tout les caractères qui ne sont pas des entiers
        // TODO : Associer joueur à prompt
        Joueur* Joueurcourrant = selectJoueur(); // Sélectionne le joueur courant
        std::cout << "Nombre de coups annoncés ?" << endl;
        while (!(std::cin >> nbCoups)) // Vérifie si l'entrée est un entier valide
        {
            std::cin.clear();                                                   // Réinitialise le flux en cas d'erreur
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore les caractères invalides
            std::cout << "Entrée invalide. Veuillez entrer un nombre : " << std::endl;
        }

        // Le joueur continue de jouer tant qu'il y a assez de coups, et que l'objectif n'est pas atteint
        ObjectifOK = false; // Réinitialisation de la variable ObjectifOK
        while (nbCoups > 0 && ObjectifOK != true)
        {
            Rob = select_Robot(); // Variable sélection robot
            cout << "Nombre de coups restants : " << nbCoups << endl;
            if (SelectionRobot(Rob, nbCoups) == true)
            {
                ObjectifOK = true;
            }
            else
            {
                ObjectifOK = false;
            }
            nbCoups--;
        }

        // Si l'objectif est validé, on incrémente le score, sinon,
        // on remet le robot à sa position initiale, et on passe au joueur suivant
        if (ObjectifOK == true) // Condition validation objectif
        {
            Afficher();
            // Les objectifs sont atteints, on incrémente le score du joueur
            cout << "Félicitations !" << endl;
            Joueurcourrant->setScore(Joueurcourrant->getScore() + 1); // Incrémente le score du joueur courant
            cout << "Score du joueur : " << Joueurcourrant->getScore() << endl;
            Tour();
        }
        else
        {
            jeu++;  // On passe au joueur suivant -> à modifier

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
            // Rob = select_Robot(); // Variable sélection robot
            TourdeJeu(); // On relance le tour de jeu
        }
    }
}

void Master::Tour()
{
    char ok; // Annonce du nombre de coups

    // En attente du joueur
    std::cout << "Appuyez sur O pour annoncer." << endl;
    std::cout << "Appuyez sur S pour afficher les scores." << endl;
    while (ok != 'O')
    {
        // Affichage des scores - option
        if (ok == 'S')
        if (ok == 'S')
        {
            AfficherScores();
        }
    }

    // On lance le sablier pendant 60 secondes
    sablier->startDecompte();
    while (!sablier->getFini())
    {
        this_thread::sleep_for(chrono::seconds(1));
        // Affichage du sablier
        //cout << "Sablier : " << sablier->getTemps() << endl;
    }
    cout << "Temps écoulé !" << endl;

    TourdeJeu(); // Appel de la fonction de jeu
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

                        if (objectif->getForme() == "cercle")
                        {
                            forme = " ⚪ ";
                        }
                        else if (objectif->getForme() == "carre")
                        {
                            forme = " ⬜ ";
                        }
                        else if (objectif->getForme() == "triangle")
                        {
                            forme = " ▲  ";
                        }
                        else
                        {
                            forme = " ✖️  ";
                        }

                        // char initiale = objectif->getForme()[0]; // Récupère l'initiale de la couleur
                        switch (objectif->getCouleur()[0])
                        {
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
void Master::initJoueurs()
{
    cout << "nombre de joueurs ?" << endl;
    cin >> nbJoueurs;

    // Libère la mémoire des anciens joueurs
    for (auto joueur : Joueurs) {
        delete joueur;
    }
    Joueurs.clear();

    for (int i = 0; i < nbJoueurs; i++) {
        string nom;
        cout << "Nom du joueur " << i + 1 << " ?" << endl;
        cin >> nom;
        Joueurs.push_back(new Joueur(nom));
    }
}

// afficher les scores
void Master::AfficherScores()
{
    cout << "Scores actuels : " << endl;
    for(int i = 0; i < nbJoueurs; i++)
    {
        cout << Joueurs[i]->getNom() << " : " << Joueurs[i]->getScore() << endl;
    }
}

Joueur* Master::selectJoueur()
{
    // Choisir le joueur
    int choix;
    cout << "Sélectionnez le joueur (1 à " << nbJoueurs << "): ";
    cin >> choix;

    if (choix < 1 || choix > nbJoueurs)
    {
        cout << "Choix invalide. Veuillez sélectionner un joueur valide." << endl;
        return selectJoueur();
    }
    else
    {
        cout << "Vous avez sélectionné le joueur : " << Joueurs[choix - 1]->getNom() << endl;
        return Joueurs[choix - 1]; // Retourne le joueur sélectionné
    }
}