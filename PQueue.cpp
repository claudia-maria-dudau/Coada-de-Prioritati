#include "PQueue.h"
using namespace std;

int PQueue::getValElem(int i = 0) { //obtinere valoarea elementului d pe pozitia i
	Node* p = this->start;
	for (int j = 0; j < i; j++)
		p = p->next;
	return p->info;
}

int PQueue::getPrEl(int i = 0) { //obtinere prioritatea elementului de pe pozitia i
	Node* p = this->start;
	for (int j = 0; j < i; j++)
		p = p->next;
	return p->pr;

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
	this->size = pq.size;
	Node* q = pq.start;
	this->start = new Node(q->info, q->pr);
	Node* p = this->start;
	while(q->next){
		q = q->next;
		p->next = new Node(q->info, q->pr);
		p = p->next;
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

void PQueue::operator =(PQueue& pq) { //supraincarcare operator =
	this->~PQueue();
	this->size = pq.size;
	this->start = pq.start;
}

PQueue PQueue::operator +(PQueue& pq) { //supraincarcare operator +
	PQueue pqNou;
	Node* p = this->start;
	while (p) {
		pqNou.push(p->info, p->pr);
		p = p->next;
	}
	p = pq.start;
	while (p) {
		pqNou.push(p->info, p->pr);
		p = p->next;
	}
	return pqNou;
	pqNou.size = this->size + pq.size;
}

void PQueue::operator ++() { //supraincarcare operator ++
	Node* p = this->start;
	while (p) {
		p->pr++;
		p = p->next;
	}
}

void PQueue::operator --() { //supraincarcare operator --
	Node* p = this->start;
	int poz = 0;
	while (p) {
		p->pr--;
		if (p->pr == 0)
			pop(poz);
		p = p->next;
		poz++;
	}
}

ostream& operator <<(ostream&, PQueue& pq) { //supraincarcare operator <<
	for (int i = 0; i < pq.getSize; i++)
		cout << "(" << pq.getValElem(i) << ", " << pq.getPrEl(i) << ")" << endl;
}

ostream& operator >>(ostream&, PQueue& pq) { //supraincarcare operator >>
	int val, prior;
	while (cin >> val >> prior)
		pq.push(val, prior);
}
