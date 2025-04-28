#include "Sablier.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void printSablier(Sablier& s, int attente = 1) {
    // Affiche le temps toutes les "attente" secondes tant que ce n'est pas fini
    while (!s.getFini()) {
        cout << "Temps restant : " << s.getTemps() << " secondes" << endl;
        this_thread::sleep_for(chrono::seconds(attente));
    }
    cout << "Sablier fini !" << endl;
}

int main() {
    // Test 1 : Sablier valeur par défaut (60 secondes), mais on racourcit pour test
    cout << "Test 1 : Sablier de 5 secondes" << endl;
    Sablier s1(5); // racourci à 5 pour la démo
    s1.startDecompte();
    printSablier(s1);

    // Test 2 : Changer le temps puis redémarrer
    cout << "\nTest 2 : Sablier remis à 3 secondes" << endl;
    s1.setTemps(3);
    s1.setFini(false); // réinitialise l'état "fini"
    s1.startDecompte();
    printSablier(s1);

    // Test 3 : Sablier valeur par défaut (60s mais on ne va pas attendre)
    cout << "\nTest 3 : Sablier de 2 secondes (nouveau sablier)" << endl;
    Sablier s2(2);
    s2.startDecompte();
    printSablier(s2);

    // Test 4 : Décrémentation manuelle
    cout << "\nTest 4 : Décrémentation manuelle sur Sablier de 4 secondes" << endl;
    Sablier s3(4);
    while (!s3.getFini()) {
        cout << "Temps restant (manuel): " << s3.getTemps() << endl;
        s3.decompte();
        this_thread::sleep_for(chrono::milliseconds(500)); // plus rapide
    }
    cout << "Sablier fini !" << endl;

    return 0;
}
