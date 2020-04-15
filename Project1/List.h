#pragma once
#include<string>
using namespace std;
struct Element {
	Element* next;
	Element* prev;
	int wartosc;
};
class List {
private:
	Element *head, * tail;
	int size;
	int lengthOfList();
public:
	List();
	List(int length);
	 ~List();
	string findValue(int wartosc);
	void putRandomValues(int ilosc);
	void readFromFile(string fileName);
	void display();
	void addAtTheBegining (int element);
	void addValue(int index, int element);
	void addAtTheEnd(int element);
	void deleteEnd();
	void deleteBegining();
	void deleteValue(int index);

};
