#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDebug>
#include <QString>
#include <QColor>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "area.h"
#include "player.h"
#include "game.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    scene = new QGraphicsScene;
    ui->setupUi(this);
    QGraphicsView *view = ui->mainGraphicsView;
    view->setScene(scene);
    view->setSceneRect(0, 0, view->frameSize().width(), view->frameSize().height());

    QPen BlackPen(Qt::black);
    for(int i = 0; i < 5; i++){ // Horizontal lines
        if(i == 2){
            scene->addLine(0, view->frameSize().height()/4*i, view->frameSize().width(), view->frameSize().height()/4*i, BlackPen);
        }
        else if(i < 2){
            scene->addLine(0, (view->frameSize().height()/4*i) + 5, view->frameSize().width(), (view->frameSize().height()/4*i) + 5, BlackPen);
        }
        else if(i > 2){
            scene->addLine(0, (view->frameSize().height()/4*i) - 5, view->frameSize().width(), (view->frameSize().height()/4*i) - 5, BlackPen);
        }
    }
    for(int i = 0; i < 5; i++){ // Vertical lines
        if(i == 2){
            scene->addLine(view->frameSize().width()/4*i, 0, view->frameSize().width()/4*i, view->frameSize().height(), BlackPen);
        }
        else if(i < 2){
            scene->addLine((view->frameSize().width()/4*i) + 5, 0, (view->frameSize().width()/4*i) + 5, view->frameSize().height(), BlackPen);
        }
        else if(i > 2){
            scene->addLine((view->frameSize().width()/4*i) - 5, 0, (view->frameSize().width()/4*i) - 5, view->frameSize().height(), BlackPen);
        }
    }

    int width, height;

    //Area * pointArea[5][5];
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){

            if(i == 2){
                width = (view->frameSize().width()/4*i) - 5;
            }
            else if(i < 2){
                width = (view->frameSize().width()/4*i);
            }
            else if(i > 2){
                width = (view->frameSize().width()/4*i) - 10;
            }
            if(j == 2){
                height = (view->frameSize().height()/4*j) - 5;
            }
            else if(j < 2){
                height = (view->frameSize().height()/4*j);
            }
            else if(j > 2){
                height = (view->frameSize().height()/4*j) - 10;
            }

            pointArea[i][j] = new Area(Qt::white, width, height, 10, 10, i, j, "pointArea");
            connect(pointArea[i][j], &Area::AreaClicked, this, &MainWindow::ClickAreaSlot);
            scene->addItem(pointArea[i][j]);
        }
    }

    //Area * horizontalArea[4][5];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){

            if(i == 2){
                width = (view->frameSize().width()/4*i) + 5;
            }
            else if(i < 2){
                width = (view->frameSize().width()/4*i) + 10;
            }
            else if(i > 2){
                width = (view->frameSize().width()/4*i);
            }
            if(j == 2){
                height = (view->frameSize().height()/4*j) - 5;
            }
            else if(j < 2){
                height = (view->frameSize().height()/4*j);
            }
            else if(j > 2){
                height = (view->frameSize().height()/4*j) - 10;
            }

            if(i == 0 || i == 3){
                horizontalArea[i][j] = new Area(Qt::white, width, height, 160, 10, i, j, "horizontalArea");
            }
            else if(i == 1 || i == 2){
                horizontalArea[i][j] = new Area(Qt::white, width, height, 155, 10, i, j, "horizontalArea");
            }
            connect(horizontalArea[i][j], &Area::AreaClicked, this, &MainWindow::ClickAreaSlot);
            scene->addItem(horizontalArea[i][j]);
        }
    }

    //Area * verticalArea[5][4];
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 4; j++){

            if(i == 2){
                width = (view->frameSize().width()/4*i) - 5;
            }
            else if(i < 2){
                width = (view->frameSize().width()/4*i);
            }
            else if(i > 2){
                width = (view->frameSize().width()/4*i) - 10;
            }
            if(j == 2){
                height = (view->frameSize().height()/4*j) + 5;
            }
            else if(j < 2){
                height = (view->frameSize().height()/4*j) + 10;
            }
            else if(j > 2){
                height = (view->frameSize().height()/4*j);
            }
            if(j == 0 || j == 3){
                verticalArea[i][j] = new Area(Qt::white, width, height, 10, 72, i, j, "verticalArea");
            }
            else if(j == 1 || j == 2){
                verticalArea[i][j] = new Area(Qt::white, width, height, 10, 67, i, j, "verticalArea");
            }
            connect(verticalArea[i][j], &Area::AreaClicked, this, &MainWindow::ClickAreaSlot);
            scene->addItem(verticalArea[i][j]);
        }
    }

    //Area * bigArea[4][4];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){

            if(i == 2){
                width = (view->frameSize().width()/4*i) + 5;
            }
            else if(i < 2){
                width = (view->frameSize().width()/4*i) + 10;
            }
            else if(i > 2){
                width = (view->frameSize().width()/4*i);
            }
            if(j == 2){
                height = (view->frameSize().height()/4*j) + 5;
            }
            else if(j < 2){
                height = (view->frameSize().height()/4*j) + 10;
            }
            else if(j > 2){
                height = (view->frameSize().height()/4*j);
            }

            int width2;
            int height2;
            if(i == 0 || i == 3){
                width2 = 160;
            }
            else if(i == 1 || i == 2){
                width2 = 155;
            }
            if(j == 0 || j == 3){
                height2 = 72;
            }
            else if(j == 1 || j == 2){
                height2 = 67;
            }
            bigArea[i][j] = new Area(Qt::white, width, height, width2, height2, i, j, "bigArea");
            connect(bigArea[i][j], &Area::AreaClicked, this, &MainWindow::ClickAreaSlot);
            scene->addItem(bigArea[i][j]);
        }
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
    //Game *g = new Game();

}

void MainWindow::ClickAreaSlot(int i, int j, std::string areaType){
    qDebug() << i;
    qDebug() << j;
    qDebug() << areaType.c_str();
    emit MainWindow::ownershipChanged(Qt::black);
}

MainWindow::~MainWindow()
{
    delete ui;
}
