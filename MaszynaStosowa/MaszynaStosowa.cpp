// MaszynaStosowa.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct element
{
	int dana;
	element *next;

	element();
};

element::element() : dana(0), next(nullptr) {}

struct lista
{
	element *glowa;
	void push(int dana);
	void show();
	void swap();
	void pop();
	void sum();

	lista();
};

lista::lista() : glowa(nullptr) {}

void lista::push(int _dana)
{
	element *nowy = new element;

	nowy->dana = _dana;
	nowy->next = glowa;
	glowa = nowy;
}

void lista::show()
{
	element * tmp;
	tmp = this->glowa;
	if (tmp)
	{
		do {
			cout << tmp->dana;
			tmp = tmp->next;
		} while (tmp != nullptr);
		cout << endl;
	}
}

void lista::swap() {
	element *tmpf, *tmps;
	
	tmpf = this->glowa;
	tmps = this->glowa->next;
	
	tmpf->next = tmps->next;
	tmps->next = tmpf;
	this->glowa = tmps;
	
}

void lista::pop()
{
	element * tmp;
	tmp = this->glowa;
	glowa = tmp->next;
	delete tmp;
}

void lista::sum()
{
	int tmps, tmpf, sum;
	tmpf = this->glowa->dana;
	pop();
	tmps = this->glowa->dana;
	pop();
	sum = tmpf + tmps;
	push(sum);
}

int main()
{

	cout << "Hello wordl!";
	lista * _lista = new lista;
	_lista->push(1);
	_lista->push(2);
	_lista->push(3);
	_lista->push(4);
	_lista->push(5);
	_lista->push(6);
	_lista->show();
	_lista->swap();
	_lista->show();
	_lista->pop();
	_lista->show();
	_lista->pop();
	_lista->show();
	_lista->sum();
	_lista->show();
	return 0;
}

