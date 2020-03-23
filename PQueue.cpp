#include "PQueue.h"
#include <iostream>
#include <exception>
using namespace std;

PQueue::PQueue() : capacity(50), size(0) { //constructor fara parametri
	this->v = new valPr[this->capacity];
}

PQueue::PQueue(int x, int pr) : capacity(50), size(1) { //constructor cu parametri
	this->v = new valPr[this->capacity];
	if (pr <= 0)
		throw invalid_argument("Prioritatea este nula sau negativa");
	this->v[0].val = x;
	this->v[0].pr = pr;
}

PQueue::PQueue(const PQueue& pq) { //constructor de copiere
	*this = pq;
}

PQueue::~PQueue() { //destructor
	if (this->size > 0) {
		delete[] this->v;
		this->size = this->capacity = 0;
	}
}

void PQueue::push(int x, int pr) { //adaugare element
	if (pr <= 0)
		throw invalid_argument("Prioritatea este nula sau negativa");
	if (this->size == this->capacity) {
		this->capacity += 10;
		valPr* aux;
		aux = new valPr[this->capacity];
		for (int i = 0; i < capacity - 10; i++) {
			aux[i].val = this->v[i].val;
			aux[i].pr = this->v[i].pr;
		}
		delete[] this->v;
		this->v = aux;
	}
	int i = this->size;
	this->size++;
	this->v[i].val = x;
	this->v[i].pr = pr;
	while ((i - 1) / 2 >= 0 and this->v[i].pr > this->v[(i - 1) / 2].pr) {
		int auxval = this->v[i].val, auxpr = this->v[i].pr;
		this->v[i].val = this->v[(i - 1) / 2].val;
		this->v[i].pr = this->v[(i - 1) / 2].pr;
		this->v[(i - 1) / 2].val = auxval;
		this->v[(i - 1) / 2].pr = auxpr;
		i = (i - 1) / 2;
	}
}

void PQueue::pop(int i) { //eliminare element
	if (this->size == 0)
		throw underflow_error("Coada este vida");
	if (i < 0 or i >= this->size)
		throw out_of_range("Index out of range");
	this->v[i].val = this->v[this->size - 1].val;
	this->v[i].pr = this->v[this->size - 1].pr;
	this->size--;
	while ((2 * i + 1 < this->size and this->v[i].pr < this->v[2 * i + 1].pr) or (2 * i + 2 < this->size and this->v[i].pr < this->v[2 * i + 2].pr)) {
		if (2 * i + 1 < this->size and 2 * i + 2 < this->size) {
			if (this->v[2 * i + 1].pr > this->v[2 * i + 2].pr) {
				int auxval = this->v[i].val, auxpr = this->v[i].pr;
				this->v[i].val = this->v[2 * i + 1].val;
				this->v[i].pr = this->v[2 * i + 1].pr;
				this->v[2 * i + 1].val = auxval;
				this->v[2 * i + 1].pr = auxpr;
				i = 2 * i + 1;
			}
			else {
				int auxval = this->v[i].val, auxpr = this->v[i].pr;
				this->v[i].val = this->v[2 * i + 2].val;
				this->v[i].pr = this->v[2 * i + 2].pr;
				this->v[2 * i + 2].val = auxval;
				this->v[2 * i + 2].pr = auxpr;
				i = 2 * i + 2;
				}
			}
		else if (2 * i + 1 < this->size) {
			int auxval = this->v[i].val, auxpr = this->v[i].pr;
			this->v[i].val = this->v[2 * i + 1].val;
			this->v[i].pr = this->v[2 * i + 1].pr;
			this->v[2 * i + 1].val = auxval;
			this->v[2 * i + 1].pr = auxpr;
			i = 2 * i + 1;
		}
		else {
			int auxval = this->v[i].val, auxpr = this->v[i].pr;
			this->v[i].val = this->v[2 * i + 2].val;
			this->v[i].pr = this->v[2 * i + 2].pr;
			this->v[2 * i + 2].val = auxval;
			this->v[2 * i + 2].pr = auxpr;
			i = 2 * i + 2;
		}
	}
}

int PQueue::getSize() const { //obtinere numar elemente
	return this->size;
}

int PQueue::getMax() const { //obtinere valoare maxima
	if (this->size == 0)
		throw underflow_error("Coada este vida");
	else {
		int max = this->v[0].val;
		for (int i = 1; i < this->size; i++)
			if (v[i].val > max)
				max = v[i].val;
		return max;
	}
}

int PQueue::getPrMax() const { //obtinere prioritate maxima
	if (this->size == 0)
		throw underflow_error("Coada este vida");
	else
		return this->v[0].pr;
}

int PQueue::getPrMin() const { //obtinere prioritate minima
	if (this->size == 0)
		throw underflow_error("Coada este vida");
	else
		return this->v[this->size - 1].pr;
}

PQueue& PQueue::operator =(const PQueue& pq) { //supraincarcare operator =
	if (this != &pq) {
		this->~PQueue();
		this->capacity = pq.capacity;
		this->size = pq.size;
		this->v = new valPr[this->capacity];
		for (int i = 0; i < pq.size; i++) {
			this->v[i].val = pq.v[i].val;
			this->v[i].pr = pq.v[i].pr;
		}
		return *this;
	}
}

PQueue PQueue::operator +(const PQueue& pq) { //supraincarcare operator +
	PQueue pqNou(*this);
	for (int i = 0; i < pq.size; i++)
		pqNou.push(pq.v[i].val, pq.v[i].pr);
	return pqNou;
}

PQueue& PQueue::operator ++() { //supraincarcare operator ++
	if (this->size == 0)
		throw underflow_error("Coada este vida");
	for (int i = 0; i < this->size; i++)
		this->v[i].pr++;
	return *this;
}

PQueue& PQueue::operator --() { //supraincarcare operator --
	if (this->size == 0)
		throw underflow_error("Coada este vida");
	int i;
	for (i = 0; i < this->size; i++) {
		this->v[i].pr--;
		if (this->v[i].pr == 0)
			break;
	}
	int j = size - 1;
	while (j >= i) {
		this->pop(j);
		j--;
	}
	return *this;
}

ostream& operator <<(ostream& out, const PQueue& pq) { //supraincarcare operator <<
	if (pq.getSize() == 0)
		out << "Coada vida";
	else {
		PQueue aux(pq);
		while (aux.getSize()) {
			out << "(" << aux.v[0].val << ", " << aux.v[0].pr << ")" << " ";
			aux.pop();
		}
	}
	return out;
}

istream& operator >>(istream& in, PQueue& pq) { //supraincarcare operator >>
	int n, val, pr;
	in >> n;
	for (int i = 0; i < n; i++) {
		in >> val >> pr;
		pq.push(val, pr);
	}
	return in;
}