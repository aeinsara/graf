#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <iostream>
#include <QPainter>
#include<QFile>
#include <QTextStream>
#include <QString>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //ui->numberH->setR
    QPalette palette(MainWindow::palette());
    palette.setColor(backgroundRole(), Qt::white);
    setPalette(palette);
}
void MainWindow::paintEvent(QPaintEvent *)
{           string num;
            int k=0;
    ifstream file("data.txt");
        if (file == NULL)
            std::cout << "file not found" << endl;
        else
        {

           file >> num;
        }
       if(num == "2")
           k=2;
    int count = 20;
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    //painter.drawEllipse();
    painter.setPen(Qt::darkGray);
       painter.setPen(Qt::darkGreen);
       // painter.drawRect(count, count+8, 30, 30);
       // painter.drawEllipse(40,50,60);*/
       for(int i=0 ; i<k ;i++)
       {
            painter.drawEllipse( count, 10, 40, 40 );
            count+=30;
       }
        //painter.setPen(QPen(Qt::black));
        painter.drawLine(10, 10, 50, 10);
        painter.drawLine(10, 10, 30, 38);
        painter.drawLine(50, 10, 30, 38);


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()
{
    writefile();
}
void MainWindow::writefile()
{
    QString str = ui->lineEdit->text();
    QString filename = "data.txt";
    QFile file(filename);
    file.open(QIODevice::WriteOnly|QIODevice::Text);
    QTextStream out (&file);
    out<<str<<endl;
}


















