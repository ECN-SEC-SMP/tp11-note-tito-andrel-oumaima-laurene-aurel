#pragma once

using namespace std;

class Sablier{
private :
    // Etat du sablier
    // 0 : en cours
    // 1 : fini
    bool fini;
    // Temps restant en secondes
    int temps;
public:
    // Constructeurs
    Sablier();
    Sablier(int temps);
    // Accesseurs
    int getTemps();
    bool getFini();

    // Mutateurs
    void startDecompte();
    void setTemps(int temps);
    void setFini();
    void setFini(bool etat);
    void decompte();    
};