#include <string>
#include <iostream>
#include <string>
#include "stdlib.h"
#include "Case.h"
#include "Sablier.h"
#include "robot.h"

using namespace std;

int main() {
    int x = 0;
    int y = 0;
    int x1 = 1;
    int y1 = 0;
    Case case1 = Case(x,y);
    case1.setBordsHaut(true);
    case1.setBordsBas(true);
    case1.setBordsGauche(false);
    case1.setBordsDroit(true);
    case1.setCouleur("rouge");
    //case1.setBordsDroit(true);
    case1.AffichageCase(x,y);
    //case1.setCouleur("bleu");
    //case1.AffichageCase(x1,y1);

    //test classe robot :
    Robot robot1("bleu", 5, 5);
    char dir = robot1.RecupereInfo();
    robot1.Deplacement(dir);

    return 0;
}