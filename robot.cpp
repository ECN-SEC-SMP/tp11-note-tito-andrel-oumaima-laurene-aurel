#include "robot.h"

Robot::Robot(std::string c, int posX, int posY)
    : couleur(c), x(posX), y(posY), nbDeplacements(0), OK(false) {}

void Robot::Deplacement(char direction) {
    // Déplacement simple (sans obstacle)
    switch (direction) {
        case 'U': y--; break; // Up
        case 'D': y++; break; // Down
        case 'L': x--; break; // Left
        case 'R': x++; break; // Right
    }
    nbDeplacements++; // À chaque mouvementon incrémente
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

bool Robot::GetOK() const {
    return OK;
}

void Robot::SetOK(bool etat) {
    OK = etat;
}
// test modification Oumaima
