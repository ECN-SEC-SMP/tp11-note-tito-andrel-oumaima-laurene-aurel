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
    int xinitial = 0;
    int yinitial = 0;

    xinitial, yinitial = rand()%16, rand()%16;
    Robot::CaseDispo(xinitial, yinitial);
    if(OK == 0) Robot robotB("bleu", xinitial, yinitial);

    xinitial, yinitial = rand()%16, rand()%16;
    Robot::CaseDispo(xinitial, yinitial);
    if(OK == 0) Robot robotJ("jaune", xinitial, yinitial);

    xinitial, yinitial = rand()%16, rand()%16;
    Robot::CaseDispo(xinitial, yinitial);
    if(OK == 0) Robot robotR("rouge", xinitial, yinitial);

    xinitial, yinitial = rand()%16, rand()%16;
    Robot::CaseDispo(xinitial, yinitial);
    if(OK == 0) Robot robotV("vert", xinitial, yinitial);

    Robot::SetPosition(xinitial, yinitial);
}

bool Robot::CaseDispo(int x, int y){
    for(int i = 0; i<=16; i++){
        for(int j = 0; j<=16; j++){
            OK = 0;
        }
    }
    return OK;
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

