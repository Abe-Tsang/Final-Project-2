#include <QDebug>
#include <string>
#include "game.h"
#include "player.h"
#include "area.h"
#include "ai.h"

Game::Game(Area *pointArea[5][5], Area *horizontalArea[4][5], Area *verticalArea[5][4], Area *bigArea[4][4], int numberOfPlayers){
    if(numberOfPlayers >= 0 || numberOfPlayers <= 4){
        numberOfAIs = 4 - numberOfPlayers;
    }
    AI * artificialIntelligence[numberOfAIs];
    for(int i = 0; i < numberOfAIs; i++){
        artificialIntelligence[i] = new AI();
    }
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

    /*p1->receiveBuilding(0, 0);
    for(int i = 0; i < 4; i++){
        p1->receiveBrick();
        p1->receiveWood();
    }*/

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(bigArea_[i][j]->getRandomNumber() == diceResult){
                if(strcmp(bigArea_[i][j]->getResourceType().c_str(), "wood") == 0){

                    if(p1->getBuilding(i, j) == true){
                        p1->receiveWood();
                    }
                    if(p1->getBuilding(i + 1, j) == true){
                        p1->receiveWood();
                    }
                    if(p1->getBuilding(i, j + 1) == true){
                        p1->receiveWood();
                    }
                    if(p1->getBuilding(i + 1, j + 1) == true){
                        p1->receiveWood();
                    }

                    if(p2->getBuilding(i, j) == true){
                        p2->receiveWood();
                    }
                    if(p2->getBuilding(i + 1, j) == true){
                        p2->receiveWood();
                    }
                    if(p2->getBuilding(i, j + 1) == true){
                        p2->receiveWood();
                    }
                    if(p2->getBuilding(i + 1, j + 1) == true){
                        p2->receiveWood();
                    }

                    if(p3->getBuilding(i, j) == true){
                        p3->receiveWood();
                    }
                    if(p3->getBuilding(i + 1, j) == true){
                        p3->receiveWood();
                    }
                    if(p3->getBuilding(i, j + 1) == true){
                        p3->receiveWood();
                    }
                    if(p3->getBuilding(i + 1, j + 1) == true){
                        p3->receiveWood();
                    }

                    if(p4->getBuilding(i, j) == true){
                        p4->receiveWood();
                    }
                    if(p4->getBuilding(i + 1, j) == true){
                        p4->receiveWood();
                    }
                    if(p4->getBuilding(i, j + 1) == true){
                        p4->receiveWood();
                    }
                    if(p4->getBuilding(i + 1, j + 1) == true){
                        p4->receiveWood();
                    }

                }
                else if(strcmp(bigArea_[i][j]->getResourceType().c_str(), "brick") == 0){

                    if(p1->getBuilding(i, j) == true){
                        p1->receiveBrick();
                    }
                    if(p1->getBuilding(i + 1, j) == true){
                        p1->receiveBrick();
                    }
                    if(p1->getBuilding(i, j + 1) == true){
                        p1->receiveBrick();
                    }
                    if(p1->getBuilding(i + 1, j + 1) == true){
                        p1->receiveBrick();
                    }

                    if(p2->getBuilding(i, j) == true){
                        p2->receiveBrick();
                    }
                    if(p2->getBuilding(i + 1, j) == true){
                        p2->receiveBrick();
                    }
                    if(p2->getBuilding(i, j + 1) == true){
                        p2->receiveBrick();
                    }
                    if(p2->getBuilding(i + 1, j + 1) == true){
                        p2->receiveBrick();
                    }

                    if(p3->getBuilding(i, j) == true){
                        p3->receiveBrick();
                    }
                    if(p3->getBuilding(i + 1, j) == true){
                        p3->receiveBrick();
                    }
                    if(p3->getBuilding(i, j + 1) == true){
                        p3->receiveBrick();
                    }
                    if(p3->getBuilding(i + 1, j + 1) == true){
                        p3->receiveBrick();
                    }

                    if(p4->getBuilding(i, j) == true){
                        p4->receiveBrick();
                    }
                    if(p4->getBuilding(i + 1, j) == true){
                        p4->receiveBrick();
                    }
                    if(p4->getBuilding(i, j + 1) == true){
                        p4->receiveBrick();
                    }
                    if(p4->getBuilding(i + 1, j + 1) == true){
                        p4->receiveBrick();
                    }

                }
                else if(strcmp(bigArea_[i][j]->getResourceType().c_str(), "sheep") == 0){

                    if(p1->getBuilding(i, j) == true){
                        p1->receiveSheep();
                    }
                    if(p1->getBuilding(i + 1, j) == true){
                        p1->receiveSheep();
                    }
                    if(p1->getBuilding(i, j + 1) == true){
                        p1->receiveSheep();
                    }
                    if(p1->getBuilding(i + 1, j + 1) == true){
                        p1->receiveSheep();
                    }

                    if(p2->getBuilding(i, j) == true){
                        p2->receiveSheep();
                    }
                    if(p2->getBuilding(i + 1, j) == true){
                        p2->receiveSheep();
                    }
                    if(p2->getBuilding(i, j + 1) == true){
                        p2->receiveSheep();
                    }
                    if(p2->getBuilding(i + 1, j + 1) == true){
                        p2->receiveSheep();
                    }

                    if(p3->getBuilding(i, j) == true){
                        p3->receiveSheep();
                    }
                    if(p3->getBuilding(i + 1, j) == true){
                        p3->receiveSheep();
                    }
                    if(p3->getBuilding(i, j + 1) == true){
                        p3->receiveSheep();
                    }
                    if(p3->getBuilding(i + 1, j + 1) == true){
                        p3->receiveSheep();
                    }

                    if(p4->getBuilding(i, j) == true){
                        p4->receiveSheep();
                    }
                    if(p4->getBuilding(i + 1, j) == true){
                        p4->receiveSheep();
                    }
                    if(p4->getBuilding(i, j + 1) == true){
                        p4->receiveSheep();
                    }
                    if(p4->getBuilding(i + 1, j + 1) == true){
                        p4->receiveSheep();
                    }

                }
            }
        }
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
        secondPlayer->receiveWood();
    }
    else if(firstItemType == "brick"){
        secondPlayer->receiveBrick();
    }
    else if(firstItemType == "sheep"){
        secondPlayer->receiveSheep();
    }

    if(secondItemType == "wood"){
        firstPlayer->receiveWood();
    }
    else if(secondItemType == "brick"){
        firstPlayer->receiveBrick();
    }
    else if(secondItemType == "sheep"){
        firstPlayer->receiveSheep();
    }

    return true;

}
