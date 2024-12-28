#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>

using namespace std;

class ApeluriTelefonice{
    const int id;
    char* consumator;
    int nrApeluri;
    int* durataConvorbiri;
    static int costMinut;
    bool apeluriPeWapp;
    bool apeluriInternationale;
public:
    ApeluriTelefonice(int id):id(id){
        this->consumator = new char[strlen("")+1];
        strcpy(this->consumator,"");
        this->nrApeluri =0;
        this->durataConvorbiri = NULL;
        this->apeluriPeWapp=0;
        this->apeluriInternationale =0;
    }
    
    ApeluriTelefonice(int id, const char* consumator, int nrApeluri, int* durataConvorbiri, bool apeluriPeWapp, bool  apeluriInternationale):id(id){
        this->consumator = new char[strlen(consumator)+1];
        strcpy(this->consumator,consumator);
        this->nrApeluri =nrApeluri;
        this->durataConvorbiri = new int[this->nrApeluri];
        for(int i=0;i<this->nrApeluri;i++){
            this->durataConvorbiri[i] = durataConvorbiri[i];
        }
        this->apeluriPeWapp=apeluriPeWapp;
        this->apeluriInternationale =apeluriInternationale;
    }
    
    ApeluriTelefonice(const ApeluriTelefonice &a):id(a.id){
        this->consumator = new char[strlen(a.consumator)+1];
        strcpy(this->consumator,a.consumator);
        this->nrApeluri =a.nrApeluri;
        this->durataConvorbiri = new int[this->nrApeluri];
        for(int i=0;i<this->nrApeluri;i++){
            this->durataConvorbiri[i] = a.durataConvorbiri[i];
        }
        this->apeluriPeWapp=a.apeluriPeWapp;
        this->apeluriInternationale =a.apeluriInternationale;
    }
    
    ApeluriTelefonice &operator=(const ApeluriTelefonice &a){
        if(this!=&a){
            if(this->consumator!=NULL){
                delete[]this->consumator;
            }
            
            if(this->durataConvorbiri!=NULL){
                delete[]this->durataConvorbiri;
            }
            
            this->consumator = new char[strlen(a.consumator)+1];
            strcpy(this->consumator,a.consumator);
            this->nrApeluri =a.nrApeluri;
            this->durataConvorbiri = new int[this->nrApeluri];
            for(int i=0;i<this->nrApeluri;i++){
                this->durataConvorbiri[i] = a.durataConvorbiri[i];
            }
            this->apeluriPeWapp=a.apeluriPeWapp;
            this->apeluriInternationale =a.apeluriInternationale;
        }
        return *this;
    }
    
    friend ostream &operator<<(ostream &out, const ApeluriTelefonice &a){
        out<<a.id <<endl;
        out<<a.consumator <<endl;
        out<<a.nrApeluri <<endl;
        for(int i=0;i<a.nrApeluri;i++){
            out<<a.durataConvorbiri[i] <<endl;
        }
        out<<a.apeluriPeWapp <<endl;
        out<<a.apeluriInternationale <<endl;
        return out;
    }
    
    bool getApeluriPeWapp()const{
        return this->apeluriPeWapp;
    }
    
    bool getApeluriInternationale()const{
        return this->apeluriInternationale;
    }
    
    void setApeluriPeWapp(bool apeluriPeWapp){
        this->apeluriPeWapp = apeluriPeWapp;
    }
    
    void setApeluriInternationale(bool apeluriInternationale){
        this->apeluriInternationale  = apeluriInternationale;
    }
    
    ~ApeluriTelefonice(){
        if(this->consumator!=NULL){
            delete[]this->consumator;
        }
        
        if(this->durataConvorbiri!=NULL){
            delete[]this->durataConvorbiri;
        }
    }
    
    int calculTotalMinute(){
        int suma =0;
        for(int i=0;i<this->nrApeluri;i++){
            if(this->durataConvorbiri[i]>0)
            {
                suma +=this->durataConvorbiri[i];
            }
            else{
                suma -= this->durataConvorbiri[i];
            }
        }
        return suma;
    }
    
    int getCostTotal(int minuteAbonament){
        int sumaMinuteVorbite = 0;
        for(int i=0;i<this->nrApeluri;i++){
            if(this->durataConvorbiri[i] >0){
                sumaMinuteVorbite += this->durataConvorbiri[i];
            }
          
        }
        if(minuteAbonament>= sumaMinuteVorbite){
            return 0;
        }
        else{
            int minuteDePlata = sumaMinuteVorbite - minuteAbonament;
            return minuteDePlata * costMinut;
        }
    }
    
    void operator()(int valApelFacut){
        ApeluriTelefonice copie = *this;
        if(this->durataConvorbiri!=NULL){
            delete[]this->durataConvorbiri;
        }
        this->nrApeluri++;
        this->durataConvorbiri = new int[this->nrApeluri];
        for(int i=0;i<copie.nrApeluri;i++){
            this->durataConvorbiri[i] = copie.durataConvorbiri[i];
        }
        this->durataConvorbiri[this->nrApeluri-1]= valApelFacut;
    }
    
    void operator[](int valApelFacut){
        ApeluriTelefonice copie = *this;
        if(this->durataConvorbiri!=NULL){
            delete[]this->durataConvorbiri;
        }
        this->nrApeluri++;
        this->durataConvorbiri = new int[this->nrApeluri];
        for(int i=0;i<copie.nrApeluri;i++){
            this->durataConvorbiri[i] = copie.durataConvorbiri[i];
        }
        this->durataConvorbiri[this->nrApeluri-1]= valApelFacut;
    }
    
    ApeluriTelefonice &operator++(){
        for(int i=0;i<this->nrApeluri;i++){
            if(this->durataConvorbiri[i]>0){
                this->durataConvorbiri[i]++;
            }
            else{
                this->durataConvorbiri[i]--;
            }
        }
        return *this;
    }
    
    ApeluriTelefonice operator++(int){
        ApeluriTelefonice copie= *this;
        for(int i=0;i<this->nrApeluri;i++){
            if(this->durataConvorbiri[i]>0){
                this->durataConvorbiri[i]++;
            }
            else{
                this->durataConvorbiri[i]--;
            }
           
        }
        return copie;
    }
    
    bool operator ==(ApeluriTelefonice a){
        bool egale=1;
        if(strcmp(this->consumator, a.consumator)==0 && this->nrApeluri == a.nrApeluri && this->apeluriPeWapp == a.apeluriPeWapp && this->apeluriInternationale == a.apeluriInternationale){
            for(int i=0;i<this->nrApeluri;i++){
                if(this->durataConvorbiri[i] != a.durataConvorbiri[i]){
                    egale=0;
                }
            }
        }
        return egale;
       
    }
};

int ApeluriTelefonice::costMinut =10;

int main(){
    ApeluriTelefonice a(4);
    cout<<a.getApeluriPeWapp()<<endl;
    cout<<a.getApeluriInternationale()<<endl;
    cout<<endl;
    cout<<endl;
    
    a.setApeluriPeWapp(true);
    a.setApeluriInternationale(true);
    cout<<a.getApeluriPeWapp()<<endl;
    cout<<a.getApeluriInternationale()<<endl;
    cout<<endl;
    cout<<endl;
    
    
    ApeluriTelefonice a1(20,"Ionel", 6, new int[6]{44,-44,33,-33,11,-11},true,true);
    cout<<a.calculTotalMinute()<<endl;
    cout<<a1.calculTotalMinute()<<endl;
    
    cout<<a1.getCostTotal(30)<<endl;
    
    
    ApeluriTelefonice a2 =a1;
    cout<<a2<<endl<<endl;
    
    ApeluriTelefonice a3(105);
    a3=a1;
    cout<<a3<<endl<<endl;
    
    a3[-55];
    a3(55);
    cout<<a3<<endl<<endl;
    
    ApeluriTelefonice a4 = a3++;
    
    cout<<a4<<endl;
    cout<<a3<<endl;
 
    cout<<endl<<endl;
    
    ApeluriTelefonice a5= ++a3;
    
    cout<<a5<<endl;
    cout<<a3<<endl;
 
    cout<<endl<<endl;
    
    ApeluriTelefonice a6 =a3;
    cout<<(a6 == a3)<<endl;
    cout<<(a5 == a3)<<endl;
    cout<<(a4 == a3)<<endl;
    cout<<(a5 == a4)<<endl;
    cout<<(a3 == a3)<<endl;
  
}
