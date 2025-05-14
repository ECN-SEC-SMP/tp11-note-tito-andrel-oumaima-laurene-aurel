#include "gtest/gtest.h"
#include "../plateauRicochet.h"
#include "../Robot.h"

class PlateauTest : public ::testing::Test {
protected:
    plateauRicochet* plateau;

    void SetUp() override {
        plateau = new plateauRicochet(16, 16);
    }

    void TearDown() override {
        delete plateau;
    }
};

TEST_F(PlateauTest, InitialRobotPositionsAreValid) {
    Robot red("red"), green("gr"), blue("bl"), yellow("ye");
    plateau->InitRobot(&red, &green, &blue, &yellow);

    std::set<std::pair<int, int>> seen;
    std::vector<Robot*> robots = {&red, &green, &blue, &yellow};

    for (Robot* r : robots) {
        int x = r->GetX();
        int y = r->GetY();

        // Vérifie que la position est dans les bornes
        EXPECT_GE(x, 0);
        EXPECT_LT(x, 16);
        EXPECT_GE(y, 0);
        EXPECT_LT(y, 16);

        // Vérifie que la position n'est pas interdite
        //EXPECT_FALSE(estInterdite(x, y));

        // Vérifie que la case contient bien le robot
        EXPECT_TRUE(plateau->getPlateau()[x][y]->getRobotHere());

        // Vérifie que deux robots ne sont pas au même endroit
        EXPECT_FALSE(seen.count({x, y}) > 0);
        seen.insert({x, y});
    }
}

TEST_F(PlateauTest, ValidMovementIsDetectedCorrectly) {
    // Place un robot à une position valide
    Robot robot("test", 5, 5);
    plateau->getPlateau()[5][5]->setRobotHere(true);

    // Position occupée
    EXPECT_FALSE(plateau->estDeplacementValide(5, 5));

    // Position en dehors des limites
    EXPECT_FALSE(plateau->estDeplacementValide(-1, 5));
    EXPECT_FALSE(plateau->estDeplacementValide(5, 16));

    // Position interdite
    EXPECT_FALSE(plateau->estDeplacementValide(7, 7));

    // Position libre
    EXPECT_TRUE(plateau->estDeplacementValide(6, 5));
}

TEST_F(PlateauTest, RobotMovementUpdatesPositionAndPlateau) {
    Robot robot("test", 5, 5);
    plateau->getPlateau()[5][5]->setRobotHere(true);

    // Bouge vers la droite (s'il n'y a pas de mur)
    plateau->DeplacerRobot(&robot, 'R');

    // Vérifie que l'ancienne case n'a plus le robot
    EXPECT_FALSE(plateau->getPlateau()[5][5]->getRobotHere());

    // Vérifie que la nouvelle position est correcte
    int x = robot.GetX();
    int y = robot.GetY();
    EXPECT_TRUE(plateau->getPlateau()[x][y]->getRobotHere());
    EXPECT_NE(y, 5);  // S'il a bougé, la colonne doit avoir changé
}
