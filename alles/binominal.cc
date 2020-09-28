#include "fcpp.hh"
#include <iostream>

using namespace std;
int f = 0;

int binominal(int n, int k)
{
f++;
	return cond (k > 0 && k != n, binominal(n-1,k-1)+binominal(n-1,k),1);
}


int main ( int argc, char* argv[])
{
	print ("Binominalkoeffizient:");	
	print (	binominal(readarg_int(argc,argv,1),readarg_int(argc, argv, 2)));
	print (f);
	return 0;
}
