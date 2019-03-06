#ifndef GAME_H
#define GAME_H

#include "player.h"
#include "area.h"
#include "ai.h"

class Game{
public:
    Game(Area *pointArea[5][5], Area *horizontalArea[4][5], Area *verticalArea[5][4], Area *bigArea[4][4]);
    int random(int max, int min);
    int rollDice();
    void turn(PlayerPrototype *p1, PlayerPrototype *p2, PlayerPrototype *p3, PlayerPrototype *p4);
    bool trade(PlayerPrototype *firstPlayer, std::string firstItemType, PlayerPrototype *secondPlayer, std::string secondItemType);
private:
    Area * pointArea_[5][5];
    Area * horizontalArea_[4][5];
    Area * verticalArea_[5][4];
    Area * bigArea_[4][4];
};

#endif GAME_H
