/**
 * @file Case.h
 * @brief Déclaration de la classe Case pour le plateau de jeu Ricochet Robots.
 *
 * Cette classe représente une case du plateau, avec ses coordonnées, ses murs, sa couleur et la présence éventuelle d'un robot.
 */
#ifndef __secsmp_case_h
#define __secsmp_case_h

/// Bibliothèques
#include <string>
#include <iostream>
#include "stdlib.h"
// #include "plateauRicochet.h"
using namespace std;

/**
 * @class Case
 * @brief Représente une case du plateau de jeu.
 */
class Case
{

    // private

protected:
    bool robotHere; ///< Indique si un robot est présent sur la case
    bool bas;       ///< Présence d'un mur en bas
    bool haut;      ///< Présence d'un mur en haut
    bool gauche;    ///< Présence d'un mur à gauche
    bool droit;     ///< Présence d'un mur à droite
    string couleur; ///< Couleur de la case

public:
    int x; ///< Coordonnée X de la case
    int y; ///< Coordonnée Y de la case

    /**
     * @brief Constructeur de base.
     * @param X Coordonnée X.
     * @param Y Coordonnée Y.
     */
    Case(int X, int Y);

    /**
     * @brief Constructeur avec murs.
     * @param X Coordonnée X.
     * @param Y Coordonnée Y.
     * @param Haut Mur en haut.
     * @param Bas Mur en bas.
     * @param Gauche Mur à gauche.
     * @param Droit Mur à droite.
     */
    Case(int X, int Y, bool Haut, bool Bas, bool Gauche, bool Droit);

    /**
     * @brief Constructeur avec couleur.
     * @param X Coordonnée X.
     * @param Y Coordonnée Y.
     * @param Couleur Couleur de la case.
     */
    Case(int X, int Y, string Couleur);

    /// @name Accesseurs
    /// @{

    /**
     * @brief Vérifie si un robot est présent sur la case.
     * @return true si un robot est présent, false sinon.
     */
    bool getRobotHere();

    /**
     * @brief Vérifie la présence d'un mur en haut.
     * @return true si un mur est présent en haut, false sinon.
     */
    bool getBordHaut();

    /**
     * @brief Vérifie la présence d'un mur en bas.
     * @return true si un mur est présent en bas, false sinon.
     */
    bool getBordBas();

    /**
     * @brief Vérifie la présence d'un mur à gauche.
     * @return true si un mur est présent à gauche, false sinon.
     */
    bool getBordGauche();

    /**
     * @brief Vérifie la présence d'un mur à droite.
     * @return true si un mur est présent à droite, false sinon.
     */
    bool getBordDroit();

    /**
     * @brief Récupère la couleur de la case.
     * @return Couleur de la case.
     */
    string getCouleur();

    /**
     * @brief Récupère la coordonnée X.
     * @return Coordonnée X.
     */
    int getX();

    /**
     * @brief Récupère la coordonnée Y.
     * @return Coordonnée Y.
     */
    int getY();

    /// @}

    /// @name Mutateurs
    /// @{

    /**
     * @brief Définit la présence d'un robot sur la case.
     * @param setRobotHere true si un robot est présent, false sinon.
     */
    void setRobotHere(bool setRobotHere);

    /**
     * @brief Définit la présence d'un mur en haut.
     * @param setHaut true si un mur est présent en haut, false sinon.
     */
    void setBordsHaut(bool setHaut);

    /**
     * @brief Définit la présence d'un mur en bas.
     * @param setBas true si un mur est présent en bas, false sinon.
     */
    void setBordsBas(bool setBas);

    /**
     * @brief Définit la présence d'un mur à gauche.
     * @param setGauche true si un mur est présent à gauche, false sinon.
     */
    void setBordsGauche(bool setGauche);

    /**
     * @brief Définit la présence d'un mur à droite.
     * @param setDroit true si un mur est présent à droite, false sinon.
     */
    void setBordsDroit(bool setDroit);

    /**
     * @brief Définit la couleur de la case.
     * @param setCouleur Nouvelle couleur.
     */
    void setCouleur(string setCouleur);

    /**
     * @brief Définit la coordonnée X de la case.
     * @param setX Nouvelle coordonnée X.
     */
    void setX(int setX);

    /**
     * @brief Définit la coordonnée Y de la case.
     * @param setY Nouvelle coordonnée Y.
     */
    void setY(int setY);

    /// @}

    /**
     * @brief Affiche la case à la position donnée.
     * @param X Coordonnée X.
     * @param Y Coordonnée Y.
     */
    void AffichageCase(int X, int Y);
};

#endif