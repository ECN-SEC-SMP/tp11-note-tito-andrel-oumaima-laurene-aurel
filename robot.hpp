#include <iostream>
using namespace std;

class Robot {
private :
    string couleur;
    double abscisse;
    double ordonnee;
public :
    double x;
    double y;
    int nbMouvement;
    bool ok;

    void deplacement();
    
    double getX();
    double getY();
    int getNbMouvement();

    void setX(double abscisse);
    void setY(double ordonnee);
    void setNbMouvement();
};
