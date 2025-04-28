#include <iostream>
#include <string>
#include "stdlib.h"
#include "Plateau.h"

Case::Case(int X, int Y)
{
    X = x;
    Y = y;
    bas = false;
    haut = false;
    droit = false;
    gauche = false;
    couleur = "incolore";
}

Case::Case(int X, int Y, bool Haut, bool Bas, bool Gauche, bool Droit)
{
    X = x;
    Y = y;
    Bas = bas;
    Haut = haut;
    Droit = droit;
    Gauche = gauche;
    couleur = "incolore";
}

Case::Case(int x, int y, string couleur)
{

}

// On récupère la valeur de l'attaque (0, 1 ou 2)
int Attaque::getAttaque() const
{
    return type;
}

// Vérification de l'attaque, renvoie true si l'attaque est réussie, sinon false
bool Attaque::resoudreAttaque(Attaque &a) const
{
    // Comparaison des 3 cas ou la fonction peut renvoyer true, sinon false
    if (this->type == 0 && a.type == 2 || this->type == 2 && a.type == 1 || this->type == 1 && a.type == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// On récupère le nom de l'attaque en fonction de la valeur du type
string Attaque::getNomAttaque() const
{
    if (type == 0)
    {
        return "Pierre";
    }
    else if (type == 1)
    {
        return "Feuille";
    }
    else if (type == 2)
    {
        return "Ciseaux";
    }
    else
    {
        return 0;
    }
}