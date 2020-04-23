#pragma once
#include<string>
using namespace std;

using namespace std;
class Heap {
private:
	int *table;
	int size;
	int maxSize;
	int leftChild(int index);
	int rightChild(int index);
	int parent(int index);
	void swap(int *a, int *b);
	
public:
	Heap(int maxSize);
	~Heap();
	void heapFixUp(int index);
	void heapFixDown(int index);
	void readFromFile(string fileName);
	void insertRandom(int howMany, int max_size);
	void insertElement(int element);
	void deleteElement(int element);
	int searchValue(int value);
	void display();
	void displayAsTable();

};