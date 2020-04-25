#include "BSTtree.h"
#include <iostream>
#include<math.h>
#include<time.h>
#include <fstream>
#include<string>

using namespace std;

BSTtree::BSTtree()
{
	root = NULL;
}

BSTtree::~BSTtree()
{
	root = NULL;
}

void BSTtree::display()
{
	if (root == NULL)
	{
		cout << "Drzewo jest puste" << endl;
		return;
	}
	inOrder(root);
	cout << endl;
}

void BSTtree::insertKey(int element)
{
	Node* y, * x;
	Node* z = new Node;
	z->leftChild = NULL;
	z->rightChild = NULL;
	z->key = element;
	y = NULL;
	x = root;
	while (x != NULL)
	{
		y = x;
		if (z->key < x->key)
			x = x->leftChild;
		else
			x = x->rightChild;
	}
	z->parent = y;
	if (y == NULL)
		root = z;
	else if (z->key < y->key)
		y->leftChild = z;
	else
		y->rightChild = z;

}

void BSTtree::deleteKey(int element)
{
	Node* z = searchNode(root, element);
	if (z == NULL)
	{
		cout << "Nie ma takiej wartosci" << endl;
		return;
	}

	if (z->leftChild == NULL)
		swap(z, z->rightChild);
	else if (z->rightChild == NULL)
		swap(z, z->leftChild);
	else
	{
		Node* y =minBSTNode(z->rightChild);
		if (y->parent != z)
		{
			swap(y, y->rightChild);
			y->rightChild = z->rightChild;
			y->rightChild->parent = y;
		}
		swap(z, y);
		y->leftChild = z->leftChild;
		y->leftChild->parent = y;

	}
}

void BSTtree::inOrder(Node* Node)
{
	if (Node != NULL)
	{
		inOrder(Node->leftChild);
		cout << Node->key << " ";
		inOrder(Node->rightChild);
	}
}

void BSTtree::insertRandomValues(int ilosc)
{
	root = NULL;
	srand(time(NULL));
	for (int i = 0; i < ilosc; i++)
	{
		insertKey(rand() % 20000);
	}
}

Node* BSTtree::searchNode(Node* Node, int element)
{
	if (Node == NULL || element == Node->key)
		return Node;
	if (element < Node->key)
		return searchNode(Node->leftChild, element);
	else
		return searchNode(Node->rightChild, element);
}

string BSTtree::searchValue(int value)
{
	Node* wynik = searchNode(root, value);
	if (wynik == NULL)
		return "Nie znaleziono podanej wartoœci";
	else
		return "Znaleziono podan¹ wartoœæ";
}

Node* BSTtree::minBSTNode(Node* Node)
{
	if (Node == NULL)
		return NULL;
	while (Node->leftChild != NULL)
		Node = Node->leftChild;
	return Node;
}

void BSTtree::readFromFile(string fileName)
{
	int x, size;
	ifstream inFile;
	inFile.open(fileName);
	if (!inFile) {
		cout << "Nie uda³o siê znaleŸæ pliku." << endl;
		return;
	}
	inFile >> size;
	while (inFile >> x) {
		insertKey(x);
	}

	inFile.close();
}

void BSTtree::swap(Node* a, Node* b)
{
	if (a->parent == NULL)
		root = b;
	else if (a == a->parent->leftChild)
		a->parent->leftChild = b;
	else
		a->parent->rightChild = b;
	if (b != NULL)
		b->parent = a->parent;
}

