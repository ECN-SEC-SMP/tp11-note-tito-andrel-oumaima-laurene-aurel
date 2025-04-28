#ifndef __secsmp_case_h
#define __secsmp_case_h

// Bibliothèques
#include <string>
#include <iostream>
#include "stdlib.h"
#include "Plateau.h"
using namespace std;

// Classe Case, héritée de la classe Plateau
class Case : public Plateau
{

private:
    bool bas;
    bool haut;
    bool gauche;
    bool droite;
    string couleur;

public:
    int x;
    int y;

    // Constructeurs
    Case(int x, int  y);
    Case(int x, int y, bool haut, bool bas, bool gauche, bool droit);
    Case(int x, int y, string couleur);

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