#include "fcpp.hh"
#include <iostream>

using namespace std;

int f = 0;

int fakIter (int produkt, int zaehler , int ende)
{
f++;
	return cond( zaehler>ende, produkt, fakIter(produkt*zaehler,zaehler+1, ende));
}

int binominal(int n, int k)
{
f++;
	return (((fakIter(1,1,n)) / ((fakIter(1,1,k)*(fakIter(1,1,n - k))))));
}


int main ( int argc, char* argv[])
{

	print ("Binominalkoeffizient:");
	print (	binominal(readarg_int(argc,argv,1),readarg_int(argc, argv, 2)));
	print (f);
	return 0;
}
