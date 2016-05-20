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

    int count = 20;
    int x, y;
    int aryx[6], aryy[6];
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    QTime time = QTime::currentTime();
    qsrand((uint)time.msec());

    ifstream file("/home/aeinsara/23.txt");

    if (file == NULL)
        std::cout << "file not found" << endl;

    else
        {
        string name, name1;
                string color, color1;
                string shape,shape1[6],shape2[6];
                for(int i=0;i<6;i++){
                file >> name >> color >> shape;

               // cout << name<<color<<shape<<endl;

                name1 = name;
                color1 = color;
                shape1[i] = shape;
                shape2[i]  = shape;
                x = qrand() % 400 + 20;
                y = qrand() % 400 + 20;
                qDebug()<<x<<"   "<<y;

                int m ,n;
                if(color1 == "g")
                     painter.setPen(Qt::darkGreen);
                if(color1 == "r")
                     painter.setPen(Qt::darkRed);
                if(color1 == "b")
                     painter.setPen(Qt::darkBlue);
                if(shape1[i] == "cir")
                     painter.drawEllipse( x, y, 40, 40 );
                if(shape1[i] == "tri")
                {
                    painter.drawLine(x, y, x-20, y+30);
                    painter.drawLine(x, y, x+20, y+30);
                    painter.drawLine(x-20, y+30,x+20, y+30);
                }
                n = y;
                m = x;
                aryx[i] = m;
                aryy[i] = n;
                }
                int ary[6][6];
                for(int i=0 ;i<6;i++)
                {
                    for(int j=0 ;j<6 ;j++)
                    {
                         file >> ary[i][j];
                        int k = ary[i][j];
                        if(j > i)
                        {
                           if(k == 1)
                           {
                               qDebug() << aryx[i] << "    " << aryy[i];
                               painter.drawLine(aryx[i]+20, aryy[i]+20, aryx[j]+20, aryy[j]+20);
                            }
                        }

                        if(j <= i)
                            continue;
                    }
                }
                file.close();
        }

   // painter.drawEllipse(99, 27,40,40);
}

MainWindow::~MainWindow()
{
    delete ui;
}



/*void MainWindow::on_pushButton_clicked()
{
    writefile();
}*/
/*void MainWindow::writefile()
{
    QString str = ui->lineEdit->text();;
    QString filename = "data.txt";
    QFile file(filename);
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream out (&file);
    out<<str<<endl;
}*/

