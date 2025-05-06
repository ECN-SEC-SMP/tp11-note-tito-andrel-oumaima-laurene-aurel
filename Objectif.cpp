/// Bibliothèques
#include <string>
#include <iostream>
#include "stdlib.h"
#include "Objectif.h"

// Constructeurs
Objectif::Objectif(string Couleur, string Forme, int X, int Y)
{
    this->couleur = Couleur;
    this->forme = Forme;
    this->x = X;
    this->y = Y;
}

// Accesseurs
string Objectif::getForme() { return this->forme; }
string Objectif::getCouleur() { return this->couleur; }
int Objectif::getX() { return this->x; }
int Objectif::getY() { return this->y; }

// Mutateurs
void Objectif::setForme(string setForme) { this->forme = setForme; }
void Objectif::setCouleur(string setCouleur) { this->couleur = setCouleur; }
void Objectif::setX(int setX) { this->x = setX; }
void Objectif::setY(int setY) { this->y = setY; }

// Méthodes
void ObjectifAtteint(string Couleur, string Forme) {
    if (this->getCouleur() == Couleur) {

    } else {

    }
}

// Destructeur
Objectif::~Objectif() {
    delete this;
}