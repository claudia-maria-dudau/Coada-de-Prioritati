#include "PQueue.h"
using namespace std;

PQueue::PQueue() { //constructor fara parametrii
	this->size = 0;
	this->start = nullptr;
}

PQueue::PQueue(int x, int pr) { //constructor cu parametrii
	if (this->size == 0)
		this->start = new Node(x, pr);
	else {
		Node* p;
		p = this->start;
		while (p->next != nullptr)
			p = p->next;
		p->next = new Node(x, pr);
	}
	this->size++;
}

