#include <QDebug>
#include <string>
#include "game.h"
#include "player.h"
#include "area.h"

Game::Game(Area *pointArea[5][5], Area *horizontalArea[4][5], Area *verticalArea[5][4], Area *bigArea[4][4]){
    Player *p = new Player(0, Qt::white);
    PlayerPrototype *p1 = p->clone();
    PlayerPrototype *p2 = p->clone();
    PlayerPrototype *p3 = p->clone();
    PlayerPrototype *p4 = p->clone();
    p1->setColor(Qt::red);
    p1->setPlayerNumber(1);
    p2->setColor(Qt::blue);
    p2->setPlayerNumber(2);
    p3->setColor(Qt::yellow);
    p3->setPlayerNumber(3);
    p4->setColor(Qt::green);
    p4->setPlayerNumber(4);
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            pointArea_[i][j] = pointArea[i][j];
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            horizontalArea_[i][j] = horizontalArea[i][j];
        }
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            verticalArea_[i][j] = verticalArea[i][j];
        }
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            bigArea_[i][j] = bigArea[i][j];
        }
    }
    turn(p1, p2, p3, p4);
}

int Game::random(int max, int min){
    static bool first = true;
    if(first){
        srand(time(NULL));
        first = false;
    }
    return min + rand() % ((max + 1) - min);
}

int Game::rollDice(){
    return random(6, 1) + random(6, 1);
}

void Game::turn(PlayerPrototype *p1, PlayerPrototype *p2, PlayerPrototype *p3, PlayerPrototype *p4){
    int diceResult = rollDice();

    p1->getBuilding(0, 0);
    for(int i = 0; i < 4; i++){
        p1->getBrick();
        p1->getWood();
    }

}

bool Game::trade(PlayerPrototype *firstPlayer, std::string firstItemType, PlayerPrototype *secondPlayer, std::string secondItemType){

    if(firstItemType == "wood"){
        if(firstPlayer->giveWood() == false){
            return false;
        }
    }
    else if(firstItemType == "brick"){
        if(firstPlayer->giveBrick() == false){
            return false;
        }
    }
    else if(firstItemType == "sheep"){
        if(firstPlayer->giveSheep() == false){
            return false;
        }
    }
    else{
        return false;
    }

    if(secondItemType == "wood"){
        if(secondPlayer->giveWood() == false){
            return false;
        }
    }
    else if(secondItemType == "brick"){
        if(secondPlayer->giveBrick() == false){
            return false;
        }
    }
    else if(secondItemType == "sheep"){
        if(secondPlayer->giveSheep() == false){
            return false;
        }
    }
    else{
        return false;
    }

    if(firstItemType == "wood"){
        secondPlayer->getWood();
    }
    else if(firstItemType == "brick"){
        secondPlayer->getBrick();
    }
    else if(firstItemType == "sheep"){
        secondPlayer->getSheep();
    }

    if(secondItemType == "wood"){
        firstPlayer->getWood();
    }
    else if(secondItemType == "brick"){
        firstPlayer->getBrick();
    }
    else if(secondItemType == "sheep"){
        firstPlayer->getSheep();
    }

    return true;

}
