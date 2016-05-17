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
//	friend void operator=(Naber&, Naber&);

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
	
	char get_name()
	{
		return name;
	}
	
	bool get_type()
	{
		return type;
	}
	
	string get_color()
	{
		return color;
	}

	void firstPrint ()
	{
		cout << name << "\t" <<  type << "\t" << color << "\n";
	}

};

class Naber
{
// friend void operator=(Naber&, Naber&);
private:
	Node *node;
	int weight;

public:
	Naber(Node node, int weight)
	{
		this -> node = new Node(node.name, node.type, node.color);
		this -> weight = weight;
	}
	Naber (){}
	
	void set_node(Node node)
	{
		this->node->setFirstNode(node.get_name(), node.get_type(), node.get_color());
	}


};

void operator=( Naber& N1,Naber& N2)
{
	N1.node->name = N2.node->name;
}

int main()
{
	char name;
	char neighbor;
	bool type;
	string color;
	int weight;
	int ptr;
	int vecCounter = 0, vecCounter2 = 0;

	Triangle tri(0, 0);
	Circle cir(0, 0, 0);

	const int size = 6;
	Node nodeArr[size];
//	nodeArr2<vector<Node *>,size>;

	vector <vector <Naber *> > neighborArr;
	vector <Naber *> neighbors; 
//	Node *n;
//	n = new Node(' ', false, 0);
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
		Node nod(name, type, color) ;
		nodeArr[i] = nod;
		//node.push_back(n);
		//node[i]->setFirstNode(name,  type, color);
		//node[i]->firstPrint();
		if (i==5)
			break;
	}

	for (int i = 0; graphFile >> neighbor >> weight; i++)
	{
		//node.push_back(n);
		//node[i]->setSecondNode(naber, weight);
		//node[i]->secondPrint();
//		graphFile >> neighbor;
		for(int j = 0; j < size; j++)
		{
			if(neighbor == nodeArr[j].get_name())
			{
				Node node1('a',1,"green");
				Naber n;
				n.set_node(node1);
				 
				Naber nbr(nodeArr[j] , (int)weight);
				neighborArr.push_back(neighbors); 
				neighborArr[vecCounter][vecCounter2]->set_node(node1);
				vecCounter2++;
				break;
			}
		}
		if (neighbor != '/')
		{
			i--;
			vecCounter2 = 0;
			vecCounter++;
			ptr = graphFile.tellg();
			graphFile.seekg(ptr-1);
		}

/*		else
		{
			cout << "\n";
		}
	*/	

	}
		for(int i = 0; i < size; i++)
			nodeArr[i].firstPrint();
	return 0;
}
