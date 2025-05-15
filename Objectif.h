/**
 * @file Objectif.h
 * @brief Déclaration de la classe Objectif pour la gestion des objectifs dans le jeu Ricochet Robots.
 *
 * Cette classe permet de représenter un objectif sur le plateau, avec sa couleur, sa forme, ses coordonnées et son état d'atteinte.
 */
#ifndef __secsmp_objectif_h
#define __secsmp_objectif_h

/// Bibliothèques
#include <string>
#include <iostream>
#include "stdlib.h"

using namespace std;

/**
 * @class Objectif
 * @brief Représente un objectif à atteindre sur le plateau de jeu.
 */
class Objectif
{
private:
public:
    int x;                ///< Coordonnée X de l'objectif
    int y;                ///< Coordonnée Y de l'objectif
    string forme;         ///< Forme de l'objectif
    string couleur;       ///< Couleur de l'objectif
    bool objectifAtteint; ///< Indique si l'objectif a été atteint

    /**
     * @brief Constructeur de l'objectif.
     * @param Couleur Couleur de l'objectif.
     * @param Forme Forme de l'objectif.
     * @param X Coordonnée X.
     * @param Y Coordonnée Y.
     */
    Objectif(string Couleur, string Forme, int X, int Y);

    /**
     * @brief Récupère la couleur de l'objectif.
     * @return Couleur de l'objectif.
     */
    string getCouleur();

    /**
     * @brief Récupère la forme de l'objectif.
     * @return Forme de l'objectif.
     */
    string getForme();

    /**
     * @brief Récupère la coordonnée X de l'objectif.
     * @return Coordonnée X.
     */
    int getX();

    /**
     * @brief Récupère la coordonnée Y de l'objectif.
     * @return Coordonnée Y.
     */
    int getY();

    /**
     * @brief Indique si l'objectif a été atteint.
     * @return true si l'objectif est atteint, false sinon.
     */
    bool getObjectifAtteint();

    /**
     * @brief Définit la forme de l'objectif.
     * @param Forme Nouvelle forme.
     */
    void setForme(string Forme);

    /**
     * @brief Définit la couleur de l'objectif.
     * @param setCouleur Nouvelle couleur.
     */
    void setCouleur(string setCouleur);

    /**
     * @brief Définit la coordonnée X de l'objectif.
     * @param setX Nouvelle coordonnée X.
     */
    void setX(int setX);

    /**
     * @brief Définit la coordonnée Y de l'objectif.
     * @param setY Nouvelle coordonnée Y.
     */
    void setY(int setY);

    /**
     * @brief Définit l'état d'atteinte de l'objectif.
     * @param objectifAtteint Nouvel état (true si atteint).
     */
    void setObjectifAtteint(bool objectifAtteint);

    /**
     * @brief Vérifie si l'objectif est atteint en fonction de la couleur et de la forme.
     * @param Couleur Couleur à vérifier.
     * @param Forme Forme à vérifier.
     * @return true si l'objectif est atteint, false sinon.
     */
    bool ObjectifAtteint(string Couleur, string Forme);

    /**
     * @brief Destructeur de la classe Objectif.
     */
    ~Objectif();
};

#endif