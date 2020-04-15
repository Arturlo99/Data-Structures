#include "List.h"
#include<iostream>
#include<time.h>
#include <fstream>
#include<string>

using namespace std;

/*Konstruktor domyœlny*/
List::List()
{
	size = 0;
	head = NULL;
	tail = NULL;
}

/*Konstruktor*/
List::List(int length)
{
	size = 0;
	head = NULL;
	tail = NULL;
	srand(time(NULL));
	for (int i = 0; i < length; i++)
	{
		addAtTheBegining(rand() % 1000);
	}
}

List::~List()
{
	while (head)
		deleteBegining();
	size = 0;
}

int List::lengthOfList()
{
	return size;
}

void List::display()
{

	if (lengthOfList())
	{
		Element* e = head;
		for (; e != NULL; e = e->next)
			cout << e->wartosc << " ";
		cout << endl;
	}
	else
		cout << "Lista jest pusta" << endl;

}

string List::findValue(int value)
{
	Element* e = head;
	for (; e; e = e->next)
	{
		if (e->wartosc == value)
		{
			return "Znaleziono podan¹ wartoœæ";
		}
	}
	return "Nie znaleziono podanej wartoœci";
}

void List::putRandomValues(int amount)
{
	size = 0;
	head = NULL;
	tail = NULL;
	srand(time(NULL));
	for (int i = 0; i < amount; i++)
	{
		addAtTheBegining(rand() % 20000);
	}
}

void List::readFromFile(string fileName)
{
	int x, size;
	ifstream inFile;
	inFile.open(fileName);
	if (!inFile) {
		cout << "Nie mozna znalezc pliku." << endl;
		return;
	}
	inFile >> size;
	while (inFile >> x) {
		addAtTheEnd(x);
	}

	inFile.close();
}

void List::addAtTheBegining(int element)
{
	Element* e;
	e = new Element;
	e->prev = NULL;
	e->wartosc = element;
	e->next = head;
	if (head != NULL)
		head->prev = e;
	if (tail == NULL)
		tail = e;
	head = e;
	size++;
}

void List::addValue(int index, int element)
{
	if (index == lengthOfList())
	{
		addAtTheEnd(element);
		return;
	}
	if (index<0 || index>lengthOfList())
	{
		cout << "Podano niepoprawny indeks" << endl;
		return;
	}
	if (index == 0)
	{
		addAtTheBegining(element);
		return;
	}

	Element* f = head;
	for (int i = 0; f; f = f->next, i++)
	{
		if (i == index)
		{
			Element* e = new Element;
			e->wartosc = element;
			e->prev = f->prev;
			e->next = f;
			f->prev->next = e;
			f->prev = e;
			size++;
			break;
		}
	}
}

void List::addAtTheEnd(int element)
{
	if (lengthOfList() == 0)
		addAtTheBegining(element);
	else
	{
		Element* e;
		e = new Element;
		e->next = NULL;
		e->prev = tail;
		e->wartosc = element;
		tail->next = e;
		tail = e;
		size++;
	}
}

void List::deleteEnd()
{
	if (tail == NULL)
		return;
	Element* e = tail;
	if (e == head)
		head = tail = NULL;
	else
	{
		tail = tail->prev;
		tail->next = NULL;
	}
	delete e;
	size--;
}

void List::deleteBegining()
{
	if (head == NULL)
		return;
	Element* e = head;
	head = head->next;
	if (head != NULL)
		head->prev = NULL;
	delete e;
	size--;
}

void List::deleteValue(int index)
{
	if (index == lengthOfList())
	{
		deleteEnd();
		return;
	}
	if (index<0 || index>lengthOfList())
	{
		cout << "Niepoprawny indeks" << endl;
		return;
	}
	if (index == 0)
	{
		deleteBegining();
		return;
	}
	Element* f = head;
	for (int i = 0; f; f = f->next, i++)
	{
		if (i == index)
		{
			f->prev->next = f->next;
			delete f;
			size--;
			break;
		}
	}
}