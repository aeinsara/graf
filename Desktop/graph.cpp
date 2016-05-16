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

class Nod
{
private:
	bool type;
	char name;
	Nod *otherNod;
	int weight;
	string color;

public:
	Nod(bool type, char name, Nod *otherNod, int weight, string color)
	{
		this -> type = type;
		this -> name = name;
		this -> otherNod = otherNod;
		this -> weight = weight;
		this -> color = color;
	}

	void setFirstNod(bool type, char name, string color)
	{
		this -> type = type;
		this -> name = name;
		this -> color = color;
	}

	void setSecondNod( Nod *otherNod, int weight)
	{
		this -> otherNod = otherNod;
		this -> weight = weight;
	}


};

class LinkedList
{
private:
	Nod *nod;

public:
	LinkedList()
	{
	//	this -> 
	}


};

int main()
{
	char name;
	bool type;
	string color;
	char otherNod;
	int weight;

	Triangle tri(0, 0);
	Circle cir(0, 0, 0);

	vector <Nod *> nod;
	Nod *n;
	vector <Nod *> nod2;
	vector <Nod *> nod3;
	vector <Nod *> nod4;
	vector <Nod *> nod5;
	vector <Nod *> nod6;

//	nod[1];

	ifstream graphFile("graph.txt" , ios::in);

	if (!graphFile) 
	{
		cerr << "file not opened!!!" << endl;
		//exit(1);
	}

	for (int i = 0; graphFile >> name >> type >> color; i++)
	{
		nod.push_back(n);
		//nod[i]->setFirstNod(name,  type, color);
		cout << name << "\t" <<  type << "\t" << color << "\n";
		break;
	}

	system ("PAUSE");
	return 0;
}