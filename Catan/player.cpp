#include <QDebug>
#include <QColor>
#include "player.h"

Player::Player(const int playerNumber, QColor color){
    this->playerNumber_ = playerNumber;
    this->color_ = color;

    this->brick_ = 0;
    this->sheep_ = 0;
    this->wood_ = 0;
    this->point_ = 0;

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            this->horizontalRoad_[i][j] = false;
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){
            this->verticalRoad_[i][j] = false;
        }
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(i == 3 && j == 1){ // This is a bug from within
                this->building_[i][j] = true;
            }
            else{
                this->building_[i][j] = false;
            }
        }
    }
    this->fix();

}

void Player::fix(){
    this->building_[3][1] = false; // Again, this is the same bug from within
}

PlayerPrototype * Player::clone(){
    return new Player(*this);
}

void PlayerPrototype::setColor(QColor color){
    this->color_ = color;
}

void PlayerPrototype::setPlayerNumber(int playerNumber){
    this->playerNumber_ = playerNumber;
}

