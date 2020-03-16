#include "Node.h"
using namespace std;

Node::Node() { //constructor fara parametrii
	this->info = this->pr = 0;
	this->next = nullptr;
}

Node::Node(int x, int p, Node* n) { //constructor fara parametrii
	this->info = x;
	this->pr = p;
	this->next = n;
}
