/**
 * @file Master.h
 * @brief Définition de la classe principale contrôlant le jeu
 * @author Équipe Tito-Andrel-Oumaima-Laurene-Aurel
 * @date Mai 2025
 */

#ifndef MASTER_H
#define MASTER_H

#include <string>
#include <iostream>
#include <string>
#include "stdlib.h"
#include "Case.h"
#include "Sablier.h"
#include "plateauRicochet.h"
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Robot.h"
#include "Joueur.h"

/**
 * @class Master
 * @brief Classe principale gérant le jeu Ricochet Robot
 *
 * Cette classe orchestre l'ensemble des éléments du jeu:
 * gestion du plateau, des robots, des joueurs, des objectifs,
 * et du déroulement du jeu.
 */
class Master {
    protected:
        /** @brief Largeur du plateau */
        int Max_X;
        /** @brief Hauteur du plateau */
        int Max_Y;
        /** @brief Plateau de jeu */
        plateauRicochet* Plateau;

        /** @brief Objectif actuel à atteindre */
        Objectif* objectifCourant;
        /** @brief Indice de l'objectif courant dans la liste */
        int indiceObjectifCourant = 0;

        /** @brief Robot rouge */
        Robot* robotRed; 
        /** @brief Robot vert */
        Robot* robotGreen;
        /** @brief Robot bleu */
        Robot* robotBlue;
        /** @brief Robot jaune */
        Robot* robotYellow;

        /** @brief Liste des joueurs */
        std::vector<Joueur*> Joueurs;
        /** @brief Nombre de joueurs */
        int nbJoueurs;

        /** @brief Sablier pour limiter le temps de réflexion */
        Sablier* sablier;

    public:
        /**
         * @brief Constructeur initialisant le jeu
         * @param X Largeur du plateau
         * @param Y Hauteur du plateau
         */
        Master(int X, int Y);
        
        /**
         * @brief Destructeur libérant les ressources
         */
        ~Master();
        
        /**
         * @brief Lance un tour de jeu
         */
        void Tour();
        
        /**
         * @brief Gère un tour de jeu complet pour tous les joueurs
         */
        void TourdeJeu();
        
        /**
         * @brief Sélectionne un robot
         * @return Caractère identifiant le robot ('R','G','B','Y')
         */
        char select_Robot();
        
        /**
         * @brief Affiche le plateau de jeu
         */
        void Afficher();
        
        /**
         * @brief Tire un nouvel objectif aléatoire
         */
        void tirerObjectif();
        
        /**
         * @brief Vérifie si l'objectif actuel est atteint
         * @return true si l'objectif est atteint, false sinon
         */
        bool getObjectifAtteint();
        
        /**
         * @brief Affiche l'objectif courant
         */
        void afficherObjectif();
        
        /**
         * @brief Déplace le robot sélectionné
         * @param Rob Identifiant du robot ('R','G','B','Y')
         * @param nbCoups Nombre de coups annoncés
         * @return true si l'objectif est atteint, false sinon
         */
        bool SelectionRobot(char Rob, int nbCoups);
        
        /**
         * @brief Initialise les joueurs pour la partie
         */
        void initJoueurs();
        
        /**
         * @brief Sélectionne un joueur pour le tour
         * @return Pointeur vers le joueur sélectionné
         */
        Joueur* selectJoueur();
        
        /**
         * @brief Affiche les scores de tous les joueurs
         */
        void AfficherScores();
};

#endif