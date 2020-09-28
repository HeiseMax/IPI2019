#include "fcpp.hh"
#include <iostream>

float zinsf(float z, int n)
{
	return (pow(1+(z/n),n) - 1);
}
double zinsd(double z, int n)
{
	return (pow(1+(z/n),n) - 1);
}


int main ()
{
	int n;
	print ("Geben sie n ein:");
	std::cin >> n;
	print ("Abrechnungsvorgänge:");
	print (n);
	print ("float:");
	print (zinsf(0.06, n));
	print ("Differenz zu float:");
	print ((exp(0.06)-1)-(zinsf(0.06, n)));	
	print ("double:");
	print (zinsd(0.06, n));
	print ("Differenz zu double:");
	print ((exp(0.06)-1)-(zinsd(0.06, n)));
	return 0;
}
