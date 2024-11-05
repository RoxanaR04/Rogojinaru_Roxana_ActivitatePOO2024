#define _CRT_SECURE_NO_WARNINGS 

#include<iostream>
using namespace std;





class Magazin
{

	string denumireMagazin;
	int nrAngajati;
	float suprafataMagazinMP;
	bool esteNonStop;
	const int anInfiintare;
	static int clasaCAENPrincipala; //47 (toate magazinele sunt incadrate la comert cod 47 in codul CAEN)

	char* numeProprietar;
	int nrProduse;
	float* preturiProduse;
	string* denumiriProduse;
public:

	Magazin() :anInfiintare(0)
	{
		this->denumireMagazin = "Anonima";
		this->nrAngajati = 0;
		this->suprafataMagazinMP = 0;
		this->esteNonStop = 0;

		//1.ALOCAREA DE MEMORIE
		this->numeProprietar = new char[strlen("Anonim") + 1];
		strcpy(this->numeProprietar, "Anonim");
		this->nrProduse = 0;
		this->preturiProduse = NULL;
		this->denumiriProduse = NULL;


	}

	//CONSTRUCTORUL CU UN PARAMETRU
	Magazin(string denumireMagazin) :anInfiintare(0)
	{
		this->denumireMagazin = denumireMagazin;
		this->nrAngajati = 0;
		this->suprafataMagazinMP = 0;
		this->esteNonStop = 0;

		//1.ALOCAREA DE MEMORIE
		this->numeProprietar = new char[strlen("Anonim") + 1];
		//2.INITIALIZAREA
		strcpy(this->numeProprietar, "Anonim");
		this->nrProduse = 0;
		this->preturiProduse = NULL;
		this->denumiriProduse = NULL;
	}

	//CONSTRUCTORUL CU DOI PARAMETRII
	Magazin(string denumireMagazin, int nrAngajati) :anInfiintare(0)
	{
		this->denumireMagazin = denumireMagazin;
		this->nrAngajati = nrAngajati;
		this->suprafataMagazinMP = 0;
		this->esteNonStop = 0;

		//1.ALOCAREA DE MEMORIE
		this->numeProprietar = new char[strlen("Anonim") + 1];
		//2.INITIALIZAREA
		strcpy(this->numeProprietar, "Anonim");

		this->nrProduse = 0;
		this->preturiProduse = NULL;
		this->denumiriProduse = NULL;
	}

	//CONSTRUCTORUL CU TREI PARAMETRII
	Magazin(string denumireMagazin, int nrAngajati, float suprafataMagazinMP) :anInfiintare(0)
	{
		this->denumireMagazin = denumireMagazin;
		this->nrAngajati = nrAngajati;
		this->suprafataMagazinMP = suprafataMagazinMP;
		this->esteNonStop = 0;

		//1.ALOCAREA DE MEMORIE
		this->numeProprietar = new char[strlen("Anonim") + 1];
		//2.INITIALIZAREA
		strcpy(this->numeProprietar, "Anonim");
		this->nrProduse = 0;
		this->preturiProduse = NULL;
		this->denumiriProduse = NULL;
	}

	//CONSTRUCTORUL CU TOTI PARAMETRII
	Magazin(string denumireMagazin, int nrAngajati, float suprafataMagazinMP, bool esteNonStop, int anInfiintare, const char* numeProprietar, int nrProduse, float* preturiProduse, string* denumiriProduse) :anInfiintare(anInfiintare)
	{
		this->denumireMagazin = denumireMagazin;
		this->nrAngajati = nrAngajati;
		this->suprafataMagazinMP = suprafataMagazinMP;
		this->esteNonStop = esteNonStop;

		//1.ALOCAREA DE MEMORIE
		this->numeProprietar = new char[strlen(numeProprietar) + 1];
		//2.INITIALIZAREA
		strcpy(this->numeProprietar, numeProprietar);

		this->nrProduse = nrProduse;
		//1.Alocarea de memorie
		this->preturiProduse = new float[this->nrProduse];
		this->denumiriProduse = new string[this->nrProduse];
		//2.Initializarea
		for (int i = 0; i < this->nrProduse; i++)
		{
			this->preturiProduse[i] = preturiProduse[i];
			this->denumiriProduse[i] = denumiriProduse[i];
		}


	}



	string getDenumireMagazin()
	{
		return this->denumireMagazin;
	}

	int getNrAngajati()
	{
		return this->nrAngajati;
	}

	float getSuprafataMagazinMP()
	{
		return this->suprafataMagazinMP;
	}

	bool getEsteNonStop()
	{
		return this->esteNonStop;
	}

	int getAnInfiintare()
	{
		return this->anInfiintare;
	}

	char* getNumeProprietar()
	{
		return this->numeProprietar;
	}

	int getNrProduse()
	{
		return this->nrProduse;
	}

	float* getPreturiProduse()
	{
		return this->preturiProduse;
	}

	string* getDenumiriProduse()
	{
		return this->denumiriProduse;
	}


	void setDenumireMagazin(string denumireNouaMagazin)
	{
		this->denumireMagazin = denumireNouaMagazin;
	}

	void setNrAngajati(int nrNouAngajati)
	{
		this->nrAngajati = nrNouAngajati;
	}

	void setSuprafataMagazinMP(float suprafataMagazinNouaMP)
	{
		this->suprafataMagazinMP = suprafataMagazinNouaMP;
	}

	void setEsteNonStop(bool esteNonStopValoareNoua)
	{
		this->esteNonStop = esteNonStopValoareNoua;
	}

};

//AICI SE INITIALIZEAZA ATRIBUTUL STATIC
int Magazin::clasaCAENPrincipala = 47;

void main()
{

	Magazin m1;
	cout << "Denumirea magazinului este:" << m1.getDenumireMagazin() << endl;
	cout << "Numarul de angajati este:" << m1.getNrAngajati() << endl;
	cout << "Suprafata este:" << m1.getSuprafataMagazinMP() << endl;
	cout << "Este non-stop? (1-DA ; 0-NU):" << m1.getEsteNonStop() << endl;
	cout << "An infiintare:" << m1.getAnInfiintare() << endl;
	cout << "Nume proprietar:" << m1.getNumeProprietar() << endl;
	cout << "Nr produse:" << m1.getNrProduse() << endl;
	cout << "Produse:" << endl;
	for (int i = 0; i < m1.getNrProduse(); i++)
	{
		cout << "Pret: " << m1.getPreturiProduse()[i] << endl;
		cout << "Denumire: " << m1.getDenumiriProduse()[i] << endl;
	}
	cout << endl << endl;

	Magazin m2("Flanco");
	cout << "Denumirea magazinului este:" << m2.getDenumireMagazin() << endl;
	cout << "Numarul de angajati este:" << m2.getNrAngajati() << endl;
	cout << "Suprafata este:" << m2.getSuprafataMagazinMP() << endl;
	cout << "Este non-stop? (1-DA ; 0-NU):" << m2.getEsteNonStop() << endl;
	cout << "An infiintare:" << m2.getAnInfiintare() << endl;
	cout << "Nume proprietar:" << m2.getNumeProprietar() << endl;
	cout << "Nr produse:" << m2.getNrProduse() << endl;
	cout << "Produse:" << endl;
	for (int i = 0; i < m2.getNrProduse(); i++)
	{
		cout << "Pret: " << m2.getPreturiProduse()[i] << endl;
		cout << "Denumire: " << m2.getDenumiriProduse()[i] << endl;
	}

	cout << endl << endl;

	Magazin m3("Zara", 50);
	cout << "Denumirea magazinului este:" << m3.getDenumireMagazin() << endl;
	cout << "Numarul de angajati este:" << m3.getNrAngajati() << endl;
	cout << "Suprafata este:" << m3.getSuprafataMagazinMP() << endl;
	cout << "Este non-stop? (1-DA ; 0-NU):" << m3.getEsteNonStop() << endl;
	cout << "An infiintare:" << m3.getAnInfiintare() << endl;
	cout << "Nume proprietar:" << m3.getNumeProprietar() << endl;
	cout << "Nr produse:" << m3.getNrProduse() << endl;
	cout << "Produse:" << endl;
	for (int i = 0; i < m3.getNrProduse(); i++)
	{
		cout << "Pret: " << m3.getPreturiProduse()[i] << endl;
		cout << "Denumire: " << m3.getDenumiriProduse()[i] << endl;
	}
	cout << endl << endl;

	Magazin m4("Nike", 30, 100.9);
	cout << "Denumirea magazinului este:" << m4.getDenumireMagazin() << endl;
	cout << "Numarul de angajati este:" << m4.getNrAngajati() << endl;
	cout << "Suprafata este:" << m4.getSuprafataMagazinMP() << endl;
	cout << "Este non-stop? (1-DA ; 0-NU):" << m4.getEsteNonStop() << endl;
	cout << "An infiintare:" << m4.getAnInfiintare() << endl;
	cout << "Nume proprietar:" << m4.getNumeProprietar() << endl;
	cout << "Nr produse:" << m4.getNrProduse() << endl;
	cout << "Produse:" << endl;
	for (int i = 0; i < m4.getNrProduse(); i++)
	{
		cout << "Pret: " << m4.getPreturiProduse()[i] << endl;
		cout << "Denumire: " << m4.getDenumiriProduse()[i] << endl;
	}
	cout << endl << endl;

	float preturi1[] = { 100.5,4900.88,1200.9,55.5 };
	string denumiri1[] = { "CabluHDMI","Monitor","Mixer","Baterie" };
	Magazin m5("Altex", 190, 590.88, 0, 2000, "Ana", 4, preturi1, denumiri1);
	cout << "Denumirea magazinului este:" << m5.getDenumireMagazin() << endl;
	cout << "Numarul de angajati este:" << m5.getNrAngajati() << endl;
	cout << "Suprafata este:" << m5.getSuprafataMagazinMP() << endl;
	cout << "Este non-stop? (1-DA ; 0-NU):" << m5.getEsteNonStop() << endl;
	cout << "An infiintare:" << m5.getAnInfiintare() << endl;
	cout << "Nume proprietar:" << m5.getNumeProprietar() << endl;
	cout << "Nr produse:" << m5.getNrProduse() << endl;
	cout << "Produse:" << endl;
	for (int i = 0; i < m5.getNrProduse(); i++)
	{
		cout << "Pret: " << m5.getPreturiProduse()[i] << endl;
		cout << "Denumire: " << m5.getDenumiriProduse()[i] << endl;
	}
	cout << endl << endl;

	float preturi2[] = { 200.99,150.8,57.88 };
	string denumiri2[] = { "Rochie","Bluza","Cercei" };
	Magazin m6("H&M", 50, 300.7, 0, 2020, "Mihai", 3, preturi2, denumiri2);
	cout << "Denumirea magazinului este:" << m6.getDenumireMagazin() << endl;
	cout << "Numarul de angajati este:" << m6.getNrAngajati() << endl;
	cout << "Suprafata este:" << m6.getSuprafataMagazinMP() << endl;
	cout << "Este non-stop? (1-DA ; 0-NU):" << m6.getEsteNonStop() << endl;
	cout << "An infiintare:" << m6.getAnInfiintare() << endl;
	cout << "Nume proprietar:" << m6.getNumeProprietar() << endl;
	cout << "Nr produse:" << m6.getNrProduse() << endl;
	cout << "Produse:" << endl;
	for (int i = 0; i < m6.getNrProduse(); i++)
	{
		cout << "Pret: " << m6.getPreturiProduse()[i] << endl;
		cout << "Denumire: " << m6.getDenumiriProduse()[i] << endl;
	}
	cout << endl << endl;

	cout << "--------------------------------APEL SETTERI--------------------------" << endl << endl;
	cout << "Obiectul m1 inainte de a apela setterii:" << endl << endl;
	cout << "Denumirea magazinului este:" << m1.getDenumireMagazin() << endl;
	cout << "Numarul de angajati este:" << m1.getNrAngajati() << endl;
	cout << "Suprafata este:" << m1.getSuprafataMagazinMP() << endl;
	cout << "Este non-stop? (1-DA ; 0-NU):" << m1.getEsteNonStop() << endl;
	cout << "An infiintare:" << m1.getAnInfiintare() << endl;
	cout << "Nume proprietar:" << m1.getNumeProprietar() << endl;
	cout << "Nr produse:" << m1.getNrProduse() << endl;
	cout << "Produse:" << endl;
	for (int i = 0; i < m1.getNrProduse(); i++)
	{
		cout << "Pret: " << m1.getPreturiProduse()[i] << endl;
		cout << "Denumire: " << m1.getDenumiriProduse()[i] << endl;
	}
	cout << endl << endl;

	m1.setDenumireMagazin("Profi");
	m1.setNrAngajati(90);
	m1.setSuprafataMagazinMP(900.5);
	m1.setEsteNonStop(1);

	cout << "Obiectul m1 dupa ce au fost apelati setterii:" << endl << endl;
	cout << "Denumirea magazinului este:" << m1.getDenumireMagazin() << endl;
	cout << "Numarul de angajati este:" << m1.getNrAngajati() << endl;
	cout << "Suprafata este:" << m1.getSuprafataMagazinMP() << endl;
	cout << "Este non-stop? (1-DA ; 0-NU):" << m1.getEsteNonStop() << endl;
	cout << "An infiintare:" << m1.getAnInfiintare() << endl;
	cout << "Nume proprietar:" << m1.getNumeProprietar() << endl;
	cout << "Nr produse:" << m1.getNrProduse() << endl;
	cout << "Produse:" << endl;
	for (int i = 0; i < m1.getNrProduse(); i++)
	{
		cout << "Pret: " << m1.getPreturiProduse()[i] << endl;
		cout << "Denumire: " << m1.getDenumiriProduse()[i] << endl;
	}
	cout << endl << endl;

}