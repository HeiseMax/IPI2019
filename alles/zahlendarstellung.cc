#include "fcpp.hh"

double determinante (double a, double b, double c, double d) //berechnet determinante mit double(1a)
{
	return(a*d - b*c);
}

float determinanteF (float a, float b, float c, float d) //berechnet determinante mit float (1a)
{
	return(a*d - b*c);
}


float assoziativitaet(int n) //(1b)
{
	float a = pow(10.0 ,n);
	float b = pow(-10.0,n);
	float c = pow(10.0, -n);
	print ((a+b)+c);
	print (a+(b+c));
	return 0;
}


int main ()
{
	print (determinanteF(100,0.01,-0.01,100));
	print (determinante(100,0.01,-0.01,100));
	int n;
	std:: cout << "Geben sie n an" << std::endl;
	std::cin >> n;
	assoziativitaet(n);
	return 0;
}
