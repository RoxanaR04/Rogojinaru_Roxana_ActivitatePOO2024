#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class Telefon {
	const int CODUnic;
	float memorieTotala;
	int nrAplicatiiInstalate;
	float* memorieOcupata; //spatiul ocupat de fiecare aplicatie
public:
	static int contor;
	//Constructorul implicit
	Telefon() :CODUnic(contor++)
	{
		this->memorieTotala = 0;
		this->nrAplicatiiInstalate=0;
		this->memorieOcupata = NULL;
	}
	//Constrictor cu parametrii
	Telefon( float memorieTotala, int nrAplicatiiInstalate, float* memorieOcupata) :CODUnic(contor++)
	{
		this->memorieTotala = memorieTotala;
		this->nrAplicatiiInstalate = nrAplicatiiInstalate;
		this->memorieOcupata = new float[this->nrAplicatiiInstalate];
		for (int i = 0; i < this->nrAplicatiiInstalate; i++)
		{
			this->memorieOcupata[i] = memorieOcupata[i];
		}
	}

	//Getteri
	const int getCODUnic()
	{
		return this->CODUnic;
	}
	float getMemorieTotala()
	{
		return this->memorieTotala;
	}
	int getNrAplicatii()
	{
		return this->nrAplicatiiInstalate;
	}
	float* getMemorieAplicatii()
	{
		return this->memorieOcupata;
	}

	//Setter
	void setMemorieOcupata(int nrAplicatii, float* memorieOcupata)
	{
		if (this->memorieOcupata != NULL)
		{
			delete[] this->memorieOcupata;
		}
		this->nrAplicatiiInstalate = nrAplicatii;
		this->memorieOcupata = new float[this->nrAplicatiiInstalate];
		for (int i = 0; i < this->nrAplicatiiInstalate; i++)
		{
			this->memorieOcupata[i] = memorieOcupata[i];
		}
	}


	//Constructorul de copiere
	Telefon(const Telefon& t):CODUnic(contor++)
	{
		this->memorieTotala = t.memorieTotala;
		this->nrAplicatiiInstalate = t.nrAplicatiiInstalate;
		this->memorieOcupata = new float[t.nrAplicatiiInstalate];
		for (int i = 0; i < t.nrAplicatiiInstalate; i++)
		{
			this->memorieOcupata[i] = t.memorieOcupata[i];
		}
	}

	//Metoda verifica memorie
	float verificaMemorie()
	{
		float suma = 0;
		float memorieRamasa;
		for(int i = 0; i < this->nrAplicatiiInstalate; i++)
		{
			suma = suma + this->memorieOcupata[i];
		}
		memorieRamasa = this->memorieTotala - suma;
		if (memorieRamasa > 0)
		{
			return memorieRamasa;
		}
		else
		{
			return -1;
		}
	}

	//Metoda upgrade memorie
	void upgradeMemorie(float val)
	{
		int copieNrAplicatii = this->nrAplicatiiInstalate;
		float* copieMemorieAplicatii = new float[copieNrAplicatii];
		for (int i = 0; i < copieNrAplicatii; i++)
		{
			copieMemorieAplicatii[i] = this->memorieOcupata[i];
		}
		delete[] this->memorieOcupata;
		this->nrAplicatiiInstalate = copieNrAplicatii + 1;
		this->memorieOcupata = new float[this->nrAplicatiiInstalate];
		for (int i = 0; i < copieNrAplicatii; i++)
		{
			this->memorieOcupata[i] = copieMemorieAplicatii[i];
		}
		this->memorieOcupata[copieNrAplicatii] = val;
	}

	//Operatorul egal
	Telefon& operator=(const Telefon& t)
	{
		if (this != &t)
		{
			if (this->memorieOcupata != NULL)
			{
				delete[] this->memorieOcupata;
			}
			this->memorieTotala = t.memorieTotala;
			this->nrAplicatiiInstalate = t.nrAplicatiiInstalate;
			this->memorieOcupata = new float[t.nrAplicatiiInstalate];
			for (int i = 0; i < t.nrAplicatiiInstalate; i++)
			{
				this->memorieOcupata[i] = t.memorieOcupata[i];
			}
		}
		return *this;
	}

	//Operatorul <<
	friend ostream& operator<<(ostream& out, const Telefon& t)
	{
		out << "COD:" << t.CODUnic << " ";
		out << "Memorie totala:" << t.memorieTotala << " ";
		out << "Nr aplicatii:" << t.nrAplicatiiInstalate << " ";
		out << "Memorie aplicatii:";
		for (int i = 0; i < t.nrAplicatiiInstalate; i++)
		{
			out << t.memorieOcupata[i] << " | ";
		}
		return out;
	}

	//Operatorul >>
	friend istream& operator>>(istream& in, Telefon& t)
	{
		if (t.memorieOcupata != NULL)
		{
			delete[]t.memorieOcupata;
		}
		cout << "Introduceti memoria totala:";
		in >> t.memorieTotala;
		cout << "Introduceti nr de aplicatii:";
		in >> t.nrAplicatiiInstalate;
		cout << "Introduceti memoria ocupata de apicatii:";
		t.memorieOcupata = new float[t.nrAplicatiiInstalate];
		for (int i = 0; i < t.nrAplicatiiInstalate; i++)
		{
			in >> t.memorieOcupata[i];
		}
		return in;
	}


	//Operatorul >
	bool operator>(const Telefon&t)
	{
		return this->memorieTotala > t.memorieTotala;
	}


	//Operatorul[]
	float operator[](int index)
	{
		float err = -1;
		if (index >= 0 && index < this->nrAplicatiiInstalate)
		{
			return this->memorieOcupata[index];
		}
		else
		{
			return err;
		}
	}

	//Destructorul
	~Telefon()
	{
		if (this->memorieOcupata != NULL)
		{
			delete[] this->memorieOcupata;
		}
	}
};

int Telefon::contor = 1;

void main()
{
	Telefon t1;
	cout << "COD:" << t1.getCODUnic()<<endl;
	cout << "Memorie totala:" << t1.getMemorieTotala() << endl;
	cout << "Nr aplicatii:" << t1.getNrAplicatii() << endl;
	cout << "Memorie aplicatii:";
	for (int i = 0; i < t1.getNrAplicatii(); i++)
	{
		cout << t1.getMemorieAplicatii()[i] << " | ";
	}
	cout << endl << endl;

	float apl1[] = { 45,50.1,55 };
	Telefon t2(256,3,apl1);
	cout << "COD:" << t2.getCODUnic() << endl;
	cout << "Memorie totala:" << t2.getMemorieTotala() << endl;
	cout << "Nr aplicatii:" << t2.getNrAplicatii() << endl;
	cout << "Memorie aplicatii:";
	for (int i = 0; i < t2.getNrAplicatii(); i++)
	{
		cout << t2.getMemorieAplicatii()[i] << " | ";
	}
	cout << endl << endl;

	//Setter memorie aplicatii
	cout << endl << endl << "-------------------Setter memorie aplicatii-----------------" << endl << endl;
	float apl2[] = { 60,70 };
	t1.setMemorieOcupata(2, apl2);
	cout << "COD:" << t1.getCODUnic() << endl;
	cout << "Memorie totala:" << t1.getMemorieTotala() << endl;
	cout << "Nr aplicatii:" << t1.getNrAplicatii() << endl;
	cout << "Memorie aplicatii:";
	for (int i = 0; i < t1.getNrAplicatii(); i++)
	{
		cout << t1.getMemorieAplicatii()[i] << " | ";
	}
	cout << endl << endl;

	//Constructorul de copiere
	cout << endl << endl << "-------------------Constructorul de copiere-----------------" << endl << endl;
	Telefon t3 = t2;
	cout << "COD:" << t3.getCODUnic() << endl;
	cout << "Memorie totala:" << t3.getMemorieTotala() << endl;
	cout << "Nr aplicatii:" << t3.getNrAplicatii() << endl;
	cout << "Memorie aplicatii:";
	for (int i = 0; i < t3.getNrAplicatii(); i++)
	{
		cout << t3.getMemorieAplicatii()[i] << " | ";
	}
	cout << endl << endl;

	//Metoda verifica memorie
	cout << endl << endl << "-------------------Metoda verifica memorie-----------------" << endl << endl;
	if (t3.verificaMemorie() == -1)
	{
		cout << "Telefonul nu mai are memorie!";
	}
	else
	{
		cout << "Memoria ramasa din telefon este:" << t3.verificaMemorie();
	}
	cout << endl << endl;

	//Metoda upgrade memorie
	cout << endl << endl << "-------------------Metoda upgrade memorie-----------------" << endl << endl;
	t3.upgradeMemorie(30);
	cout << "COD:" << t3.getCODUnic() << endl;
	cout << "Memorie totala:" << t3.getMemorieTotala() << endl;
	cout << "Nr aplicatii:" << t3.getNrAplicatii() << endl;
	cout << "Memorie aplicatii:";
	for (int i = 0; i < t3.getNrAplicatii(); i++)
	{
		cout << t3.getMemorieAplicatii()[i] << " | ";
	}
	cout << endl << endl;


	//Operatorul egal
	cout << endl << endl << "-------------------Operatorul egal-----------------" << endl << endl;
	cout << "COD:" << t1.getCODUnic() << endl;
	cout << "Memorie totala:" << t1.getMemorieTotala() << endl;
	cout << "Nr aplicatii:" << t1.getNrAplicatii() << endl;
	cout << "Memorie aplicatii:";
	for (int i = 0; i < t1.getNrAplicatii(); i++)
	{
		cout << t1.getMemorieAplicatii()[i] << " | ";
	}
	cout << endl << endl;
	t1 = t3;
	cout << "COD:" << t1.getCODUnic() << endl;
	cout << "Memorie totala:" << t1.getMemorieTotala() << endl;
	cout << "Nr aplicatii:" << t1.getNrAplicatii() << endl;
	cout << "Memorie aplicatii:";
	for (int i = 0; i < t1.getNrAplicatii(); i++)
	{
		cout << t1.getMemorieAplicatii()[i] << " | ";
	}
	cout << endl << endl;

	//Operatorul <<
	cout << endl << endl << "-------------------Operatorul <<-----------------" << endl << endl;
	cout << t1;
	cout << endl << endl;

	//Operatorul >>
	cout << endl << endl << "-------------------Operatorul >>-----------------" << endl << endl;
	cin >> t1;
	cout << endl << endl;
	cout << t1;
	cout << endl << endl;

	//Operatorul >
	cout << endl << endl << "-------------------Operatorul >-----------------" << endl << endl;
	if (t3 > t1)
	{
		cout << "Telefonul t3 are mai multa memorie decat telefonul t1";
	}
	else
	{
		cout << "Telefonul t1 are mai multa memorie decat telefonul t3";
	}

	//Operatorul[]
	cout << endl << endl << "-------------------Operatorul[]-----------------" << endl << endl;
	cout << "Memorie aplicatiei este:" << t3[1];
	cout << endl << endl;
	cout << "Memorie aplicatiei este:" << t3[10];
}