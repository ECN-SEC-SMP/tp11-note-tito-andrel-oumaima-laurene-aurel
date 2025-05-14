#pragma once

#include <string>

using namespace std;

class Joueur{
    private :
        // Attributs
        // Nom du joueur
        string nom;
        // Score du joueur
        int score;
        // Nombre de coups du joueur
        int coups;
    public :
        // Constructeurs
        Joueur();
        Joueur(string nom);

        // Accesseurs
        string getNom();
        int getScore();
        int getCoups();

        // Mutateurs
        void setNom(string nom);
        void setScore(int score);
        void setCoups(int coups);

        // Méthode
        void incrementerScore();
};