#include<iostream>
#include<string>
using namespace std;

class AgendaTelefon{
    const int id;
    int nrContacte;
    string* listaContacte;
    static int dimensiuneMaximaStocare;
    bool acceptaEmoticoane;
    static int NUMAR_URGENTA;
public:
    AgendaTelefon(int id):id(id){
        this->nrContacte = 0;
        this->listaContacte = NULL;
        this->acceptaEmoticoane =0;
    }
    
    AgendaTelefon(const AgendaTelefon &a):id(a.id){
        this->nrContacte = a.nrContacte;
        this->listaContacte = new string[this->nrContacte];
        for(int i=0;i<this->nrContacte;i++){
            this->listaContacte[i] = a.listaContacte[i];
        }
        this->acceptaEmoticoane =a.acceptaEmoticoane;
    }
    
    AgendaTelefon &operator =(const AgendaTelefon&a){
        if(this!=&a){
            if(this->listaContacte!=NULL){
                delete[]this->listaContacte;
            }
            this->nrContacte = a.nrContacte;
            this->listaContacte = new string[this->nrContacte];
            for(int i=0;i<this->nrContacte;i++){
                this->listaContacte[i] = a.listaContacte[i];
            }
            this->acceptaEmoticoane =a.acceptaEmoticoane;
        }
        return *this;
    }
    
    bool getAcceptaEmoticoane()const{
        return this->acceptaEmoticoane;
    }
    
    static int getNUMAR_URGENTA(){
        return NUMAR_URGENTA;
    }
    
    
    void setAcceptaEmoticoane(bool acceptaEmoticoane){
        this->acceptaEmoticoane = acceptaEmoticoane;
    }
    
    static void setNUMAR_URGENTA(int numarUrgenta){
        if(numarUrgenta>100 ){
            NUMAR_URGENTA = numarUrgenta;
        }
    }
    
    ~AgendaTelefon(){
        if(this->listaContacte!=NULL){
            delete[]this->listaContacte;
        }
    }
    
    void adaugaContact(string contact){
        if(contact.size()>=3){
            int nrCopie = this->nrContacte;
            string * aux = new string [nrCopie];
            for(int i=0;i<nrCopie;i++){
                aux[i] = this->listaContacte[i];
            }
            if(this->listaContacte!=NULL){
                delete[]this->listaContacte;
            }
            this->nrContacte++;
            this->listaContacte = new string [this->nrContacte];
            for(int i=0;i<nrCopie;i++){
                this->listaContacte[i] = aux[i];
            }
            this->listaContacte[this->nrContacte-1] = contact;
        }
        else throw exception();
    }
    
    int getNrContactiDupaInitiala(char c){
        int nrContacteGasite =0;
        for(int i=0;i<this->nrContacte;i++){
            if(tolower(this->listaContacte[i][0]) == tolower(c)){
                nrContacteGasite++;
            }
        }
        return nrContacteGasite;
    }
    
    AgendaTelefon operator +(string contact){
        AgendaTelefon copie = *this;
        copie.adaugaContact(contact);
        return copie;
    }
    
    friend AgendaTelefon operator+(string contact, AgendaTelefon a){
        AgendaTelefon copie = a;
        copie.adaugaContact(contact);
        return copie;
    }
    
    friend ostream &operator<<(ostream &out, const AgendaTelefon &a){
        out<<a.id <<endl;
        out<<a.nrContacte <<endl;
        for(int i=0;i<a.nrContacte;i++){
            out<<a.listaContacte[i] <<endl;
        }
        out<<a.acceptaEmoticoane<<endl;
        
        return out;
    }
    
    
    bool operator()(){
        string denumire="";
        for(int i=0;i<this->nrContacte;i++){
            int nrDuplicate =0;
            denumire = this->listaContacte[i];
            for(int j=0;j<this->nrContacte;j++){
                if(denumire == this->listaContacte[j]){
                    nrDuplicate++;
                }
            }
            if(nrDuplicate>=2){
                return true;
            }
        }
        return false;
    }
    
    void operator[](char c){
        int nrContacteGasite =0;
        for(int i=0;i<this->nrContacte;i++){
            if(tolower(this->listaContacte[i][0]) == tolower(c)){
                nrContacteGasite++;
            }
        }
        string * aux = new string [nrContacteGasite];
        int poz = 0;
        for(int i=0;i<this->nrContacte;i++){
            if(tolower(this->listaContacte[i][0]) == tolower(c)){
                aux[poz] = this->listaContacte[i];
                poz++;
            }
        }
        
        cout<<"Din toate cele: " << this->nrContacte <<" au ramas, dupa formatare: "<< nrContacteGasite<<endl;
        cout<<"Acestea sunt: ";
        for(int i=0;i<nrContacteGasite;i++){
            cout<<aux[i]<<endl;
        }
    }
};
int AgendaTelefon::dimensiuneMaximaStocare =100;
int AgendaTelefon::NUMAR_URGENTA = 112;


int main(){
    AgendaTelefon a(101);
    cout<<a.getAcceptaEmoticoane()<<endl;
    cout<<a.getNUMAR_URGENTA()<<endl;
    
    cout<<endl;
    
    a.setAcceptaEmoticoane(true);
    a.setNUMAR_URGENTA(113);
    a.setNUMAR_URGENTA(58);
    
    cout<<a.getAcceptaEmoticoane()<<endl;
    cout<<a.getNUMAR_URGENTA()<<endl;
    
    cout<<endl;
    
    a.adaugaContact("Georgel");
    a.adaugaContact("Minuel");
    a.adaugaContact("Diana");
    a.adaugaContact("Dragos");
    a.adaugaContact("Alexandru");
    a.adaugaContact("Alexandrc");
    a.adaugaContact("Alexandra");
    a.adaugaContact("Maia");
    a.adaugaContact("Costel");
    a.adaugaContact("Mihai");
    a.adaugaContact("Nelu");
    
    try {
        a.adaugaContact("Io");
    } catch (exception ex) {
        cout<<ex.what()<<endl;
        cout<<"Numele introdus nu este bun!"<<endl;
    }
    
    
    cout<<endl<<endl;
    cout<<a.getNrContactiDupaInitiala('g')<<endl;
    cout<<a.getNrContactiDupaInitiala('a')<<endl;
    
    
    cout<<endl;
    
    AgendaTelefon a2 = a;
    cout<<a.getAcceptaEmoticoane()<<endl;
    cout<<a.getNUMAR_URGENTA()<<endl;
    cout<<a.getNrContactiDupaInitiala('g')<<endl;
    cout<<a.getNrContactiDupaInitiala('a')<<endl;
    
    cout<<endl;
    
    AgendaTelefon a3(105);
    cout<<a3.getAcceptaEmoticoane()<<endl;
    cout<<a3.getNUMAR_URGENTA()<<endl;
    cout<<a3.getNrContactiDupaInitiala('g')<<endl;
    cout<<a3.getNrContactiDupaInitiala('a')<<endl;
    
    cout<<endl;
    
    a3= a;
    
    cout<<a3.getAcceptaEmoticoane()<<endl;
    cout<<a3.getNUMAR_URGENTA()<<endl;
    cout<<a3.getNrContactiDupaInitiala('g')<<endl;
    cout<<a3.getNrContactiDupaInitiala('a')<<endl;
    
    cout<<endl;
    
    AgendaTelefon a4(104);
    a4 = "Costica" + a2;
    cout<<a4.getNrContactiDupaInitiala('g')<<endl;
    cout<<a4.getNrContactiDupaInitiala('a')<<endl;
    cout<<a4.getNrContactiDupaInitiala('c')<<endl;
    cout<<a4.getNrContactiDupaInitiala('m')<<endl;
    
    cout<<endl;
    cout<<endl;
    AgendaTelefon a5(101);
    a5 = a2 + "Mircea";
    a5 = a5 + "Mircea";
    a5 = a5 + "Mircea";
    cout<<a5.getNrContactiDupaInitiala('g')<<endl;
    cout<<a5.getNrContactiDupaInitiala('a')<<endl;
    cout<<a5.getNrContactiDupaInitiala('c')<<endl;
    cout<<a5.getNrContactiDupaInitiala('m')<<endl;
    
    cout<<endl;
    cout<<endl;
    
    ///operator <<si >> nu am mai implementat
    ///
    cout<<a5<<endl;
    cout<<a<<endl;
    
    cout<<endl;
    cout<<endl;
    
    cout<<a()<<endl;
    cout<<a5()<<endl;
    
    cout<<endl;
    cout<<endl;
    
    a5['m'];
    
    cout<<endl<<endl;
    
    a5['g'];

    cout<<endl<<endl;
    
    a5['c'];
}

