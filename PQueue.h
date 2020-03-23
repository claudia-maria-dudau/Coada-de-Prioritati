#pragma once
#include <fstream>
using namespace std;

class PQueue {
	int capacity, size;
	struct valPr {
		int val, pr;
	}* v;
	
public:
	PQueue();                                               //constructor fara parametri
	PQueue(int, int);                                       //constructor cu parametri
	PQueue(const PQueue& pq);								//constructor de copiere
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

	friend class Test;
};