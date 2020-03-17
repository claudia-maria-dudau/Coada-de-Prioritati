#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(int x, int p): info(x), pr(p), next(NULL) { //constructor fara parametrii
}

Node::Node(Node& n) { //constructor de copiere
	this->info = info;
	this->pr = pr;
	this->next = next;
}