#include "PQueue.h"
#include <iostream>
#include <fstream>
using namespace std;

ostream& operator <<(ostream& cout, PQueue& pq) { //supraincarcare operator <<
	if (pq.getSize() == 0)
		cout << "Coada vida";
	else
		for (int i = 0; i < pq.getSize(); i++)
			cout << "(" << pq.getValElem(i) << ", " << pq.getPrEl(i) << ")" << " ";
	return cout;
}

istream& operator >>(istream& cin, PQueue& pq) { //supraincarcare operator >>
	int n, val, prior;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> val >> prior;
		pq.push(val, prior);
	}
	return cin;
}

int main()
{
    PQueue p1;
    cin >> p1;
    PQueue p2;
    cin >> p2;
	cout << "Coada 1: " << p1 << endl << "Coada 2: " << p2 << endl;
	PQueue p3;
	cout << "Coada 3: " << p3 << endl;
	PQueue p4(4, 6);
	cout << "Coada 4: " << p4 << endl;
	PQueue p5(p2);
	cout << "Coada 5: " << p5 << endl;
	p4.~PQueue();
	cout << "Coada 4: " << p4 << endl;
	p5.pop();
	cout << "Coada 5: " << p5 << endl;
	p1.pop(2);
	cout << "Coada 1: " << p1 << endl;
	cout << "Lungime coada 2: " << p2.getSize() << endl;
	p1.push(6, 3);
	cout << "Coada 1: " << p1 << endl;
	cout << "Maxim coada 1: " << p1.getMax() << endl;
	p3.push(7, 8);
	p3.push(2, 1);
	cout << "Prioritate maxima coada 3: " << p3.getPrMax() << endl;
	cout << "Prioritate minima coada 3: " << p3.getPrMin() << endl;
	p5 = p4;
	cout << "Coada 5: " << p5 << endl;
	//PQueue p6;
	//p6 = p1 + p3;
	//cout << "Coada 1 + 3: " << p6 << endl;
	cout << "Coada 1++: " << ++p1 << endl;
	p3.push(1, 1);
	cout << "Coada 3: " << p3 << endl;
	cout << "Coada 3--: " << --p3 << endl;
}
