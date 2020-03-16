#pragma once
class Node {
	int info, pr;
	Node* next;

public:
	Node(int, int); //constructor ce creeaza un nod cu val si prioritatea data
	Node(Node& n); //constructor de copiere
	friend class PQueue;
};
