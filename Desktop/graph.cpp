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
private:
	bool type;
	char name;
	char naber;
	Node *otherNod;
	int weight;
	string color;

public:
	Node( char name,bool type, int weight, string color)
	{
		this -> type = type;
		this -> name = name;
		//this -> otherNod = otherNod;
		this -> weight = weight;
		this -> color = color;
	}

	void setFirstNod(char name1, bool type, string color)
	{
		this -> name = name1;
		this -> type = type;
		this -> color = color;
	}

	void setSecondNod(char naber, int weight)
	{
		this -> naber = naber;
		this -> weight = weight;
	}

	void firstPrint ()
	{
		cout << name << "\t" <<  type << "\t" << color << "\n";
	}

	void secondPrint ()
	{
		cout << naber << "\t" << weight << "\t";
	}

};

class LinkedList
{
private:
	Node *nod;

public:
	LinkedList()
	{
	//	this -> 
	}


};

int main()
{
	char name;
	char naber;
	bool type;
	string color;
	int weight;
	int a;

	Triangle tri(0, 0);
	Circle cir(0, 0, 0);

	vector <Node *> nod;
	Node *n;
	n = new Node(' ', false, 0, " ");
	vector <Node *> nod2;
	vector <Node *> nod3;
	vector <Node *> nod4;
	vector <Node *> nod5;
	vector <Node *> nod6;

//	nod[1];

	ifstream graphFile("graph.txt" , ios::in);

	if (!graphFile) 
	{
		cerr << "file not opened!!" << endl;
		//exit(1);
	}

	for (int i = 0; graphFile >> name >> type >> color; i++)
	{
		nod.push_back(n);
		nod[i]->setFirstNod(name,  type, color);
		nod[i]->firstPrint();
		if (i==5)
			break;
	}

	for (int i = 0; graphFile >> naber >> weight; i++)
	{
		nod.push_back(n);
		nod[i]->setSecondNod(naber, weight);
		nod[i]->secondPrint();
		graphFile >> naber;
		if (naber != '/')
		{
			i--;
			a = graphFile.tellg();
			graphFile.seekg(a-1);
		}

		else
		{
			//graphFile.ignore(1);
			cout << "\n";
			//graphFile.seekg(a+1);
		}
	}

	return 0;
}
