#include "Robot.h"
#include <iostream>
#include <vector>
#include <list>

bool obstacle;
Robot::Robot(std::string c, int posX, int posY) : couleur(c), x(posX), y(posY), nbDeplacements(0), OK(false) {}

char Robot::RecupereInfo(){
    char direction;
    std::cout<<"Directions ?"<<std::endl;
    std::cout<<"   U"<<std::endl;
    std::cout<<"L     R"<<std::endl;
    std::cout<<"   D"<<std::endl;
    std::cin>>direction;
    return direction;
}

void Robot::Deplacement(char direction) {
    switch (direction) {
        case 'U': while (obstacle==0) y--; break; // Up
        case 'D': while (obstacle==0) y++; break; // Down
        case 'L': while (obstacle==0) x--; break; // Left
        case 'R': while (obstacle==0) x++; break; // Right
    }
    nbDeplacements++; // A chaque mouvement, on ajoute 1 déplacement
}

void Robot::GenereRobot(){
    int i = rand()%4;
    int j = 0;
    std::string color;

    // assigne une couleur au robot :
    switch(i){
        case 0 : color = "jaune"; j=1; break;
        case 1 : color = "rouge"; j=1; break;
        case 2 : color = "bleu"; j=1; break;
        case 3 : color = "vert"; j=1; break;
        case 4 : break;
    }

    if(j==1) i = 4;

    int xinitial = rand()%16;
    int yinitial = rand()%16;
    Robot::SetPosition(xinitial, yinitial);
}

// Accesseur :
int Robot::GetX() const {
    return x;
}

int Robot::GetY() const {
    return y;
}

int Robot::GetNbDeplacement() const {
    return nbDeplacements;
}

std::vector<int> Robot::GetPosition() const {
    int x = GetX();
    int y = GetY();
    std::vector<int> position = {x,y};
    return position;
}

// Setteur :
void Robot::SetX(int posX) {
    x = posX;
}

void Robot::SetY(int posY) {
    y = posY;
}

void Robot::SetNbDeplacement(int nb) {
    nbDeplacements = nb;
}

void Robot::SetPosition(int xpos, int ypos){
    SetX(xpos);
    SetY(ypos);
}