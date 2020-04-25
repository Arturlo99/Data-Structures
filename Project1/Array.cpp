#include <iostream>;
#include<chrono>
#include<time.h>
#include<fstream>
#include<string>

using namespace std;


/*deklaracja struktury tablicy*/

class Array	//deklaracja klasy Tablica
{
private:
	int sizeTab; // zmienna okre�laj�ca rozmiar tablicy
	int *pointerTab;	// wska�nik na tablic�

public:

	/*konstruktor tworz�cy tablic� o zadanym rozmiarze*/
	Array(int size)	
	{
		this->sizeTab = size;  
		pointerTab = new int[sizeTab];
		// wype�nienie tablicy losowymi warto�ciami z przedzia�y 1 - 1000
		srand(time(NULL));
		for (int i = 0; i < sizeTab; i++) 
		{
			pointerTab[i] = rand() % 1000 + 1;

		}
	}

	/*domy�lny konstruktor - tworzy pust� tablic�*/
	Array()
	{
		this->sizeTab = 0;			
		pointerTab = new int[0];
	}

	/*destruktor*/
	~Array() 
	{
		delete[] pointerTab; 
	}

	/*wy�wietlanie struktury tablicy*/
	void display() 
	{
		if (sizeTab) {
			cout << "Tablica jest pusta" << endl;
		}

		for (int i = 0; i < sizeTab; i++)
		{
			cout << pointerTab[i] << " ";
		}
	}

	/*funkcja wstawiaj�ca element do tablicy*/
	void addValue(int indeks, int wartosc ) 
	{	
		int newSizeTab = sizeTab + 1; //utworzenie zmiennej przechowuj�cej rozmiar tablicy po dodaniu elementu do tablicy
		int* pointerNewTab;
		pointerNewTab = new int[newSizeTab]; // utworzenie nowej tablicy o zwi�kszonym rozmiarze
		
		for (int i = 0; i < newSizeTab; i++)
		{
			if (i < indeks) 
			{
				pointerNewTab[i] = pointerTab[i];
			}
			else if (i == indeks) 
			{
				pointerNewTab[i] = wartosc;
			}
			else
			{
				pointerNewTab[i] = pointerTab[i - 1];
			}
		}

		delete[] pointerTab;
		pointerTab = pointerNewTab;
		sizeTab = newSizeTab;
	}

	/* funkcja dodaj�ca element na koniec tablicy*/
	void addAtTheEnd(int value)
	{
		int newSizeTab =  + 1;
		int* pointerNewTab;
		pointerNewTab = new int[newSizeTab];

		for (int i = 0; i < newSizeTab - 1; i++)
			pointerNewTab[i] = pointerTab[i];
		pointerNewTab[newSizeTab - 1] = value;

		delete[] pointerTab;
		pointerTab = pointerNewTab;
		sizeTab = newSizeTab;

	}

	/*funkcja usuwaj�ca wskazany elemnt z tablicy*/
	void deleteValue(int indeks)	// funkcja do usuwania warto�ci znajduj�cej si� zadanym numerze indeksu
	{
		int newSizeTab = sizeTab - 1; //utworzenie zmiennej przechowuj�cej rozmiar tablicy po usuni�ciu elementu z tablicy
		int* pointerNewTab;
		pointerNewTab = new int[newSizeTab]; // utworzenie nowej tablicy o mniejszym rozmiarze

		for (int i = 0; i < sizeTab; i++)
		{
			if (i < indeks)
			{
				pointerNewTab[i] = pointerTab[i];
			}
			else if (i >= indeks)
			{
				pointerNewTab[i] = pointerTab[i + 1];
			}

		}
		delete[]pointerTab;
		pointerTab = pointerNewTab;
		sizeTab = newSizeTab;
	}

	/*Zwracanie warto�ci tablicy pod wskazanym indeksem*/
	string findValue(int wartosc) 
	{
		for (int i = 0; i < sizeTab; i++)
		{
			if (pointerTab[i] == wartosc)
			{
				return "Znaleziono podan� warto��" ;
			}
		}
		return "Nie znaleziono podanej warto�ci";
	}

	/*funkcja wype�niaj�ca tablic� losowymi warto�ciami*/
	void putRandomValues() 
	{
		srand(time(NULL));
		for (int i = 0; i < sizeTab; i++)
		{
			pointerTab[i] = rand() % 1000 + 1;
		}
	}

	void readFromFile(string fileName)
	{
		int x, size;
		ifstream inFile;
		inFile.open(fileName);
		if (!inFile) {
			cout << "Nie mozna znalezc " << endl;
			return;
		}
		inFile >> size;
		while (inFile >> x) {
			addAtTheEnd(x);
		}

		inFile.close();
	}


};

