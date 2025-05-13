#include "Robot.h"
#include "Case.h"
#include "plateauRicochet.h"
#include <iostream>
#include <vector>
#include <list>

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <cstdlib>
#include <cstring>

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
    this->couleur = c;
    this->nbDeplacements = 0;
}

Robot::Robot(std::string c, int posX, int posY){
    // Initialisation des attributs
    x = rand()%16;
    y = rand()%16;
    couleur = c;
    nbDeplacements = 0;
    //OK = false;
}

// Structure pour stocker les paramètres originaux du terminal
struct termios orig_termios;

void reset_terminal_mode() {
    tcsetattr(STDIN_FILENO, TCSANOW, &orig_termios);
}

void set_terminal_mode() {
    struct termios new_termios;
    tcgetattr(STDIN_FILENO, &orig_termios);
    memcpy(&new_termios, &orig_termios, sizeof(new_termios));
    atexit(reset_terminal_mode);
    cfmakeraw(&new_termios);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
}

char Robot::GetKeyboardInfo() const {
    return keyboard_info;
}

void Robot::SetKeyboardInfo(char consigne) {
    keyboard_info = consigne;
}


// Voici la fonction RecupereInfo modifiée pour qu'elle ne soit pas bloquante
char Robot::RecupereInfo() {
    // Définir le terminal en mode non-bloquant
    int oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
    
    // Structure pour stocker les paramètres du terminal
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // mode non canonique, pas d'echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
    char ch1 = getchar();
    char direction = ' '; // Valeur par défaut si aucune touche n'est pressée
    
    if (ch1 != EOF) {
        if (ch1 == '\033') { // ESC (début d'une séquence de touches fléchées)
            char ch2 = getchar();
            if (ch2 == '[') {
                char ch3 = getchar();
                switch (ch3) {
                    case 'A': direction = 'U'; break; // haut
                    case 'B': direction = 'D'; break; // bas
                    case 'C': direction = 'R'; break; // droite
                    case 'D': direction = 'L'; break; // gauche
                }
            }
        } else if (ch1 == 'q') {
            direction = 'Q'; // Quitter
        }
    }
    
    // Restaurer les paramètres originaux du terminal
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);
    
    return direction;
}
// void clear_screen() {
//     std::cout << "\033[2J\033[H";
// }

//void Robot::Deplacement(char input_direction) {
    // switch (input_direction) {
    //     case 'z': y--; break; // Up
    //     case 's': while (obstacle==0) y++; break; // Down
    //     case 'q': while (obstacle==0) x--; break; // Left
    //     case 'd': while (obstacle==0) x++; break; // Right
    // }

    //récupére le robot et la direction de deplacement
    //nbDeplacements++; // A chaque mouvement, on ajoute 1 déplacement
//}

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