#pragma once
#include "Node.h"
#include <fstream>
using namespace std;

class PQueue {
	int size;
	Node* start;
	int getValElem(int) const;								//obtinere valoarea elementului de pe pozitia i
	int getPrEl(int) const;									//obtinere prioritatea elementului de pe pozitia i
	
public:
	PQueue();                                               //constructor fara parametri
	PQueue(int, int);                                       //constructor cu parametri
	PQueue(PQueue& pq);										//constructor de copiere
	~PQueue();												//destrcutor
	void push(int, int);									//adaugare element
	void pop(int i = 0);									//eliminare element
	int getSize() const;									//obtinere numar elemente
	int getMax() const;										//obtinere maxim
	int getPrMax() const;									//obtinere prioritatea maxima
	int getPrMin() const;									//obtinere prioritatea minima
	PQueue& operator =(const PQueue&);					    //supraincarcare operator =
	PQueue operator +(const PQueue&);						//supraincarcare operator +
	PQueue& operator ++();									//supraincarcare operator ++
	PQueue& operator --();									//supraincarcare operator --
	friend ostream& operator <<(ostream&, const PQueue&);	//supraincarcare operator << (afisare)
	friend istream& operator >>(istream&, PQueue&);			//supraincarcarea operatorului >> (citire)
};