#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include "game.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Game *g = new Game();
    MainWindow w;
    w.show();


    return a.exec();
}
