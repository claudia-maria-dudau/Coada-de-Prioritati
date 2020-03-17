#pragma once
#include "Node.h"
#include <fstream>
#include <iostream>
using namespace std;

class PQueue {
	int size;
	Node* start;
	int getValElem(int); // obtinere valoarea elementului de pe pozitia i
	int getPrEl(int); //obtinere prioritatea elementului de pe pozitia i

public:
	PQueue(); //constructor fara parametrii
	PQueue(int, int); //constructor cu parametrii
	PQueue(PQueue& pq); //constructor de copiere
	~PQueue(); //destrcutor
	void push(int, int); //adaugare element
	void pop(int); //eliminare element
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