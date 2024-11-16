#include <iostream>
#include <string>

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


// Clasa Bicicleta
class Bicicleta {
private:
    string tip;
    int vitezaMaxima;
    static int numarBiciclete;
    const int idBicicleta;
    float* greutate;

public:
    Bicicleta(string t, int v, int id) : tip(t), vitezaMaxima(v), idBicicleta(id) {
        greutate = new float(0.0);
        numarBiciclete++;
    }
    Bicicleta(string t, int v) : Bicicleta(t, v, ++numarBiciclete) {}
    Bicicleta() : tip("Unknown"), vitezaMaxima(0), idBicicleta(++numarBiciclete) {
        greutate = new float(0.0);
    }
    Bicicleta(const Bicicleta& other) : tip(other.tip), vitezaMaxima(other.vitezaMaxima), idBicicleta(++numarBiciclete) {
        greutate = new float(*(other.greutate));
    }
    ~Bicicleta() { delete greutate; numarBiciclete--; }

    static int getNumarBiciclete() { return numarBiciclete; }
    int getIdBicicleta() const { return idBicicleta; }

    friend ostream& operator<<(ostream& os, const Bicicleta& b);
    friend istream& operator>>(istream& is, Bicicleta& b);
};

// Initializare atribut static
int Bicicleta::numarBiciclete = 0;

// Operatorul de citire pentru Bicicleta
istream& operator>>(istream& is, Bicicleta& b) {
    cout << "Introduceti tipul bicicletei: ";
    is >> b.tip;
    cout << "Introduceti viteza maxima a bicicletei: ";
    is >> b.vitezaMaxima;
    cout << "Introduceti greutatea bicicletei (kg): ";
    is >> *(b.greutate);
    return is;
}

// Operatorul de afișare pentru Bicicleta
ostream& operator<<(ostream& os, const Bicicleta& b) {
    os << "Bicicleta: " << b.tip << ", Viteza Maxima: " << b.vitezaMaxima
        << " km/h, Greutate: " << *(b.greutate) << " kg, ID: " << b.getIdBicicleta() << endl;
    return os;
}


// Clasa Motocicleta
class Motocicleta {
private:
    string marca;
    int cilindree;
    static int numarMotociclete;
    const int idMotocicleta;
    double* putere;

public:
    Motocicleta(string m, int c, int id) : marca(m), cilindree(c), idMotocicleta(id) {
        putere = new double(0.0);
        numarMotociclete++;
    }
    Motocicleta(string m, int c) : Motocicleta(m, c, ++numarMotociclete) {}
    Motocicleta() : marca("Unknown"), cilindree(0), idMotocicleta(++numarMotociclete) {
        putere = new double(0.0);
    }
    Motocicleta(const Motocicleta& other) : marca(other.marca), cilindree(other.cilindree), idMotocicleta(++numarMotociclete) {
        putere = new double(*(other.putere));
    }
    ~Motocicleta() { delete putere; numarMotociclete--; }

    static int getNumarMotociclete() { return numarMotociclete; }
    int getIdMotocicleta() const { return idMotocicleta; }

    friend ostream& operator<<(ostream& os, const Motocicleta& m);
    friend istream& operator>>(istream& is, Motocicleta& m);
};

// Initializare atribut static
int Motocicleta::numarMotociclete = 0;

// Operatorul de citire pentru Motocicleta
istream& operator>>(istream& is, Motocicleta& m) {
    cout << "Introduceti marca motocicletei: ";
    is >> m.marca;
    cout << "Introduceti cilindreea motocicletei (cm^3): ";
    is >> m.cilindree;
    cout << "Introduceti puterea motocicletei (CP): ";
    is >> *(m.putere);
    return is;
}

// Operatorul de afișare pentru Motocicleta
ostream& operator<<(ostream& os, const Motocicleta& m) {
    os << "Motocicleta: " << m.marca << ", Cilindree: " << m.cilindree
        << " cm^3, Putere: " << *(m.putere) << " CP, ID: " << m.getIdMotocicleta() << endl;
    return os;
}

int main() {
    // Crearea vectorilor pentru masini, biciclete si motociclete
    Masina masini[3];
    Bicicleta biciclete[3];
    Motocicleta motociclete[3];

    // Citirea obiectelor pentru vectorii de masini
    cout << "Introduceti informatiile pentru 3 masini:\n";
    for (int i = 0; i < 3; i++) {
        cin >> masini[i];
    }

    // Citirea obiectelor pentru vectorii de biciclete
    cout << "\nIntroduceti informatiile pentru 3 biciclete:\n";
    for (int i = 0; i < 3; i++) {
        cin >> biciclete[i];
    }

    // Citirea obiectelor pentru vectorii de motociclete
    cout << "\nIntroduceti informatiile pentru 3 motociclete:\n";
    for (int i = 0; i < 3; i++) {
        cin >> motociclete[i];
    }

    // Afișarea obiectelor pentru fiecare tip de vehicul
    cout << "\nInformatii masini:\n";
    for (int i = 0; i < 3; i++) {
        cout << masini[i];
    }

    cout << "\nInformatii biciclete:\n";
    for (int i = 0; i < 3; i++) {
        cout << biciclete[i];
    }

    cout << "\nInformatii motociclete:\n";
    for (int i = 0; i < 3; i++) {
        cout << motociclete[i];
    }

    // Crearea unei matrice de obiecte dintr-o anumita clasa (de exemplu, Motocicleta)
    Motocicleta matriceMotociclete[2][2];

    // Citirea obiectelor din matricea de motociclete
    cout << "\nIntroduceti informatiile pentru o matrice 2x2 de motociclete:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> matriceMotociclete[i][j];
        }
    }

    // Afișarea obiectelor din matricea de motociclete
    cout << "\nInformatii matrice motociclete:\n";
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            cout << matriceMotociclete[i][j];
        }
    }

    return 0;
}