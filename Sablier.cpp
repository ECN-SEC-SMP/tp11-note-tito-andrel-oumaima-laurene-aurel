#include "Sablier.h"
#include <thread>
#include <chrono>

// ---------- Constructeurs ----------

// Initialisation d'un sablier de 60 secondes
Sablier::Sablier(){
    temps = 60;
    fini = 0;
}

// Initialisation du sablier au temps souhaité
Sablier::Sablier(int temps){
    this->temps = temps;
    fini = 0;
}

// ---------- Accesseurs ----------

// Renvoie le temps en secondes
int Sablier::getTemps(){
    return temps;
}

// Renvoie l'état du sablier
// 0 : en cours
// 1 : terminé
bool Sablier::getFini(){
    return fini;
}

// ---------- Mutateurs ----------

// Parametrage du temps
void Sablier::setTemps(int temps){
    this->temps = temps;
}

// Termine le sablier
void Sablier::setFini(){
    this->fini = 1;
}

// Change l'état du sablier
void Sablier::setFini(bool etat){
    this->fini = etat;
}

// ---------- Méthodes ----------

// Démarrage du décompte du sablier et décompte toutes les secondes en arrière plan
void Sablier::startDecompte(){
    // Lancer un thread qui décrémente automatiquement le sablier
    std::thread([this]() {
        while (!this->getFini()) { // Tant que sablier non fini
            this->decompte();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }).detach(); // détache le thread pour qu'il fonctionne en arrière-plan
}

// Fonction de décomptage du sablier
void Sablier::decompte(){
    if(temps > 0 && fini == 0){
        temps--; // Decomptage
    } else fini = 1; // Fin du décomptage
}