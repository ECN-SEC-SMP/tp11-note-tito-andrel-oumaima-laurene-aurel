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
std::vector<std::vector<Case *>> plateauRicochet::getPlateau()
{
    return Plateau;
}
void plateauRicochet::setBordsBas(int X, int Y)
{
    if (X < 0 || X >= Max_X || Y < 0 || Y >= Max_Y)
        return; // Sécurité: Vérifie les indices
    Plateau[X][Y]->setBordsBas(true);
    if (X + 1 < Max_X)
    {                                          // Vérifie qu'on ne dépasse pas en bas
        Plateau[X + 1][Y]->setBordsHaut(true); // Met le bord HAUT de la case EN DESSOUS
    }
}

void plateauRicochet::setBordsHaut(int X, int Y)
{
    if (X < 0 || X >= Max_X || Y < 0 || Y >= Max_Y)
        return; // Sécurité: Vérifie les indices
    Plateau[X][Y]->setBordsHaut(true);
    if (X - 1 >= 0)
    {                                         // Vérifie qu'on ne dépasse pas en haut
        Plateau[X - 1][Y]->setBordsBas(true); // Met le bord BAS de la case AU DESSUS
    }
}

void plateauRicochet::setBordsGauche(int X, int Y)
{
    if (X < 0 || X >= Max_X || Y < 0 || Y >= Max_Y)
        return; // Sécurité: Vérifie les indices
    Plateau[X][Y]->setBordsGauche(true);
    if (Y - 1 >= 0)
    {                                           // Vérifie qu'on ne dépasse pas à gauche
        Plateau[X][Y - 1]->setBordsDroit(true); // Met le bord DROIT de la case A GAUCHE
    }
}

void plateauRicochet::setBordsDroit(int X, int Y)
{
    if (X < 0 || X >= Max_X || Y < 0 || Y >= Max_Y)
        return; // Sécurité: Vérifie les indices
    Plateau[X][Y]->setBordsDroit(true);
    if (Y + 1 < Max_Y)
    {                                            // Vérifie qu'on ne dépasse pas à droite
        Plateau[X][Y + 1]->setBordsGauche(true); // Met le bord GAUCHE de la case A DROITE
    }
}

void plateauRicochet::setObstacle(int min_x, int max_x, int min_y, int max_y, string forme)
{
    // Initialisation des obstacles
    int i = 0;
    string couleurs[4] = {"rouge", "vert", "jaune", "bleu"};
    // Garder trace des positions des obstacles placés
    vector<pair<int, int>> obstaclesPlaces;

    while (i < 4)
    {
        int k = rand() % 4; // Type de coin
        int x = min_x + 1 + rand() % (max_x - min_x - 2);
        int y = min_y + 1 + rand() % (max_y - min_y - 2);

        // Vérifier si cette position est valide (cases adjacentes libres)
        bool positionValide = true;

        // Vérifier que la case et celle

        if (Plateau[x][y]->getBordHaut() == false && Plateau[x][y]->getBordBas() == false &&
            Plateau[x][y]->getBordGauche() == false && Plateau[x][y]->getBordDroit() == false)
        {
            positionValide = true;
        }
        else
        {
            positionValide = false;
        }

        if (positionValide)
        {
            switch (k)
            {
            case 0: // coin haut gauche
                if (Plateau[x - 1][y]->getBordDroit() == false && Plateau[x - 1][y]->getBordGauche() == false &&
                    Plateau[x][y + 1]->getBordHaut() == false && Plateau[x][y - 1]->getBordHaut() == false && Plateau[x][y - 1]->getBordBas() == false && Plateau[x + 1][y]->getBordGauche() == false)
                {
                    setBordsHaut(x, y);
                    setBordsGauche(x, y);
                    Objectifs.push_back(new Objectif(couleurs[i], "cercle", x, y));
                }
                else
                {
                    positionValide = false;
                }
                break;
            case 1: // coin haut droit
                if (Plateau[x - 1][y]->getBordDroit() == false && Plateau[x - 1][y]->getBordGauche() == false &&
                    Plateau[x][y + 1]->getBordHaut() == false && Plateau[x][y + 1]->getBordBas() == false && Plateau[x][y - 1]->getBordHaut() == false)
                {
                    setBordsHaut(x, y);
                    setBordsDroit(x, y);
                    Objectifs.push_back(new Objectif(couleurs[i], "cercle", x, y));
                }
                else
                {
                    positionValide = false;
                }
                break;
            case 2: // coin bas gauche
                if (Plateau[x - 1][y]->getBordGauche() == false &&
                    Plateau[x][y + 1]->getBordBas() == false && Plateau[x][y - 1]->getBordBas() == false && Plateau[x][y - 1]->getBordHaut() == false && Plateau[x + 1][y]->getBordGauche() == false && Plateau[x + 1][y]->getBordDroit() == false)
                {
                    setBordsBas(x, y);
                    setBordsGauche(x, y);
                    Objectifs.push_back(new Objectif(couleurs[i], forme, x, y));
                }
                else
                {
                    positionValide = false;
                }
                break;
            case 3: // coin bas droit
                if (Plateau[x - 1][y]->getBordDroit() == false &&
                    Plateau[x][y + 1]->getBordBas() == false && Plateau[x][y + 1]->getBordHaut() == false && Plateau[x][y - 1]->getBordBas() == false && Plateau[x + 1][y]->getBordGauche() == false && Plateau[x + 1][y]->getBordDroit() == false)
                {
                    setBordsBas(x, y);
                    setBordsDroit(x, y);
                    Objectifs.push_back(new Objectif(couleurs[i], forme, x, y));
                }
                else
                {
                    positionValide = false;
                }
            }
        }
        if (positionValide)
        {
            Plateau[x][y]->setCouleur(couleurs[i]);
            obstaclesPlaces.push_back({x, y});
            i++;
        }
    }
}
plateauRicochet::plateauRicochet(int x, int y)
{
    Max_X = x;
    Max_Y = y;
    // Initialisation du plateau
    // Initialisation de chaque case
    Plateau.resize(Max_X, std::vector<Case *>(Max_Y));
    // Initialisation des coins
    Plateau[0][0] = new Case(0, 0, true, false, true, false);
    Plateau[0][Max_Y - 1] = new Case(0, Max_Y - 1, true, false, false, true);
    Plateau[Max_X - 1][0] = new Case(Max_X - 1, 0, false, true, true, false);
    Plateau[Max_X - 1][Max_Y - 1] = new Case(Max_X - 1, Max_Y - 1, false, true, false, true);

    for (int i = 0; i < Max_X; i++)
    {
        for (int j = 0; j < Max_Y; j++)
        {
            // case vide
            if (Plateau[i][j] == nullptr)
            {

                // Bordure haut
                if (i == 0 and j != 0 and j != Max_X - 1)
                {
                    Plateau[i][j] = new Case(i, j, true, false, false, false);
                    // bordure gauche
                }
                else if (j == 0 and i != 0 and i != Max_X - 1)
                {
                    Plateau[i][j] = new Case(i, j, false, false, true, false);
                }
                // bordure droite
                else if (j == Max_Y - 1 and i != 0 and i != Max_X - 1)
                {
                    Plateau[i][j] = new Case(i, j, false, false, false, true);
                }
                // bordure bas
                else if (i == Max_X - 1 and j != 0 and j != Max_Y - 1)
                {
                    Plateau[i][j] = new Case(i, j, false, true, false, false);
                }
                else
                {
                    Plateau[i][j] = new Case(i, j);
                }
            }
        }
    }

    // Coin gauche
    setBordsHaut(Max_X / 2 - 1, Max_Y / 2 - 1);
    setBordsGauche(Max_X / 2 - 1, Max_Y / 2 - 1);
    // Coin droit
    setBordsHaut(Max_X / 2 - 1, Max_Y / 2);
    setBordsDroit(Max_X / 2 - 1, Max_Y / 2);
    // Coin bas gauche
    setBordsBas(Max_X / 2, Max_Y / 2 - 1);
    setBordsGauche(Max_X / 2, Max_Y / 2 - 1);
    // Coin bas droit
    setBordsBas(Max_X / 2, Max_Y / 2);
    setBordsDroit(Max_X / 2, Max_Y / 2);

    // Partie haute gauche du tableau
    // obstacles collés au bord

    setBordsDroit(0, rand() % (Max_Y / 2 - 1));
    setBordsBas(rand() % (Max_X / 2 - 1), 0);

    // Partie haute droite du tableau
    setBordsGauche(0, Max_Y / 2 + rand() % (Max_Y / 2 - 1));
    setBordsBas(rand() % (Max_X / 2 - 1), Max_Y - 1);

    // Partie basse gauche du tableau
    setBordsDroit(Max_X - 1, rand() % (Max_Y / 2 - 1));
    setBordsBas(rand() % (Max_X / 2 - 1) + Max_X / 2, 0);
    // Partie basse droite du tableau
    setBordsGauche(Max_Y - 1, Max_X / 2 + rand() % (Max_X / 2));
    setBordsHaut(Max_Y / 2 + rand() % (Max_Y / 2), Max_X - 1);

    // obstacles sur le plateau
    setObstacle(0, Max_X / 2, 0, Max_Y / 2, "carre");

    setObstacle(Max_X / 2, Max_X - 1, 0, Max_Y / 2, "croix");

    setObstacle(Max_X / 2, Max_X - 1, Max_Y / 2, Max_Y, "triangle");

    setObstacle(0, Max_X / 2, Max_Y / 2, Max_Y, "cercle");
}


// Destructeur
plateauRicochet::~plateauRicochet()
{
    for (int i = 0; i < Max_X; ++i)
    {
        for (int j = 0; j < Max_Y; ++j)
        {
            delete Plateau[i][j];
        }
        // Vectors themselves are automatically destroyed
    }
}

void plateauRicochet::DeplacerRobotPos(Robot *robot, int Pos_X, int Pos_Y) {
    Plateau[robot->GetX()][robot->GetY()]->setRobotHere(false); // Enlève le robot de la case actuelle
    robot->SetPosition(Pos_X, Pos_Y);
    Plateau[Pos_X][Pos_Y]->setRobotHere(true);

}

void plateauRicochet::DeplacerRobot(Robot *robot, char direction)
{
    // Code pour déplacer le robot sur le plateau

    int Pos_X = robot->GetX();
    int Pos_Y = robot->GetY();
    Plateau[Pos_X][Pos_Y]->setRobotHere(false); // Enlève le robot de la case actuelle
    int Deplacement = robot->GetNbDeplacement();
    robot->SetNbDeplacement(Deplacement + 1);
    cout << "Robot position: " << Pos_X << ", " << Pos_Y << endl;
    switch (direction)
    {

        // Vérifier si la case est libre avant de déplacer

    case 'U': // Upy
        while (1)
        {
            if (Plateau[Pos_X][Pos_Y]->getBordHaut() or Plateau[Pos_X + 1][Pos_Y]->getRobotHere())
            {
                robot->SetPosition(Pos_X, Pos_Y);

                cout << "Robot moved to Up: " << Pos_X << ", " << Pos_Y << endl;
                break;
            }
            else
            {
                Pos_X--;
            }
        }
        break;

    case 'D': // Down
        while (1)
        {
            if (Plateau[Pos_X][Pos_Y]->getBordBas() or Plateau[Pos_X + 1][Pos_Y]->getRobotHere())
            {
                robot->SetPosition(Pos_X, Pos_Y);
                cout << "Robot moved to Down: " << Pos_X << ", " << Pos_Y << endl;
                break;
            }
            else
            {
                Pos_X++;
            }
        }
        cout << "end Down" << endl;
        break;

    case 'L': // Left
        while (1)
        {
            if (Plateau[Pos_X][Pos_Y]->getBordGauche() or Plateau[Pos_X][Pos_Y - 1]->getRobotHere())
            {
                robot->SetPosition(Pos_X, Pos_Y);
                cout << "Robot moved to: Left " << Pos_X << ", " << Pos_Y << endl;
                break;
            }
            else
            {
                Pos_Y--;
            }
        }
        break;
    case 'R': // Right
        while (1)
        {
            if (Plateau[Pos_X][Pos_Y]->getBordDroit() or Plateau[Pos_X][Pos_Y + 1]->getRobotHere())
            {
                robot->SetPosition(Pos_X, Pos_Y);
                cout << "Robot moved to Right: " << Pos_X << ", " << Pos_Y << endl;
                break;
            }
            else
            {
                Pos_Y++;
            }
        }
        break;
    }
    Plateau[Pos_X][Pos_Y]->setRobotHere(true);
}

void plateauRicochet::InitRobot(Robot *robotRed, Robot *robotGreen, Robot *robotBlue, Robot *robotYellow)
{
    // Initialisation des robots
    Plateau[robotRed->GetX()][robotRed->GetY()]->setRobotHere(true);
    Plateau[robotGreen->GetX()][robotGreen->GetY()]->setRobotHere(true);
    Plateau[robotBlue->GetX()][robotBlue->GetY()]->setRobotHere(true);
    Plateau[robotYellow->GetX()][robotYellow->GetY()]->setRobotHere(true);
}

std::vector<Objectif *> plateauRicochet::getObjectifs()
{
    return Objectifs;
}