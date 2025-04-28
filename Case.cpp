#include <iostream>
#include <string>
#include "stdlib.h"
#include "Plateau.h"

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
bool Case::getCouleur() { return this->couleur; }
bool Case::getX() { return this->x; }
bool Case::getY() { return this->y; }

// Mutateurs
void Case::setBordsHaut(bool setHaut) { this->haut = setHaut; }
void Case::setBordsBas(bool setBas) { this->bas = setBas; }
void Case::setBordsGauche(bool setGauche) { this->gauche = setGauche; }
void Case::setBordsDroit(bool setDroit) { this->droit = setDroit; }
void Case::setCouleur(string setCouleur) { this->couleur = setCouleur; }
void Case::setX(int setX) { this->x = setX; }
void Case::setY(int setY) { this->y = setY; }

// Méthodes
void Case::AffichageCase()
{
    if (this->haut == true)
    {
        case[0][1] = '_';
    } else {
        case[0][1] = ' ';
    }

    if (this->bas == true) {
        case[2][1] = '_';
    }else {
        case[2][1] = ' ';
    }

    if (this->gauche == true) {
        case[1][2] = '_';
    }else {
        case[1][2] = '_';
    }

    if (this->droit == true) {
        case[1][2] = '_';
    }else {
        
    }
}