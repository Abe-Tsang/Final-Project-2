#ifndef AREA_H
#define AREA_H

#include <QColor>
#include <QGraphicsItem>
#include <string>

class Area : public QObject, public QGraphicsItem {

    Q_OBJECT

public:
    Area(QColor color, const int x, const int y, const int width, const int height, const int i, const int j, const std::string areaType);  // constructor

    int get_x() const { return x_; }  // inline member function
    int get_y() const { return y_; }  // inline member function

    double Distance(const Area &other) const;  // member function

    QRectF boundingRect() const override;
    QPainterPath shape() const override;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;

    //static int get_width() { return width_; }

    static bool get_delete_mode() { return delete_mode_; }
    static void set_delete_mode(bool val) { delete_mode_ = val; }

    int random(int max, int min);
    int rollDice();
    std::string showResourceType();
    int showRandomNumber();

private slots:


signals:
    void AreaClicked(int i, int j, std::string areaType);
    void DeleteArea(Area * p);
    void DistanceAreasClicked(int x, int y);
    void AreaRightClicked(int x, int y);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

private:
  int x_;
  int y_;
  int width_;
  int height_;
  int i_;
  int j_;
  std::string areaType_;
  int randomNumber_;
  std::string resourceType_;

  QColor color_;

  // all our Areas will be 10 wide and tall (they are circles)
  //static const int width_ = 10;

  static bool delete_mode_;

  // if you declare the operator as a friend, then it isn't
  // part of the object
  // friend will let this method access the private fields
  friend bool operator==(const Area &first, const Area &other);
};  // class Area



#endif // AREA_H
