#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class ApartamentDeInchiriat{
	string adresa;
	float chirie;
	int durataAniContract; //pt cati ani e inchiriat ap
	int nrLuniInchiriere; //nr de luni de cand ap este inchiriat
	float* cheltuieliLunareIntretinere; //intretinerea lunara
	static int NR_MAXIM_LOCATARI; //limita maxima de pers ce pot ocupa apartamentul
public:
	//Constructor implicit
	ApartamentDeInchiriat()
	{
		this->adresa = "Necunoscuta";
		this->chirie = 0;
		this->durataAniContract = 0;
		this->nrLuniInchiriere = 0;
		this->cheltuieliLunareIntretinere = NULL;
	}
	//Constructor cu toti parametrii
	ApartamentDeInchiriat(string adresa, float chirie, int durataAniContract, int nrLuniInchiriere, float* cheltuieliLunareIntretinere)
	{
		this->adresa = adresa;
		this->chirie = chirie;
		this->durataAniContract = durataAniContract;
		this->nrLuniInchiriere = nrLuniInchiriere;
		this->cheltuieliLunareIntretinere = new float[this->nrLuniInchiriere];
		for (int i = 0; i < this->nrLuniInchiriere; i++)
		{
			this->cheltuieliLunareIntretinere[i] = cheltuieliLunareIntretinere[i];
		}

	}

	//Getteri
	string getAdresa()
	{
		return this->adresa;
	}
	float getChirie()
	{
		return this->chirie;
	}
	int getAniContract()
	{
		return this->durataAniContract;
	}
	int getNrLuniPerioadaInchiriere()
	{
		return this->nrLuniInchiriere;
	}
	float* getCheltuieliLunareIntretinere()
	{
		return this->cheltuieliLunareIntretinere;
	}


	//Adauga intretinere lunara
	void adaugaIntretinereLunara(float val)
	{
		int copieNrLuni = this->nrLuniInchiriere;
		float* copieIntretinereLunara = new float[copieNrLuni];
		for (int i = 0; i < copieNrLuni; i++)
		{
			copieIntretinereLunara[i] = this->cheltuieliLunareIntretinere[i];
		}
		delete[] this->cheltuieliLunareIntretinere;
		this->nrLuniInchiriere = copieNrLuni + 1;
		this->cheltuieliLunareIntretinere = new float[this->nrLuniInchiriere];
		for (int i = 0; i < copieNrLuni; i++)
		{
			this->cheltuieliLunareIntretinere[i] = copieIntretinereLunara[i];
		}
		this->cheltuieliLunareIntretinere[copieNrLuni] = val;
	}

	//Constructorul de copiere
	ApartamentDeInchiriat(const ApartamentDeInchiriat& a)
	{
		this->adresa = a.adresa;
		this->chirie = a.chirie;
		this->durataAniContract = a.durataAniContract;
		this->nrLuniInchiriere = a.nrLuniInchiriere;
		this->cheltuieliLunareIntretinere = new float[a.nrLuniInchiriere];
		for (int i = 0; i < a.nrLuniInchiriere; i++)
		{
			this->cheltuieliLunareIntretinere[i] = a.cheltuieliLunareIntretinere[i];
		}
	}

	//Metoda durata ramasa contract
	int durataRamasaContract()
	{
		return this->durataAniContract * 12 - this->nrLuniInchiriere;

	}


	//Metoda inchiriaza apartament

	//Operatorul egal
	ApartamentDeInchiriat& operator=(const ApartamentDeInchiriat& a)
	{
		if (this != &a)
		{
			if (this->cheltuieliLunareIntretinere != NULL)
			{
				delete[] this->cheltuieliLunareIntretinere;
			}
			this->adresa = a.adresa;
			this->chirie = a.chirie;
			this->durataAniContract = a.durataAniContract;
			this->nrLuniInchiriere = a.nrLuniInchiriere;
			this->cheltuieliLunareIntretinere = new float[a.nrLuniInchiriere];
			for (int i = 0; i < a.nrLuniInchiriere; i++)
			{
				this->cheltuieliLunareIntretinere[i] = a.cheltuieliLunareIntretinere[i];
			}
		}
		return *this;
	}

	//Operatorul <<
	friend ostream& operator<<(ostream& out, const ApartamentDeInchiriat& a)
	{
		out << "Adresa:" << a.adresa << " ";
		out << "Chirie:" << a.chirie << " ";
		out << "Ani contract:" << a.durataAniContract << " ";
		out << "Nr luni:" << a.nrLuniInchiriere << " ";
		out << "Intretinere:";
		for (int i = 0; i < a.nrLuniInchiriere; i++)
		{
			out << a.cheltuieliLunareIntretinere[i] << " | ";
		}
		return out;
	}

	//Operatorul >>
	friend istream& operator>>(istream& in, ApartamentDeInchiriat& a)
	{
		cout << "Introduceti adresa:";
		in >> a.adresa;
		cout << "Introduceti chirie:";
		in >> a.chirie;
		cout << "Introduceti nr ani contract:";
		in >> a.durataAniContract;
		cout << "Introduceti nr luni inchiriere:";
		in >> a.nrLuniInchiriere;
		delete[] a.cheltuieliLunareIntretinere;
		a.cheltuieliLunareIntretinere = new float[a.nrLuniInchiriere];
		cout << "Inroduceti cheltuielile lunare cu intretinerea:";
		for (int i = 0; i < a.nrLuniInchiriere; i++)
		{
			in >> a.cheltuieliLunareIntretinere[i];
		}
		return in;
	}

	//Operatorul+=
	ApartamentDeInchiriat& operator+=(float val)
	{
		int copieNrLuni = this->nrLuniInchiriere;
		float* copieIntretinereLunara = new float[copieNrLuni];
		for (int i = 0; i < copieNrLuni; i++)
		{
			copieIntretinereLunara[i] = this->cheltuieliLunareIntretinere[i];
		}
		delete[] this->cheltuieliLunareIntretinere;
		this->nrLuniInchiriere = copieNrLuni + 1;
		this->cheltuieliLunareIntretinere = new float[this->nrLuniInchiriere];
		for (int i = 0; i < copieNrLuni; i++)
		{
			this->cheltuieliLunareIntretinere[i] = copieIntretinereLunara[i];
		}
		this->cheltuieliLunareIntretinere[copieNrLuni] = val;
		return* this;
	}

	//Operatorul de indexare[]
	float operator[](int index)
	{
		float err = -1;
		if (index >= 0 && index < this->nrLuniInchiriere)
		{
			return this->cheltuieliLunareIntretinere[index];
		}
		else
		{
			return err;
		}
	}

	//Destructorul
	~ApartamentDeInchiriat()
	{
		if (this->cheltuieliLunareIntretinere != NULL)
		{
			delete[] this->cheltuieliLunareIntretinere;
		}
	}
};



void main()
{
	ApartamentDeInchiriat a1;
	cout << "Adresa:" << a1.getAdresa() << endl;
	cout << "Chirie:" << a1.getChirie() << endl;
	cout << "Nr ani contract:" << a1.getAniContract() << endl;
	cout << "Nr luni perioada inchiriere:" << a1.getNrLuniPerioadaInchiriere() << endl;
	cout << "Intretinere lunara:";
	for (int i = 0; i < a1.getNrLuniPerioadaInchiriere(); i++)
	{
		cout << a1.getCheltuieliLunareIntretinere()[i] << " | ";
	}
	cout << endl << endl;

	float chelt1[] = { 100,80,90 };
	ApartamentDeInchiriat a2("Bucuresti, str.Straduintei", 300, 2, 3, chelt1);
	cout << "Adresa:" << a2.getAdresa() << endl;
	cout << "Chirie:" << a2.getChirie() << endl;
	cout << "Nr ani contract:" << a2.getAniContract() << endl;
	cout << "Nr luni perioada inchiriere:" << a2.getNrLuniPerioadaInchiriere() << endl;
	cout << "Intretinere lunara:";
	for (int i = 0; i < a2.getNrLuniPerioadaInchiriere(); i++)
	{
		cout << a2.getCheltuieliLunareIntretinere()[i] << " | ";
	}
	cout << endl << endl;

	//Adauga intretinere lunara
	cout << endl << endl << "------------------------Adauga intretinere lunara-----------------" << endl << endl;
	a2.adaugaIntretinereLunara(100);
	cout << "Adresa:" << a2.getAdresa() << endl;
	cout << "Chirie:" << a2.getChirie() << endl;
	cout << "Nr ani contract:" << a2.getAniContract() << endl;
	cout << "Nr luni perioada inchiriere:" << a2.getNrLuniPerioadaInchiriere() << endl;
	cout << "Intretinere lunara:";
	for (int i = 0; i < a2.getNrLuniPerioadaInchiriere(); i++)
	{
		cout << a2.getCheltuieliLunareIntretinere()[i] << " | ";
	}
	cout << endl << endl;

	//Constructorul de copiere
	cout << endl << endl << "------------------------Constructorul de copiere-----------------" << endl << endl;
	ApartamentDeInchiriat a3 = a2;
	cout << "Adresa:" << a3.getAdresa() << endl;
	cout << "Chirie:" << a3.getChirie() << endl;
	cout << "Nr ani contract:" << a3.getAniContract() << endl;
	cout << "Nr luni perioada inchiriere:" << a3.getNrLuniPerioadaInchiriere() << endl;
	cout << "Intretinere lunara:";
	for (int i = 0; i < a3.getNrLuniPerioadaInchiriere(); i++)
	{
		cout << a3.getCheltuieliLunareIntretinere()[i] << " | ";
	}
	cout << endl << endl;

	//Metoda durata ramasa contract
	cout << endl << endl << "------------------------Metoda durata ramasa contract-----------------" << endl << endl;
	cout << "Durata ramasa din contract este:" << a3.durataRamasaContract() << " luni.";
	cout << endl << endl;

	//Operatorul egal
	cout << endl << endl << "------------------------Operatorul egal-----------------" << endl << endl;
	cout << "Adresa:" << a1.getAdresa() << endl;
	cout << "Chirie:" << a1.getChirie() << endl;
	cout << "Nr ani contract:" << a1.getAniContract() << endl;
	cout << "Nr luni perioada inchiriere:" << a1.getNrLuniPerioadaInchiriere() << endl;
	cout << "Intretinere lunara:";
	for (int i = 0; i < a1.getNrLuniPerioadaInchiriere(); i++)
	{
		cout << a1.getCheltuieliLunareIntretinere()[i] << " | ";
	}
	cout << endl << endl;
	a1 = a3;
	cout << "Adresa:" << a1.getAdresa() << endl;
	cout << "Chirie:" << a1.getChirie() << endl;
	cout << "Nr ani contract:" << a1.getAniContract() << endl;
	cout << "Nr luni perioada inchiriere:" << a1.getNrLuniPerioadaInchiriere() << endl;
	cout << "Intretinere lunara:";
	for (int i = 0; i < a1.getNrLuniPerioadaInchiriere(); i++)
	{
		cout << a1.getCheltuieliLunareIntretinere()[i] << " | ";
	}
	cout << endl << endl;

	//Operatorul <<
	cout << endl << endl << "------------------------Operatorul <<-----------------" << endl << endl;
	cout << a3;

	//Operatorul >>
	cout << endl << endl << "------------------------Operatorul >>-----------------" << endl << endl;
	cout << a1;
	cout << endl << endl;
	cin >> a1;
	cout << endl << endl;
	cout << a1;

	//Operatorul+=
	cout << endl << endl << "------------------------Operatorul +=-----------------" << endl << endl;
	a1 += 100;
	cout << a1;

	//Operatorul de indexare[]
	cout << endl << endl << "------------------------Operatorul +=-----------------" << endl << endl;
	cout << "Intretinerea:" << a1[2];
	cout << endl << endl;
	cout << "Intretinerea:" << a1[10];
}