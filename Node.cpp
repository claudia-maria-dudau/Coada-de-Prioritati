#include "Node.h"
using namespace std;

Node::Node(int x, int p) { //constructor fara parametrii
	this->info = x;
	this->pr = p;
	this->next = nullptr;
}

Node::Node(Node& n) { //constructor de copiere
	this->info = info;
	this->pr = pr;
	this->next = next;
}