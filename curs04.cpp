#include <iostream>
#include<string>

class Clasa {
public:
	char* pointer;
	int atribut;
};

void main()
{
	Clasa c1;
	c1.pointer = new char[strlen("text") + 1];
	strcpy(c1.pointer, "text");
	c1.atribut = 10;

	Clasa c2 = c1;
	strcpy(c2.pointer, "newT");

	cout<< c1.pointer;


}