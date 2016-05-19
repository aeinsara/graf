#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <ctime>

using namespace std;


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
};

class Node
{
	friend class Neighbor;
private:
	char name;
	bool type;
	string color;
	double x;
	double y;

public:
	Node(char name,bool type, string color)
	{
		this -> type = type;
		this -> name = name;
		this -> color = color;
	}

	Node(){}

	void setNode(char name, bool type, string color, double x, double y)//......................
	{
		this -> name = name;
		this -> type = type;
		this -> color = color;
		this -> x = x;//......
		this -> y = y;//..........

	}

	void nodePrint ()
	{
		cout << name << "\t" <<  type << "\t" << color << "\n";
	}

	char getName()
	{
		return name;
	}

	bool getType()
	{
		return type;
	}

	string getColor()
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

	void neighborPrint ()
	{
		cout << node->name << "\t" <<  weight << "\t";
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

string checkColor(Node *nodeArr, int i)
{ 
			if (nodeArr[i].getColor() ==  "blue")
				return "blue";
			else if (nodeArr[i].getColor() ==  "red")
				return "red";
			else if (nodeArr[i].getColor() ==  "yellow")
				return "yellow";
}

int main()
{
	char name;
	char neighbor;
	bool type;
	string color;
	int weight;
	Shape *shape;
	shape = new Shape(0, 0);
	
	const int size = 6;
	Node nodeArr[size];

	vector <vector <Neighbor >> node;
	vector <Neighbor >;

	 srand(time(0));

	ifstream graphFile("graph.txt" , ios::in);

	if (!graphFile) 
	{
		cerr << "file not opened!!" << endl;
	}

//...............* read feature of nodes from file *......................

	for (int i = 0; graphFile >> name >> type >> color; i++)
	{
		nodeArr[i] = Node(' ', true, " ");
		nodeArr[i].setNode(name, type, color, rand() % 100 + 20, rand() % 100 + 20);
		nodeArr[i].nodePrint();

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
			
			node[i][j].neighborPrint();

			graphFile >> neighbor;
		}
		cout << "\n";
	}

//..............* check the shape of nodes and draw them *...................

	for (int  i = 0;  i < size;  i++)
	{
		color = checkColor(nodeArr,i);
		if (nodeArr[i].getType() == 0)
		{
			Triangle *triangle = static_cast<Triangle *>(shape);
			triangle->set_triangle(nodeArr[i].getX(), nodeArr[i].getY());
			//make a Qt triangle with color
		}

		else
		{
			Circle *circle = static_cast<Circle *>(shape);
			circle->set_circle(nodeArr[i].getX(), nodeArr[i].getY(), 2);
			//make a Qt circle with color
		}
	}

//............* find relation bittwin nodes and draw edges *.............

	for (int  i = 0; i < size;  i++)
	{
		for (int  j = 0; node[i][j].getName() != '/' && j < (size - 1);  j++)
		{
			cout << node[i][j].getName() <<"\t";
			for (int k = i; k < size; k++)
			{
				if (nodeArr[k].getName() == node[i][j].getName())
				{
					//draw a line x1 = nodeArr[k].getX() y1 = nodeArr[k].getY() ## x2 = nodeArr[j].getX() y2 = nodeArr[j].getY()
					//dar mokhtasat x = (x1 + x2)/2 ## y = (y1 + y2)/2  : cout << node[i][j].getWeight();
					break;
				}
			}
		}
		cout << "\n";
	}

	system ("PAUSE");
	return 0;
}
