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
	void replace();

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

void lista::replace()
{
	int n = 0;
	element * tmpf, *tmps, *head;
	
	n = this->glowa->dana;
	pop();
	
	
	if ( n>1 )
	{
		tmpf = this->glowa;
		tmps = this->glowa->next;

		for (int i = 1; i < n; i++)
		{
			tmpf = tmpf->next;
		}

		/*head->next = tmpf->next;
		tmpf->next = head;
		this->glowa = tmps;*/

		this->glowa->next = tmpf->next;
		tmpf->next = this->glowa;
		this->glowa = tmps;

		/*tmps->next = this->glowa;
		tmpf->next = this->glowa->next;
		this->glowa = tmpf;*/
	}
	

}

int main()
{
	lista * _lista = new lista;
	int liczba=0;
	char key;
	char r;
	while (true)
	{
		scanf("%c", &key);

		if (key && isdigit(key)) {
			
			while (key && isdigit(key)) {
				liczba = (liczba * 10) + (key - '0');
				scanf("%c", &key);
			}

			_lista->push(liczba);
			liczba = 0;
		}

		switch (key)
		{
		case '+':
			_lista->sum();
			break;
		case 's':
			//TODO poprawiæ sumê gdy jedna liczba dodac funkcje sprawdzajaca ilosc elementow w liscie.
			_lista->swap();
			break;
		case 'p':
			_lista->show();
			break;
		case 'x':
			_lista->pop();
			break;
		case 'r':
			_lista->replace();
			break;
		case 'q':
			exit(0);
		default:
			break;
		}
	}

	return 0;
}

