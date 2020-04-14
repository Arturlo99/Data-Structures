#include <iostream>;
#include<chrono>
using namespace std;


//deklaracja struktury tablicy

class Table	//deklaracja klasy Tablica
{
	int sizeTab; // zmienna okre�laj�ca rozmiar tablicy
	int *pointerTab;	// wska�nik na tablic�

public:

	/*konstruktor tworz�cy tablic� o zadanym rozmiarze*/
	Table(int size)	
	{
		this->sizeTab = size;  
		pointerTab = new int[sizeTab];
	}

	/*domy�lny konstruktor*/
	Table()
	{
		this->sizeTab = 50;			
		pointerTab = new int[50];
	}

	/*destruktor*/
	~Table() 
	{
		delete[] pointerTab; 
	}

	/*wy�wietlanie struktury tablicy*/
	void display() 
	{
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


};

int main()
{	
	/*
	Tablica t1(5);
	t1.wstaw(0, 1);
	t1.wyswietl();
	*/
	return 0;
}
