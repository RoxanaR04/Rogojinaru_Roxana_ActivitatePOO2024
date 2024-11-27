#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class ProfilInfluencer{
	string numeCont;
	int numarUrmaritori; //mai mare de 1000
	int numarPostari;
	int* aprecieriPostari;
public:

	//Constructorul implicit, fara parametrii
	ProfilInfluencer()
	{
		this->numeCont = "Necunoscut";
		this->numarUrmaritori = 0;
		this->numarPostari = 0;
		this->aprecieriPostari = NULL;
	}

	//Constructor cu toti parametrii
	ProfilInfluencer(string numeCont, int numarUrmaritori, int numarPostari, int* aprecieriPostari)
	{
		this->numeCont = numeCont;
		if (numarUrmaritori > 1000)
		{
			this->numarUrmaritori = numarUrmaritori;
		}
		else
		{
			this->numarUrmaritori =1001;
		}
		this->numarPostari = numarPostari;
		this->aprecieriPostari = new int[this->numarPostari];
		for (int i = 0; i < this->numarPostari; i++)
		{
			this->aprecieriPostari[i] = aprecieriPostari[i];
		}
	}

	//Getteri
	string getNumeCont()
	{
		return this->numeCont;
	}
	int getNumarUrmaritori()
	{
		return this->numarUrmaritori;
	}
	int getNumarPostari()
	{
		return this->numarPostari;
	}
	int* getAprecieriPostari()
	{
		return this->aprecieriPostari;
	}

	//Setteri
	void setNumeCont(string numeNou)
	{
		this->numeCont = numeNou;
	}
	void setNumarUrmaritori(int numarUrmaritoriNou)
	{
		if (numarUrmaritoriNou > 1000)
		{
			this->numarUrmaritori = numarUrmaritoriNou;
		}
	}


	//Constrctorul de copiere
	ProfilInfluencer(const ProfilInfluencer& obj)
	{
		this->numeCont = obj.numeCont;
		if (obj.numarUrmaritori > 1000)
		{
			this->numarUrmaritori = obj.numarUrmaritori;
		}
		else
		{
			this->numarUrmaritori = 1001;
		}
		this->numarPostari = obj.numarPostari;
		this->aprecieriPostari = new int[obj.numarPostari];
		for (int i = 0; i < obj.numarPostari; i++)
		{
			this->aprecieriPostari[i] = obj.aprecieriPostari[i];
		}
	}

	//Operatorul =
	ProfilInfluencer& operator=(const ProfilInfluencer& obj)
	{
		if (this != &obj)
		{
			if (this->aprecieriPostari != NULL)
			{
				delete[] this->aprecieriPostari;
			}
			this->numeCont = obj.numeCont;
			if (obj.numarUrmaritori > 1000)
			{
				this->numarUrmaritori = obj.numarUrmaritori;
			}
			else
			{
				this->numarUrmaritori = 1001;
			}
			this->numarPostari = obj.numarPostari;
			this->aprecieriPostari = new int[obj.numarPostari];
			for (int i = 0; i < obj.numarPostari; i++)
			{
				this->aprecieriPostari[i] = obj.aprecieriPostari[i];
			}
		}
		return *this;
	}

	//Adauga postare
	void adaugaPostare(int aprecieri)
	{
		int copieNrPostari = this->numarPostari;
		int* copieAprecieri = new int[copieNrPostari];
		for (int i = 0; i < copieNrPostari; i++)
		{
			copieAprecieri[i] = this->aprecieriPostari[i];
		}
		delete[] this->aprecieriPostari;
		this->numarPostari = copieNrPostari + 1;
		this->aprecieriPostari = new int[this->numarPostari];
		for (int i = 0; i < copieNrPostari; i++)
		{
			this->aprecieriPostari[i] = copieAprecieri[i];
		}
		for (int i = copieNrPostari; i < this->numarPostari; i++)
		{
			this->aprecieriPostari[i] = aprecieri;
		}

	}

	//Operatorul de afisare<<
	friend ostream& operator<<(ostream& out, const ProfilInfluencer& obj)
	{
		out << "Nume cont:" << obj.numeCont << " ";
		out << "Nr aprecieri:" << obj.numarUrmaritori << " ";
		out << "Nr postari:" << obj.numarPostari << " ";
		out << "Aprecieri:";
		for (int i = 0; i < obj.numarPostari; i++)
		{
			out << obj.aprecieriPostari[i] << " ";
		}
		return out;
	}


	//Operatorul de scriere>>
	friend istream& operator>>(istream& in,  ProfilInfluencer& obj)
	{
		cout << "Introduceti numele contului:";
		in >> obj.numeCont;
		cout << "Introduceti numarul de urmaritori:";
		in >> obj.numarUrmaritori;
		if (obj.numarUrmaritori < 1000)
		{
			obj.numarUrmaritori = 1000;
		}
		cout << "Introduceti numarul de postari:";
		in >> obj.numarPostari;
		cout << "Introduceti aprecierile:";
		if (obj.aprecieriPostari != NULL)
		{
			delete[] obj.aprecieriPostari;
		}
		obj.aprecieriPostari = new int[obj.numarPostari];
		for (int i = 0; i < obj.numarPostari; i++)
		{
			in >> obj.aprecieriPostari[i];
		}
		return in;
	}


	//Operator <
	bool operator<(const ProfilInfluencer& obj)
	{
		return this->numarUrmaritori < obj.numarUrmaritori;
	}

	//Operatorul de cast la int
	explicit operator int()
	{
		int suma = 0;
		for (int i = 0; i < this->numarPostari; i++)
		{
			suma = suma + this->aprecieriPostari[i];
		}
		return suma;
	}

	//Operatrul de indexare
	int operator[](int index)
	{
		int err = -1;
		if (index >= 0 && index < this->numarPostari)
		{
			return this->aprecieriPostari[index];
		}
		else
		{
			return err;
		}
	}


	//Destructorul
	~ProfilInfluencer()
	{
		if (this->aprecieriPostari != NULL)
		{
			delete[] this->aprecieriPostari;
		}
	}
};

void main()
{
	ProfilInfluencer p1;
	cout << "Nume cont:" << p1.getNumeCont() << " ";
	cout << "Nr urmaritori:" << p1.getNumarUrmaritori() << " ";
	cout << "Nr postari:" << p1.getNumarPostari() << " ";
	cout << "Aprecieri:";
	for (int i = 0; i < p1.getNumarPostari(); i++)
	{
		cout << p1.getAprecieriPostari()[i] << " | ";
	}
	cout << endl << endl;

	int aprecieri1[] = { 100,200,300};
	ProfilInfluencer p2("Alina Ceusan",10000,3,aprecieri1);
	cout << "Nume cont:" << p2.getNumeCont() << " ";
	cout << "Nr urmaritori:" << p2.getNumarUrmaritori() << " ";
	cout << "Nr postari:" << p2.getNumarPostari() << " ";
	cout << "Aprecieri:";
	for (int i = 0; i < p2.getNumarPostari(); i++)
	{
		cout << p2.getAprecieriPostari()[i] << " | ";
	}
	cout << endl << endl;

	cout << "-------------Setteri-----------" << endl;
	p1.setNumeCont("Ioana Grama");
	p1.setNumarUrmaritori(5000);
	cout << "Nume cont:" << p1.getNumeCont() << " ";
	cout << "Nr urmaritori:" << p1.getNumarUrmaritori() << " ";
	cout << "Nr postari:" << p1.getNumarPostari() << " ";
	cout << "Aprecieri:";
	for (int i = 0; i < p1.getNumarPostari(); i++)
	{
		cout << p1.getAprecieriPostari()[i] << " | ";
	}
	cout << endl << endl;

	//Constrctorul de copiere
	cout << "-----------------Constrctorul de copiere-------------------" << endl;
	ProfilInfluencer p3 = p2;
	cout << "Nume cont:" << p3.getNumeCont() << " ";
	cout << "Nr urmaritori:" << p3.getNumarUrmaritori() << " ";
	cout << "Nr postari:" << p3.getNumarPostari() << " ";
	cout << "Aprecieri:";
	for (int i = 0; i < p3.getNumarPostari(); i++)
	{
		cout << p3.getAprecieriPostari()[i] << " | ";
	}
	cout << endl << endl;

	//Operatorul =
	cout << "-------------------Operatorul=------------------" << endl;
	cout << "Nume cont:" << p1.getNumeCont() << " ";
	cout << "Nr urmaritori:" << p1.getNumarUrmaritori() << " ";
	cout << "Nr postari:" << p1.getNumarPostari() << " ";
	cout << "Aprecieri:";
	for (int i = 0; i < p1.getNumarPostari(); i++)
	{
		cout << p1.getAprecieriPostari()[i] << " | ";
	}
	cout << endl << endl;
	p1 = p2;
	cout << "Nume cont:" << p1.getNumeCont() << " ";
	cout << "Nr urmaritori:" << p1.getNumarUrmaritori() << " ";
	cout << "Nr postari:" << p1.getNumarPostari() << " ";
	cout << "Aprecieri:";
	for (int i = 0; i < p1.getNumarPostari(); i++)
	{
		cout << p1.getAprecieriPostari()[i] << " | ";
	}
	cout << endl << endl;


	//Adauga postare
	cout << "------------------Adauga postare---------------" << endl;
	p3.adaugaPostare(900);
	cout << "Nume cont:" << p3.getNumeCont() << " ";
	cout << "Nr urmaritori:" << p3.getNumarUrmaritori() << " ";
	cout << "Nr postari:" << p3.getNumarPostari() << " ";
	cout << "Aprecieri:";
	for (int i = 0; i < p3.getNumarPostari(); i++)
	{
		cout << p3.getAprecieriPostari()[i] << " | ";
	}
	cout << endl << endl;

	//Operatorul >> si Operatorul  <<
	cout << "--------------------Operatorul >> si Operatorul  <<--------------" << endl;
	cin >> p3;
	cout << endl << endl;
	cout << p3;

	//Operator <
	cout << endl << endl << "--------------------Operator <-----------------" << endl;
	cout << "Numar urmaritori p2:" << p2.getNumarUrmaritori();
	cout << endl << "Numar urmaritori p3:" << p3.getNumarUrmaritori();
	cout << endl;
	if (p2 < p3)
	{
		cout << "Influencer-ul p2 are mai putini urmaritori decat influencer-ul p3.";
	}
	else
	{
		cout << "Influencer-ul p2 are mai multi urmaritori decat influencer-ul p3.";
	}

	//Operatorul de cast la in
	cout << endl << endl << "--------------------Operatorul de cast la int------------------" << endl;
	int rez = (int)p3;
	cout << "Influencer-ul p3 are un numar total de aprecieri de:" << rez;

	//Operatrul de indexare
	cout << endl << endl << "-------------------Operatorul de indexare------------------" << endl;
	cout << "Numar de aprecieri:" << p3[1];
	cout << endl;
	cout << "Numar de aprecieri:" << p3[-6];
}