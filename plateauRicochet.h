/**
 * @file plateauRicochet.h
 * @brief Définition de la classe gérant le plateau de jeu Ricochet Robot
 * @author Équipe Tito-Andrel-Oumaima-Laurene-Aurel
 * @date Mai 2025
 */

#ifndef PLATEAU_H
#define PLATEAU_H

#include "Case.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "Robot.h"
#include "Objectif.h"
#include <map>

/**
 * @class plateauRicochet
 * @brief Gestion du plateau de jeu et des déplacements des robots
 *
 * Cette classe gère l'ensemble du plateau de jeu, les obstacles, les objectifs
 * et les mouvements des robots sur le plateau.
 */
class plateauRicochet
{
    private:
     /** @brief Largeur du plateau */
     int Max_X;
     /** @brief Hauteur du plateau */
     int Max_Y;
     /** @brief Grille 2D contenant les cases du plateau */
     std::vector<std::vector<Case*>> Plateau;
     /** @brief Liste des objectifs à atteindre */
     std::vector<Objectif*> Objectifs;
     /** @brief Positions des obstacles déjà placés sur le plateau */
     std::vector<std::pair<int, int>> obstaclesPlaces;
    public:
        /**
         * @brief Constructeur initialisant le plateau
         * @param x Largeur du plateau
         * @param y Hauteur du plateau
         */
        plateauRicochet(int x, int y);
        
        /**
         * @brief Récupère la grille 2D du plateau
         * @return Référence vers la grille de jeu
         */
        std::vector<std::vector<Case*>> getPlateau();
        
        /**
         * @brief Destructeur libérant la mémoire du plateau
         */
        ~plateauRicochet();
        
        /**
         * @brief Initialise les robots sur le plateau
         * @param robotRed Robot rouge
         * @param robotGreen Robot vert
         * @param robotBlue Robot bleu
         * @param robotYellow Robot jaune
         */
        void InitRobot(Robot* robotRed, Robot* robotGreen, Robot* robotBlue, Robot* robotYellow);
        
        /**
         * @brief Crée un obstacle dans la zone spécifiée
         * @param x1 Coordonnée X minimum
         * @param x2 Coordonnée X maximum
         * @param y1 Coordonnée Y minimum
         * @param y2 Coordonnée Y maximum
         * @param forme Type de forme pour l'objectif ("cercle", "carre", etc.)
         */
        void setObstacle(int x1, int x2, int y1, int y2, string forme);
        
        /**
         * @brief Ajoute un bord en bas d'une case
         * @param X Coordonnée X de la case
         * @param Y Coordonnée Y de la case
         */
        void setBordsBas(int X, int Y);

        /**
         * @brief Ajoute un bord en haut d'une case
         * @param X Coordonnée X de la case
         * @param Y Coordonnée Y de la case
         */
        void setBordsHaut(int X, int Y);

        /**
         * @brief Ajoute un bord à gauche d'une case
         * @param X Coordonnée X de la case
         * @param Y Coordonnée Y de la case
         */
        void setBordsGauche(int X, int Y);

        /**
         * @brief Ajoute un bord à droite d'une case
         * @param X Coordonnée X de la case
         * @param Y Coordonnée Y de la case
         */
        void setBordsDroit(int X, int Y);

        /**
         * @brief Déplace un robot dans une direction
         * @param robot Pointeur vers le robot à déplacer
         * @param direction Direction ('U','D','L','R')
         */
        void DeplacerRobot(Robot* robot, char direction);

        /**
         * @brief Déplace un robot à une position spécifique
         * @param robot Pointeur vers le robot à déplacer
         * @param Pos_X Nouvelle coordonnée X
         * @param Pos_Y Nouvelle coordonnée Y
         */
        void DeplacerRobotPos(Robot *robot, int Pos_X, int Pos_Y);
        
        /**
         * @brief Obtient la liste des objectifs
         * @return Vecteur d'objectifs
         */
        std::vector<Objectif*> getObjectifs();

        /**
         * @brief Vérifie si un déplacement est valide
         * @param x Coordonnée X de destination
         * @param y Coordonnée Y de destination
         * @return true si le déplacement est valide, false sinon
         */
        bool estDeplacementValide(int x, int y);
};

#endif