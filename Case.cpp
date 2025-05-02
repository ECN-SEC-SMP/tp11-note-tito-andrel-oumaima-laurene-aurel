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
    char affcase[2][2];

    affcase[0][0] = '.';
    affcase[0][2] = '.';
    affcase[2][0] = '.';
    affcase[2][2] = '.';
    if (this->haut == true)
    {
        affcase[0][1] = '_';
    }
    else
    {
        affcase[0][1] = '.';
    }

    if (this->bas == true)
    {
        affcase[2][1] = '_';
    }
    else
    {
        affcase[2][1] = '.';
    }

    if (this->gauche == true)
    {
        affcase[1][0] = '|';
    }
    else
    {
        affcase[1][0] = '.';
    }

    if (this->droit == true)
    {
        affcase[1][2] = '|';
    }
    else
    {
        affcase[1][2] = '.';
    }

    if (this->couleur == "incolore")
    {
        affcase[1][1] = 'I';
    }
    else if (this->couleur == "rouge")
    {
        affcase[1][1] = 'R';
    }
    else if (this->couleur == "vert")
    {
        affcase[1][1] = 'V';
    }
    else if (this->couleur == "jaune")
    {
        affcase[1][1] = 'J';
    }
    else if (this->couleur == "bleu")
    {
        affcase[1][1] = 'B';
    }
    else if (this->couleur == "multicolore")
    {
        affcase[1][1] = 'M';
    }
    else
    {
        affcase[1][1] = 'I';
    }
}