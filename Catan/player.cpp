#include <QDebug>
#include <QColor>
#include "player.h"

Player::Player(const int playerNumber, QColor color){
    this->playerNumber_ = playerNumber;
    this->color_ = color;

    this->brick_ = 4;
    this->sheep_ = 2;
    this->wood_ = 8;
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

void PlayerPrototype::receiveWood(){
    this->wood_++;
}

void PlayerPrototype::receiveBrick(){
    this->brick_++;
}

void PlayerPrototype::receiveSheep(){
    this->sheep_++;
}

bool PlayerPrototype::giveWood(){
    if(this->wood_ > 0){
        this->wood_--;
        return true;
    }
    return false;
}

bool PlayerPrototype::giveBrick(){
    if(this->brick_ > 0){
        this->brick_--;
        return true;
    }
    return false;
}

bool PlayerPrototype::giveSheep(){
    if(this->sheep_ > 0){
        this->sheep_--;
        return true;
    }
    return false;
}

int PlayerPrototype::getWood(){
    return this->wood_;
}

int PlayerPrototype::getBrick(){
    return this->brick_;
}

int PlayerPrototype::getSheep(){
    return this->sheep_;
}

bool PlayerPrototype::receiveBuilding(int i, int j){
    if(this->building_[i][j] == false && this->brick_ >= 4 && this->wood_ >= 4){
        this->building_[i][j] = true;
        this->brick_ -= 4;
        this->wood_ -= 4;
        this->point_ += 1;
        return true;
    }
    return false;
}

bool PlayerPrototype::receiveHorizontalRoad(int i, int j){
    if(this->horizontalRoad_[i][j] == false && this->wood_ >= 2 && this->sheep_ >= 1){
        this->horizontalRoad_[i][j] = true;
        this->wood_ -= 2;
        this->sheep_ -= 1;
        return true;
    }
    return false;
}

bool PlayerPrototype::receiveVerticalRoad(int i, int j){
    if(this->verticalRoad_[i][j] == false && this->wood_ >= 2 && this->sheep_ >= 1){
        this->verticalRoad_[i][j] = true;
        this->wood_ -= 2;
        this->sheep_ -= 1;
        return true;
    }
    return false;
}

bool PlayerPrototype::getBuilding(int i, int j){
    return this->building_[i][j];
}
