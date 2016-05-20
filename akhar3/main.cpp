#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsView>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    QGraphicsScene *scene = new QGraphicsScene();;
    QGraphicsView* view=new QGraphicsView(scene);
    qDebug()<<"main";
    w.setFixedSize(view->width(), view->height());
    w.show();

    return a.exec();
}
