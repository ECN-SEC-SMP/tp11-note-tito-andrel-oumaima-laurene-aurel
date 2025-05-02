#include <string>
#include <iostream>
#include <string>
#include "stdlib.h"
#include "Case.h"
// #include "Plateau.h"

// Constructeurs
Case::Case(int X, int Y)
{
    this->x = X;
    this->y = Y;
    this->bas = false;
    this->haut = false;
    this->droit = false;
    this->gauche = false;
    this->couleur = "incolore";
}

Case::Case(int X, int Y, bool Haut, bool Bas, bool Gauche, bool Droit)
{
    this->x = X;
    this->y = Y;
    this->bas = Bas;
    this->haut = Haut;
    this->droit = Droit;
    this->gauche = Gauche;
    this->couleur = "incolore";
}

Case::Case(int X, int Y, string Couleur)
{
    this->y = X;
    this->x = Y;
    this->bas = false;
    this->haut = false;
    this->droit = false;
    this->gauche = false;
    this->couleur = Couleur;
}

// Accesseurs
bool Case::getBordHaut() { return this->haut; }
bool Case::getBordBas() { return this->bas; }
bool Case::getBordGauche() { return this->gauche; }
bool Case::getBordDroit() { return this->droit; }
string Case::getCouleur() { return this->couleur; }
int Case::getX() { return this->x; }
int Case::getY() { return this->y; }

// Mutateurs
void Case::setBordsHaut(bool setHaut) { this->haut = setHaut; }
void Case::setBordsBas(bool setBas) { this->bas = setBas; }
void Case::setBordsGauche(bool setGauche) { this->gauche = setGauche; }
void Case::setBordsDroit(bool setDroit) { this->droit = setDroit; }
void Case::setCouleur(string setCouleur) { this->couleur = setCouleur; }
void Case::setX(int setX) { this->x = setX; }
void Case::setY(int setY) { this->y = setY; }

// Méthodes
void Case::AffichageCase(int X, int Y)
{
    char affcase[X+2][Y+2];

    if (this->getBordHaut() == true)
    {
        affcase[X][Y+1] = '_';
    }
    else
    {
        affcase[X][Y+1] = '.';
    }

    if (this->getBordBas() == true)
    {
        affcase[X+2][Y+1] = '_';
    }
    else
    {
        affcase[X+2][Y+1] = '.';
    }

    if (this->getBordGauche() == true)
    {
        affcase[X+1][Y] = '|';
    }
    else
    {
        affcase[X+1][Y]  = '.';
    }

    if (this->getBordDroit() == true)
    {
        affcase[X+1][Y+2]  = '|';
    }
    else
    {
        affcase[X+1][Y+2]  = '.';
    }

    if (this->getCouleur() == "incolore")
    {
        affcase[X+1][Y+1] = 'I';
    }
    else if (this->getCouleur() == "rouge")
    {
        affcase[X+1][Y+1] = 'R';
    }
    else if (this->getCouleur() == "vert")
    {
        affcase[X+1][Y+1] = 'V';
    }
    else if (this->getCouleur() == "jaune")
    {
        affcase[X+1][Y+1] = 'J';
    }
    else if (this->getCouleur() == "bleu")
    {
        affcase[X+1][Y+1] = 'B';
    }
    else if (this->getCouleur() == "multicolore")
    {
        affcase[X+1][Y+1] = 'M';
    }

    affcase[X][Y] = '.';
    affcase[X][Y+2] = '.';
    affcase[X+2][Y] = '.';
    affcase[X+2][Y+2] = '.';

    for (int i = 0; i < X+3; i ++) {
        for (int j = 0; j < Y+3; j++) {
            cout << affcase[i][j];
        }
        cout << endl;
    }
}
