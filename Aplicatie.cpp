#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Aplicatie {
	int IDUnic;
	int nrZileUtilizate; //cate zile este folosita aplicatia
	int *nrAccesariZilnice; // numar de accesari pe fiecare zi
	bool protectieAccesCopil; //are restrictii 1 nu are restrictii 0
public:
	static int contor;
	Aplicatie():IDUnic(contor++)
	{
		this->nrZileUtilizate = 0;
		this->nrAccesariZilnice = NULL;
		this->protectieAccesCopil = 0; //are restrictii
	}
	Aplicatie( int nrZileUtilizate, int* nrAccesariZilnice, bool protectieAccesCopil) :IDUnic(contor++)
	{
		this->nrZileUtilizate = nrZileUtilizate;
		this->nrAccesariZilnice = new int[this->nrZileUtilizate];
		for (int i = 0; i < this->nrZileUtilizate; i++)
		{
			this->nrAccesariZilnice[i] = nrAccesariZilnice[i];
		}
		this->protectieAccesCopil = protectieAccesCopil; 
	}

	//Getteri
	int getIDUnic()
	{
		return this->IDUnic;
	}
	int getNrZileUtilizate()
	{
		return this->nrZileUtilizate;
	}
	int* getNrAccesariZilnice()
	{
		return this->nrAccesariZilnice;
	}
	bool getProtectieAccesCopil()
	{
		return this->protectieAccesCopil;
	}

	//Adauga o noua zi cu 0 accesari
	void adaugaONouaZi()
	{
		int copieNrZile = this->nrZileUtilizate;
		int* copieNrAccesari = new int[copieNrZile];
		for (int i = 0; i < this->nrZileUtilizate; i++)
		{
			copieNrAccesari[i] = this->nrAccesariZilnice[i];
		}
		delete[] this->nrAccesariZilnice;
		this->nrZileUtilizate = copieNrZile + 1;
		this->nrAccesariZilnice = new int[this->nrZileUtilizate];
		for (int i = 0; i < copieNrZile; i++)
		{
			this->nrAccesariZilnice[i] = copieNrAccesari[i];
		}
		for (int i = copieNrZile; i < this->nrZileUtilizate; i++)
		{
			this->nrAccesariZilnice[i] = 0;
		}
	}

	//Constructorul de copiere
	Aplicatie(const Aplicatie& a) :IDUnic(a.IDUnic)
	{
		this->nrZileUtilizate = a.nrZileUtilizate;
		this->nrAccesariZilnice = new int[a.nrZileUtilizate];
		for (int i = 0; i < this->nrZileUtilizate; i++)
		{
			this->nrAccesariZilnice[i] = a.nrAccesariZilnice[i];
		}
		this->protectieAccesCopil = a.protectieAccesCopil;
	}

	//Operatorul egal
	Aplicatie& operator=(const Aplicatie& a)
	{
		if (this != &a)
		{
			if (this->nrAccesariZilnice != NULL)
			{
				delete[]this->nrAccesariZilnice;
			}
			this->nrZileUtilizate = a.nrZileUtilizate;
			this->nrAccesariZilnice = new int[a.nrZileUtilizate];
			for (int i = 0; i < this->nrZileUtilizate; i++)
			{
				this->nrAccesariZilnice[i] = a.nrAccesariZilnice[i];
			}
			this->protectieAccesCopil = a.protectieAccesCopil;
			return *this;
		}
	}
	

	//Metoda accesareAplicatie
	bool accesareAplictie()
	{
		if (this->protectieAccesCopil == 1)
		{
			return 0;
		}
		else
		{
			return 1;
		}
	}

	//Metoda zi cu maxim de utilizari
	int getZiCuMaximUtilizari()
	{
		int max = this->nrAccesariZilnice[0];
		int poz = 0;
		for (int i = 1; i < this->nrZileUtilizate; i++)
		{
			if (max < this->nrAccesariZilnice[i])
			{
				max = this->nrAccesariZilnice[i];
				poz = i + 1;
			}
		}
		return poz;
	}

	//Operator<<
	friend ostream& operator<<(ostream& out, const Aplicatie& a)
	{
		out << "ID:" << a.IDUnic << " ";
		out << "Nr de zile:" << a.nrZileUtilizate << " ";
		out << "Accesari pe zi:";
		for (int i = 0; i < a.nrZileUtilizate; i++)
		{
			out << a.nrAccesariZilnice[i] << " ";
		}
		out << "Are protectie:"<<a.protectieAccesCopil;
		return out;
	}

	//Operator >>
	friend istream& operator>>(istream& in, Aplicatie& a)
	{
		cout << "Introduceti nr de zile: ";
		in >> a.nrZileUtilizate;
		if (a.nrAccesariZilnice != NULL)
		{
			delete[]a.nrAccesariZilnice;
		}
		a.nrAccesariZilnice = new int[a.nrZileUtilizate];
		cout << "Introduceti nr de accesari pe zi: ";
		for (int i= 0; i < a.nrZileUtilizate; i++)
		{
			in >> a.nrAccesariZilnice[i];
		}
		cout << "Are protectie acces copil? ";
		in >> a.protectieAccesCopil;
		return in;
	}

	//Operatorul cast la int
	explicit operator int()
	{
		int suma = 0;
		for (int i = 0; i < this->nrZileUtilizate; i++)
		{
			suma = suma + this->nrAccesariZilnice[i];
		}
		return suma;
	}

	//Operatorul !
	void operator!()
	{
		if (this->protectieAccesCopil == 1)
		{
			this->protectieAccesCopil = 0;
		}
		else
		{
			this->protectieAccesCopil = 1;
		}
	}

	~Aplicatie()
	{
		if (this->nrAccesariZilnice != NULL)
		{
			delete[]this->nrAccesariZilnice;
		}
	}

};

int Aplicatie::contor = 0;

void main()
{
	Aplicatie a1;
	cout << a1.getIDUnic() << " ";
	cout << a1.getNrZileUtilizate() << " ";
	for (int i = 0; i < a1.getNrZileUtilizate(); i++)
	{
		cout << a1.getNrAccesariZilnice()[i] << " | ";
	}
	cout << a1.getProtectieAccesCopil();
	cout << endl << endl;

	int accesari1[] = { 4,5,6 };
	Aplicatie a2(3, accesari1, 1);
	cout << a2.getIDUnic() << " ";
	cout << a2.getNrZileUtilizate() << " ";
	for (int i = 0; i < a2.getNrZileUtilizate(); i++)
	{
		cout << a2.getNrAccesariZilnice()[i] << " | ";
	}
	cout << a2.getProtectieAccesCopil();
	cout << endl << endl;

	//Adauga o noua zi cu 0 accesari
	cout << "-----------------Adauga o noua zi cu 0 accesari----------------" << endl;
	a2.adaugaONouaZi();
	cout << a2.getIDUnic() << " ";
	cout << a2.getNrZileUtilizate() << " ";
	for (int i = 0; i < a2.getNrZileUtilizate(); i++)
	{
		cout << a2.getNrAccesariZilnice()[i] << " | ";
	}
	cout << a2.getProtectieAccesCopil();
	cout << endl << endl;

	//Constructorul de copiere
	cout << "-----------------Constructorul de copiere-----------------" << endl;
	Aplicatie a3 = a2;
	cout << a3.getIDUnic() << " ";
	cout << a3.getNrZileUtilizate() << " ";
	for (int i = 0; i < a2.getNrZileUtilizate(); i++)
	{
		cout << a3.getNrAccesariZilnice()[i] << " | ";
	}
	cout << a3.getProtectieAccesCopil();
	cout << endl << endl;

	//Metoda accesareAplicatie
	cout << "-----------------Metoda accesareAplicatie-----------------" << endl;
	if (a3.accesareAplictie() == 1)
	{
		cout << "Aplicata poate fi accesata de copil";
	}
	else
	{
		cout << "Apicatia nu poate fi accesata de copil";
	}

	//Metoda zi cu maxim de utilizari
	cout << endl << endl << "-----------------Metoda zi cu maxim de utilizari-----------------" << endl;
	cout << "Aplicatia a3 a fost accesata cel mai mul in ziua:" << a3.getZiCuMaximUtilizari();

	//Operatorul egal
	cout << endl << endl << "-----------------Operatorul egal-----------------" << endl;
	Aplicatie a4;
	cout << a4.getIDUnic() << " ";
	cout << a4.getNrZileUtilizate() << " ";
	for (int i = 0; i < a4.getNrZileUtilizate(); i++)
	{
		cout << a4.getNrAccesariZilnice()[i] << " | ";
	}
	cout << a4.getProtectieAccesCopil();
	cout << endl << endl;
	a4 = a3;
	cout << a4.getIDUnic() << " ";
	cout << a4.getNrZileUtilizate() << " ";
	for (int i = 0; i < a4.getNrZileUtilizate(); i++)

	{
		cout << a4.getNrAccesariZilnice()[i] << " | ";
	}
	cout << a4.getProtectieAccesCopil();
	cout << endl << endl;

	//Operator >> si <<
	cout << "-----------------Operator << si >>-----------------" << endl;
	cin >> a4;
	cout << endl << endl;
	cout << a4;

	//Operatorul cast la int
	cout << endl << endl << "-----------------Operatorul cast la int-----------------" << endl;
	int rez = (int)a4;
	cout << "Numarul total de accesari pentru aplicatia a4 este:"<<rez;

	//Operatorul!
	cout << endl << endl << "-----------------Operatorul!-----------------" << endl;
	!a4;
	cout << "Protectia a fost schimbata" << endl;
	cout << a4;
}