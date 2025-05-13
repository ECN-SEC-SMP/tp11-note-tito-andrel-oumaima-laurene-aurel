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

    JoueurRouge = new Joueur("Rouge");
    // JoueurBleu = new Joueur("Bleu");
    // JoueurJaune = new Joueur("Jaune");
    // JoueurVert = new Joueur("Vert");

    // robotYellow = new Robot("jaune", 4, 7);
    // robotYellow->GenereRobot();
    Plateau->InitRobot(robotRed, robotGreen, robotBlue, robotYellow);

    tirerObjectif();
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

void Master::Tour()
{
    char ok;     // Annonce du nombre de coups
    int nbCoups; // Nombre de coups
    // En attente du joueur
    std::cout << "Appuyez sur O pour annoncer." << endl;
    std::cout << "Appuyez sur S pour afficher les scores." << endl;
    while (ok != 'O')
    {
        cin >> ok;
    }

    if (ok == 'S')
    {
        cout << "S";
    }
    else if (ok == 'O')
    {

        // std::cout << "Nombre de coups annoncés ?" << endl;
        // while (!(std::cin >> nbCoups)) // Vérifie si l'entrée est un entier valide
        // {
        //     std::cin.clear();                                                   // Réinitialise le flux en cas d'erreur
        //     std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore les caractères invalides
        //     std::cout << "Entrée invalide. Veuillez entrer un nombre : " << std::endl;
        // }
        // std::cout << "Nombre de coups annoncés : " << nbCoups << endl;

        // choisir le robot entre les 4
        char Rob = select_Robot();
        int getX;
        int getY;

        if (Rob == 'R')
        {   
            Plateau->DeplacerRobot(robotRed, robotRed->RecupereInfo());
            cout << "Robot position end: " << robotRed->GetX() << ", " << robotRed->GetY() << endl;
            // while (nbCoups != 0)
            // {
            //     // choisir la direction
            //     // Déplacer le robot avec la direction choisie
            //     Plateau->DeplacerRobot(robotRed, robotRed->RecupereInfo());
            //     cout << "Robot position end: " << robotRed->GetX() << ", " << robotRed->GetY() << endl;
            //     getX = robotRed->GetX();
            //     getY = robotRed->GetY();
            //     Afficher();
            //     nbCoups--;
                
            //     // Gestion des objectifs ici
            //     // On supprime un élémet du vecteur si le robot se trouve sur une case objectif
            // }
            // if (Plateau->getObjectifs().empty())
            // {
            //     // Les objectifs sont atteints, on incrémente le score du joueur
            //     cout << "Félicitations !";
            //     JoueurRouge->setScore(JoueurRouge->getScore() + 1);
            //     cout << "Score du robot Rouge :" << JoueurRouge->getScore() << endl;
            // }
            // else
            // {
            //     // Tout les objectifs ne sont pas atteints
            //     cout << "Skill Issue + gênant";
            //     robotRed->SetX(getX);
            //     robotRed->SetY(getY);
            //     Afficher();
            // }
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

        if(getObjectifAtteint()){
            tirerObjectif();
            if(Plateau->getObjectifs().empty()){
                cout << "Partie terminée" << endl;
                return;
            }
        }
        Afficher();
        for (auto obj : Plateau->getObjectifs()) {
            std::cout << obj->getForme() << " " << obj->getCouleur() << " (" << obj->getX() << "," << obj->getY() << ")" << std::endl;
        }
        Tour();
    }
}

void Master::Afficher()
{
    afficherObjectif();
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

void Master::tirerObjectif()
{
    if(!Plateau->getObjectifs().empty())
    {
        // On tire un objectif au hasard
        srand(time(0)); // Initialiser le générateur de nombres aléatoires
        int randomIndex = rand() % Plateau->getObjectifs().size();
        objectifCourant = Plateau->getObjectifs()[randomIndex];
    }
}

bool Master::getObjectifAtteint()
{
    if((robotRed->GetX() == objectifCourant->getX() && robotRed->GetY() == objectifCourant->getY() && robotRed->getCouleur() == objectifCourant->getCouleur())
    || (robotGreen->GetX() == objectifCourant->getX() && robotGreen->GetY() == objectifCourant->getY() && robotGreen->getCouleur() == objectifCourant->getCouleur()) 
    || (robotBlue->GetX() == objectifCourant->getX() && robotBlue->GetY() == objectifCourant->getY() && robotBlue->getCouleur() == objectifCourant->getCouleur())
    || (robotYellow->GetX() == objectifCourant->getX() && robotYellow->GetY() == objectifCourant->getY() && robotYellow->getCouleur() == objectifCourant->getCouleur()))
    {
        cout << "Objectif atteint !" << endl;
        // On supprime l'objectif du vecteur
        //auto objectifs = Plateau->getObjectifs();
        auto it = std::find(Plateau->getObjectifs().begin(), Plateau->getObjectifs().end(), objectifCourant);
        Plateau->getObjectifs().erase(it);
        return true;
    }
    else
    {
        cout << "Objectif non atteint." << endl;
        return false;
        
    }
}

void Master::afficherObjectif(){
    cout << "Objectif : " << objectifCourant->getForme() << endl;
    cout << "Couleur : " << objectifCourant->getCouleur() << endl;
    cout << "Position : (" << objectifCourant->getX() << ", " << objectifCourant->getY() << ")" << endl;
}