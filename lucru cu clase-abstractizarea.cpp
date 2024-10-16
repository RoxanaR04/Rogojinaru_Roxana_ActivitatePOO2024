#include<iostream>
#include<string>

using namespace std;

class Cafenea {
public:
	string numeCafenea;
	int nrAngajati;
	float cheltuieliUtilitati;
	bool esteCunoscuta;

	Cafenea(string numeCafenea, int nrAngajati, float cheltuieliUtilitati, bool esteCunoscuta) {
		this->numeCafenea = numeCafenea;
		this->nrAngajati = nrAngajati;
		this->cheltuieliUtilitati = cheltuieliUtilitati;
		this->esteCunoscuta = esteCunoscuta;
	}
};

void main()
{
	Cafenea c1("Bistro Aroma", 23, 569.78, 1);
	Cafenea c2("Green", 12, 128.32, 0);
}