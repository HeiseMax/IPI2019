#include <iostream>
#include <cmath>

bool primzahl (int zahl) //prueft ob zahl eine Primzahl
{
	int gTeiler;
	for (int i = 1; i <= sqrt((double) zahl); i++) //sucht groessten Teiler
	{
		if (zahl%i == 0)
		{
			gTeiler = i;
		}
	}

	if (zahl == 1)
	{
		return 0;
	}
	else if (gTeiler == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


void primfaktor(int zahl) //berechnet und gibt die Primfaktorzerlegung aus
{
	if (primzahl(zahl) == 1)
	{
		std::cout << zahl;
	}
	else //wenn keine primzahl
	{
		for (int i = 2; i <= zahl/2; i++)
		{
			int j = 1;
			while ((zahl/j)%i == 0 && primzahl(i) == 1) //prüft ob eine Zahl mehrmals Teiler der Zahl ist
			{
				std::cout << i << " ";
				j = j*i;
			}
		}
	}
}


int main()
{
	std::cout << ("Zahl:");
	int n;
	std::cin >> n;
	std::cout << "Primfaktorzerlegung: ";
	primfaktor(n);
	std::cout << std::endl;
	return 0;
}
