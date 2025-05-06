#ifndef ROBOT_H
#define ROBOT_H


#include <string>
#include <vector>

class Robot {
private:
    std::string couleur; // Couleur du robot

public:
    int nbDeplacements;  // Nombre de déplacements
    bool OK;             // Statut OK
    int x;               // Position X
    int y;               // Position Y

    Robot(std::string c, int posX, int posY); // Constructeur
    Robot(std::string c); // Constructeur par défaut

    char RecupereInfo(); // recupere la direction du robot
    void Deplacement(char direction); // Bouger
    void GenereRobot();
    bool CaseDispo(int x, int y);

    // Accesseur :
    int GetX() const;
    int GetY() const;
    int GetNbDeplacement() const;
    std::vector<int> GetPosition() const;

    // Setteur :
    void SetX(int posX);
    void SetY(int posY);
    void SetNbDeplacement(int nb);
    void SetPosition(int xpos, int ypos);
};

#endif
