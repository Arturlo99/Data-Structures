#include <iostream>;

using namespace std;


//deklaracja struktury tablicy

class Tablica	//deklaracja klasy Tablica
{
	int rozmiar_tab; // zmienna okre�laj�ca rozmiar tablicy
	int *wsk_tab;	// wska�nik na tablic�

public:
	/*konstruktor tworz�cy tablic� o zadanym rozmiarze*/
	Tablica(int rozmiar)	
	{
		this->rozmiar_tab = rozmiar;  
		wsk_tab = new int[rozmiar_tab];
	}

	Tablica()
	{
		this->rozmiar_tab = 50;			//domy�lny konstruktor
		wsk_tab = new int[50];
	}

	/*destruktor*/
	~Tablica() 
	{
		delete[] wsk_tab; 
	}

	/*wy�wietlanie struktury tablicy*/
	void wyswietl() 
	{
		for (int i = 0; i < rozmiar_tab; i++)
		{
			cout << wsk_tab[i] << " ";
		}
	}
	/*metoda wstawiaj�ca element do tablicy*/
	void wstaw(int indeks, int wartosc ) 
	{	
		int nowy_rozmiar_tab = rozmiar_tab + 1; //utworzenie zmiennej przechowuj�cej rozmiar tablicy po dodaniu elementu do tablicy
		int* wsk_nowa_tab;
		wsk_nowa_tab = new int[nowy_rozmiar_tab]; // utworzenie nowej tablicy o zwi�kszonym rozmiarze
		
		for (int i = 0; i < nowy_rozmiar_tab; i++)
		{
			if (i < indeks) 
			{
				wsk_nowa_tab[i] = wsk_tab[i];
			}
			else if (i == indeks) 
			{
				wsk_nowa_tab[i] = wsk_tab[i - 1];
			}
		}

		delete[] wsk_tab;
		wsk_tab = wsk_nowa_tab;
		rozmiar_tab = nowy_rozmiar_tab;
	}

	/*Zwracanie warto�ci tablicy pod wskazanym indeksem*/
	string wyszukaj(int wartosc) 
	{
		for (int i = 0; i < rozmiar_tab; i++)
		{
			if (wsk_tab[i] == wartosc)
			{
				return "Znaleziono podan� warto��" ;
			}
		}
		return "Nie znaleziono podanej warto�ci";
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
