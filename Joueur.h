/**
 * @file Joueur.h
 * @brief Déclaration de la classe Joueur pour la gestion des joueurs dans le jeu Ricochet Robots.
 *
 * Cette classe permet de gérer les informations d'un joueur, telles que son nom, son score et son nombre de coups.
 */

#pragma once

#include <string>

using namespace std;

/**
 * @class Joueur
 * @brief Représente un joueur du jeu.
 */
class Joueur
{
private:
    string nom; ///< Nom du joueur
    int score;  ///< Score du joueur
    int coups;  ///< Nombre de coups du joueur

public:
    /**
     * @brief Constructeur par défaut.
     */

    Joueur();

    /**
     * @brief Constructeur avec nom.
     * @param nom Nom du joueur.
     */
    Joueur(string nom);

    /**
     * @brief Récupère le nom du joueur.
     * @return Le nom du joueur.
     */
    string getNom();

    /**
     * @brief Récupère le score du joueur.
     * @return Le score du joueur.
     */
    int getScore();

    /**
     * @brief Récupère le nombre de coups du joueur.
     * @return Le nombre de coups.
     */
    int getCoups();

    /**
     * @brief Définit le nom du joueur.
     * @param nom Nouveau nom du joueur.
     */
    void setNom(string nom);

    /**
     * @brief Définit le score du joueur.
     * @param score Nouveau score.
     */
    void setScore(int score);

    /**
     * @brief Définit le nombre de coups du joueur.
     * @param coups Nouveau nombre de coups.
     */
    void setCoups(int coups);

    /**
     * @brief Incrémente le score du joueur de 1.
     */
    void incrementerScore();
};