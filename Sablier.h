/**
 * @file Sablier.h
 * @brief Déclaration de la classe Sablier pour la gestion du temps dans le jeu Ricochet Robots.
 *
 * Cette classe permet de gérer un sablier, avec un temps de décompte et un état (en cours ou fini).
 */
#pragma once

using namespace std;

/**
 * @class Sablier
 * @brief Représente un sablier pour gérer le temps imparti à un joueur.
 */
class Sablier
{
private:
    bool fini; ///< Etat du sablier : false = en cours, true = fini
    int temps; ///< Temps restant en secondes

public:
    /**
     * @brief Constructeur par défaut du sablier.
     */
    Sablier();

    /**
     * @brief Constructeur du sablier avec temps initial.
     * @param temps Temps initial en secondes.
     */
    Sablier(int temps);

    /**
     * @brief Récupère le temps restant.
     * @return Temps restant en secondes.
     */
    int getTemps();

    /**
     * @brief Indique si le sablier est fini.
     * @return true si le sablier est fini, false sinon.
     */
    bool getFini();

    /**
     * @brief Définit le temps restant.
     * @param temps Nouveau temps en secondes.
     */
    void setTemps(int temps);

    /**
     * @brief Définit l'état du sablier à fini.
     */
    void setFini();

    /**
     * @brief Définit l'état du sablier.
     * @param etat Nouvel état (true = fini, false = en cours).
     */
    void setFini(bool etat);

    /**
     * @brief Lance le décompte du sablier.
     */
    void startDecompte();

    /**
     * @brief Effectue le décompte du sablier (diminution du temps).
     */
    void decompte();
};