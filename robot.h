
#include <string>

class Robot {
private:
    std::string couleur; // Couleur du robot

public:
    int nbDeplacements;  // Nombre de déplacements
    bool OK;             // Statut OK
    int x;               // Position X
    int y;               // Position Y

    Robot(std::string c, int posX, int posY); // Constructeur

    void Deplacement(char direction); // Bouger

    int GetX() const;
    int GetY() const;
    void SetX(int posX);
    void SetY(int posY);

    int GetNbDeplacement() const;
    void SetNbDeplacement(int nb);
};
