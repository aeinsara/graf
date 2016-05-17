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
		cout << node->name << "\t" <<  weight << "\n";
	}

};

int main()
{
	char name;
	char neighbor;
	bool type;
	string color;
	int weight = 3;
	int ptr;
	int k;

	Triangle tri(0, 0);
	Circle cir(0, 0, 0);

	const int size = 6;
	Node nodeArr[size];
	Node *nab;

	vector <vector <Neighbor >> node;
	vector <Neighbor >;
	Neighbor *n;
	n = new Neighbor;
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

	//node.resize(size);

	for (int i = 0; graphFile >> name >> type >> color; i++)
	{
		/*node[i].resize(size);
		node[i].push_back(neighbors);
		neighbors.push_back(nab);

		
		for(int i = 0 ; i < m ; ++i)
		{
    		//Grow Columns by n
    		a[i].resize(n);
		}
		*/
		nodeArr[i] = Node(' ', true, " ");
		nodeArr[i].setNode(name, type, color);
		nodeArr[i].nodePrint();
	
		//node[0][i]->setFirstNode(name, type, color);
		//node[0][i]->firstPrint();
		//node[i]->setFirstNode(name,  type, color);
		//node[i]->firstPrint();
		if (i == 5)
			break;
	}

	node.resize(size);

//.........................................................	

	for (int i = 0; graphFile >> neighbor; i++)
	{	
		node[i].resize(size);
		//graphFile >> naber;
		//graphFile >> neighbor >> weight;

		for (int j = 0; neighbor != '/'; j++)
		{
			graphFile.seekg(-1);
			graphFile >> neighbor >> weight;
		
			node[i][j] = Neighbor(&nodeArr[1], weight);
			//cout << weight << endl;
			for (k = 0; k < size; k++)
			{
				if (nodeArr[k].getName() == neighbor)
				{
					node[i][j].setNeighbor(&nodeArr[k], weight);

					break;
				}
			}
			
			node[i][j].neighborPrint();
			//node[i]->secondPrint();

			graphFile >> neighbor;
		}

		cout << "\n";
/*
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
*/
	}

	system ("PAUSE");
	return 0;
}
