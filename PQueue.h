#pragma once
#include <iostream>
#include "Node.h"
#include "Node.cpp"

class PQueue {
	int size;
	Node* start;
	int getValElem(int i = 0); // obtinere valoarea elementului de pe pozitia i
	int getPrEl(int); //obtinere prioritatea unui element

public:
	PQueue(); //constructor fara parametrii
	PQueue(int, int); //constructor cu parametrii
	PQueue(PQueue& pq); //constructor de copiere
	~PQueue(); //destrcutor
	void push(int, int); //adaugare element
	void pop(int i = 0); //eliminare element
	int getSize(); //obtinere numar elemente
	int getMax(); //obtinere maxim
	int getPrMax(); //obtinere prioritatea maxima
	void operator =(PQueue&); //supraincarcare operator =
	PQueue operator +(PQueue&); //supraincarcare operator +
	void operator ++(); //supraincarcare operator ++
	void operator --(); //supraincarcare operator --
	friend ostream& operator <<(ostream&, PQueue&); //supraincarcare operator << (afisare)
	friend istream& operator >>(istream&, PQueue&); //supraincarcarea operatorului >> (citire)
};