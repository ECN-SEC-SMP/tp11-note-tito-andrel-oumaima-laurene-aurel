#ifndef PLATEAU_H
#define PLATEAU_H
class plateauRicochet
{
    private:
     int Max_X;
     int Max_Y;
     //vector<std::vector<Case*>> Plateau;
     Case* Plateau[100][100]; // Assuming a maximum size of 100x100 for simplicity

    public:
        plateauRicochet(int x, int y);
        void Afficher();   
}

#endif