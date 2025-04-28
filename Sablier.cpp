#include "Sablier.h"
#include <thread>
#include <chrono>

// Constructeurs
Sablier::Sablier(){
    // Initialisation du sablier à 60 secondes
    temps = 60;
    // Démarrage du sablier
    fini = 0;
}

Sablier::Sablier(int temps){
    // Initialisation du sablier au temps souhaité
    this->temps = temps;
    // Démarrage du sablier
    fini = 0;
}

// Accesseurs
int Sablier::getTemps(){
    return temps;
}

bool Sablier::getFini(){
    return fini;
}

// Mutateurs
void Sablier::setTemps(int temps){
    this->temps = temps;
}

void Sablier::setFini(){
    this->fini = 1;
}

void Sablier::setFini(bool etat){
    this->fini = etat;
}

// Méthodes
void Sablier::startDecompte(){
    // Lancer un thread qui décrémente automatiquement le sablier
    std::thread([this]() {
        while (!this->getFini()) {
            this->decompte();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    }).detach(); // détache le thread pour qu'il fonctionne en arrière-plan
}

void Sablier::decompte(){
    if(temps > 0 && fini == 0){
        temps--;
    } else fini = 1;
}