#include "Test.h"
#include <iostream>
#include <cassert>
using namespace std;

void Test::test_PQueue() {
	//constructor fara parametrii
	PQueue p1;
	assert(p1.size == 0);

	//constructor cu parametrii
	try {
		PQueue p2(4, 8);
		assert(p2.size == 1 and p2.v[0].val == 4 and p2.v[0].pr == 8);
	}
	catch (invalid_argument) {
		assert(false);
	}

	//constructor de copiere
	PQueue p2(4, 8);
	PQueue p5(p2);
	assert(p5.size == p2.size and p5.v[0].val == p2.v[0].val and p5.v[0].pr == p2.v[0].pr);

	//destructor
	p5.~PQueue();
	assert(p5.size == 0 and p5.capacity == 0);

	//adaugare element
	PQueue p3;
	try {
		p1.push(6, 3);
		assert(p1.size == 1 and p1.v[0].val == 6 and p1.v[0].pr == 3);
		p2.push(3, 6);
		assert(p2.size == 2);
		assert(p2.v[0].val == 4 and p2.v[0].pr == 8);
		assert(p2.v[1].val == 3 and p2.v[1].pr == 6);
		p3.push(4, 5);
		p3.push(3, 7);
		p3.push(5, 3);
		assert(p3.size == 3);
		assert(p3.v[0].val == 3 and p3.v[0].pr == 7);
		assert(p3.v[1].val == 4 and p3.v[1].pr == 5);
		assert(p3.v[2].val == 5 and p3.v[2].pr == 3);
	}
	catch (invalid_argument) {
		assert(false);
	}

	//eliminare element
	try {
		p1.pop();
		assert(p1.size == 0);
		p3.pop(1);
		assert(p3.size == 2);
		assert(p3.v[0].val == 3 and p3.v[0].pr == 7);
		assert(p3.v[1].val == 5 and p3.v[1].pr == 3);
	}
	catch (underflow_error) {
		assert(false);
	}
	catch (out_of_range) {
		assert(false);
	}

	//obtinere dimensiune
	assert(p1.getSize() == p1.size);

	//obtinere maxim
	try {
		p1.push(9, 7);
		assert(p1.getMax() == 9);
	}
	catch (underflow_error) {
		assert(false);
	}

	//obtinere prioritate maxima
	try {
		p2.push(7, 8);
		assert(p2.getPrMax() == 8 and p2.getPrMax() == p2.v[0].pr);
	}
	catch (underflow_error) {
		assert(false);
	}

	//obtinere prioritate minima
	try {
		p3.push(2, 1);
		assert(p3.getPrMin() == 1 and p3.getPrMin() == p3.v[p3.size - 1].pr);
	}
	catch (underflow_error) {
		assert(false);
	}

	//operator =
	PQueue p4;
	p4 = p2;
	assert(p2.size == p2.size);
	assert(p4.v[0].val == p2.v[0].val and p4.v[0].pr == p2.v[0].pr);
	assert(p4.v[1].val == p2.v[1].val and p4.v[1].pr == p2.v[1].pr);
	assert(p4.v[2].val == p2.v[2].val and p4.v[2].pr == p2.v[2].pr);

	//operator +
	p4 = p1 + p2;
	assert(p4.size == 4);
	assert(p4.v[0].val == p2.v[0].val and p4.v[0].pr == p2.v[0].pr);
	assert(p4.v[1].val == p2.v[2].val and p4.v[1].pr == p2.v[2].pr);
	assert(p4.v[2].val == p2.v[1].val and p4.v[2].pr == p2.v[1].pr);
	assert(p4.v[3].val == p1.v[0].val and p4.v[3].pr == p1.v[0].pr);

	//operator ++
	try {
		++p1;
		assert(p1.v[0].pr == 8);
	}
	catch (underflow_error) {
		assert(false);
	}

	//operator --
	try {
		p1.push(2, 1);
		--p1;
		assert(p1.size == 1);
		assert(p1.v[0].pr == 7);
	}
	catch (underflow_error) {
		assert(false);
	}
}