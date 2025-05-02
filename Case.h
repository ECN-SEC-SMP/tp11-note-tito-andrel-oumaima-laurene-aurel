#ifndef __secsmp_case_h
#define __secsmp_case_h

/// Bibliothèques
#include <string>
#include <iostream>
#include "stdlib.h"
//#include "Plateau.h"
using namespace std;

/// Classe Case, héritée de la classe Plateau
class Case
{

//private

protected:
    bool bas;
    bool haut;
    bool gauche;
    bool droit;
    string couleur;

public:
    int x;
    int y;

    // Constructeurs
    Case(int X, int  Y);
    Case(int X, int Y, bool Haut, bool Bas, bool Gauche, bool Droit);
    Case(int X, int Y, string Couleur);

    // Accesseurs
    bool getBordHaut();
    bool getBordBas();
    bool getBordGauche();
    bool getBordDroit();
    string getCouleur();
    int getX();
    int getY();

    // Mutateurs
    void setBordsHaut(bool setHaut);
    void setBordsBas(bool setBas);
    void setBordsGauche(bool setGauche);
    void setBordsDroit(bool setDroit);
    void setCouleur(string setCouleur);
    void setX(int setX);
    void setY(int setY);

    // Méthodes
    void AffichageCase(int X, int Y);
};

#endif