#include "Node.h"
using namespace std;

Node::Node(int x, int p, Node* n) { //constructor fara parametrii
	this->info = x;
	this->pr = p;
	this->next = n;
}

Node::Node(Node& n) { //constructor de copiere
	this->info = info;
	this->pr = pr;
	this->next = next;
}