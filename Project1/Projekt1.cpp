#include <iostream>;
#include<chrono>
using namespace std;


//deklaracja struktury tablicy

class Tablica	//deklaracja klasy Tablica
{
	int rozmiar_tab; // zmienna okreœlaj¹ca rozmiar tablicy
	int *wsk_tab;	// wskaŸnik na tablicê

public:

	/*konstruktor tworz¹cy tablicê o zadanym rozmiarze*/
	Tablica(int rozmiar)	
	{
		this->rozmiar_tab = rozmiar;  
		wsk_tab = new int[rozmiar_tab];
	}

	/*domyœlny konstruktor*/
	Tablica()
	{
		this->rozmiar_tab = 50;			
		wsk_tab = new int[50];
	}

	/*destruktor*/
	~Tablica() 
	{
		delete[] wsk_tab; 
	}

	/*wyœwietlanie struktury tablicy*/
	void wyswietl() 
	{
		for (int i = 0; i < rozmiar_tab; i++)
		{
			cout << wsk_tab[i] << " ";
		}
	}

	/*funkcja wstawiaj¹ca element do tablicy*/
	void wstaw(int indeks, int wartosc ) 
	{	
		int nowy_rozmiar_tab = rozmiar_tab + 1; //utworzenie zmiennej przechowuj¹cej rozmiar tablicy po dodaniu elementu do tablicy
		int* wsk_nowa_tab;
		wsk_nowa_tab = new int[nowy_rozmiar_tab]; // utworzenie nowej tablicy o zwiêkszonym rozmiarze
		
		for (int i = 0; i < nowy_rozmiar_tab; i++)
		{
			if (i < indeks) 
			{
				wsk_nowa_tab[i] = wsk_tab[i];
			}
			else if (i == indeks) 
			{
				wsk_nowa_tab[i] = wartosc;
			}
			else
			{
				wsk_nowa_tab[i] = wsk_tab[i - 1];
			}
		}

		delete[] wsk_tab;
		wsk_tab = wsk_nowa_tab;
		rozmiar_tab = nowy_rozmiar_tab;
	}

	/*funkcja usuwaj¹ca wskazany elemnt z tablicy*/
	void usun(int indeks)	// funkcja do usuwania wartoœci znajduj¹cej siê zadanym numerze indeksu
	{
		int nowy_rozmiar_tab = rozmiar_tab - 1; //utworzenie zmiennej przechowuj¹cej rozmiar tablicy po usuniêciu elementu z tablicy
		int* wsk_nowa_tab;
		wsk_nowa_tab = new int[nowy_rozmiar_tab]; // utworzenie nowej tablicy o mniejszym rozmiarze

		for (int i = 0; i < rozmiar_tab; i++)
		{
			if (i < indeks)
			{
				wsk_nowa_tab[i] = wsk_tab[i];
			}
			else if (i >= indeks)
			{
				wsk_nowa_tab[i] = wsk_tab[i + 1];
			}

		}
		delete[]wsk_tab;
		wsk_tab = wsk_nowa_tab;
		rozmiar_tab = nowy_rozmiar_tab;
	}


	/*Zwracanie wartoœci tablicy pod wskazanym indeksem*/
	string wyszukaj(int wartosc) 
	{
		for (int i = 0; i < rozmiar_tab; i++)
		{
			if (wsk_tab[i] == wartosc)
			{
				return "Znaleziono podan¹ wartoœæ" ;
			}
		}
		return "Nie znaleziono podanej wartoœci";
	}

	/*funkcja wype³niaj¹ca tablicê losowymi wartoœciami*/
	void wypelnij_losowo() 
	{
		srand(time(NULL));
		for (int i = 0; i < rozmiar_tab; i++)
		{
			wsk_tab[i] = rand() % 1000 + 1;
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
