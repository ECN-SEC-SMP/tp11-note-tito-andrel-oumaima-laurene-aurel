#include "Robot.h"
bool obstacle;
Robot::Robot(std::string c, int posX, int posY) : couleur(c), x(posX), y(posY), nbDeplacements(0), OK(false) {}

void Robot::Deplacement(char direction) {
    while (obstacle==0){
        switch (direction) {
            case 'U': y--; break; // Up
            case 'D': y++; break; // Down
            case 'L': x--; break; // Left
            case 'R': x++; break; // Right
        }
        nbDeplacements++; // A chaque mouvement, on ajoute 1 déplacement
    }
    
}

int Robot::GetX() const {
    return x;
}

int Robot::GetY() const {
    return y;
}

void Robot::SetX(int posX) {
    x = posX;
}

void Robot::SetY(int posY) {
    y = posY;
}

int Robot::GetNbDeplacement() const {
    return nbDeplacements;
}
 
void Robot::SetNbDeplacement(int nb) {
    nbDeplacements = nb;
}