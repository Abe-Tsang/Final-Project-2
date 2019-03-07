#ifndef PLAYER_H
#define PLAYER_H

#include <QColor>

class PlayerPrototype{
public:
    virtual PlayerPrototype * clone() = 0;
    void setPlayerNumber(int playerNumber);
    void setColor(QColor color);
    void receiveWood();
    void receiveBrick();
    void receiveSheep();
    bool giveWood();
    bool giveBrick();
    bool giveSheep();
    int getWood();
    int getBrick();
    int getSheep();
    bool receiveBuilding(int i, int j);
    bool receiveHorizontalRoad(int i, int j);
    bool receiveVerticalRoad(int i, int j);
    bool getBuilding(int i, int j);
protected:
    bool horizontalRoad_[4][5];
    bool verticalRoad_[5][4];
    bool building_[5][5];
    int wood_;
    int brick_;
    int sheep_;
    int point_;
    int playerNumber_;
    QColor color_;
};

class Player : public PlayerPrototype{
public:
    Player(const int playerNumber, QColor color);
    void fix();
    PlayerPrototype * clone();

private:

};

#endif
