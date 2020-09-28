#include "fcpp.hh"


bool deck_check(int deck[], int n) //schaut, ob deck == ausgangsdeck
{
	int deckPruef[n];
	for (int i = 0; i<n ;i++)
	{
		deckPruef[i] = i;
	}
	int pruefzahl = 0;
	for (int i = 0; i < n; i++)//prüft ob die einzelnen Elemente der beiden Decks gleich sind
	{
		if (deckPruef[i] == deck[i])
		{
		}
		else
		{
			pruefzahl++;//wenn ein element im deck anders ist, wird pruefzahl erhöht
		}
	}
	if (pruefzahl == 0)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}


int out_shuffle ( int n) //simuliert den out_shuffle mit n elementen
{
	int deck[n];
	for (int i = 0; i<n ;i++)
	{
		deck[i] = i;
	}

	int deckShuffeled[n];//hilfsarray zum mischen
	int pruef = 0;//variable für Abbruch der while-schleife
	int Schrittzaehler = 0;//zählt die benötigten Mischvorgaenge um zum ausgangsdeck zurückzukehren
	while (pruef< 1)
	{
		for (int i = 0; i < n; i++)//mischt das Deck nach der Out_shuffle technik
		{
			if (i % 2 == 0)
			{
				deckShuffeled[i] = deck[i/2];
			}
			else
			{
				deckShuffeled[i] = deck[(n/2) +(i/2)];
			}
		}
		for (int i = 0; i<n; i++)//das Ursprungsdeck wird mit den gemischten Deck ersetzt
		{
			deck[i] = deckShuffeled[i];
		}
		if (deck_check(deck,n) == 1) //wenn die decks gleich sind, wird die schleife beendet
		{
			pruef++;
		}
		Schrittzaehler++;
	}
	return Schrittzaehler;//gibt die anzahl der benötigten shuffles zurück
}

int in_shuffle ( int n) //simmuliert den In_shuffle mit n Elementen
{
	int deck[n];
	for (int i = 0; i<n ;i++)
	{
		deck[i] = i;
	}

	int deckShuffeled[n];//hilfsarray zum mischen
	int pruef = 0;//variable für die while-schleife
	int Schrittzaehler = 0;//zählt die benötigten mischvorgaenge um zum ausangsdeck zurückzukehren
	while (pruef< 1)
	{
		for (int i = 0; i < n; i++)//mischt das Deck nach der in-shuffle technik
		{
			if (i % 2 == 0)
			{
				deckShuffeled[i] = deck[(n/2) +(i/2)];
			}
			else
			{
				deckShuffeled[i] = deck[i/2];
			}
		}
		for (int i = 0; i<n; i++)//das Deck wir mit dem gemischten deck ersetzt
		{
			deck[i] = deckShuffeled[i];
		}
		if (deck_check(deck,n) == 1)//wenn die Decks gleich sind, wird die schleife beendet
		{
			pruef++;
		}
		Schrittzaehler++;
	}
	return Schrittzaehler;//gibt die anzahl der benötigten shuffles zurück
}

int main()
{
	int n;//anzahl Karten im array
	std::cin >> n;
	if (n % 2 != 0) //prüft ob n gerade
	{
		print ("bitte gerades n waehlen");
		std::cin >> n;
	}
	print ("Mischvorgänge mit out_shuffle:");
	print (out_shuffle (n));
	print ("Mischvorgänge mit in_shuffle:");
	print (in_shuffle (n));
}

