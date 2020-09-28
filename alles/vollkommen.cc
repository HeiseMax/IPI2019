#include "fcpp.hh"
#include <iostream>

using namespace std;


int teilersumme (int y,int z,int x)
{	
	return cond(y < x, ((cond (x % y == 0, z = z+y , z = z), y = y+1, teilersumme(y,z,x))) , (z = z ));
}

bool vollkommen(int x)
{
	return (teilersumme(1,0,x) == x);
}

int main ()
{
	int x;
	cout << "wahle X:" ;
	cin >> x;
	cout << "1 = true/ 0 = false \n" ;
	cout << "Ist X Vollkommen?  => " ;
	return print(vollkommen(x));
}



