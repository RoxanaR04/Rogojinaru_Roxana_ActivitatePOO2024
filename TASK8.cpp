#include <iostream>
#include <string>
#include <vector>
#include <fstream> // Pentru lucru cu fisiere
#include <stdexcept> // Pentru out_of_range

using namespace std;

// Clasa Masina
class Masina {
private:
    string marca;
    string model;
    int an;
    static int numarMasini;
    const int idMasina;
    int* consum; // Pointer pentru consum

public:
    Masina(string m, string mdl, int a, int id)
        : marca(m), model(mdl), an(a), idMasina(id) {
        consum = new int(0);
        numarMasini++;
    }
    Masina(string m, string mdl, int a)
        : Masina(m, mdl, a, ++numarMasini) {}
    Masina()
        : marca("Unknown"), model("Unknown"), an(0), idMasina(++numarMasini) {
        consum = new int(0);
    }
    Masina(const Masina& other)
        : marca(other.marca), model(other.model), an(other.an), idMasina(++numarMasini) {
        consum = new int(*(other.consum));
    }
    ~Masina() {
        delete consum;
        numarMasini--;
    }

    static int getNumarMasini() { return numarMasini; }
    int getIdMasina() const { return idMasina; }

    friend ostream& operator<<(ostream& os, const Masina& m);
    friend istream& operator>>(istream& is, Masina& m);

    // Metode pentru lucru cu fi?iere text
    void scrieInFisierText(const string& fisier) const {
        ofstream out(fisier, ios::app);
        if (!out) {
            throw runtime_error("Eroare la deschiderea fi?ierului text.");
        }
        out << marca << " " << model << " " << an << " " << *consum << "\n";
        out.close();
    }

    void citesteDinFisierText(const string& fisier) {
        ifstream in(fisier);
        if (!in) {
            throw runtime_error("Eroare la deschiderea fi?ierului text.");
        }
        in >> marca >> model >> an >> *consum;
        in.close();
    }

    // Metode pentru lucru cu fi?iere binare
    void scrieInFisierBinar(const string& fisier) const {
        ofstream out(fisier, ios::binary | ios::app);
        if (!out) {
            throw runtime_error("Eroare la deschiderea fi?ierului binar.");
        }
        size_t len = marca.size();
        out.write((char*)&len, sizeof(len));
        out.write(marca.c_str(), len);

        len = model.size();
        out.write((char*)&len, sizeof(len));
        out.write(model.c_str(), len);

        out.write((char*)&an, sizeof(an));
        out.write((char*)consum, sizeof(*consum));
        out.close();
    }

    void citesteDinFisierBinar(const string& fisier) {
        ifstream in(fisier, ios::binary);
        if (!in) {
            throw runtime_error("Eroare la deschiderea fi?ierului binar.");
        }
        size_t len;
        in.read((char*)&len, sizeof(len));
        marca.resize(len);
        in.read(&marca[0], len);

        in.read((char*)&len, sizeof(len));
        model.resize(len);
        in.read(&model[0], len);

        in.read((char*)&an, sizeof(an));
        in.read((char*)consum, sizeof(*consum));
        in.close();
    }
};

int Masina::numarMasini = 0;

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

ostream& operator<<(ostream& os, const Masina& m) {
    os << "Masina: " << m.marca << " " << m.model << ", An: " << m.an
        << ", Consum: " << *(m.consum) << " km/l, ID: " << m.getIdMasina() << endl;
    return os;
}

// Clasa Garage
class Garage {
private:
    string numeGaraj;
    int capacitate;
    vector<Masina> masini;

public:
    Garage(string nume, int capacitateMaxima)
        : numeGaraj(nume), capacitate(capacitateMaxima) {}

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

    friend ostream& operator<<(ostream& os, const Garage& g) {
        os << "Garajul " << g.numeGaraj << " (capacitate " << g.capacitate << "):\n";
        for (const auto& m : g.masini) {
            os << m;
        }
        return os;
    }

    // Metode pentru lucru cu fi?iere text
    void scrieInFisierText(const string& fisier) const {
        ofstream out(fisier, ios::app);
        if (!out) {
            throw runtime_error("Eroare la deschiderea fi?ierului text.");
        }
        out << numeGaraj << " " << capacitate << "\n";
        for (const auto& masina : masini) {
            masina.scrieInFisierText(fisier);
        }
        out.close();
    }

    void citesteDinFisierText(const string& fisier) {
        ifstream in(fisier);
        if (!in) {
            throw runtime_error("Eroare la deschiderea fi?ierului text.");
        }
        in >> numeGaraj >> capacitate;
        masini.clear();
        while (!in.eof()) {
            Masina m;
            m.citesteDinFisierText(fisier);
            masini.push_back(m);
        }
        in.close();
    }
};

int main() {
    try {
        Masina m1("Toyota", "Corolla", 2020, 1);
        m1.scrieInFisierText("masini.txt");
        m1.scrieInFisierBinar("masini.dat");

        Masina m2;
        m2.citesteDinFisierText("masini.txt");
        m2.citesteDinFisierBinar("masini.dat");
        cout << m2;

        Garage garaj("Garajul 1", 5);
        garaj.adaugaMasina(m1);
        garaj.scrieInFisierText("garaj.txt");

        Garage garajCitit("Temp", 1);
        garajCitit.citesteDinFisierText("garaj.txt");
        cout << garajCitit;

    }
    catch (const exception& e) {
        cout << "Eroare: " << e.what() << endl;
    }
    return 0;
}