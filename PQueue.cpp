#include "PQueue.h"
using namespace std;

int PQueue::getValElem(int i = 0) { //obtinere valoarea elementului d pe pozitia i
	Node* p = start;
	for (int j = 0; j < i; j++)
		p = p->next;
	return p->info;
}

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

PQueue::PQueue(PQueue& pq) { //constructor de copiere
	this->size = pq.getSize();
	this->start = new Node(pq.getElem(), pq.getPrMax());
	Node* p;
	p = this->start;
	for (int i = 1; i < size; i++) {
		p->next = new Node(pq.getElem(i), pq.getPrEl(pq.getElem(i)));
		start = p->next;
	}
}

PQueue::~PQueue() { //destructor
	this->size = 0;
	Node* p = this->start;
	while (p) {
		Node* q = p->next;
		delete p;
		p = q;
	}
}

void PQueue::push(int x, int pr) { //adaugare element
	Node* p = this->start;
	while (p->next->pr > pr)
		p = p->next;
	Node* q = new Node(x, pr);
	q->next = p->next;
	p->next = q;
	this->size++;
}

void PQueue::pop(int i = 0) { //eliminare element
	if (this->size == 0) {
		cout << "Coada vida"; //exceptie dc reusesc
		return;
	}
	else {
		Node* p = this->start;
		for (int j = 1; j < i; j++)
			p = p->next;
		Node* q = p->next;
		p->next = q->next;
		delete q;
	}
	this->size--;
}

int PQueue::getSize() { //obtinere numar elemente
	return this->size;
}

int PQueue::getMax() { //obtinere valoare maxima
	Node* p = this->start;
	int max = p->info;
	while (p) {
		if (p->info > max)
			max = p->info;
		p = p->next;
	}
	return max;
}

int PQueue::getPrMax() { //obtinere prioritate maxima
	return start->pr;
}

