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
	Triangle(double x, double y) : Shape(x, y){
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
	friend class Naber;
private:
	char name;
	bool type;
	string color;

public:
	Node( char name,bool type, string color)
	{
		this -> type = type;
		this -> name = name;
		this -> color = color;
	}

	Node()
	{
	}

	void setFirstNode(char name, bool type, string color)
	{
		this -> name = name;
		this -> type = type;
		this -> color = color;
	}

	void firstPrint ()
	{
		cout << name << "\t" <<  type << "\t" << color << "\n";
	}

};

class Naber
{
private:
	Node *node;
	int weight;

public:
	Naber(Node *node, int weight)
	{
		this -> node = new Node(node->name, node->type, node->color);
		this -> weight = weight;
	}


};

int main()
{
	char name;
	char naber;
	bool type;
	string color;
	int weight;
	int ptr;

	Triangle tri(0, 0);
	Circle cir(0, 0, 0);

	const int size = 6;
	Node nodeArr[size];

	vector <vector <Node *>> node;
	Node *n;
	n = new Node(' ', false, 0);
	vector <Node *> node2;
	vector <Node *> node3;
	vector <Node *> node4;
	vector <Node *> node5;
	vector <Node *> node6;

	ifstream graphFile("graph.txt" , ios::in);

	if (!graphFile) 
	{
		cerr << "file not opened!!" << endl;
		//exit(1);
	}

	for (int i = 0; graphFile >> name >> type >> color; i++)
	{
		//node.push_back(n);
		//node[i]->setFirstNode(name,  type, color);
		//node[i]->firstPrint();
		if (i==5)
			break;
	}

	for (int i = 0; graphFile >> naber >> weight; i++)
	{
		//node.push_back(n);
		//node[i]->setSecondNode(naber, weight);
		//node[i]->secondPrint();
		graphFile >> naber;
		if (naber != '/')
		{
			i--;
			ptr = graphFile.tellg();
			graphFile.seekg(ptr-1);
		}

		else
		{
			cout << "\n";
		}
	}

	system ("PAUSE");
	return 0;
}
