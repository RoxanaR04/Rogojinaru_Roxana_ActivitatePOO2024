#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

class Cafenea {
	string denumireCafenea;
	int nrAngajati;
	float cheltuieliUtilitatiPerLuna;
	bool esteCunoscuta;
	const int anInfiintare;
	static int clasaCAENPrincipala;

	char* numePropietar;
	int nrCafele;
	float* preturiCafele;
	string* denumiriCafele;

public:
	//Constructorul fara parametrii
	Cafenea() :anInfiintare(0)
	{
		this->denumireCafenea = "Anonima";
		this->cheltuieliUtilitatiPerLuna = 0;
		this->nrAngajati = 0;
		this->esteCunoscuta = 0;

		this->numePropietar = new char[strlen("Anonima") + 1];
		strcpy(this->numePropietar, "Anonima");
		this->nrCafele = 0;
		this->preturiCafele = NULL;
		this->denumiriCafele = NULL;
	}

	//Constructorul cu un parametru
	Cafenea(string denumireCafenea) :anInfiintare(0)
	{
		this->denumireCafenea = denumireCafenea;
		this->nrAngajati = 0;
		this->cheltuieliUtilitatiPerLuna = 0;
		this->esteCunoscuta = 0;

		this->numePropietar = new char[strlen("Anonima") + 1];
		strcpy(this->numePropietar, "Anonima");
		this->nrCafele = 0;
		this->preturiCafele = NULL;
		this->denumiriCafele = NULL;
	}

	//Constructorul cu 2 parametrii
	Cafenea(string denumireCafenea, int nrAngajati) :anInfiintare(0) {
		this->denumireCafenea = denumireCafenea;
		this->nrAngajati = nrAngajati;
		this->cheltuieliUtilitatiPerLuna = 0;
		this->esteCunoscuta = 0;

		this->numePropietar = new char[strlen("Anonima") + 1];
		strcpy(this->numePropietar, "Anonima");
		this->nrCafele = 0;
		this->preturiCafele = NULL;
		this->denumiriCafele = NULL;
	}

	//Constructorul cu 3 parametrii
	Cafenea(string denumireCafenea, int nrAngajati, float cheltuieliUtilitatiPerLuna) :anInfiintare(0) {
		this->denumireCafenea = denumireCafenea;
		this->nrAngajati = nrAngajati;
		this->cheltuieliUtilitatiPerLuna = cheltuieliUtilitatiPerLuna;
		this->esteCunoscuta = 0;

		this->numePropietar = new char[strlen("Anonima") + 1];
		strcpy(this->numePropietar, "Anonima");
		this->nrCafele = 0;
		this->preturiCafele = NULL;
		this->denumiriCafele = NULL;
	}

	//Constructorul cu toti parametrii
	Cafenea(string denumireCafenea, int nrAngajati, float cheltuieliUtilitatiPerLuna, bool esteCunoscuta, int anInfiintare, const char* numePropietar, int nrCafele, float* preturiCafele, string* denumiriCafele) :anInfiintare(anInfiintare)
	{
		this->denumireCafenea = denumireCafenea;
		this->nrAngajati = nrAngajati;
		this->cheltuieliUtilitatiPerLuna = cheltuieliUtilitatiPerLuna;
		this->esteCunoscuta = esteCunoscuta;

		this->numePropietar = new char[strlen("numePropietar") + 1];
		strcpy(this->numePropietar, "numePropietar");
		this->nrCafele = nrCafele;
		this->preturiCafele = new float[this->nrCafele];
		this->denumiriCafele = new string[this->nrCafele];
		for (int i = 0; i < this->nrCafele; i++) {
			this->preturiCafele[i] = preturiCafele[i];
			this->denumiriCafele[i] = denumiriCafele[i];
		}

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

	char* getnumepropietar() {
		this->numePropietar;
	}

	int getnrCafele() {
		this->nrCafele;
	}

	float* getpreturiCafele() {
		this->preturiCafele;
	}

	string* getdenumiriCafele() {
		this->denumiriCafele;
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

	void setnumePropietar(const char* numeNouPropietar) {
		if (this->numePropietar != NULL) {
			delete[] this->numePropietar;
		}

		this->numePropietar = new char[strlen(numeNouPropietar) + 1];
		strcpy(this->numePropietar, numeNouPropietar);
	}

	void setCafele(int nrNouCafele, float* preturiNoiCafele, string* denumiriNoiCafele) {
		if (this->preturiCafele != NULL) {
			delete[] this->preturiCafele;
		}

		if (this->denumiriCafele != NULL) {
			delete[] this->denumiriCafele;
		}

		this->preturiCafele = new float[this->nrCafele];
		this->denumiriCafele = new string[this->nrCafele];

		for (int i = 0; i < this->nrCafele; i++) {
			this->preturiCafele[i] = preturiCafele[i];
			this->denumiriCafele[i] = denumiriCafele[i];
		}
	}

	~Cafenea() {
		if (this->numePropietar != NULL) {
			delete[] this->numePropietar;
		}

		if (this->preturiCafele != NULL) {
			delete[] this->preturiCafele;
		}

		if (this->denumiriCafele != NULL) {
			delete[] this->denumiriCafele;
		}
	}

	Cafenea(const Cafenea& obj) :anInfiintare(obj.anInfiintare)
	{
		this->denumireCafenea = obj.denumireCafenea;
		this->nrAngajati = obj.nrAngajati;
		this->cheltuieliUtilitatiPerLuna = obj.cheltuieliUtilitatiPerLuna;
		this->esteCunoscuta = obj.esteCunoscuta;
		this->numePropietar = new char[strlen(obj.numePropietar) + 1];
		strcpy(this->numePropietar, obj.numePropietar);
		this->nrCafele = obj.nrCafele;
		this->preturiCafele = new float[obj.nrCafele];
		this->denumiriCafele = new string[obj.nrCafele];
		for (int i = 0; i < this->nrCafele; i++) {
			this->preturiCafele[i] = preturiCafele[i];
			this->denumiriCafele[i] = denumiriCafele[i];
		}

	}

	Cafenea& operator=(const Cafenea& obj)
	{
		{
			if (this != &obj)
				if (this->numePropietar != NULL)
				{
					delete[] this->numePropietar;
				}

			if (this->preturiCafele != NULL)
			{
				delete[] this->preturiCafele;
			}

			if (this->denumiriCafele != NULL)
			{
				delete[] this->denumiriCafele;
			}

			this->denumireCafenea = obj.denumireCafenea;
			this->nrAngajati = obj.nrAngajati;
			this->cheltuieliUtilitatiPerLuna = obj.cheltuieliUtilitatiPerLuna;
			this->esteCunoscuta = obj.esteCunoscuta;
			this->numePropietar = new char[strlen(obj.numePropietar) + 1];
			strcpy(this->numePropietar, obj.numePropietar);
			this->nrCafele = obj.nrCafele;
			this->preturiCafele = new float[obj.nrCafele];
			this->denumiriCafele = new string[obj.nrCafele];
			for (int i = 0; i < this->nrCafele; i++)
			{
				this->preturiCafele[i] = preturiCafele[i];
				this->denumiriCafele[i] = denumiriCafele[i];
			}

		}
		return *this;
	}

	//MAXIM - Sa se det cea mai mare valoare din vectorul float* preturiCafele
	float pretMax() {
		float rezultat;
		rezultat = this->preturiCafele[0];
		for (int i = 1; i < this->nrCafele; i++) {
			if (this->preturiCafele[i] > rezultat) {
				rezultat = this->preturiCafele[i];
			}

		}

	}

	//MINIM- Sa se det cea mai mica valoare din vectorul float* preturiCafele
	int pretMin() {
		int rezultat;
		rezultat = this->preturiCafele[0];
		for (int i = 1; i < this->nrCafele; i++) {
			if (this->preturiCafele[i] < rezultat) {
				rezultat = this->preturiCafele[i];
			}
		}
	}

	//SUMA-Sa se det lichiditatile din cafenea
	int suma() {
		int suma;
		suma = 0;
		for (int i = 0; i < nrCafele; i++) {
			suma += this->preturiCafele[i];
		}
		return suma;
	}

	// MEDIE - Sa se det media preturilor din Cafenea
	float medie() {
		float medie;
		medie = this->suma() / this->nrCafele;
		return medie;

	}

	//APLICARE DISCOUNT - Sa se aplice un discount la alegere pt o singura cafea din stoc
	void aplicareDiscount(float discount, int pozitieCafea) {
		if (pozitieCafea >= 0 && pozitieCafea < this->nrCafele) {
			this->preturiCafele[pozitieCafea] = this->preturiCafele[pozitieCafea] - discount * this->preturiCafele[pozitieCafea];

		}

	}

	//PRAG -Sa se det cate cafele au pretul mai mare ales de un anumit prag la intamplare
	int detNrCafele(float pragPret) {
		int nrCafele;
		nrCafele = 0;
		for (int i = 0; i < this->nrCafele; i++) {
			if (this->preturiCafele[i] > pragPret) {
				nrCafele++;
			}
		}
		return nrCafele;
	}


};
int Cafenea::clasaCAENPrincipala = 5078;

void main() {
	Cafenea c1;
	cout << "Denumire cafenea:" << c1.getDenumireCafenea() << endl;
	cout << "Numar angajati:" << c1.getNrAngajati() << endl;
	cout << "Cheltuieli utilitati per luna:" << c1.getCheltuieliUtilitatiPerLuna() << endl;
	cout << "Este cunoscuta:" << c1.getEsteCunoscuta() << endl;
	cout << "An infiintare:" << c1.getAnInfiintare() << endl;
	cout << "Nume propietar:" << c1.getnumepropietar() << endl;
	cout << "Numar Cafele:" << c1.getnrCafele() << endl;
	cout << "Cafele:" << endl;
	for (int i = 0; i < c1.getnrCafele(); i++) {
		cout << "Preturi:" << c1.getpreturiCafele() << endl;
		cout << "Denumiri:" << c1.getdenumiriCafele() << endl;

	}
	cout << endl << endl;


	Cafenea c2("Green Caffe");
	cout << "Denumire cafenea:" << c2.getDenumireCafenea() << endl;
	cout << "Numar angajati:" << c2.getNrAngajati() << endl;
	cout << "Cheltuieli utilitati Per Luna:" << c2.getCheltuieliUtilitatiPerLuna() << endl;
	cout << "Este cunoscuta:" << c2.getEsteCunoscuta() << endl;
	cout << "An infiintare:" << c2.getAnInfiintare() << endl;
	cout << "Nume Propietar:" << c2.getnumepropietar() << endl;
	cout << "Numar Cafele:" << c2.getnrCafele() << endl;
	cout << "Cafele:" << endl;
	for (int i = 0; i < c2.getnrCafele(); i++) {
		cout << "Preturi:" << c2.getpreturiCafele() << endl;
		cout << "Denumiri:" << c2.getdenumiriCafele() << endl;
	}
	cout << endl << endl;

	Cafenea c3("Bistro Aroma", 9);
	cout << "Denumire cafenea:" << c3.getDenumireCafenea() << endl;
	cout << "Numar angajati:" << c3.getNrAngajati() << endl;
	cout << "Cheltuieli utilitati per luna:" << c3.getCheltuieliUtilitatiPerLuna() << endl;
	cout << "Este cunoscuta:" << c3.getEsteCunoscuta() << endl;
	cout << "An infiintare:" << c3.getAnInfiintare() << endl;
	cout << "Nume Propietar:" << c3.getnumepropietar() << endl;
	cout << "Numar Cafele:" << c3.getnrCafele() << endl;
	cout << "Cafele:" << endl;
	for (int i = 0; i < c3.getnrCafele(); i++) {
		cout << "Preturi:" << c3.getpreturiCafele() << endl;
		cout << "Denumiri:" << c3.getdenumiriCafele() << endl;
	}
	cout << endl << endl;

	Cafenea c4("Coquette Bistro Caffe", 14, 437.8);
	cout << "Denumire cafenea:" << c4.getDenumireCafenea() << endl;
	cout << "Numar angajati:" << c4.getNrAngajati() << endl;
	cout << "Cheltuieli utilitati per luna:" << c4.getCheltuieliUtilitatiPerLuna() << endl;
	cout << "Este cunoscuta:" << c4.getEsteCunoscuta() << endl;
	cout << "An infiintare:" << c4.getAnInfiintare() << endl;
	cout << "Nume Propietar:" << c4.getnumepropietar() << endl;
	cout << "Numar Cafele" << c4.getnrCafele() << endl;
	cout << "Cafele:" << endl;
	for (int i = 0; i < c4.getnrCafele(); i++) {
		cout << "Preturi:" << c4.getpreturiCafele() << endl;
		cout << "Denumiri:" << c4.getdenumiriCafele() << endl;
	}
	cout << endl << endl;

	float preturi1[] = { 10,12, 18, 25, 28, 30 };
	string denumiri1[] = { "Ciocolata Calda", "Ciocolata Calda Medie", "Capucciono", "Cappuciono Mare", "Latte", "Specilitati" };
	Cafenea c5("Tuccano", 5, 23, 1, 2018, "Ioana", 6, preturi1, denumiri1);
	cout << "Denumire cafenea:" << c5.getDenumireCafenea() << endl;
	cout << "Numar angajati:" << c5.getNrAngajati() << endl;
	cout << "Cheltuieli utilitati per luna:" << c5.getCheltuieliUtilitatiPerLuna() << endl;
	cout << "Este cunoscuta:" << c5.getEsteCunoscuta() << endl;
	cout << "An infiintare:" << c5.getAnInfiintare() << endl;
	cout << "Nume Propietar:" << c5.getnumepropietar() << endl;
	cout << "Numar Cafele:" << c5.getnrCafele() << endl;
	cout << "Cafele:" << endl;
	for (int i = 0; i < c5.getnrCafele(); i++) {
		cout << "Preturi:" << c5.getpreturiCafele() << endl;
		cout << "Denumiri:" << c5.getdenumiriCafele() << endl;
	}
	cout << endl << endl;

	float preturi2[] = { 18, 27, 25, 22, 20, 26 };
	string denumiri2[] = { "Ciocolata Calda", "Ciocolata Calda Medie", "Capucciono", "Cappuciono Mare", "Latte", "Specilitati" };
	Cafenea c6("TED's Coffee", 12, 421.1, 1, 2020, "Alina", 6, preturi2, denumiri2);
	cout << "Denumire cafenea:" << c6.getDenumireCafenea() << endl;
	cout << "Numar angajati:" << c6.getNrAngajati() << endl;
	cout << "Cheltuieli utilitati per luna:" << c6.getCheltuieliUtilitatiPerLuna() << endl;
	cout << "Este cunoscuta:" << c6.getEsteCunoscuta() << endl;
	cout << "An infiintare:" << c6.getAnInfiintare() << endl;
	cout << "Nume Propietar:" << c6.getnumepropietar() << endl;
	cout << "Numar Cafele:" << c6.getnrCafele() << endl;
	cout << "Cafele:" << endl;
	for (int i = 0; i < c6.getnrCafele();i++) {
		cout << "Preturi:" << c6.getpreturiCafele() << endl;
		cout << "Denumiri:" << c6.getdenumiriCafele() << endl;
	}
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
	c1.setnumePropietar("Alexandru");
	float preturi3[] = { 15, 18, 25 };
	string denumiri3[] = { "Ciocolata calda", "Latte Machiatto", "Irish Coffe" };
	c1.setCafele(3, preturi3, denumiri3);

	cout << "Obiectul c1 dupa ce au fost apelati setterii:" << endl << endl;
	cout << "Denumire cafenea:" << c1.getDenumireCafenea() << endl;
	cout << "Numar angajati:" << c1.getNrAngajati() << endl;
	cout << "Cheltuieli utilitati per luna:" << c1.getCheltuieliUtilitatiPerLuna() << endl;
	cout << "Este cunoscuta:" << c1.getEsteCunoscuta() << endl;
	cout << "An infiintare:" << c1.getAnInfiintare() << endl;
	cout << "Nume Propietar:" << c1.getnumepropietar() << endl;
	cout << "Numar Cafele:" << endl;
	for (int i = 0; i < c1.getnrCafele(); i++) {
		cout << "Preturi:" << c1.getpreturiCafele()[i] << endl;
		cout << "Denumiri:" << c1.getdenumiriCafele()[i] << endl;
	}

	cout << "--------------------------------APEL CONSTRUCTORUL DE COPIERE--------------------------" << endl << endl;

	Cafenea c7(c1);
	Cafenea c1;
	cout << "Denumire cafenea:" << c1.getDenumireCafenea() << endl;
	cout << "Numar angajati:" << c1.getNrAngajati() << endl;
	cout << "Cheltuieli utilitati per luna:" << c1.getCheltuieliUtilitatiPerLuna() << endl;
	cout << "Este cunoscuta:" << c1.getEsteCunoscuta() << endl;
	cout << "An infiintare:" << c1.getAnInfiintare() << endl;
	cout << "Nume propietar:" << c1.getnumepropietar() << endl;
	cout << "Numar Cafele:" << c1.getnrCafele() << endl;
	cout << "Cafele:" << endl;
	for (int i = 0; i < c1.getnrCafele(); i++) {
		cout << "Preturi:" << c1.getpreturiCafele() << endl;
		cout << "Denumiri:" << c1.getdenumiriCafele() << endl;

	}
	cout << endl << endl;

	cout << "Obiectul nou creat c7:" << endl << endl;
	cout << "Denumire cafenea:" << c7.getDenumireCafenea() << endl;
	cout << "Numar angajati:" << c7.getNrAngajati() << endl;
	cout << "Cheltuieli utilitati per luna:" << c7.getCheltuieliUtilitatiPerLuna() << endl;
	cout << "Este cunoscuta:" << c7.getEsteCunoscuta() << endl;
	cout << "An infiintare:" << c7.getAnInfiintare() << endl;
	cout << "Nume propietar:" << c7.getnumepropietar() << endl;
	cout << "Numar Cafele:" << c7.getnrCafele() << endl;
	cout << "Cafele:" << endl;
	for (int i = 0; i < c7.getnrCafele(); i++) {
		cout << "Preturi:" << c7.getpreturiCafele() << endl;
		cout << "Denumiri:" << c7.getdenumiriCafele() << endl;

	}
	cout << endl << endl;



	cout << "--------------------------------APEL OPERATORUL=--------------------------" << endl << endl;

	cout << "Obiectul c2 inainte de a fi modificat pe baza lui c4:" << endl << endl;
	cout << "Denumire cafenea:" << c2.getDenumireCafenea() << endl;
	cout << "Numar angajati:" << c2.getNrAngajati() << endl;
	cout << "Cheltuieli utilitati Per Luna:" << c2.getCheltuieliUtilitatiPerLuna() << endl;
	cout << "Este cunoscuta:" << c2.getEsteCunoscuta() << endl;
	cout << "An infiintare:" << c2.getAnInfiintare() << endl;
	cout << "Nume Propietar:" << c2.getnumepropietar() << endl;
	cout << "Numar Cafele:" << c2.getnrCafele() << endl;
	cout << "Cafele:" << endl;
	for (int i = 0; i < c2.getnrCafele(); i++) {
		cout << "Preturi:" << c2.getpreturiCafele() << endl;
		cout << "Denumiri:" << c2.getdenumiriCafele() << endl;
	}
	cout << endl << endl;


	cout << "Obiectul macheta c4:" << endl << endl;
	cout << "Denumire cafenea:" << c4.getDenumireCafenea() << endl;
	cout << "Numar angajati:" << c4.getNrAngajati() << endl;
	cout << "Cheltuieli utilitati per luna:" << c4.getCheltuieliUtilitatiPerLuna() << endl;
	cout << "Este cunoscuta:" << c4.getEsteCunoscuta() << endl;
	cout << "An infiintare:" << c4.getAnInfiintare() << endl;
	cout << "Nume Propietar:" << c4.getnumepropietar() << endl;
	cout << "Numar Cafele" << c4.getnrCafele() << endl;
	cout << "Cafele:" << endl;
	for (int i = 0; i < c4.getnrCafele(); i++) {
		cout << "Preturi:" << c4.getpreturiCafele() << endl;
		cout << "Denumiri:" << c4.getdenumiriCafele() << endl;
	}
	cout << endl << endl;

	c2 = c4;

	cout << "Obiectul c2 dupa ce a fost modificat pe baza lui c4:" << endl << endl;
	cout << "Denumire cafenea:" << c2.getDenumireCafenea() << endl;
	cout << "Numar angajati:" << c2.getNrAngajati() << endl;
	cout << "Cheltuieli utilitati Per Luna:" << c2.getCheltuieliUtilitatiPerLuna() << endl;
	cout << "Este cunoscuta:" << c2.getEsteCunoscuta() << endl;
	cout << "An infiintare:" << c2.getAnInfiintare() << endl;
	cout << "Nume Propietar:" << c2.getnumepropietar() << endl;
	cout << "Numar Cafele:" << c2.getnrCafele() << endl;
	cout << "Cafele:" << endl;
	for (int i = 0; i < c2.getnrCafele(); i++) {
		cout << "Preturi:" << c2.getpreturiCafele() << endl;
		cout << "Denumiri:" << c2.getdenumiriCafele() << endl;
	}
	cout << endl << endl;


	cout << "--------------------------------METODE--------------------" << endl << endl;

	cout << "Denumire cafenea:" << c1.getDenumireCafenea() << endl;
	cout << "Numar angajati:" << c1.getNrAngajati() << endl;
	cout << "Cheltuieli utilitati per luna:" << c1.getCheltuieliUtilitatiPerLuna() << endl;
	cout << "Este cunoscuta:" << c1.getEsteCunoscuta() << endl;
	cout << "An infiintare:" << c1.getAnInfiintare() << endl;
	cout << "Nume propietar:" << c1.getnumepropietar() << endl;
	cout << "Numar Cafele:" << c1.getnrCafele() << endl;
	cout << "Cafele:" << endl;
	for (int i = 0; i < c1.getnrCafele(); i++) {
		cout << "Preturi:" << c1.getpreturiCafele() << endl;
		cout << "Denumiri:" << c1.getdenumiriCafele() << endl;

	}
	cout << endl << endl;

	cout << "Pretul minim din cafeneaua c1 este:" << c1.pretMin() << endl << endl;
	cout << "Pretul maxim din cafeneaua c1 este:" << c1.pretMax() << endl << endl;
	cout << "Suma preturilor cafelelor din cafeneaua c1 este: " << c1.suma() << endl << endl;

	c1.aplicareDiscount(0.1, 3);
	cout << "Denumire cafenea:" << c1.getDenumireCafenea() << endl;
	cout << "Numar angajati:" << c1.getNrAngajati() << endl;
	cout << "Cheltuieli utilitati per luna:" << c1.getCheltuieliUtilitatiPerLuna() << endl;
	cout << "Este cunoscuta:" << c1.getEsteCunoscuta() << endl;
	cout << "An infiintare:" << c1.getAnInfiintare() << endl;
	cout << "Nume propietar:" << c1.getnumepropietar() << endl;
	cout << "Numar Cafele:" << c1.getnrCafele() << endl;
	cout << "Cafele:" << endl;
	for (int i = 0; i < c1.getnrCafele(); i++) {
		cout << "Preturi:" << c1.getpreturiCafele() << endl;
		cout << "Denumiri:" << c1.getdenumiriCafele() << endl;

	}
	cout << endl << endl;

	cout << "In cafeneaua c1 nr de cafele cu pretul de peste 20 lei este:" << c1.detNrCafele(20) << endl << endl;





}