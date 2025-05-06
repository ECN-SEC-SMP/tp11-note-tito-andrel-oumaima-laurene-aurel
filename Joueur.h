#pragma once

#include <string>

using namespace std;

class Joueur{
    private :
    string nom;
    int score;
    public :
    // Constructeurs
    Joueur();
    Joueur(string nom);

    // Accesseurs
    string getNom();
    int getScore();

    // Mutateurs
    void setNom(string nom);
    void setScore(int score);

    // Méthode
    void incrementerScore();
};