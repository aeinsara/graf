#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <iostream>
#include <QPainter>
#include<QFile>
#include <QTextStream>
#include <QString>
#include <QtGlobal>
#include <QTime>
#include <QDebug>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QPalette palette(MainWindow::palette());
    palette.setColor(backgroundRole(), Qt::white);
    setPalette(palette);
}


void MainWindow::paintEvent(QPaintEvent *)
{
    char name;
    char neighbor;
    bool type;
    char color;
    int weight;
    Shape *shape;
    shape = new Shape(0, 0);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    const int size = 6;
    Node nodeArr[size];

    QVector <vector <Neighbor > > node;
   // QVector <Neighbor>;

    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    ifstream graphFile("/home/samin/graph.txt" , ios::in);

    if (!graphFile)
    {
        std::cout << "file not opened!!" << endl;
    }

//...............* read feature of nodes from file *......................

    for (int i = 0; graphFile >> name >> type >> color; i++)
    {
        nodeArr[i] = Node(' ', true, ' ');
        nodeArr[i].setNode(name, type, color, rand() % 400 + 20, rand() % 400 + 20);
 //       nodeArr[i].nodePrint();

        if (i == 5)
            break;
    }

//..................* resize vectors *..................

    node.resize(size);
    for (int i = 0; i < size; i++)
    {
        node[i].resize(size - 1);
        for (int j = 0; j < size - 1; j++)
        node[i][j] = Neighbor(&nodeArr[1], 0);
    }

//................* read neighbors from file *...............

    for (int i = 0; graphFile >> neighbor; i++)
    {
        node[i].resize(size - 1);
        for (int j = 0; neighbor != '/'; j++)
        {
            graphFile >> weight;
            for (int k = 0; k < size; k++)
            {
                if (nodeArr[k].getName() == neighbor)
                {
                    node[i][j].setNeighbor(&nodeArr[k], weight);
                    break;
                }
            }

            graphFile >> neighbor;
        }
        cout << "\n";
    }

//..............* check the shape of nodes and draw them *...................

    for (int  i = 0;  i < size;  i++)
    {

        if(nodeArr[i].getColor() == 'y')
             painter.setPen(Qt::darkYellow);
        else if(nodeArr[i].getColor() == 'r')
             painter.setPen(Qt::red);
        else if(nodeArr[i].getColor() == 'b')
             painter.setPen(Qt::blue);

       // color = checkColor(nodeArr,i);
        if (nodeArr[i].getType() == 0)
        {
            Triangle *triangle = static_cast<Triangle *>(shape);
            triangle->set_triangle(nodeArr[i].getX(), nodeArr[i].getY());
            //make a Qt triangle with color::::::::::::::::::::::::::::::::::::::::::::

            painter.drawLine(triangle->getX(), triangle->getY(), triangle->getX()-20, triangle->getY()+30);
            painter.drawLine(triangle->getX(), triangle->getY(), triangle->getX()+20, triangle->getY()+30);
            painter.drawLine(triangle->getX()-20, triangle->getY()+30,triangle->getX()+20, triangle->getY()+30);

        }

        else
        {
            Circle *circle = static_cast<Circle *>(shape);
            circle->set_circle(nodeArr[i].getX(), nodeArr[i].getY(), 2);
            //make a Qt circle with color:::::::::::::::::::::::::::::::::::::::::::::::

            painter.drawEllipse( circle->getX()-20, circle->getY()-20, 40, 40 );



        }
    }

//............* find relation bittwin nodes and draw edges *.............

    for (int  i = 0; i < size;  i++)
    {
        for (int  j = 0; node[i][j].getName() != '/' && j < (size - 1);  j++)
        {
   //////////////////////         cout << node[i][j].getName() <<"\t";
            for (int k = i; k < size; k++)
            {
                if (nodeArr[k].getName() == node[i][j].getName())
                {
                    //draw a line x1 = nodeArr[k].getX() y1 = nodeArr[k].getY() ## x2 = nodeArr[j].getX() y2 = nodeArr[j].getY()
                    painter.drawLine(nodeArr[k].getX(), nodeArr[k].getY(), nodeArr[j].getX(), nodeArr[j].getY());
                    painter.setPen(Qt::black);

                    //dar mokhtasat x = (x1 + x2)/2 ## y = (y1 + y2)/2  : cout << node[i][j].getWeight();
                    break;
                }
            }
        }
  //////////////////////      cout << "\n";
    }








}
MainWindow::~MainWindow()
{
    delete ui;
}


