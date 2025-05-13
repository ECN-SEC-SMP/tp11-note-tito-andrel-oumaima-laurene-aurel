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

int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // mode non canonique, pas d'echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt); // restaure
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin); // remet le caractère dans le buffer
        return 1;
    }

    return 0;
}

char Robot::GetKeyboardInfo() const {
    return keyboard_info;
}

void Robot::SetKeyboardInfo(char consigne) {
    keyboard_info = consigne;
}

void Robot::RecupereInfo(){ //renommer en info
    //char input_direction;
    std::cout<<"Directions ? (q pour quitter)"<<std::endl;
    std::cout<<"   ^"<<std::endl;
    std::cout<<"<     >"<<std::endl;
    std::cout<<"   v"<<std::endl;

    bool running = true;
    plateauRicochet* plateau = new plateauRicochet;

    while (running) {
        int test = kbhit();
        //std::cout << "la valeur reçu " << test << std::endl;
        if (test) {
            char ch1 = getchar();
            //std::cout << "la valeur reçu de robot en mouvement ch1 :" << ch1 << std::endl;
            if (ch1 == '\033') { // ESC
                char ch2 = getchar();
                //std::cout << "la valeur reçu de robot en mouvement ch2 :" << ch2 << std::endl;
                if (ch2 == '[') {
                    char ch3 = getchar();
                    //std::cout << "la valeur reçu de robot en mouvement ch3 :" << ch3 << std::endl;
                    switch (ch3) {
                        case 'A': this->SetKeyboardInfo('U');
                                Plateau->DeplacerRobot(robotRed);
                                break; // haut
                        case 'B': this->SetKeyboardInfo('D'); break; // bas
                        case 'C': this->SetKeyboardInfo('R'); break; // droite
                        case 'D': this->SetKeyboardInfo('L'); break; // gauche
                    }
                    std::cout << "lA" << keyboard_info << std::endl;
                }
            } else if (ch1 == 'q') {
                running = false;
            }
        }
        usleep(100000); // Petite pause pour limiter la vitesse (100ms)
    }
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