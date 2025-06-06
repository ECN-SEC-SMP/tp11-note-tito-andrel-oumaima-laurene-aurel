#include "Robot.h"
#include "Case.h"
#include "plateauRicochet.h"
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <cstdlib> // Pour srand() et rand()
#include <ctime>   // Pour time()

bool OK = false; // Variable globale pour la disponibilité de la case
bool obstacle;
// Constructeurs que j'utilise
Robot::Robot(std::string c) {
    // Initialisation des attributs
    //robot spawn au meme endroit
    this->x = rand()%16;
    this->y = rand()%16;
    while(x== 7 && y==7 || x==8 && y==8 || x==7 && y==8 || x==8 && y==7){
        this->x = rand()%16;
        this->y = rand()%16;
    }
    this->couleur = c;
    this->nbDeplacements = 0;
}

Robot::Robot(std::string c, int posX, int posY){
    // Initialisation des attributs
    this->x = posX;
    this->y = posY;
    couleur = c;
    nbDeplacements = 0;
}

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
    // switch (direction) {
    //     case 'U': y--; break; // Up
    //     case 'D': while (obstacle==0) y++; break; // Down
    //     case 'L': while (obstacle==0) x--; break; // Left
    //     case 'R': while (obstacle==0) x++; break; // Right
    // }

    // //récupére le robot et la direction de deplacement
    // nbDeplacements++; // A chaque mouvement, on ajoute 1 déplacement
}

void Robot::GenereRobot(){
    //je pense que c'est plus compliqué de tous les générer en même temps
    // //je pref les stocker un à un
    // int i = rand()%4;
    // int j = 0;
    // std::string color;
    // int xinitial = 0;
    // int yinitial = 0;

    // xinitial, yinitial = rand()%16, rand()%16;
    // Robot::CaseDispo(xinitial, yinitial);
    // if(OK == 0) Robot robotB("bleu", xinitial, yinitial);

    // xinitial, yinitial = rand()%16, rand()%16;
    // Robot::CaseDispo(xinitial, yinitial);
    // if(OK == 0) Robot robotJ("jaune", xinitial, yinitial);

    // xinitial, yinitial = rand()%16, rand()%16;
    // Robot::CaseDispo(xinitial, yinitial);
    // if(OK == 0) Robot robotR("rouge", xinitial, yinitial);

    // xinitial, yinitial = rand()%16, rand()%16;
    // Robot::CaseDispo(xinitial, yinitial);
    // if(OK == 0) Robot robotV("vert", xinitial, yinitial);

    // Robot::SetPosition(xinitial, yinitial);
}

// Accesseur :
int Robot::GetX() const {
    return x;
}

int Robot::GetY() const {
    return y;
}

string Robot::getCouleur(){
    return couleur;
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
    this->x = posX;
}

void Robot::SetY(int posY) {
    this->y = posY;
}

void Robot::SetNbDeplacement(int nb) {
    this->nbDeplacements = nb;
}

void Robot::SetPosition(int xpos, int ypos){
    SetX(xpos);
    SetY(ypos);
}

