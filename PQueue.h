#pragma once
#include "Node.h"
#include <fstream>
using namespace std;

class PQueue {
	int size;
	Node* start;
	int getValElem(int);									//obtinere valoarea elementului de pe pozitia i MERGE
	int getPrEl(int);										//obtinere prioritatea elementului de pe pozitia i MERGE

public:
	PQueue();                                               //constructor fara parametri MERGE
	PQueue(int, int);                                       //constructor cu parametri MERGE
	PQueue(PQueue& pq);										//constructor de copiere MERGE
	~PQueue();												//destrcutor MERGE
	void push(int, int);									//adaugare element	MERGE
	void pop(int i = 0);									//eliminare element MERGE
	int getSize();											//obtinere numar elemente MERGE
	int getMax();											//obtinere maxim MERGE
	int getPrMax();											//obtinere prioritatea maxima MERGE
	int getPrMin();											//obtinere prioritatea minima MERGE
	PQueue& operator =(const PQueue&);					    //supraincarcare operator = MERGE
	PQueue& operator +(const PQueue&);						//supraincarcare operator +
	PQueue& operator ++();									//supraincarcare operator ++ MERGE
	PQueue& operator --();									//supraincarcare operator -- MERGE
	friend ostream& operator <<(ostream&, PQueue&);			//supraincarcare operator << (afisare) MERGE
	friend istream& operator >>(istream&, PQueue&);			//supraincarcarea operatorului >> (citire) MERGE
};