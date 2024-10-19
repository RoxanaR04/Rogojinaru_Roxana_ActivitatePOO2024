#include<iostream>
#include<string>

using namespace std;

class Cafenea {
	string denumireCafenea;
	int nrAngajati;
	float cheltuieliUtilitatiPerLuna;
	bool esteCunoscuta;
	const int anInfiintare;
	static int clasaCaenPrincipala;

public:
	//Constructorul fara parametrii
	Cafenea() :anInfiintare(0)
	{
		this->denumireCafenea = "Anonima";
		this->cheltuieliUtilitatiPerLuna = 0;
		this->nrAngajati = 0;
		this->esteCunoscuta = 0;
	}

	//Constructorul cu un parametru
	Cafenea(string denumireCafenea) :anInfiintare(0)
	{
		this->denumireCafenea = denumireCafenea;
		this->nrAngajati = 0;
		this->cheltuieliUtilitatiPerLuna = 0;
		this->esteCunoscuta = 0;
	}

	//Constructorul cu 2 parametrii
	Cafenea(string denumireCafenea, int nrAngajati) :anInfiintare(0) {
		this->denumireCafenea = denumireCafenea;
		this->nrAngajati = nrAngajati;
		this->cheltuieliUtilitatiPerLuna = 0;
		this->esteCunoscuta = 0;
	}

	//Constructorul cu 3 parametrii
	Cafenea(string denumireCafenea, int nrAngajati, float cheltuieliUtilitatiPerLuna) :anInfiintare(0) {
		this->denumireCafenea = denumireCafenea;
		this->nrAngajati = nrAngajati;
		this->cheltuieliUtilitatiPerLuna = cheltuieliUtilitatiPerLuna;
		this->esteCunoscuta = 0;
	}

	//Constructorul cu toti parametrii
	Cafenea(string denumireCafenea, int nrAngajati, float cheltuieliUtilitatiPerLuna, bool esteCunoscuta, int anInfiintare) :anInfiintare(anInfiintare)
	{
		this->denumireCafenea = denumireCafenea;
		this->nrAngajati = nrAngajati;
		this->cheltuieliUtilitatiPerLuna = cheltuieliUtilitatiPerLuna;
		this->esteCunoscuta = esteCunoscuta;

	}

	string getDenumireCafenea() {
		return this->denumireCafenea;
	}

	int getNrAngajati() {
		return this->nrAngajati;
	}

	float getCheltuieliUtilitatiPerLuna() {
		return this->cheltuieliUtilitatiPerLuna;
	}

	bool getEsteCunoscuta() {
		return this->esteCunoscuta;
	}

	int getAnInfiintare() {
		return this->anInfiintare;
	}


	void setdenumireCafenea(string denumireNouaCafenea) {

		this->denumireCafenea = denumireNouaCafenea;
	}

	void setnrAngajati(int nrNouAngajati) {

		this->nrAngajati = nrNouAngajati;
	}

	void setcheltuieliUtilitatiPerLuna(float cheltuieliUtilitatiNoiPerLuna) {
		this->cheltuieliUtilitatiPerLuna = cheltuieliUtilitatiNoiPerLuna;
	}

	void setesteCunoscuta(bool esteNouaCunoscuta) {
		this->esteCunoscuta = esteNouaCunoscuta;
	}
};
int Cafenea::clasaCaenPrincipala = 5160;

void main() {
	Cafenea c1;
	cout << "Denumire cafenea:" << c1.getDenumireCafenea() << endl;
	cout << "Numar angajati:" << c1.getNrAngajati() << endl;
	cout << "Cheltuieli utilitati per luna:" << c1.getCheltuieliUtilitatiPerLuna() << endl;
	cout << "Este cunoscuta:" << c1.getEsteCunoscuta() << endl;
	cout << "An infiintare:" << c1.getAnInfiintare() << endl;
	cout << endl << endl;


	Cafenea c2("Green Caffe");
	cout << "Denumire cafenea:" << c2.getDenumireCafenea() << endl;
	cout << "Numar angajati:" << c2.getNrAngajati() << endl;
	cout << "Cheltuieli utilitati Per Luna:" << c2.getCheltuieliUtilitatiPerLuna() << endl;
	cout << "Este cunoscuta:" << c2.getEsteCunoscuta() << endl;
	cout << "An infiintare:" << c2.getAnInfiintare() << endl;
	cout << endl << endl;

	Cafenea c3("Bistro Aroma", 9);
	cout << "Denumire cafenea:" << c3.getDenumireCafenea() << endl;
	cout << "Numar angajati:" << c3.getNrAngajati() << endl;
	cout << "Cheltuieli utilitati per luna:" << c3.getCheltuieliUtilitatiPerLuna() << endl;
	cout << "Este cunoscuta:" << c3.getEsteCunoscuta() << endl;
	cout << "An infiintare:" << c3.getAnInfiintare() << endl;
	cout << endl << endl;

	Cafenea c4("Coquette Bistro Caffe", 14, 437.8);
	cout << "Denumire cafenea:" << c4.getDenumireCafenea() << endl;
	cout << "Numar angajati:" << c4.getNrAngajati() << endl;
	cout << "Cheltuieli utilitati per luna:" << c4.getCheltuieliUtilitatiPerLuna() << endl;
	cout << "Este cunoscuta:" << c4.getEsteCunoscuta() << endl;
	cout << "An infiintare:" << c4.getAnInfiintare() << endl;
	cout << endl << endl;

	Cafenea c5("Tuccano", 5, 234.8, 1, 2018);
	cout << "Denumire cafenea:" << c5.getDenumireCafenea() << endl;
	cout << "Numar angajati:" << c5.getNrAngajati() << endl;
	cout << "Cheltuieli utilitati per luna:" << c5.getCheltuieliUtilitatiPerLuna() << endl;
	cout << "Este cunoscuta:" << c5.getEsteCunoscuta() << endl;
	cout << "An infiintare:" << c5.getAnInfiintare() << endl;
	cout << endl << endl;

	Cafenea c6("TED's Coffee", 12, 421.1, 1, 2020);
	cout << "Denumire cafenea:" << c6.getDenumireCafenea() << endl;
	cout << "Numar angajati:" << c6.getNrAngajati() << endl;
	cout << "Cheltuieli utilitati per luna:" << c6.getCheltuieliUtilitatiPerLuna() << endl;
	cout << "Este cunoscuta:" << c6.getEsteCunoscuta() << endl;
	cout << "An infiintare:" << c6.getAnInfiintare() << endl;
	cout << endl << endl;


	cout << "--------------------APEL SETTERI-----------------" << endl << endl;
	cout << "Obiectul c1 inainte de a apela setteri:" << endl << endl;
	cout << "Denumire cafenea:" << c1.getDenumireCafenea() << endl;
	cout << "Numar angajati:" << c1.getNrAngajati() << endl;
	cout << "Cheltuieli utilitati per luna:" << c1.getCheltuieliUtilitatiPerLuna() << endl;
	cout << "Este cunoscuta:" << c1.getEsteCunoscuta() << endl;
	cout << "An infiintare:" << c1.getAnInfiintare() << endl;
	cout << endl << endl;

	c1.setdenumireCafenea("Habitts Coffee Bar");
	c1.setnrAngajati(4);
	c1.setcheltuieliUtilitatiPerLuna(287.2);
	c1.setesteCunoscuta(0);

	cout << "Obiectul c1 dupa ce au fost apelati setterii:" << endl << endl;
	cout << "Denumire cafenea:" << c1.getDenumireCafenea() << endl;
	cout << "Numar angajati:" << c1.getNrAngajati() << endl;
	cout << "Cheltuieli utilitati per luna:" << c1.getCheltuieliUtilitatiPerLuna() << endl;
	cout << "Este cunoscuta:" << c1.getEsteCunoscuta() << endl;
	cout << "An infiintare:" << c1.getAnInfiintare() << endl;

}
