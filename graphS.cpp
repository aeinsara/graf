#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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
	Triangle(double x, double y) : Shape(x, y)
	{
	}
};

class Circle : public Shape{
private:
	double r;
public:
	Circle(double x, double y, double r) : Shape(x, y){
		this->r = r;
	}

	void set_cir(double x, double y, double r){
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

public:
	Node(char name,bool type, string color)
	{
		this -> type = type;
		this -> name = name;
		this -> color = color;
	}

	Node()
	{
	}

	void setNode(char name, bool type, string color)
	{
		this -> name = name;
		this -> type = type;
		this -> color = color;
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



};

class Neighbor
{
private:
	Node *node;
	int weight;

public:
	Neighbor(Node *node, int weight)
	{
		this -> node = new Node(node->name, node->type, node->color);
		this -> weight = weight;
	}

	Neighbor()
	{
	}

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
	int weight = 3;
	int ptr;

	const int size = 6;
	Node nodeArr[size];
	Node *nab;

	vector <vector <Neighbor >> node;
	vector <Neighbor >;
	Neighbor *n;
	n = new Neighbor;

	ifstream graphFile("graph.txt" , ios::in);

	if (!graphFile) 
	{
		cerr << "file not opened!!" << endl;
	}


	for (int i = 0; graphFile >> name >> type >> color; i++)
	{
		nodeArr[i] = Node(' ', true, " ");
		nodeArr[i].setNode(name, type, color);
		nodeArr[i].nodePrint();
		
		if (i == 5)
			break;
	}

	node.resize(size);

	for (int i = 0; graphFile >> neighbor; i++)
	{	
		node[i].resize(size-1);

		for (int j = 0; neighbor != '/'; j++)
		{
			graphFile >> weight;
		
			node[i][j] = Neighbor(&nodeArr[1], weight);
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

	for (int  i = 0;  i < size;  i++)
	{
		color= checkColor(nodeArr,i);
		if (nodeArr[i].getType() == 0)
		{
			Triangle tri( i * 5 + 5 , i);
			//make a Qt triangle
		}

		else
		{
			Circle cir( i * 5 + 5 , i, 2);
			//make a Qt circle
		}

		cout << "color : " << color << "\t";
	}

	for (int  i = 0;  i < size;  i++)
	{
		for (int  j = 0;  j < size;  j++)
		{

		}
	}

	system ("PAUSE");
	return 0;
}
