#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
      void paintEvent(QPaintEvent *);

private slots:
      //void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
};


class Shape{
protected:
    double x;
    double y;
public:
    Shape(double x, double y){
        this->x = x;
        this->y = y;
    }
};

class Triangle : public Shape{
private:

public:
    Triangle(double x, double y) : Shape(x, y){}

    void set_triangle(double x, double y){
        this->x = x;
        this->y = y;
    }

    double getX(){
        return x;
    }

    double getY(){
        return y;
    }
};

class Circle : public Shape{
private:
    double r;
public:
    Circle(double x, double y, double r) : Shape(x, y)
    {
        this->r = r;
    }

    void set_circle(double x, double y, double r){
        this->x = x;
        this->y = y;
        this->r = r;
    }

    double getX(){
        return x;
    }

    double getY(){
        return y;
    }

    double getR(){
        return r;
    }
};

class Node
{
    friend class Neighbor;
private:
    char name;
    bool type;
    std::string color;
    double x;
    double y;

public:
    Node(char name,bool type, std::string color)
    {
        this -> type = type;
        this -> name = name;
        this -> color = color;
    }

    Node(){}

    void setNode(char name, bool type, std::string color, double x, double y)//......................
    {
        this -> name = name;
        this -> type = type;
        this -> color = color;
        this -> x = x;//......
        this -> y = y;//..........

    }

    char getName()
    {
        return name;
    }

    bool getType()
    {
        return type;
    }

    std::string getColor()
    {
        return color;
    }

    double getX()//.......
    {
        return x;
    }

    double getY()//.........
    {
        return y;
    }


};

class Neighbor
{
private:
    Node *node;
    int weight;

public:
    Neighbor(Node *node, int weight)
    {
        this -> node = new Node('/', node->type, node->color);
        this -> weight = weight;
    }

    Neighbor(){}

    void setNeighbor(Node *node, int weight)
    {
        this -> node->name = node->name;
        this -> node->type = node->type;
        this -> node->color = node->color;
        this -> weight = weight;
    }

    char getName()
    {
        //cout << node->name << "*\t";
        return node->name;
    }

    int getWeight()//...............................
    {
        return weight;
    }

    void setName(char name)
    {
        node -> name = name;
    }


};



#endif // MAINWINDOW_H
