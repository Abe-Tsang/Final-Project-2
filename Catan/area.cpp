#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iostream>
#include <QtWidgets>
#include <string>
#include <unistd.h>
#include "area.h"

bool Area::delete_mode_ = false; // starting value

/**
  Creates a new Area object with coordinates x and y
  @param x int x coordinate
  @param y int y coordinate
*/
Area::Area(QColor color, const int x, const int y, const int width, const int height, const int i, const int j, const std::string areaType) {
  this->color_ = color;
  x_ = x;
  y_ = y;
  width_ = width;
  height_ = height;
  i_ = i;
  j_ = j;
  areaType_ = areaType;
  randomNumber_ = -1;
  if(areaType_ == "bigArea"){
      randomNumber_ = rollDice();
      int randomResourceType = random(3, 1);
      if(randomResourceType == 1){
          resourceType_ = "wood";
      }
      else if(randomResourceType == 2){
          resourceType_ = "brick";
      }
      if(randomResourceType == 3){
          resourceType_ = "sheep";
      }
  }

  //connect(); connect sender object to receiver object
}

QRectF Area::boundingRect() const
{
    return QRectF(x_, y_, width_, height_);
}

QPainterPath Area::shape() const
{
    QPainterPath path;
    //path.addEllipse(x_, y_, width_, width_);
    path.addRect(x_, y_, width_, height_);
    return path;
}


void Area::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);


    QBrush b = painter->brush();
    painter->setBrush(QBrush(color_.dark(option->state & QStyle::State_Sunken ? 120 : 100)));

    //painter->drawEllipse(QRect(this->x_, this->y_, this->width_, this->width_));
    painter->drawRect(QRect(this->x_, this->y_, this->width_, this->height_));
    painter->setBrush(b);
}

void Area::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    qDebug() << "This method automatically called when the Area is clicked!";

    // Day 2, Task 5, number 2
    if(!delete_mode_){
        if(Qt::ShiftModifier && event->modifiers()){
            emit Area::DistanceAreasClicked(x_, y_);
        }
        else if(event->button() == Qt::RightButton){
            emit Area::AreaRightClicked(x_, y_);
        }
        else{
            emit Area::AreaClicked(i_, j_, areaType_);
        }
    }
    else{
        emit Area::DeleteArea(this);
    }

    // Day 2, Task 6, number 2
    // generate a random color

    // update this QGraphicsItem (sends a signal that it should be repainted)
    update();
}

/**
  Calculates the distance between this Area and another Area.
  @param other Area object to calculate the distance to
*/
double Area::Distance(const Area &other) const {
  double distance = (x_ - other.get_x()) * (x_ - other.get_x());
  distance += (y_ - other.y_) * (y_ - other.y_);
  return sqrt(distance);
}

int Area::random(int max, int min){
    static bool first = true;
    if(first){
        srand(time(NULL));
        first = false;
    }
    return min + rand() % ((max + 1) - min);
}

int Area::rollDice(){
    return random(6, 1) + random(6, 1);
}

std::string Area::getResourceType(){
    return this->resourceType_;
}

int Area::getRandomNumber(){
    return this->randomNumber_;
}

void Area::setColor(QColor color){
    this->color_ = color;
}

/**
  Makes it so the == operator will have the behavior that you
  expect when comparing Areas.
  You can overload pretty much any operator in c++
  @param first Area left hand side of the expression
  @param other Area right hand side of the expression
*/
bool operator==(const Area &first, const Area &other) {
  return first.x_ == other.x_ && first.y_ == other.y_;
}
