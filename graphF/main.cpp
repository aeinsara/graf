#include "mainwindow.h"
#include <QApplication>
#include <iostream>
#include <fstream>
#include<QFile>
#include <QTextStream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFile file("out.txt");
    file.open(QIODevice::WriteOnly | QIODevice::Text);
     QTextStream out(&file);
    out << "This file is generated by Qt\n";

      // optional, as QFile destructor will already do it:
        file.close();
    MainWindow w;
    w.setFixedSize(600,500);
    w.show();
    //QObject::connect()
    return a.exec();
}
