#include "fcpp.hh"
#include <iostream>

using namespace std;

int steps=0;
int quadrat (int x)
{
	return x*x;
}

int potenz (int x, int exp)
{
	steps++;
	return cond (exp >= 2, quadrat(x)*potenz(x, exp-2), cond (exp == 1, x, 1));
}

int main (int argc, char** argv)
{
	
	return print (potenz(readarg_int(argc, argv, 1),2));
	
}

/*int x;
	int exp;
	cout << "waehle X:";
	cin >> x;
	cout << "waehle Exponent:";
	cin>> exp;
	cout << x << "°" << exp << "=" ;
	print (potenz(x,exp));
	cout << "benoetigte Schritte:";
	return print(steps); */

