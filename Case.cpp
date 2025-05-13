///
/// @brief Bibliothèques
/// @details Nécéssaires pour le bon focntionnement du projet.
///
#include <string>
#include <iostream>
#include <string>
#include "stdlib.h"
#include "Case.h"

///
/// @brief Création d'une case en fonction des coordonnées X, Y
/// @details Création d'une case d'un tableau. on initialise uniquement les coordonnées.
/// Les bords de la case sont automatiquement mit à 0, et elle ne possède pas de couleur.
/// @param[in]  X, Y entier
///
Case::Case(int X, int Y)
{
    this->x = X;
    this->y = Y;
    this->robotHere = false;
    this->bas = false;
    this->haut = false;
    this->droit = false;
    this->gauche = false;
    this->couleur = "incolore";

}

///
/// @brief Création d'une case en fonction des coordonnées X, Y et initialisation des bords.
/// @details Création d'une case d'un tableau. on initialise les coordonnées ainsi que les bords de la case.
/// L'utilisateur peut alors configurer manuellement les bords de la case. Cette dernière ne possède cependant pas de couleur
/// @param[in]  X, Y entier
/// @param[in]  Haut,Bas,Gauche,Droit booléens
///
Case::Case(int X, int Y, bool Haut, bool Bas, bool Gauche, bool Droit)
{
    this->robotHere = false;
    this->x = X;
    this->y = Y;
    this->bas = Bas;
    this->haut = Haut;
    this->droit = Droit;
    this->gauche = Gauche;
    this->couleur = "incolore";
}

///
/// @brief Création d'une case en fonction des coordonnées X, Y et initialisation de la couleur.
/// @details Création d'une case d'un tableau. on initialise les coordonnées ainsi que la couleur de la case.
/// Les bords de la case sont par défaut à false (modifications nécéssaires à partir des accesseurs)
/// @param[in]  X, Y entier
/// @param[in]  Couleur string
///
Case::Case(int X, int Y, string Couleur)
{
    this->robotHere = false;
    this->y = X;
    this->x = Y;
    this->bas = false;
    this->haut = false;
    this->droit = false;
    this->gauche = false;
    this->couleur = Couleur;
}

///
/// @brief Accesseurs
/// @details Fonctions permettant l'accès aux différents paramètres d'une case. 
/// L'utilisateur récupère alors les informaions nécéssaires au bon fonctionnement du programme.
///
bool Case::getBordHaut() { return this->haut; }
bool Case::getBordBas() { return this->bas; }
bool Case::getBordGauche() { return this->gauche; }
bool Case::getBordDroit() { return this->droit; }
bool Case::getRobotHere() { return this->robotHere; }

string Case::getCouleur() { return this->couleur; }
int Case::getX() { return this->x; }
int Case::getY() { return this->y; }

///
/// @brief Mutateurs
/// @details Fonctions permettant la modification des différents paramètres d'une case. 
/// Permet de configurer et de modifier les paramètres spécifiques d'une case.
///
void Case::setBordsHaut(bool setHaut) { this->haut = setHaut; }
void Case::setBordsBas(bool setBas) { this->bas = setBas; }
void Case::setBordsGauche(bool setGauche) { this->gauche = setGauche; }
void Case::setBordsDroit(bool setDroit) { this->droit = setDroit; }
void Case::setCouleur(string setCouleur) { this->couleur = setCouleur; }
void Case::setX(int setX) { this->x = setX; }
void Case::setY(int setY) { this->y = setY; }
void Case::setRobotHere(bool setRobotHere) { this->robotHere = setRobotHere; }

///
/// @brief Méthode, Affichage Case
/// @details Fonctions méthode permettant d'afficher sur le terminal une case particulière en fonction de ses coordonnées.
/// On cherche à afficher le centre, le bord droit, ainsi que le bord bas de la case, afin de pouvoir les "encastrer" dans la gestion plateau
/// @param[in] X, Y entier
///
void Case::AffichageCase(int X, int Y)
{
    // Création tableau pour affichage
    char affcase[X + 2][Y + 2];

    // Coins de la case
    affcase[X][Y] = '#';
    affcase[X][Y + 2] = '#';
    affcase[X + 2][Y] = '#';
    affcase[X + 2][Y + 2] = '#';

    // Vérification des bords à l'aide d'accesseurs
    if (this->getBordHaut() == true)
    {
        affcase[X][Y + 1] = '#';
    }
    else
    {
        affcase[X][Y + 1] = '-';
    }

    if (this->getBordBas() == true)
    {
        affcase[X + 2][Y + 1] = '#';
    }
    else
    {
        affcase[X + 2][Y + 1] = '-';
    }

    if (this->getBordGauche() == true)
    {
        affcase[X + 1][Y] = '#';
    }
    else
    {
        affcase[X + 1][Y] = '|';
    }

    if (this->getBordDroit() == true)
    {
        affcase[X + 1][Y + 2] = '#';
    }
    else
    {
        affcase[X + 1][Y + 2] = '|';
    }

    // Modification de la case centrale en fonction de la couleur
    if (this->getCouleur() == "incolore")
    {
        affcase[X + 1][Y + 1] = 'I';
    }
    else if (this->getCouleur() == "rouge")
    {
        affcase[X + 1][Y + 1] = 'R';
    }
    else if (this->getCouleur() == "vert")
    {
        affcase[X + 1][Y + 1] = 'V';
    }
    else if (this->getCouleur() == "jaune")
    {
        affcase[X + 1][Y + 1] = 'J';
    }
    else if (this->getCouleur() == "bleu")
    {
        affcase[X + 1][Y + 1] = 'B';
    }
    else if (this->getCouleur() == "multicolore")
    {
        affcase[X + 1][Y + 1] = 'M';
    }

    // Affichage de la case dans le terminal
    // . . .
    // . # #
    // . # #
    cout << affcase[X + 1][Y + 1] << affcase[X + 1][Y + 2] << endl;
    cout << affcase[X + 2][Y + 1] << affcase[X + 2][Y + 2] << endl;
}
