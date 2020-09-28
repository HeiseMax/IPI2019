#include <iostream>
#include <string.h>

struct Stack
{
	int array[30];
	int stelle;
} stapelA;

void push(int element)
{
	stapelA.array[stapelA.stelle] = element;
	stapelA.stelle = stapelA.stelle + 1;
}

int pop()
{
	stapelA.stelle = stapelA.stelle - 1;
	return stapelA.array[stapelA.stelle];
}

int main(int argc, char* argv[])
{
	for (int i = 0; i <=30; i++)
	{
		stapelA.array[i] = 0;
		stapelA.stelle = 0;
	}

	if(argc < 2)
	{
		std::cout << "Eingabe für den Taschenrechner erwartet!" << std::endl;
		return 1;
	}

	char* arg = argv[1]; //arg enthaelt die Zeichenfolge von der Kommandozeile 
	for (int i = 0; i <= strlen(arg); i = i+1)
	{
		char zeichen = arg[i];
		if (zeichen >= 48 && zeichen <= 57) //Zahl
		{
			int zahl = 0;
			int j = 1;
			while ((zeichen) >= 48 && (zeichen) <= 57)
			{
				zahl = zahl * 10 + (zeichen -48);				
				zeichen = arg[i + j];
				j++;
			}
			push(zahl);
			zahl = 0;
			i = i + j - 2;
			j = 0;
		}
		else if (zeichen == 43) //plus
		{
			push (pop() + pop());
		}
		else if (zeichen == 45) //minus
		{
			int minus = pop();	
			push ((pop()) -  minus);
		}
		else if (zeichen == 42)	//mal
		{
			push (pop() * pop());
		}
		else if (zeichen == 47) //geteilt
		{
			int teiler = pop();
			push (pop() / teiler);
		}
		else
		{
		}
	}
std::cout << "= " << stapelA.array[0] << std::endl;
return 0;
}
