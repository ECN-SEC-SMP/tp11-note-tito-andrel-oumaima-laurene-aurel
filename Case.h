#ifndef __secsmp_case_h
#define __secsmp_case_h

/// Bibliothèques
#include <string>
#include <iostream>
#include "stdlib.h"
#include "Plateau.h"
using namespace std;

/// Classe Case, héritée de la classe Plateau
class Case : public Plateau
{

//private

protected:
    bool bas;
    bool haut;
    bool gauche;
    bool droite;
    string couleur;

public:
    int x;
    int y;

    // Constructeurs
    Case(int X, int  Y);
    Case(int X, int Y, bool Haut, bool Bas, bool Gauche, bool Droit);
    Case(int X, int Y, string Couleur);

    // Accesseurs
    getBordHaut();
    getBordBas();
    getBordGauche();
    getBordDroit();
    getCouleur();
    getX();
    getY();

    // Mutateurs
    setBordsHaut();
    setBordsBas();
    setBordsGauche();
    setBordsDroit();
    setCouleur();
    setX();
    setY();
    
};

#endif