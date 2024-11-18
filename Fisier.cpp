#include<iostream>
#include<string>
using namespace std;

enum tipFisier {
	WORD, POWER_POINT, EXCEL, OTHER
};

class Fisier {
	const int codFisier;//trebuie mereu initializat si o facem in constructori
	string numeFisier;//minim 5 caractere
	int nrAccesari;
	string* editori;
	float dimensiuneFisier;//sa vedem cat spatiu ocupa fisierul
	bool areParola;//daca fisierul nostru este criptat(daca e protejat de parola, pentru a limita accesul)
	tipFisier tip;
	static int MAX_DIMENSIUNE_FISIER;
	static int nrFisier;
public:
	//constructor default/implicit/fara parametrii
	Fisier():codFisier(nrFisier++){
		this->numeFisier = "Anonim";
		this->nrAccesari = 0;
		this->editori = NULL;//sau nullptr
		this->dimensiuneFisier = 0;
		this->areParola = 0;//sau false
		this->tip = OTHER;
		
	}
	Fisier(string numeFisier, int nrAccesari, string* editori, float dimensiuneFisier, bool areParola, tipFisier tip) :codFisier(nrFisier++){
		if (numeFisier.size() >= 5) {
			this->numeFisier = numeFisier;
		}
		else {
			this->numeFisier = "Necunoscut";
		}
		if (nrAccesari > 0 && dimensiuneFisier != NULL) {
			this->nrAccesari = nrAccesari;
			this->editori = new string[this->nrAccesari];//sau nullptr
			for (int i = 0; i < this->nrAccesari; i++) {
				this->editori[i] = editori[i];
			}
		}
		else {
			this->nrAccesari = 0;
			this->editori = NULL;
		}
	
		if (dimensiuneFisier <= MAX_DIMENSIUNE_FISIER) {
			this->dimensiuneFisier = dimensiuneFisier;
		}
		else {
			this->dimensiuneFisier = 0;
		}
		this->areParola = areParola;
		this->tip = tip;
	}
	//destructor
	~Fisier() {
		if (this->editori != NULL) {
			delete[]this->editori;
		}
	}

	//constructor de copiere
	Fisier(const Fisier& f):codFisier(f.codFisier) {
		if (f.numeFisier.size() >= 5) {
			this->numeFisier = f.numeFisier;
		}
		else {
			this->numeFisier = "Necunoscut";
		}
		if (f.nrAccesari > 0 && f.dimensiuneFisier != NULL) {
			this->nrAccesari = f.nrAccesari;
			this->editori = new string[this->nrAccesari];//sau nullptr
			for (int i = 0; i < this->nrAccesari; i++) {
				this->editori[i] = f.editori[i];
			}
		}
		else {
			this->nrAccesari = 0;
			this->editori = NULL;
		}

		if (f.dimensiuneFisier <= MAX_DIMENSIUNE_FISIER) {
			this->dimensiuneFisier = f.dimensiuneFisier;
		}
		else {
			this->dimensiuneFisier = 0;
		}
		this->areParola = f.areParola;
		this->tip = f.tip;
	}


	//getteri 
	float getDimensiuneFisier() {
		return this->dimensiuneFisier;
	}

	bool getAreParola() {
		return this->areParola;
	}
	int getNrAccesari() {
		return this->nrAccesari;
	}

	string* getEditori() {
		return this->editori;
	}
	//setteri
	void setDimensiuneFisier(float dimensiuneFisier) {
		if (dimensiuneFisier <= MAX_DIMENSIUNE_FISIER)
			this->dimensiuneFisier = dimensiuneFisier;
		else throw new exception("Dimensiunea fisierului este prea mare!");
	}

	void setAreParola(bool areParola) {
		this->areParola = areParola;
	}


	//operator =
	Fisier& operator=(const Fisier& f) {
		if (this != &f) {
			if (this->editori != NULL) {
				delete[]this->editori;
			}
			if (f.numeFisier.size() >= 5) {
				this->numeFisier = f.numeFisier;
			}
			else {
				this->numeFisier = "Necunoscut";
			}
			if (f.nrAccesari > 0 && f.dimensiuneFisier != NULL) {
				this->nrAccesari = f.nrAccesari;
				this->editori = new string[this->nrAccesari];//sau nullptr
				for (int i = 0; i < this->nrAccesari; i++) {
					this->editori[i] = f.editori[i];
				}
			}
			else {
				this->nrAccesari = 0;
				this->editori = NULL;
			}

			if (f.dimensiuneFisier <= MAX_DIMENSIUNE_FISIER) {
				this->dimensiuneFisier = f.dimensiuneFisier;
			}
			else {
				this->dimensiuneFisier = 0;
			}
			this->areParola = f.areParola;
			this->tip = f.tip;
			return *this;
		}
	}

	friend ostream& operator<<(ostream& out, const Fisier & f) {
		out << "Cod fisier: " << f.codFisier << endl;
		out << "Nume fisier: " << f.numeFisier << endl;
		out << "Numar Accesari fisier: " << f.nrAccesari << endl;
		out << "Nume editori fisier: ";
		for (int i = 0; i < f.nrAccesari; i++) {
			out << f.editori[i] << ", ";
		}
		out << endl;
		out << "Dimensiune fisier: " << f.dimensiuneFisier << endl;
		out << "Are parola acest fisier? (1-Da sau 0-Nu): " << f.areParola << endl;
		out << "Tip fisier: ";
		switch (f.tip)
		{
		case 0: out << "WORD" << endl; break;
		case 1: out << "POWER_POINT" << endl; break;
		case 2: out << "EXCEL" << endl; break;
		default:
			out << "OTHER" << endl;
			break;
		}
		out << endl;
		return out;
	}

	//determinareNumarAccesari
	int determinareNumarAccesari(string editor) {
		int contor = 0;
		for (int i = 0; i < this->nrAccesari; i++) {
			if (this->editori[i] == editor) {
				contor++;
			}
		}
		return contor;
	}

	//operator >
	bool operator >(Fisier f) {
		return this->numeFisier.size() > f.numeFisier.size();
	}

	//operator index/ de indexare --- operator [] 
	string &operator[](int index) {
		if (index >= 0 && index < this->nrAccesari) {
			return this->editori[index];
		}
		else {
			string eroare = "Index gresit!";
			return eroare;
		}
	}

	//functie adaugareELementinVector
	void adaugaAccesare(string editor) {
		Fisier copie = *this;
		if (this->editori != NULL) {
			delete[]this->editori;
		}
		this->nrAccesari++;
		this->editori = new string[this->nrAccesari];
		for (int i = 0; i < copie.nrAccesari; i++) {
			this->editori[i] = copie.editori[i];
		}
		this->editori[this->nrAccesari - 1] = editor;

	}
	//functie eliminaEditor
	void eliminaAccesare(string editor) {
		Fisier copie = *this;
		int nr = 0;
		for (int i = 0;i< this->nrAccesari; i++) {
			if (this->editori[i] == editor) {
				nr++;
			}
		}
		this->nrAccesari = this->nrAccesari - nr;
		if (this->editori != NULL) {
			delete[]this->editori;
		}
		this->editori = new string[this->nrAccesari];
		int pozitie = 0;
		for (int i = 0; i < copie.nrAccesari; i++) {
			if (copie.editori[i] != editor) {
				this->editori[pozitie] = copie.editori[i];
				pozitie++;
			}
		}

	}
	//operator cast
	explicit operator int() {
		return this->nrAccesari;
	}

	explicit operator string() {
		string numeFinal = this->numeFisier+ "_" + to_string(this->nrAccesari);
		return numeFinal;
	}

	explicit operator string* () {
		string* vectDenumiriCuPoziti = new string[this->nrAccesari];
		for (int i = 0; i < this->nrAccesari; i++) {
			vectDenumiriCuPoziti[i] = this->editori[i] + "_" + to_string(i);
		}
		return vectDenumiriCuPoziti;
	}
	//operator += (ex: obj+=ceva)
	//cerinta: supraincarcati operatorul += astfel incat sa mareasca dimensiuneaFisierului cu valoarea parametrului dat
	/*Fisier& operator+=(float dimensiuneFisier) {
		if (this->dimensiuneFisier + dimensiuneFisier <= MAX_DIMENSIUNE_FISIER) {
			this->dimensiuneFisier += dimensiuneFisier;
		}
		return *this;
	}*/
	//cerinta: supraincarcati operatorul += astfel incat sa mareasca nr de Accesari, iar ca editor sa puna "Necunoscut
	Fisier& operator+=(int nrAccesari) {
		Fisier copie = *this;
		if (this->editori != NULL) {
			delete[]this->editori;
		}
		this->nrAccesari+=nrAccesari;
		this->editori = new string[this->nrAccesari];
		for (int i = 0; i < copie.nrAccesari; i++) {
			this->editori[i] = copie.editori[i];
		}
		for (int i = copie.nrAccesari; i < this->nrAccesari; i++) {
			this->editori[i] = "Anonim";
		}
		return *this;
	}

	//cerinta: supraincarcati operator += astfel incat sa adauge nr de accesari si editorii din alt fisier primit ca parametru

	Fisier& operator+=(Fisier f) {
		Fisier copie = *this;
		if (this->editori != NULL) {
			delete[]this->editori;
		}
		this->nrAccesari += f.nrAccesari;
		this->editori = new string[this->nrAccesari];
		for (int i = 0; i < copie.nrAccesari; i++) {
			this->editori[i] = copie.editori[i];
		}
		for (int i = copie.nrAccesari; i < this->nrAccesari; i++) {
			this->editori[i] = f.editori[i-copie.nrAccesari];
		}
		return *this;
	}

	//forma post-incrementata
	Fisier operator ++(int) {
		Fisier copie = *this;
		this->dimensiuneFisier++;
		return copie;
	}
	//forma pre-incrementata
	Fisier& operator++() {
		this->dimensiuneFisier++;
		return *this;
	}


	//operator +(obj+valoare)
	Fisier operator +(float dimFisier) {
		Fisier copie = *this;
		copie.dimensiuneFisier += dimFisier;
		return copie;
	}

	//operator+(obj + obj)
	Fisier operator+(Fisier f) {
		Fisier copie = *this;
		if (copie.editori != NULL) {
			delete[]copie.editori;
		}
		copie.nrAccesari += f.nrAccesari;
		copie.editori = new string[copie.nrAccesari];
		for (int i = 0; i < this->nrAccesari; i++) {
			copie.editori[i] = this->editori[i];
		}
		for (int i = this->nrAccesari; i < copie.nrAccesari; i++) {
			copie.editori[i] = f.editori[i - this->nrAccesari];
		}
		return copie;
	}
	//operator + (val + obj) -- avem nevoie de friend

	friend Fisier operator+(int val, Fisier f);
};

Fisier operator+(int val, Fisier f) {
	Fisier copie = f;
	copie.dimensiuneFisier += val;
	return copie;
}
//initializare atribut static
int Fisier::MAX_DIMENSIUNE_FISIER = 256;
int Fisier::nrFisier = 1;
int main() {
	cout << "Testare constructor implicit" << endl;
	Fisier f;
	cout << f.getDimensiuneFisier() << endl;
	cout << f.getAreParola() << endl;
	try {
		f.setDimensiuneFisier(500);
	}
	catch (exception* ex) {
		cout << ex->what() << endl;
	}
	f.setDimensiuneFisier(25);
	f.setAreParola(true);
	cout << f.getDimensiuneFisier() << endl;
	cout << f.getAreParola() << endl;
	cout << endl << endl;
	//constructor cu toti parametrii
	cout << "Testare constructor cu toti parametrii" << endl;
	string numeEditori[]={ "Marcel","Ionel","Marcel","Marcel","Viorel"};
	Fisier f1("Program_test", 5, numeEditori, 10, 1, EXCEL);
	cout << f1.getDimensiuneFisier() << endl;
	cout << f1.getAreParola() << endl;
	cout << endl << endl;

	//constructor de copiere
	cout << "Testare constructor copy" << endl;

	Fisier f2 = f1;
	cout << f2.getDimensiuneFisier() << endl;
	cout << f2.getAreParola() << endl;

	cout << endl << endl;
	cout << "Testare op =" << endl;
	f2 = f;
	cout << f2.getDimensiuneFisier() << endl;
	cout << f2.getAreParola() << endl;
	cout << endl << endl;
	//op << --- cout<< f;
	cout << f1 << endl<<endl;


	//determinareNumarAccesari
	cout << f1.determinareNumarAccesari("Marcel") << endl << endl;
	cout << (f1 > f) << endl;
	cout << f << endl << endl;

	//op [] -- operator index
	cout << f1[22] << endl;

	f1[1] = "David";
	cout << f1 << endl<<endl;
	f1.adaugaAccesare("Dan");
	cout << f1 << endl << endl;
	f1.eliminaAccesare("Marcel");
	cout << f1 << endl << endl;
	int castLaInt = (int)f1;
	cout << castLaInt << endl;

	string castLaString = (string)f1;
	cout << castLaString << endl;

	string* vectCuPozitiiSiNume = (string*)f1;
	for (int i = 0; i < f1.getNrAccesari(); i++) {
		cout << vectCuPozitiiSiNume[i] << endl;
	}
	cout << endl << endl;


	//operator +=
	f1 += 4;
	cout << f1 << endl << endl;


	cout << f2 << endl << endl;
	f2 += f1;
	cout << f2 << endl << endl;


	//operator ++ post- incrementat
	Fisier f3 = f1++;
	cout << f3 << endl << endl;
	cout << f1 << endl << endl;
	//operator ++ pre-incrementat
	Fisier f4 = ++f1;
	cout << f4 << endl << endl;
	cout << f1 << endl << endl;
	//operator +(obj+val)
	Fisier f5 = f1 + 50;
	cout << f5 << endl << endl;
	cout << f1 << endl << endl;

	//operator + (obj + obj)
	Fisier f6 = f5 + f1;
	cout<<f6<<endl<<endl;
	cout<<f5<<endl<<endl;
	cout<<f1<<endl<<endl;

	//operator + (valoare + obj) 
	Fisier f7 = 10 + f6;
	cout << f7 << endl<<endl;
	cout << f6 << endl<<endl;

	//int a = 10;
	//int b = a++;//post- incrementat ---> int b = a++=> 1)int b = a; 2)a++;
	//int c = ++a;//pre- incrementat ---> int b = ++a=> 1)++a 2)int c = a;

	//cout << a << "  " << b << " " << c << endl;


	
}