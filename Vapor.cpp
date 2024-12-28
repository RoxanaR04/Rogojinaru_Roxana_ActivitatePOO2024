#include<iostream>
using namespace std;
class Vapor
{
private:
	const int id; // id-ul dupa care identificam vaporul
	static int nrVapoare;
	int capacitate;
	int nrPersoaneImbarcate;
	int* varstePasageri;
	bool auVoieAnimale; // atribut cu ajutorul care returneaza 1 daca este permis cu animale sau 0 in caz contrar
public:
	Vapor() :id(nrVapoare++)
	{
		this->capacitate = 0;
		this->nrPersoaneImbarcate = 0;
		this->varstePasageri = NULL;
		this->auVoieAnimale = 0;
	}
	Vapor(int capacitate, int nrPersoaneImbarcate, int* varstePasageri, bool auVoieAnimale) :id(nrVapoare++)
	{
		this->capacitate = capacitate;
		if (nrPersoaneImbarcate != 0 && varstePasageri != NULL)
		{
			this->varstePasageri = new int[nrPersoaneImbarcate];
			this->nrPersoaneImbarcate = nrPersoaneImbarcate;
			for (int i = 0; i < this->nrPersoaneImbarcate; i++)
				this->varstePasageri[i] = varstePasageri[i];
		}
		else
		{
			this->nrPersoaneImbarcate = 0;
			this->varstePasageri = NULL;
		}
		this->auVoieAnimale = auVoieAnimale;
	}
	Vapor(const Vapor& v) :id(v.id)
	{
		this->capacitate = v.capacitate;
		if (v.nrPersoaneImbarcate != 0 && v.varstePasageri != NULL)
		{
			this->varstePasageri = new int[v.nrPersoaneImbarcate];
			this->nrPersoaneImbarcate = v.nrPersoaneImbarcate;
			for (int i = 0; i < this->nrPersoaneImbarcate; i++)
				this->varstePasageri[i] = v.varstePasageri[i];
		}
		else
		{
			this->nrPersoaneImbarcate = 0;
			this->varstePasageri = NULL;
		}
		this->auVoieAnimale = v.auVoieAnimale;
	}
	Vapor& operator=(Vapor& v)
	{
		if (this->varstePasageri)
		{
			delete[]this->varstePasageri;
		}
		this->capacitate = v.capacitate;
		if (v.nrPersoaneImbarcate != 0 && v.varstePasageri != NULL)
		{
			this->varstePasageri = new int[v.nrPersoaneImbarcate];
			this->nrPersoaneImbarcate = v.nrPersoaneImbarcate;
			for (int i = 0; i < this->nrPersoaneImbarcate; i++)
				this->varstePasageri[i] = v.varstePasageri[i];
		}
		else
		{
			this->nrPersoaneImbarcate = 0;
			this->varstePasageri = NULL;
		}
		this->auVoieAnimale = v.auVoieAnimale;
		return *this;
	}
	int getid()
	{
		return this->id;
	}
	bool getauVoieAnimale()
	{
		return this->auVoieAnimale;
	}
	void setauVoieAnimale(bool auVoieAnimale)
	{
		this->auVoieAnimale = auVoieAnimale;
	}
	int getcapacitate()
	{
		return this->capacitate;
	}
	void setcapacitate(int capacitate)
	{
		this->capacitate = capacitate;
	}
	friend ostream& operator<<(ostream& out, Vapor& v)
	{
		out << "\n Vaporul cu id-ul " << v.id << " are capacitatea de " << v.capacitate << " persoane " << ", iar la bordul lui s-au imbarcat " << v.nrPersoaneImbarcate << " persoane " << " avand urmatoarele varste: " << endl;
		for (int i = 0; i < v.nrPersoaneImbarcate; i++)
		{
			out << v.varstePasageri[i] << " ";
		}
		if (v.auVoieAnimale == 1)
		{
			out << "\n Este permis cu animale";
		}
		else
		{
			out << "\n Nu este permis cu animale";
		}
		return out;
	}
	float calculareVarstaMedie()
	{
		float medie = 0;
		for (int i = 0; i < this->nrPersoaneImbarcate; i++)
		{
			medie += this->varstePasageri[i];
		}
		medie = medie / this->nrPersoaneImbarcate;
		return medie;
	}
	int operator()()
	{
		return this->capacitate - this->nrPersoaneImbarcate;
	}
	Vapor operator++(int)
	{
		Vapor copie = *this;
		if (this->varstePasageri != NULL)
		{
			delete[]this->varstePasageri;
		}
		this->nrPersoaneImbarcate++;
		this->varstePasageri = new int[this->nrPersoaneImbarcate];
		for (int i = 0; i < copie.nrPersoaneImbarcate; i++)
			this->varstePasageri[i] = copie.varstePasageri[i];
		this->varstePasageri[nrPersoaneImbarcate - 1] = 0;
		return copie;
	}
	~Vapor()
	{
		if (this->varstePasageri)
		{
			delete[]this->varstePasageri;
		}
	}
};
int Vapor::nrVapoare = 0;
int main()
{
	Vapor v;
	cout << v.getid() << endl;
	cout << v.getauVoieAnimale() << endl;
	v.setauVoieAnimale(1);
	cout << v.getauVoieAnimale() << endl;
	cout << v.getcapacitate() << endl;
	v.setcapacitate(200);
	cout << v.getcapacitate() << endl;
	Vapor v1(100, 4, new int[4]{ 16,78,49,60 }, 1);
	cout << v1;
	Vapor v2 = v1;
	cout << v2 << endl << endl;
	cout << v2.calculareVarstaMedie() << endl;
	int NrPersDisp = v2();
	cout << NrPersDisp << endl << endl;
	v2++;
	cout << v2;
	return 0;
}