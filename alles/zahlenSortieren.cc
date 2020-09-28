#include "fcpp.hh"

void einordnen()
{
	int array[10];
	for (int i = 0; i<10 ;i++)
	{
		array[i] = 0;
	}
	int i = 0;
	while (i < 10) //höchstens 10 eingaben
	{
		int x;
		print ("zahl eingeben:");
		std::cin >> x; //eingabe der zu sortierenden Zahl
		if (x == -1) //terminirungsbedingung x == -1
		{
			i = 100;
		}
		else if (x < -1) //terminierungsbedingung x kleiner -1
		{
			print ("Keine zugelassene Zahl!");
			i = 100;
		}
		else if (x == 0) //terminierunungsbedingung x == 0
		{
			i = 10;
		}
		else //alle Zahlen die sortiert werden können
		{
			int n = 0; 
			while (n <= 9) //läuft alle stellen des Arrays ab
			{
				if (x < array[n]) //x ist kleiner als Element vom array an der stelle n
				{
					for (int l = 9; l > n; l--)//zahlen die grösser sind als x werden eine stelle im array nach oben kopiert
					{
						array[l] = array[l-1];
					}
				array[n] = x;
				n = 10;//beenden der while-schleife
				}
				else if (array[n] == 0)//Stelle des arrays ist noch nicht besetzt
				{
					array[n] = x;
					n = 10;//beenden der while-schleife
				}
				else//das element an der stelle n im array ist kleiner als x
				{
					n++;
				}
			}
		}
		i++;
	}
	if (i >= 100)//abbruchbedingungen beenden programm
	{
		print ("Programm beendet");
	}
	else//das array wird auf der Konsole ausgegeben
	{
		print ("Sortiert:");
		for (int l = 0; l < 10; l++)
		{
			print (array[l]);
		}
	}
}


int main ()
{
	einordnen();//mainfunfktion ruft die funktion "einordnen" ohne uebergebene werte auf
	return 0;
}
