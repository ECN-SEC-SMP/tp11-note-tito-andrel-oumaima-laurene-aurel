/**
 * @file Robot.h
 * @brief Déclaration de la classe Robot pour le jeu Ricochet Robots.
 *
 * Cette classe représente un robot sur le plateau, avec sa couleur, sa position, son nombre de déplacements et son état.
 */
#ifndef ROBOT_H
#define ROBOT_H

#include <iostream>
#include <string>
#include <vector>
#include "stdlib.h"

/**
 * @class Robot
 * @brief Représente un robot sur le plateau de jeu.
 */
class Robot
{
private:
    std::string couleur; ///< Couleur du robot

public:
    int nbDeplacements; ///< Nombre de déplacements effectués par le robot
    bool OK;            ///< Statut du robot (OK ou non)
    int x;              ///< Position X du robot sur le plateau
    int y;              ///< Position Y du robot sur le plateau

    /**
     * @brief Constructeur du robot avec couleur et position.
     * @param c Couleur du robot.
     * @param posX Position X initiale.
     * @param posY Position Y initiale.
     */
    Robot(std::string c, int posX, int posY);

    /**
     * @brief Constructeur du robot avec couleur uniquement.
     * @param c Couleur du robot.
     */
    Robot(std::string c);

    /**
     * @brief Récupère la direction choisie pour le déplacement du robot.
     * @return Caractère représentant la direction.
     */
    char RecupereInfo();

    /**
     * @brief Déplace le robot dans la direction indiquée.
     * @param direction Direction du déplacement ('N', 'S', 'E', 'O', etc.).
     */
    void Deplacement(char direction);

    /**
     * @brief Génère un robot avec des paramètres aléatoires ou par défaut.
     */
    void GenereRobot();

    /**
     * @brief Récupère la position X du robot.
     * @return Position X.
     */
    int GetX() const;

    /**
     * @brief Récupère la position Y du robot.
     * @return Position Y.
     */
    int GetY() const;

    /**
     * @brief Récupère la couleur du robot.
     * @return Couleur du robot.
     */
    std::string getCouleur();

    /**
     * @brief Récupère le nombre de déplacements effectués par le robot.
     * @return Nombre de déplacements.
     */
    int GetNbDeplacement() const;

    /**
     * @brief Récupère la position du robot sous forme de vecteur [x, y].
     * @return Vecteur contenant la position.
     */
    std::vector<int> GetPosition() const;

    /**
     * @brief Définit la position X du robot.
     * @param posX Nouvelle position X.
     */
    void SetX(int posX);

    /**
     * @brief Définit la position Y du robot.
     * @param posY Nouvelle position Y.
     */
    void SetY(int posY);

    /**
     * @brief Définit le nombre de déplacements du robot.
     * @param nb Nouveau nombre de déplacements.
     */
    void SetNbDeplacement(int nb);

    /**
     * @brief Définit la position du robot.
     * @param xpos Nouvelle position X.
     * @param ypos Nouvelle position Y.
     */
    void SetPosition(int xpos, int ypos);
};

#endif
