#include "PQueue.h"
#include "Node.h"
#include <iostream>
using namespace std;

int PQueue::getValElem(int i = 0) const { //obtinere valoarea elementului d pe pozitia i
	Node* p = this->start;
	for (int j = 0; j < i; j++)
		p = p->next;
	return p->info;
}

int PQueue::getPrEl(int i = 0) const {//obtinere prioritatea elementului de pe pozitia i
	Node* p = this->start;
	for (int j = 0; j < i; j++)
		p = p->next;
	return p->pr;

}

PQueue::PQueue(): size(0), start(NULL){ //constructor fara parametri
}

PQueue::PQueue(int x, int pr): size(1) { //constructor cu parametri
	this->start = new Node(x, pr);
}

PQueue::PQueue(PQueue& pq) { //constructor de copiere
	*this = pq;
}

PQueue::~PQueue() { //destructor
	if (size > 0) {
		Node* p = this->start;
		while (p->next != NULL) {
			Node* q = p->next;
			delete p;
			p = q;
		}
		delete p;
		this->size = 0;
		this->start = NULL;
	}
}

void PQueue::push(int x, int pr) { //adaugare element
	Node* q = new Node(x, pr);
	if (this->size == 0)
		start = q;
	else {
		Node* p = this->start;
		if (pr > p->pr) {
			q->next = p;
			start = q;
		}
		else {
			while (p->next and p->next->pr > pr)
				p = p->next;
			q->next = p->next;
			p->next = q;
		}
	}
	this->size++;
}

void PQueue::pop(int i) { //eliminare element
	if (this->size == 0) {
		cout << "Coada vida";
		return;
	}
	if (i < 0 or i >= size) {
		cout << "Index out of range";
		return;
	}
	if (i == 0) {
		Node* p = this->start;
		this->start = this->start->next;
		delete p;
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

int PQueue::getSize() const { //obtinere numar elemente
	return this->size;
}

int PQueue::getMax() const { //obtinere valoare maxima
	if (this->size == 0)
		cout << "Coada este vida";
	else {
		Node* p = this->start;
		int max = p->info;
		while (p) {
			if (p->info > max)
				max = p->info;
			p = p->next;
		}
		return max;
	}
}

int PQueue::getPrMax() const { //obtinere prioritate maxima
	if (this->size == 0)
		cout << "Coada este vida";
	else
		return start->pr;
}

int PQueue::getPrMin() const { //obtinere prioritate minima
	if (this->size == 0)
		cout << "Coada este vida";
	else {
		Node* p = start;
		while (p->next)
			p = p->next;
		return p->pr;
		}
}

PQueue& PQueue::operator =(const PQueue& pq) { //supraincarcare operator =
	if (this != &pq) {
		this->~PQueue();
		this->size = pq.size;
		Node* q = pq.start;
		this->start = new Node(q->info, q->pr);
		Node* p = this->start;
		while (q->next) {
			q = q->next;
			p->next = new Node(q->info, q->pr);
			p = p->next;
		}
		return *this;
	}
}

PQueue PQueue::operator +(const PQueue& pq) { //supraincarcare operator +
	PQueue pqNou(*this);
	Node* p = pq.start;
	while (p) {
		pqNou.push(p->info, p->pr);
		p = p->next;
	}
	return pqNou;
}

PQueue& PQueue::operator ++() { //supraincarcare operator ++
	Node* p = this->start;
	while (p) {
		p->pr++;
		p = p->next;
	}
	return *this;
}

PQueue& PQueue::operator --() { //supraincarcare operator --
	Node* p = this->start;
	for(int i = 0; i< size; i++) {
		p->pr--;
		if (p->pr == 0)
			pop(i);
		p = p->next;
	}
	return *this;
}
