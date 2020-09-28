#include <iostream>
#include <fstream>


int main ()
{
	std::ifstream file;
	file.open("Datei.txt");
	std::string line;

	std::ofstream writefile;
	writefile.open("Datei-a.txt");
	int i = 1;
	while (std::getline(file, line))
	{
		writefile << i << ": " << line << std::endl;
		i++;
	}
	file.close();
}
