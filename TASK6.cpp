#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Clasa Masina (din codul precedent)
class Masina {
private:
    string marca;
    string model;
    int an;
    static int numarMasini;
    const int idMasina;
    int* consum; // Pointer pentru consum

public:
    Masina(string m, string mdl, int a, int id) : marca(m), model(mdl), an(a), idMasina(id) {
        consum = new int(0);
        numarMasini++;
    }
    Masina(string m, string mdl, int a) : Masina(m, mdl, a, ++numarMasini) {}
    Masina() : marca("Unknown"), model("Unknown"), an(0), idMasina(++numarMasini) {
        consum = new int(0);
    }
    Masina(const Masina& other) : marca(other.marca), model(other.model), an(other.an), idMasina(++numarMasini) {
        consum = new int(*(other.consum));
    }
    ~Masina() { delete consum; numarMasini--; }

    static int getNumarMasini() { return numarMasini; }
    int getIdMasina() const { return idMasina; }

    friend ostream& operator<<(ostream& os, const Masina& m);
    friend istream& operator>>(istream& is, Masina& m);
};

// Initializare atribut static
int Masina::numarMasini = 0;

// Operatorul de citire pentru Masina
istream& operator>>(istream& is, Masina& m) {
    cout << "Introduceti marca masinii: ";
    is >> m.marca;
    cout << "Introduceti modelul masinii: ";
    is >> m.model;
    cout << "Introduceti anul masinii: ";
    is >> m.an;
    cout << "Introduceti consumul (km/l): ";
    is >> *(m.consum);
    return is;
}

// Operatorul de afișare pentru Masina
ostream& operator<<(ostream& os, const Masina& m) {
    os << "Masina: " << m.marca << " " << m.model << ", An: " << m.an
        << ", Consum: " << *(m.consum) << " km/l, ID: " << m.getIdMasina() << endl;
    return os;
}


// Noua Clasa Garage
class Garage {
private:
    string numeGaraj;
    int capacitate;
    vector<Masina> masini; // Relatie de tip "has-a" cu Masina

public:
    // Constructor
    Garage(string nume, int capacitateMaxima) : numeGaraj(nume), capacitate(capacitateMaxima) {}

    // Getter și setter pentru numeGaraj
    string getNumeGaraj() const { return numeGaraj; }
    void setNumeGaraj(string nume) { numeGaraj = nume; }

    // Getter și setter pentru capacitate
    int getCapacitate() const { return capacitate; }
    void setCapacitate(int c) { capacitate = c; }

    // Metodă pentru a adăuga o mașină în garaj
    bool adaugaMasina(const Masina& m) {
        if (masini.size() < capacitate) {
            masini.push_back(m);
            return true;
        }
        else {
            cout << "Garajul este plin, nu se poate adauga masina.\n";
            return false;
        }
    }

    // Verifică dacă garajul este plin
    bool estePlin() const {
        return masini.size() == capacitate;
    }

    // Suprascriere operator [] pentru a accesa mașinile din garaj
    Masina& operator[](int index) {
        if (index >= 0 && index < masini.size()) {
            return masini[index];
        }
        throw out_of_range("Indexul este in afara limitelor.");
    }

    // Suprascriere operator << pentru a afisa garajul
    friend ostream& operator<<(ostream& os, const Garage& g) {
        os << "Garajul " << g.numeGaraj << " (capacitate " << g.capacitate << "):\n";
        for (const auto& m : g.masini) {
            os << m;
        }
        return os;
    }

    // Suprascriere operator + pentru a adăuga două garaje
    Garage operator+(const Garage& g) const {
        int capacitateNoua = this->capacitate + g.capacitate;
        Garage gNou(numeGaraj + " & " + g.numeGaraj, capacitateNoua);
        for (const auto& m : this->masini) {
            gNou.adaugaMasina(m);
        }
        for (const auto& m : g.masini) {
            gNou.adaugaMasina(m);
        }
        return gNou;
    }
};

int main() {
    // Crearea unui obiect de tip Garage
    Garage garaj1("Garajul 1", 5);

    // Adăugarea mașinilor în garaj
    Masina m1("Toyota", "Corolla", 2020, 1);
    Masina m2("Honda", "Civic", 2019, 2);
    Masina m3("BMW", "X5", 2021, 3);

    garaj1.adaugaMasina(m1);
    garaj1.adaugaMasina(m2);
    garaj1.adaugaMasina(m3);

    // Crearea unui alt garaj
    Garage garaj2("Garajul 2", 3);
    Masina m4("Audi", "Q7", 2018, 4);
    Masina m5("Mercedes", "S-Class", 2020, 5);

    garaj2.adaugaMasina(m4);
    garaj2.adaugaMasina(m5);

    // Afișarea unui garaj
    cout << garaj1;

    // Accesarea unei mașini din garaj folosind operatorul []
    try {
        cout << "\nMasina de la indexul 1: " << garaj1[1];
    }
    catch (const out_of_range& e) {
        cout << e.what() << endl;
    }

    // Combinarea a două garaje folosind operatorul +
    Garage garajCombinat = garaj1 + garaj2;
    cout << "\nGaraj combinat:\n" << garajCombinat;

    return 0;
}