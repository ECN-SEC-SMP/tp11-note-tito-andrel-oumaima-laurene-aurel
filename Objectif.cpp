///
/// @brief Bibliothèques
/// @details Nécéssaires pour le bon focntionnement du projet.
///
#include <string>
#include <iostream>
#include "stdlib.h"
#include "Objectif.h"

///
/// @brief Création d'un objectif en fonction des coordonnées X, Y ainsi que d'une couleur et d'une forme (type d'objectif)
/// @details Création d'un objectif lié à une case. On cherche à initialiser les coordonnées (case particulière)
/// Ainsi que les coordonnées et la forme de l'objectif.
/// @param[in]  X, Y entier
/// @param[in]  Couleur, Forme string
///
Objectif::Objectif(string Couleur, string Forme, int X, int Y)
{
    this->couleur = Couleur;
    this->forme = Forme;
    this->x = X;
    this->y = Y;
}

///
/// @brief Accesseurs
/// @details Fonctions permettant l'accès aux différents paramètres d'un objectif. 
/// L'utilisateur récupère alors les informaions nécéssaires au bon fonctionnement du programme.
///
string Objectif::getForme() { return this->forme; }
string Objectif::getCouleur() { return this->couleur; }
int Objectif::getX() { return this->x; }
int Objectif::getY() { return this->y; }

///
/// @brief Mutateurs
/// @details Fonctions permettant la modification des différents paramètres d'un objectif. 
/// Permet de configurer et de modifier les paramètres spécifiques d'un objectif.
///
void Objectif::setForme(string setForme) { this->forme = setForme; }
void Objectif::setCouleur(string setCouleur) { this->couleur = setCouleur; }
void Objectif::setX(int setX) { this->x = setX; }
void Objectif::setY(int setY) { this->y = setY; }

///
/// @brief Méthode, ObjectifAtteint
/// @details Fonctions méthode permettant de faire ressortir une information d'objectif atteint. 
/// @param[in] Couleur, Forme string
///
bool Objectif::ObjectifAtteint(string Couleur, string Forme)
{
    if (this->getCouleur() == Couleur && this->getForme() == Forme)
    {
        return true;
    }
    else
    {
        return false;
    }
}

///
/// @brief Destructeur
/// @details Fonction destructrice permettant de supprimer un élément, dans le cas d'un objectif atteint par exemple.
///
Objectif::~Objectif()
{
    delete this;
}