#include "Joueur.h"

// ---------- Constructeurs ----------

// Création d'un joueur
Joueur::Joueur(){
    nom = nullptr;
    score = 0;
    coups = 0;
}

// Création d'un joueur avec un nom
Joueur::Joueur(string nom){
    this->nom = nom;
    score = 0;
    coups = 0;
}

// ---------- Accesseurs ----------

// Renvoie le nom du joueur
string Joueur::getNom(){
    return nom;
}
// Renvoie le score du joueur
int Joueur::getScore(){
    return score;
}
// Renvoie le nombre de coups du joueur
int Joueur::getCoups(){
    return coups;
}

// ---------- Mutateurs ----------

// Modifie le nom du joueur
void Joueur::setNom(string nom){
    this->nom = nom;
}

// Modifie le score du joueur
void Joueur::setScore(int score){
    this->score = score;
}

// Modifie le nombre de coups du joueur
void Joueur::setCoups(int coups){
    this->coups = coups;
}

// ---------- Méthodes ----------

// Incrémente le score du joueur
void Joueur::incrementerScore(){
    this->score++;
}