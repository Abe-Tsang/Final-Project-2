#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "area.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void ClickAreaSlot(int i, int j, std::string areaType);

signals:
    void ownershipChanged(QColor color);

private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;

    Area * pointArea[5][5];
    Area * horizontalArea[4][5];
    Area * verticalArea[5][4];
    Area * bigArea[4][4];
};

#endif // MAINWINDOW_H
