#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>
#include <memory> // Pentru std::shared_ptr

using namespace std;

// Clasa abstractă Vehicul
class Vehicul {
public:
    virtual ~Vehicul() = default;
    virtual void afiseaza() const = 0;
    virtual int getId() const = 0;
};

// Clasa abstractă ObiectFisier
class ObiectFisier {
public:
    virtual ~ObiectFisier() = default;
    virtual void scrieInFisierText(const string& fisier) const = 0;
    virtual void citesteDinFisierText(const string& fisier) = 0;
};

// Clasa Masina moștenește Vehicul și ObiectFisier
class Masina : public Vehicul, public ObiectFisier {
private:
    string marca;
    string model;
    int an;
    static int numarMasini;
    const int idMasina;
    int* consum;

public:
    Masina(string m, string mdl, int a)
        : marca(m), model(mdl), an(a), idMasina(++numarMasini) {
        consum = new int(0);
    }

    Masina() : Masina("Unknown", "Unknown", 0) {}

    Masina(const Masina& other)
        : marca(other.marca), model(other.model), an(other.an), idMasina(++numarMasini) {
        consum = new int(*(other.consum));
    }

    ~Masina() override {
        delete consum;
        numarMasini--;
    }

    static int getNumarMasini() { return numarMasini; }

    // Implementarea metodei din Vehicul
    void afiseaza() const override {
        cout << "Masina: " << marca << " " << model << ", An: " << an
            << ", Consum: " << *consum << " km/l, ID: " << idMasina << endl;
    }

    int getId() const override { return idMasina; }

    // Implementarea metodelor din ObiectFisier
    void scrieInFisierText(const string& fisier) const override {
        ofstream out(fisier, ios::app);
        if (!out) {
            throw runtime_error("Eroare la deschiderea fișierului text.");
        }
        out << marca << " " << model << " " << an << " " << *consum << "\n";
        out.close();
    }

    void citesteDinFisierText(const string& fisier) override {
        ifstream in(fisier);
        if (!in) {
            throw runtime_error("Eroare la deschiderea fișierului text.");
        }
        in >> marca >> model >> an >> *consum;
        in.close();
    }
};

int Masina::numarMasini = 0;

// Clasa Garage
class Garage {
private:
    string numeGaraj;
    int capacitate;
    vector<shared_ptr<Vehicul>> vehicule; // Vector de pointeri la Vehicul

public:
    Garage(string nume, int capacitateMaxima)
        : numeGaraj(nume), capacitate(capacitateMaxima) {}

    bool adaugaVehicul(shared_ptr<Vehicul> v) {
        if (vehicule.size() < capacitate) {
            vehicule.push_back(v);
            return true;
        }
        else {
            cout << "Garajul este plin, nu se poate adauga vehicul.\n";
            return false;
        }
    }

    void afiseazaGaraj() const {
        cout << "Garajul " << numeGaraj << " (capacitate " << capacitate << "):\n";
        for (const auto& v : vehicule) {
            v->afiseaza();
        }
    }
};

// Funcția main
int main() {
    try {
        vector<shared_ptr<Vehicul>> vehicule;

        // Creăm 10 mașini și le adăugăm într-un vector
        for (int i = 0; i < 10; ++i) {
            shared_ptr<Masina> masina = make_shared<Masina>("Marca" + to_string(i), "Model" + to_string(i), 2000 + i);
            vehicule.push_back(masina);
        }

        // Exemplificăm late-binding
        for (const auto& vehicul : vehicule) {
            vehicul->afiseaza();
        }

        // Creăm un garaj și adăugăm mașini
        Garage garaj("Garaj Central", 5);
        for (int i = 0; i < 5; ++i) {
            garaj.adaugaVehicul(vehicule[i]);
        }

        garaj.afiseazaGaraj();

    }
    catch (const exception& e) {
        cout << "Eroare: " << e.what() << endl;
    }

    return 0;
}