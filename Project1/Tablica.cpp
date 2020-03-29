//deklaracja struktury tablicy

class Tablica	//deklaracja klasy Tablica
{
	int rozmiar_tab; // zmienna okreœlaj¹ca rozmiar tablicy
	int *wsk_tab;
public:
	Tablica(int rozmiar)	//konstruktor tworz¹cy tablicê o zadanym rozmiarze
	{
		this->rozmiar_tab = rozmiar;  
		wsk_tab = new int[rozmiar_tab];
	}

	Tablica()	//konstruktor domyœlny
	{
		this->rozmiar_tab = 50;
		wsk_tab = new int[50];
	}
	~Tablica() {
		delete[] wsk_tab; //destruktor
	}
};