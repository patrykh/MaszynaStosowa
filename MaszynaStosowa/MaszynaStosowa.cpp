// MaszynaStosowa.cpp : Defines the entry point for the console application.
//

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
			cout << tmp->dana << " ";
			tmp = tmp->next;
		} while (tmp != nullptr);
		cout << endl;
	}
	else {
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
	lista * _lista = new lista;
	
	char key;
	while (true)
	{

		cin >> key;
		if (isdigit(key))
		{
			int liczba = int(key) - 48;
			_lista->push(liczba);
		}
		switch (key)
		{
		case '+':
			_lista->sum();
			break;
		case 's':
			_lista->swap();
			break;
		case 'p':
			_lista->show();
			break;
		case 'x':
			_lista->pop();
			break;
		case 'q':
			exit(0);
		default:
			break;
		}
	}

	return 0;
}

