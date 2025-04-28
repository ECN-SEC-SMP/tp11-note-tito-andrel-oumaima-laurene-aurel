#include "robot.hpp"

void Robot::deplacement(){
    
}

double Robot::getX(){
    return x;
}

double Robot::getY(){
    return y;
}

int Robot::getNbMouvement(){
    return nbMouvement;
}

void Robot::setX(double abscisse){
    x = abscisse;
}

void Robot::setY(double ordonnee){
    y = ordonnee;
}

void Robot::setNbMouvement(){
    int move = nbMouvement;
}