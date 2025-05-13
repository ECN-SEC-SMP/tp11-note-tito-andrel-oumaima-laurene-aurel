
#ifndef __secsmp_objectif_h
#define __secsmp_objectif_h

/// Bibliothèques
#include <string>
#include <iostream>
#include "stdlib.h"

using namespace std;

class Objectif {
private :

public:
    int x;
    int y;
    string forme;
    string couleur;
    bool objectifAtteint;

    // Constructeurs
    Objectif(string Couleur, string Forme, int X, int Y);

    // Accesseurs
    string getCouleur();
    string getForme();
    int getX();
    int getY();
    bool getObjectifAtteint();


    // Mutateurs
    void setForme(string Forme);
    void setCouleur(string setCouleur);
    void setX(int setX);
    void setY(int setY);
    void setObjectifAtteint(bool objectifAtteint);

    // Méthodes
    bool ObjectifAtteint(string Couleur, string Forme);

    // Destructeur
    ~Objectif();
};

#endif