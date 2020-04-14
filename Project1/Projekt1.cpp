#include <iostream>;
#include<chrono>
using namespace std;


//deklaracja struktury tablicy

class Table	//deklaracja klasy Tablica
{
	int sizeTab; // zmienna okreœlaj¹ca rozmiar tablicy
	int *pointerTab;	// wskaŸnik na tablicê

public:

	/*konstruktor tworz¹cy tablicê o zadanym rozmiarze*/
	Table(int size)	
	{
		this->sizeTab = size;  
		pointerTab = new int[sizeTab];
	}

	/*domyœlny konstruktor*/
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

	/*wyœwietlanie struktury tablicy*/
	void display() 
	{
		for (int i = 0; i < sizeTab; i++)
		{
			cout << pointerTab[i] << " ";
		}
	}

	/*funkcja wstawiaj¹ca element do tablicy*/
	void addValue(int indeks, int wartosc ) 
	{	
		int newSizeTab = sizeTab + 1; //utworzenie zmiennej przechowuj¹cej rozmiar tablicy po dodaniu elementu do tablicy
		int* pointerNewTab;
		pointerNewTab = new int[newSizeTab]; // utworzenie nowej tablicy o zwiêkszonym rozmiarze
		
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

	/*funkcja usuwaj¹ca wskazany elemnt z tablicy*/
	void deleteValue(int indeks)	// funkcja do usuwania wartoœci znajduj¹cej siê zadanym numerze indeksu
	{
		int newSizeTab = sizeTab - 1; //utworzenie zmiennej przechowuj¹cej rozmiar tablicy po usuniêciu elementu z tablicy
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

	/*Zwracanie wartoœci tablicy pod wskazanym indeksem*/
	string findValue(int wartosc) 
	{
		for (int i = 0; i < sizeTab; i++)
		{
			if (pointerTab[i] == wartosc)
			{
				return "Znaleziono podan¹ wartoœæ" ;
			}
		}
		return "Nie znaleziono podanej wartoœci";
	}

	/*funkcja wype³niaj¹ca tablicê losowymi wartoœciami*/
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
