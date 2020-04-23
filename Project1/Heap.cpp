#include "Heap.h"
#include <iostream>
#include<math.h>
#include<time.h>
#include <fstream>
#include<string>

using namespace std;

Heap::Heap(int maxSize)
{
	this->maxSize = maxSize;
	size = 0;
	table = new int[maxSize];
}

Heap::~Heap()
{
	delete[] table;
}

int Heap::parent(int index)
{
	return (index - 1) / 2;
}

int Heap::leftChild(int index)
{
	return 2 * index + 1;
}

int Heap::rightChild(int index)
{
	return 2 * index + 2;
}

int Heap::searchValue(int element)
{
	for (int i = 0; i < size; i++)
	{
		if (table[i] == element)
		{
			return i;
		}
	}
	return -1;
}

void Heap::insertElement(int element)
{
	if (size == maxSize)
	{
		cout << "Nie mozna wstawic, Heap osiagnal maksymalny size" << endl;
		return;
	}

	size++;
	int index = size - 1;
	table[index] = element;

	heapFixUp(index);

}

void Heap::heapFixUp(int index)
{
	if (index >= 0 && parent(index) >= 0 && table[parent(index)] < table[index])
	{
		swap(&table[index], &table[parent(index)]);
		heapFixUp(parent(index));
	}
}

void Heap::heapFixDown(int index)
{
	int lewy = leftChild(index);
	int prawy = rightChild(index);
	int parent = index;
	if (lewy<size && table[lewy]>table[index])
		parent = lewy;
	if (prawy<size && table[prawy]>table[parent])
		parent = prawy;
	if (parent != index)
	{
		swap(&table[index], &table[parent]);
		heapFixDown(parent);
	}
}

void Heap::deleteElement(int element)
{
	int index = searchValue(element);
	if (index >= 0)
	{
		swap(&table[index], &table[size - 1]);
		size--;
	}
	heapFixDown(index);
}

void Heap::insertRandom(int ilosc, int maxSize)
{
	this->maxSize = maxSize;
	size = 0;
	table = new int[maxSize];
	srand(time(NULL));
	for (int i = 0; i < ilosc; i++)
	{
		insertElement(rand() % 20000);
	}

}

void Heap::display()
{
	int poziom = 1;
	if (size == 0)
	{
		cout << "Heap jest pusty" << endl;
		return;
	}

	cout << table[0] << " ";
	cout << endl;
	for (int i = 1; i < size; i++)
	{
		cout << table[i] << " ";
		if (i == poziom + 1)
		{
			cout << endl;
			poziom = (2 * i) + 1;
		}
	}

	cout << endl;

}

void Heap::displayAsTable()
{
	if (size)
	{
		for (int i = 0; i < size; i++)
			cout << table[i] << " ";
		cout << endl;
	}
	else
		cout << "Heap jest pusty" << endl;
}

void Heap::swap(int* a, int* b)
{
	int pomoc = *a;
	*a = *b;
	*b = pomoc;
}

void Heap::readFromFile(string nazwaPliku)
{
	int x, size;
	ifstream inFile;
	inFile.open(nazwaPliku);
	if (!inFile) {
		cout << "Nie mozna znalezc " << endl;
		return;
	}
	inFile >> size;
	while (inFile >> x) {
		insertElement(x);
	}

	inFile.close();
}