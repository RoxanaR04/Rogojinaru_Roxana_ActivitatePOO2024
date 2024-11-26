#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
class CartelaTransport {
	const int codPin;
	const int idCartela;
	const string serieCartela;
	string numePosesor;
	char* producatorCartela;
	int nrZileUtilizare;//nr pozitiv intreg
	float sumaPortofel;
	int nrCalatorii;
	float* valoriCalatorii;
	static float valoareaMinCalatorie;
	static int nrCartela;
public:
	//constructor default

	CartelaTransport():codPin(1000),idCartela(nrCartela++),serieCartela("XXXX") {
		this->numePosesor = "Necunoscut";
		this->producatorCartela = new char[strlen("AAA") + 1];
		strcpy(this->producatorCartela, "AAA");
		this->nrZileUtilizare = 0;
		this->sumaPortofel = 0;
		this->nrCalatorii = 0;
		this->valoriCalatorii = NULL;
	}
	//cu 4 parametrii
	CartelaTransport(string numePosesor,float sumaPortofel, float* valoriCalatorii, int nrCalatorii) :codPin(1234), idCartela(nrCartela++), serieCartela("XXXX") {
		if (numePosesor.size() >= 3) {
			this->numePosesor = numePosesor;
		}
		else {
			this->numePosesor = "Anonim";
		}
		this->producatorCartela = new char[strlen("AAA") + 1];
		strcpy(this->producatorCartela, "AAA");
		this->nrZileUtilizare = 0;
		if (sumaPortofel > 0) {
			this->sumaPortofel = sumaPortofel;
		}
		else {
			this->sumaPortofel = 0;
		}
		if (nrCalatorii > 0 && valoriCalatorii != NULL) {
			this->nrCalatorii = nrCalatorii;
			this->valoriCalatorii = new float[this->nrCalatorii];
			for (int i = 0; i < this->nrCalatorii; i++) {
				if (valoriCalatorii[i] >= valoareaMinCalatorie) {

					this->valoriCalatorii[i] = valoriCalatorii[i];
				}
				else {
					this->valoriCalatorii[i] = valoareaMinCalatorie;
				}
			}
		}
		else {
			this->nrCalatorii = 0;
			this->valoriCalatorii = NULL;
		}
		
	}


	~CartelaTransport() {
		if (this->producatorCartela != NULL) {
			delete[]this->producatorCartela;
		}
		if (this->valoriCalatorii != NULL) {
			delete[]this->valoriCalatorii;
		}
	}

	 int getCodPin()const {
		return this->codPin;
	}

	 string getSerieCartela() const {
		return this->serieCartela;
	}

	 int getIdCartela() const {
		return this->idCartela;
	}
	string getNumePosesor() {
		return this->numePosesor;
	}

	float* getValoriCalatorii() {
		return this->valoriCalatorii;
	}

	int getNrCalatorii() {
		return this->nrCalatorii;
	}

	char* getProducatorCartela() {
		return this->producatorCartela;
	}

	void setNumePosesor(string numePosesor) {
		if (numePosesor.size() >= 3) {
			this->numePosesor = numePosesor;
		}
		else throw new exception("Numele primit ca parametru nu respecta conditiile!");
	}

	void setProducatorCartela(const char* producatorCartela) {
		
		if (strlen(producatorCartela) >= 3) {
			if (this->producatorCartela != NULL) {
				delete[]this->producatorCartela;
			}
			this->producatorCartela = new char[strlen(producatorCartela) + 1];
			strcpy(this->producatorCartela, producatorCartela);
		}
	}

	/*void setValoriCalatorii(float* valoriCalatorii) {
		if (valoriCalatorii != NULL) {
			if (this->valoriCalatorii != NULL) {
				delete[]this->valoriCalatorii;
			}
			this->valoriCalatorii = new float[this->nrCalatorii];
			for (int i = 0; i < this->nrCalatorii; i++) {
				if (valoriCalatorii[i] >= valoareaMinCalatorie) {

					this->valoriCalatorii[i] = valoriCalatorii[i];
				}
					else {
						this->valoriCalatorii[i] = valoareaMinCalatorie;
					}
			}
		}
		
	}*/

	void setValoriCalatorii(int nrCalatorii, float* valoriCalatorii) {
		if (nrCalatorii > 0 && valoriCalatorii != NULL) {
			if (this->valoriCalatorii != NULL) {
				delete[]this->valoriCalatorii;
			}
			this->nrCalatorii = nrCalatorii;
			this->valoriCalatorii = new float[this->nrCalatorii];
			for (int i = 0; i < this->nrCalatorii; i++) {
				if (valoriCalatorii[i] >= valoareaMinCalatorie) {

					this->valoriCalatorii[i] = valoriCalatorii[i];
				}
				else {
					this->valoriCalatorii[i] = valoareaMinCalatorie;
				}
			}
		}
	}

	CartelaTransport(const CartelaTransport& c):codPin(c.codPin),idCartela(c.idCartela),serieCartela(c.serieCartela) {
		if (c.numePosesor.size() >= 3) {
			this->numePosesor = c.numePosesor;
		}
		else {
			this->numePosesor = "Anonim";
		}
		this->producatorCartela = new char[strlen(c.producatorCartela) + 1];
		strcpy(this->producatorCartela, c.producatorCartela);
		if (c.nrZileUtilizare > 0) {
			this->nrZileUtilizare = c.nrZileUtilizare;
		}
		else {
			this->nrZileUtilizare = 0;
		}
		if (c.sumaPortofel > 0) {
			this->sumaPortofel = c.sumaPortofel;
		}
		else {
			this->sumaPortofel = 0;
		}
		if (c.nrCalatorii > 0 && c.valoriCalatorii != NULL) {
			this->nrCalatorii = c.nrCalatorii;
			this->valoriCalatorii = new float[this->nrCalatorii];
			for (int i = 0; i < this->nrCalatorii; i++) {
				if (c.valoriCalatorii[i] >= valoareaMinCalatorie) {

					this->valoriCalatorii[i] = c.valoriCalatorii[i];
				}
				else {
					this->valoriCalatorii[i] = valoareaMinCalatorie;
				}
			}
		}
		else {
			this->nrCalatorii = 0;
			this->valoriCalatorii = NULL;
		}
	}

	//constructor cu toti parametrii
	CartelaTransport(int codPin, string serieCartela, string numePosesor, const char* producatorCartela, int nrZileUtilizare,float sumaPortofel, float* valoriCalatorii, int nrCalatorii) :codPin(codPin), idCartela(nrCartela++), serieCartela(serieCartela) {
		if (numePosesor.size() >= 3) {
			this->numePosesor = numePosesor;
		}
		else {
			this->numePosesor = "Anonim";
		}
		if (strlen(producatorCartela) >= 3) {
			this->producatorCartela = new char[strlen(producatorCartela) + 1];
			strcpy(this->producatorCartela, producatorCartela);
		}
		else {
			this->producatorCartela = new char[strlen("AAA") + 1];
			strcpy(this->producatorCartela, "AAA");
		}

		if (nrZileUtilizare > 0) {
			this->nrZileUtilizare = nrZileUtilizare;
		}
		else {
			this->nrZileUtilizare = 0;
		}
		
		if (sumaPortofel > 0) {
			this->sumaPortofel = sumaPortofel;
		}
		else {
			this->sumaPortofel = 0;
		}
		if (nrCalatorii > 0 && valoriCalatorii != NULL) {
			this->nrCalatorii = nrCalatorii;
			this->valoriCalatorii = new float[this->nrCalatorii];
			for (int i = 0; i < this->nrCalatorii; i++) {
				if (valoriCalatorii[i] >= valoareaMinCalatorie) {

					this->valoriCalatorii[i] = valoriCalatorii[i];
				}
				else {
					this->valoriCalatorii[i] = valoareaMinCalatorie;
				}
			}
		}
		else {
			this->nrCalatorii = 0;
			this->valoriCalatorii = NULL;
		}

	}

	CartelaTransport& operator=(const CartelaTransport& c) {
		if (this != &c) {
			if (this->producatorCartela != NULL) {
				delete[]this->producatorCartela;
			}
			if (this->valoriCalatorii != NULL) {
				delete[]this->valoriCalatorii;
			}
			if (c.numePosesor.size() >= 3) {
				this->numePosesor = c.numePosesor;
			}
			else {
				this->numePosesor = "Anonim";
			}
			this->producatorCartela = new char[strlen(c.producatorCartela) + 1];
			strcpy(this->producatorCartela, c.producatorCartela);
			if (c.nrZileUtilizare > 0) {
				this->nrZileUtilizare = c.nrZileUtilizare;
			}
			else {
				this->nrZileUtilizare = 0;
			}
			if (c.sumaPortofel > 0) {
				this->sumaPortofel = c.sumaPortofel;
			}
			else {
				this->sumaPortofel = 0;
			}
			if (c.nrCalatorii > 0 && c.valoriCalatorii != NULL) {
				this->nrCalatorii = c.nrCalatorii;
				this->valoriCalatorii = new float[this->nrCalatorii];
				for (int i = 0; i < this->nrCalatorii; i++) {
					if (c.valoriCalatorii[i] >= valoareaMinCalatorie) {

						this->valoriCalatorii[i] = c.valoriCalatorii[i];
					}
					else {
						this->valoriCalatorii[i] = valoareaMinCalatorie;
					}
				}
			}
			else {
				this->nrCalatorii = 0;
				this->valoriCalatorii = NULL;
			}
		}
		return* this;
	}
	//const int codPin;
	//const int idCartela;
	//const string serieCartela;
	//string numePosesor;
	//char* producatorCartela;
	//int nrZileUtilizare;//nr pozitiv intreg
	//float sumaPortofel;
	//int nrCalatorii;
	//float* valoriCalatorii;
	friend ostream& operator<<(ostream& out, const CartelaTransport & c) {
		out << "Cod Pin: " << c.codPin << endl;
		out << "Id Cartela: " << c.idCartela << endl;
		out << "Serie Cartela: " << c.serieCartela << endl;
		out << "Nume Posesor: " << c.numePosesor << endl;
		out << "Producator Cartela: " << c.producatorCartela << endl;
		out << "Nr zile Utilizare: " << c.nrZileUtilizare << endl;
		out << "Suma portofel: " << c.sumaPortofel << endl;
		out << "Numar calatorii: " << c.nrCalatorii << endl;
		out << "Valori calatorii: ";
		for (int i = 0; i < c.nrCalatorii; i++) {
			out << c.valoriCalatorii[i] << " | ";
		}
		out << endl;
		return out;

	}

	//NICIODATA NU CITITI ATRIBUTULE CONSTANTE SAU STATICE!!!!
	friend istream& operator>>(istream& in, CartelaTransport& c) {
		if (c.producatorCartela != NULL) {
			delete[]c.producatorCartela;
		}
		/*
		if (c.valoriCalatorii != NULL) {
			delete[]c.valoriCalatorii;
		}*/
	
		cout << "Nume Posesor: ";
		//in >> c.numePosesor;
		getline(in, c.numePosesor);//de a citi pana apasiti enter
		cout << "Producator cartela: ";
		char aux[100];
		//in >> aux;
		in.getline(aux, 99);//de a citi pana apasiti enter
		c.producatorCartela = new char[strlen(aux) + 1];
		strcpy(c.producatorCartela, aux);
	
		cout << "Nr zile Utilizare: ";
		in >> c.nrZileUtilizare;
		
		cout << "Suma portofel: " ;
		in >> c.sumaPortofel;
	

		cout << "Numar calatorii: " ;
		in >> c.nrCalatorii;
		cout << "Valori calatorii: ";
		c.valoriCalatorii = new float[c.nrCalatorii];
		for (int i = 0; i < c.nrCalatorii; i++) {
			in >> c.valoriCalatorii[i];
		}
		return in;
	}

	CartelaTransport& operator+=(float valoareCalatorie) {
		if (this->sumaPortofel >= valoareCalatorie) {
			this->sumaPortofel = this->sumaPortofel - valoareCalatorie;
			CartelaTransport copie = *this;
			if (this->valoriCalatorii != NULL) {
				delete[]this->valoriCalatorii;
			}
			this->nrCalatorii++;
			this->valoriCalatorii = new float[this->nrCalatorii];
			for (int i = 0; i < copie.nrCalatorii; i++) {
				this->valoriCalatorii[i] = copie.valoriCalatorii[i];
			}
			this->valoriCalatorii[this->nrCalatorii - 1] = valoareCalatorie;
		}
		return *this;
	}

	//ct>ct1
	bool operator >(CartelaTransport c) {
		float suma = 0;
		float suma1 = 0;
		for (int i = 0; i < this->nrCalatorii; i++) {
			suma += this->valoriCalatorii[i];
		}
		for (int i = 0; i < c.nrCalatorii; i++) {
			suma1 += c.valoriCalatorii[i];
		}
		return suma > suma1;
	}

	float medieSumaPeZi() {
		float medie = 0;
		for (int i = 0; i < this->nrCalatorii; i++) {
			medie += this->valoriCalatorii[i];
		}
		return medie / this->nrZileUtilizare;
	}

	//Supraincarcati op && astfel incat sa verifice daca doua cartele sunt detinute de aceeasi persoana si utilizate de acelasi nr de zile
	bool operator &&(CartelaTransport c) {
		return (c.numePosesor == this->numePosesor && c.nrZileUtilizare == this->nrZileUtilizare);
	}
	//supraincarcati op || astfel incat sa se verifice daca doua cartele au aceeasi serie sau aceeasi firma producatoare
	bool operator||(CartelaTransport c) {
		//strcmp(primul char*,al doilea char*) ==0(inseamna ca cele doua sunt identice)
		return (this->serieCartela == c.serieCartela || strcmp(this->producatorCartela, c.producatorCartela) == 0);
	}

	//supraincarcati op de indexare astfel incat sa intoarca valoarea de pe o anumita pozitie si sa o poata modifica.
	float & operator[](int pozitie) {
		if (pozitie >= 0 && pozitie < this->nrCalatorii) {
			return this->valoriCalatorii[pozitie];
		}
		else throw new exception("Pozitia indicata nu se afla in vector");
		//else {
		//	float eroare = -1;
		//	return eroare;
		//}
	}
};

float CartelaTransport::valoareaMinCalatorie = 2.5;
int CartelaTransport::nrCartela = 1;


int main() {
	cout << "Constructor implicit/default: " << endl;
	CartelaTransport ct;
	cout << ct.getCodPin() << endl;
	cout << ct.getIdCartela() << endl;
	cout << ct.getSerieCartela() << endl;
	cout << ct.getNumePosesor() << endl;
	cout << ct.getProducatorCartela() << endl;
	for (int i = 0; i < ct.getNrCalatorii(); i++) {
		cout << ct.getValoriCalatorii()[i] << ", ";
	}
	cout << endl;
	cout << "Setteri: " << endl;
	try {
		ct.setNumePosesor("Viorel");
	}
	catch (exception* ex) {
		cout << ex->what() << endl;
	}
	
	float valCalatorii[] = { 1.5,5.3 };
	ct.setValoriCalatorii(2,valCalatorii);
	cout << ct.getNumePosesor() << endl;
	for (int i = 0; i < ct.getNrCalatorii(); i++) {
		cout << ct.getValoriCalatorii()[i] << ", ";
	}
	cout << endl << endl;

	float valCal[] = { 3.5,1.2,4.5,2.0 };
	cout << "Constructor cu 4 parametrii: " << endl;
	CartelaTransport ct1("Gica", 400.5, valCal, 4);
	cout << ct1.getCodPin() << endl;
	cout << ct1.getIdCartela() << endl;
	cout << ct1.getSerieCartela() << endl;
	cout << ct1.getNumePosesor() << endl;
	cout << ct1.getProducatorCartela() << endl;
	for (int i = 0; i < ct1.getNrCalatorii(); i++) {
		cout << ct1.getValoriCalatorii()[i] << ", ";
	}
	cout << endl;
	cout << "Setteri: " << endl;
	try {
		ct1.setNumePosesor("Au");
	}
	catch (exception* ex) {
		cout << ex->what() << endl;
	}
	float valoriNoiCalatorii[] = { 3.7,1.1,9.5 };
	ct1.setValoriCalatorii(3,valoriNoiCalatorii);
	cout << ct1.getIdCartela() << endl;
	cout << ct1.getNumePosesor() << endl;

	for (int i = 0; i < ct1.getNrCalatorii(); i++) {
		cout << ct1.getValoriCalatorii()[i] << ", ";
	}
	cout << endl << endl;
	CartelaTransport ct0("Tibi", 100.5, valCal, 4);
	cout << ct0.getCodPin() << endl;
	cout << ct0.getIdCartela() << endl;
	cout << ct0.getSerieCartela() << endl;
	cout << ct0.getNumePosesor() << endl;
	cout << ct0.getProducatorCartela() << endl;
	for (int i = 0; i < ct0.getNrCalatorii(); i++) {
		cout << ct0.getValoriCalatorii()[i] << ", ";
	}
	cout << endl;



	cout << endl << endl;
	cout << "Constructor de copiere: " << endl;
	CartelaTransport ct2 = ct1;// CartelaTransport ct2(ct1)
	for (int i = 0; i < ct2.getNrCalatorii(); i++) {
		cout << ct2.getValoriCalatorii()[i] << ", ";
	}

	cout << endl << endl;
	cout << "Constructor cu toti parametrii: " << endl;
	CartelaTransport ct3(3451,"A3232","Ionica", "MetroRex", 3,100.3, valCal, 4);
	cout << ct3.getCodPin() << endl;
	cout << ct3.getIdCartela() << endl;
	cout << ct3.getSerieCartela() << endl;
	cout << ct3.getNumePosesor() << endl;
	cout << ct3.getProducatorCartela() << endl;
	for (int i = 0; i < ct3.getNrCalatorii(); i++) {
		cout << ct3.getValoriCalatorii()[i] << ", ";
	}
	cout << endl << endl;


	CartelaTransport ct4(1421, "B984", "Tudor", "mr", 4,100.3, valCal, 4);
	cout << ct4.getCodPin() << endl;
	cout << ct4.getIdCartela() << endl;
	cout << ct4.getSerieCartela() << endl;
	cout << ct4.getNumePosesor() << endl;
	cout << ct4.getProducatorCartela() << endl;
	for (int i = 0; i < ct4.getNrCalatorii(); i++) {
		cout << ct4.getValoriCalatorii()[i] << ", ";
	}

	cout << endl << endl;
	cout << "Operator =: " << endl;
	ct0 = ct4;
	cout << ct0.getCodPin() << endl;
	cout << ct0.getIdCartela() << endl;
	cout << ct0.getSerieCartela() << endl;
	cout << ct0.getNumePosesor() << endl;
	cout << ct0.getProducatorCartela() << endl;
	for (int i = 0; i < ct0.getNrCalatorii(); i++) {
		cout << ct0.getValoriCalatorii()[i] << ", ";
	}
	cout << endl;
	cout << endl << endl;

	cout << "Operator <<: " << endl;
	cout << ct4 << endl;


	cout << endl << endl;

	cout << "Operator >>: " << endl;
	//cin >> ct4;
	//cout << ct4<<endl;

	cout << endl << endl;

	cout << "Operator +=: " << endl;
	ct4 += 70;
	cout << ct4 << endl;
	ct4 += 40;
	cout << ct4 << endl;
	cout << endl << endl;
	cout << "Operator >: " << endl;
	cout << (ct4 > ct1) << endl;

	cout << endl << endl;

	cout << "Valoare calatorii medie pe zi: " << ct4.medieSumaPeZi() << endl<<endl;
	cout << "Operator &&: " << endl;
	cout << (ct4 && ct0) << endl;

	cout << endl << endl;

	cout << ct4 << endl<<endl;
	ct1.setProducatorCartela("STB");
	cout << ct1 << endl<<endl;
	cout << ct0 << endl<<endl;

	cout << endl << endl;
	cout << "Operator ||: " << endl;
	cout << (ct4 || ct0) << endl;
	cout << (ct1 || ct0) << endl;
	cout << (ct4 || ct1) << endl;
	cout << endl << endl;



	cout << "Operator [] --- operator de indexare/index: " << endl;
	cout << ct4[2] << endl;
	ct4[2] = 20.5;
	cout << ct4[2] << endl;
	try {
		cout << ct4[6] << endl;
	}
	catch (exception* ex) {
		cout << ex->what() << endl;
	}
	cout << endl << endl;

}
