#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class TraseuMontan
{
	string numeTraseu;
	int gradDificultate;
	int numarSegmente;
	int* distanteSegmente;
public:
	//Constructor implicit, fara paramtrii
	TraseuMontan()
	{
		this->numeTraseu = "Necunoscut";
		this->gradDificultate = 0;
		this->numarSegmente = 0;
		this->distanteSegmente = NULL;
	}
	//Constructor cu toti parametrii
	TraseuMontan(string numeTraseu, int gradDificultate, int numarSegmente, int* distanteSegmente)
	{
		this->numeTraseu = numeTraseu;
		if (gradDificultate >= 0 && gradDificultate <= 10)
		{
			this->gradDificultate = gradDificultate;
		}
		else
		{
			this->gradDificultate = 0;
		}
		this->numarSegmente = numarSegmente;
		this->distanteSegmente = new int[this->numarSegmente];
		for (int i = 0; i < this->numarSegmente; i++)
		{
			this->distanteSegmente[i] = distanteSegmente[i];
		}
	}

	//Getteri
	string getNumeTraseu()
	{
		return this->numeTraseu;
	}
	int getGradDificultate()
	{
		return this->gradDificultate;
	}
	int getNumarSegmente()
	{
		return this->numarSegmente;
	}
	int* getDistanteSegmente()
	{
		return this->distanteSegmente;
	}

	//Setteri
	void setNumeTraseu(string numeNou)
	{
		this->numeTraseu = numeNou;
	}
	void setGradDificultate(int gradNou)
	{
		if (gradNou >= 0 && gradNou <= 10)
		{
			this->gradDificultate = gradNou;
		}
		else
		{
			this->gradDificultate = 0 ;
		}
	}
	void setDistante(int numarSegmenteNou, int* distanteSegmenteNoi)
	{
		if (this->distanteSegmente != NULL)
		{
			delete this->distanteSegmente;
		}
		this->numarSegmente = numarSegmenteNou;
		this->distanteSegmente = new int[numarSegmenteNou];
		for (int i = 0; i < this->numarSegmente; i++)
		{
			this->distanteSegmente[i] = distanteSegmenteNoi[i];
		}
	}

	//Constructor copiere
	TraseuMontan(const TraseuMontan& obj)
	{
		this->numeTraseu = obj.numeTraseu;
		if (obj.gradDificultate >= 0 && obj.gradDificultate <= 10)
		{
			this->gradDificultate = obj.gradDificultate;
		}
		else
		{
			this->gradDificultate = 0;
		}
		this->numarSegmente = obj.numarSegmente;
		this->distanteSegmente = new int[this->numarSegmente];
		for (int i = 0; i < this->numarSegmente; i++)
		{
			this->distanteSegmente[i] = obj.distanteSegmente[i];
		}
	}

	//Operatorul =
	TraseuMontan& operator=(const TraseuMontan& obj)
	{
		if (this != &obj)
		{
			if (this->distanteSegmente != NULL)
			{
				delete this->distanteSegmente;
			}
			this->numeTraseu = obj.numeTraseu;
			if (obj.gradDificultate >= 0 && obj.gradDificultate <= 10)
			{
				this->gradDificultate = obj.gradDificultate;
			}
			else
			{
				this->gradDificultate = 0;
			}
			this->numarSegmente = obj.numarSegmente;
			this->distanteSegmente = new int[this->numarSegmente];
			for (int i = 0; i < this->numarSegmente; i++)
			{
				this->distanteSegmente[i] = obj.distanteSegmente[i];
			}
			return *this;
		}
	}

	//Metoda adauga distanta
	void adaugaDistanta(int val)
	{
		int copieNrSegmente = this->numarSegmente;
		int* copieDistante = new int[copieNrSegmente];
		for (int i = 0; i < copieNrSegmente; i++)
		{
			copieDistante[i] = this->distanteSegmente[i];
		}
		delete this->distanteSegmente;
		this->numarSegmente = copieNrSegmente + 1;
		this->distanteSegmente = new int[this->numarSegmente];
		for (int i = 0; i < copieNrSegmente; i++)
		{
			this->distanteSegmente[i]=copieDistante[i]  ;
		}
		for (int i = copieNrSegmente; i < this->numarSegmente; i++)
		{
			this->distanteSegmente[i] = val;
		}
	}

	//Operatorul <<
	friend ostream& operator<<(ostream& out, const TraseuMontan& obj)
	{
		out << "Nume:" << obj.numeTraseu<<" ";
		out << "Dificultate:" << obj.gradDificultate << " ";
		out << "Nr segmente:" << obj.numarSegmente << " ";
		cout << "Distante:";
		for (int i = 0; i < obj.numarSegmente; i++)
		{
			out  << obj.distanteSegmente[i] << " | ";
		}
		return out;
	}

	//Operatorul >>
	friend istream& operator>>(istream& in, TraseuMontan& obj)
	{
		cout << "Introduceti numele:";
		in >> obj.numeTraseu;
		cout << "Intrduceti dificultate:";
		in >> obj.gradDificultate;
		if (obj.gradDificultate < 0 || obj.gradDificultate >= 10)
		{
			obj.gradDificultate = 0;
		}
		cout << "Introduceti numar segmente:";
		in >> obj.numarSegmente;
		cout << "Introduceti distante:";
		if (obj.distanteSegmente != NULL)
		{
			delete obj.distanteSegmente;
		}
		obj.distanteSegmente = new int[obj.numarSegmente];
		for (int i = 0; i < obj.numarSegmente; i++)
		{
			in >> obj.distanteSegmente[i];
		}
		return in;
	}

	//Operator<
	bool operator<(const TraseuMontan t)
	{
		return this->gradDificultate < t.gradDificultate;
	}

	//Operatorul cast la int
	explicit operator int()
	{
		int suma=0;
		for (int i = 0; i < this->numarSegmente; i++)
		{
			suma = suma + this->distanteSegmente[i];
		}
		return suma;
	}

	//Operator index
	int operator[](int index)
	{
		int err = -1;
		if (index >= 0 && index < this->numarSegmente)
		{
			return this->distanteSegmente[index];
		}
		else
		{
			return err;
		}
	}

	//Destructor
	~TraseuMontan()
	{
		if (this->distanteSegmente != NULL)
		{
			delete this->distanteSegmente;
		}
	}

};

void main()
{
	TraseuMontan t1; 
	cout << t1.getNumeTraseu() << " ";
	cout << t1.getGradDificultate() << " ";
	cout << t1.getNumarSegmente() << " ";
	cout << "Distante segmente:";
	for (int i = 0; i < t1.getNumarSegmente(); i++)
	{
		cout << t1.getDistanteSegmente()[i]<<" | ";
	}
	cout << endl << endl;

	int distante1[] = { 1000,2000 };
	TraseuMontan t2("Bran", 15, 2, distante1);
	cout << t2.getNumeTraseu() << " ";
	cout << t2.getGradDificultate() << " ";
	cout << t2.getNumarSegmente() << " ";
	cout << "Distante segmente:";
	for (int i = 0; i < t2.getNumarSegmente(); i++)
	{
		cout << t2.getDistanteSegmente()[i] << " | ";
	}
	cout << endl << endl;

	//Setteri
	cout << endl << endl << "----------------Setteri----------------" << endl << endl;
	t2.setNumeTraseu("Sinaia");
	t2.setGradDificultate(9);
	int distante2[] = { 1000,200,300 };
	t2.setDistante(3, distante2);
	cout << t2.getNumeTraseu() << " ";
	cout << t2.getGradDificultate() << " ";
	cout << t2.getNumarSegmente() << " ";
	cout << "Distante segmente:";
	for (int i = 0; i < t2.getNumarSegmente(); i++)
	{
		cout << t2.getDistanteSegmente()[i] << " | ";
	}
	cout << endl << endl;

	t1.setGradDificultate(15);
	cout << t1.getNumeTraseu() << " ";
	cout << t1.getGradDificultate() << " ";
	cout << t1.getNumarSegmente() << " ";
	cout << "Distante segmente:";
	for (int i = 0; i < t1.getNumarSegmente(); i++)
	{
		cout << t1.getDistanteSegmente()[i] << " | ";
	}
	cout << endl << endl;

	//Constructor copiere
	cout << endl<<endl<<"---------------Constructor copiere--------------" << endl << endl;
	TraseuMontan t3 = t2;
	cout << t3.getNumeTraseu() << " ";
	cout << t3.getGradDificultate() << " ";
	cout << t3.getNumarSegmente() << " ";
	cout << "Distante segmente:";
	for (int i = 0; i < t3.getNumarSegmente(); i++)
	{
		cout << t3.getDistanteSegmente()[i] << " | ";
	}
	cout << endl << endl;

	//Operatorul =
	cout << endl << endl << "---------------Operatorul =--------------" << endl << endl;
	int distante3[] = { 100,200,300 };
	TraseuMontan t4("Bucegi", 6,3, distante3);
	cout << t4.getNumeTraseu() << " ";
	cout << t4.getGradDificultate() << " ";
	cout << t4.getNumarSegmente() << " ";
	cout << "Distante segmente:";
	for (int i = 0; i < t4.getNumarSegmente(); i++)
	{
		cout << t4.getDistanteSegmente()[i] << " | ";
	}
	cout << endl << endl;
	t4 = t2;
	cout << t4.getNumeTraseu() << " ";
	cout << t4.getGradDificultate() << " ";
	cout << t4.getNumarSegmente() << " ";
	cout << "Distante segmente:";
	for (int i = 0; i < t4.getNumarSegmente(); i++)
	{
		cout << t4.getDistanteSegmente()[i] << " | ";
	}
	cout << endl << endl;

	//Adauga distanta
	cout << endl << endl << "---------------Adauga distanta--------------" << endl << endl;
	t4.adaugaDistanta(50);
	cout << t4.getNumeTraseu() << " ";
	cout << t4.getGradDificultate() << " ";
	cout << t4.getNumarSegmente() << " ";
	cout << "Distante segmente:";
	for (int i = 0; i < t4.getNumarSegmente(); i++)
	{
		cout << t4.getDistanteSegmente()[i] << " | ";
	}
	cout << endl << endl;

	//Operator << si >>
	cout <<endl<<endl<< "------------------Operatori << >>--------------" << endl<<endl;
	cin >> t4;
	cout << endl;
	cout << t4 << endl << endl;

	//Operator <
	cout << "------------------Operator <--------------" << endl;
	cout << t3;
	cout << endl << endl;
	cout << t4;
	cout << endl << endl;
	if (t3 < t4)
	{
		cout << "Traseul t3 este mai usor decat t4";
	}
	else
	{
		cout << "Traseul t3 este mai dificil decat traseul t4";
	}

	//Operatorul cast la int
	cout << endl << endl << "-----------Operatorul cast la int---------------" << endl << endl;
	int rez = (int)t4;
	cout << "Distanta totala a traseului t4 este:" << rez;

	//Operator index
	cout << endl << endl<<"-----------Operator index----------------" << endl << endl;
	cout <<"Lungimea segmentului:"<< t4[2];
}
