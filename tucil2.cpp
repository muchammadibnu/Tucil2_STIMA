#include "sukubanyak.hpp"
#include "DivideAndConquer.hpp"
int SukuBanyak::count=0;
int SukuBanyak::time=0;
SukuBanyak::SukuBanyak():SukuBanyak(0){}
SukuBanyak::SukuBanyak(int n){
    if(n>=0){
        size=n;
    }
    else{
        size=0;
    }
    Polinom=new int[size+1];
    for(int i=0; i<=size; i++){
        Polinom[i]=0;
    }
}
SukuBanyak::SukuBanyak(const SukuBanyak& P){
    this->size=P.size;
    this->Polinom=new int[this->size+1];
    for(int i=0; i<=size; i++){
        this->Polinom[i]=P.Polinom[i];
    }
}
SukuBanyak& SukuBanyak::operator=(const SukuBanyak& P){
    this->size=P.size;
    delete[] Polinom;
    this->Polinom=new int[this->size+1];
    for(int i=0; i<=size; i++){
        this->Polinom[i]=P.Polinom[i];
    }
    return *this;
}
SukuBanyak SukuBanyak::operator*(const SukuBanyak& P){
    SukuBanyak A((this->size)+P.size);
    for(int i=0; i<=size; i++){
        for(int j=0; j<=P.size; j++){
            A.Polinom[i+j]+=this->Polinom[i] * P.Polinom[j];
            SukuBanyak::count+=2;
        }
    }
    SukuBanyak::count-=A.size + 1;
    return A;
}
SukuBanyak SukuBanyak::operator*(int x){
    SukuBanyak P(this->size+x);
    for(int i=x; i<=P.size; i++){
        P.Polinom[i]=this->Polinom[i-x];
    }
    SukuBanyak::count+=this->size;
    return P;
}
SukuBanyak SukuBanyak::operator+(const SukuBanyak& P){
    if(this->size>P.size){
        SukuBanyak A(this->size);
        for(int i=0; i<=A.size; i++){
            if(i<=P.size){
                A.Polinom[i]=this->Polinom[i]+P.Polinom[i];
            }
            else{
                A.Polinom[i]=this->Polinom[i];
            }
        }
        SukuBanyak::count+=P.size; 
        return A;
    }
    else{
        SukuBanyak A(P.size);
        for(int i=0; i<=A.size; i++){
            if(i<=this->size){
                A.Polinom[i]=this->Polinom[i]+P.Polinom[i];
            }
            else{
                A.Polinom[i]=P.Polinom[i];
            }
        }
        SukuBanyak::count+=this->size;    
        return A;
    }
}

SukuBanyak SukuBanyak::operator-(const SukuBanyak& P){
    if(this->size>P.size){
        SukuBanyak A(this->size);
        for(int i=0; i<=A.size; i++){
            if(i<=P.size){
                A.Polinom[i]=this->Polinom[i]-P.Polinom[i];
            }
            else{
                A.Polinom[i]=this->Polinom[i];
            }
        }    
        SukuBanyak::count+=P.size;
        return A;
    }
    else{
        SukuBanyak A(P.size);
        for(int i=0; i<=A.size; i++){
            if(i<=this->size){
                A.Polinom[i]=this->Polinom[i]-P.Polinom[i];
            }
            else{
                A.Polinom[i]-=P.Polinom[i];
            }
        }    
        SukuBanyak::count+=A.size;
        return A;
    }
}

void SukuBanyak::setPolinom(){
    for(int i=0; i<=size; i++){
        Polinom[i]=rand()%10 - rand()%10;
        if(Polinom[i]==0){
            Polinom[i]=rand()%10 - rand()%10;
        }
    }
}

void SukuBanyak::Multiplication(SukuBanyak& A, SukuBanyak& B){
    SukuBanyak C;
    auto start= chrono::steady_clock::now();
    C = A * B ;
    auto end = chrono::steady_clock::now();
    SukuBanyak::time+=chrono::duration_cast<chrono::microseconds>(end-start).count();
    C.print();
}
void SukuBanyak::print(){
    int i=0;
    while(Polinom[i]==0 && i<=size){
        i++;
    }
    if(i<=size){
        cout << Polinom[i];
        for(i=i+1; i<=size; i++){
            if(Polinom[i]<0){
                cout << " - " <<Polinom[i]*-1 << "x^" << i;    
            }
            else if(Polinom[i]!=0){
                cout << " + " <<Polinom[i] << "x^" << i;
            }
        }
        cout << endl;
    }
    else{
        cout<<0<<endl;
    }
}
void SukuBanyak::menu(){
    int n;
    cout << "\n\nSelamat Datang di Program Perkalian Polinom\n\n";
    cout << "Silahkan Masukkan Derajat Polinom (n) : ";
    cin >> n;
    SukuBanyak A(n);
    SukuBanyak B(n);
    string S;
    A.setPolinom();
    B.setPolinom();
    cout << "A(x): ";
    A.print();
    cout << "B(x): ";
    B.print();
    cout << "Pilih metode yang akan digunakan:\n1.Brute Force\n2.Divide and Conquer\nPilihan: ";
    cin >> S;
    while(!(S=="1"||S=="1."||S=="Brute Force"||S=="2"||S=="2."||S=="Divide and Conquer")){
        cout << "Masukan yang Anda berikan salah! Mohon isi kembali\nPilihan: ";
        cin >> S;
    }
    cout << "A(x) x B(x) = ";
    if(S=="1"||S=="1."||S=="Brute Force"){
        A.Multiplication(A,B);
    }
    else{
        DivideAndConquer D;
        D.Multiplication(A,B);
    }
    cout << "Banyak operasi penjumlahan dan perkalian: " << SukuBanyak::count << endl;
    cout << "Perhitungan waktu: " << SukuBanyak::time << " microseconds" << endl;
}
SukuBanyak::~SukuBanyak(){
    delete[] Polinom;
}
DivideAndConquer::DivideAndConquer():SukuBanyak(0){} 
DivideAndConquer::DivideAndConquer(int n):SukuBanyak(n){}
void DivideAndConquer::Multiplication(SukuBanyak& A, SukuBanyak& B){
    SukuBanyak C;
    auto start= chrono::steady_clock::now();
    C=DivideAndConquerMulti(A,B);
    auto end = chrono::steady_clock::now();
    SukuBanyak::time+=chrono::duration_cast<chrono::microseconds>(end-start).count();
    C.print();
}
SukuBanyak DivideAndConquer::DivideAndConquerMulti(SukuBanyak A, SukuBanyak B){
    if(A.size<=0){
        return A*B; 
    }
    else{
        int n=A.size/2;
        if(A.size % 2 == 1){
            n++;
        }
        SukuBanyak D(n-1);
        SukuBanyak E(A.size-D.size-1);
        SukuBanyak F(n-1);
        SukuBanyak G(B.size-F.size-1);
        for(int i=0; i<=A.size; i++){
            if(i<=D.size){
                D.Polinom[i]=A.Polinom[i];
                F.Polinom[i]=B.Polinom[i];
            }
            else{
                E.Polinom[i-n]=A.Polinom[i];
                G.Polinom[i-n]=B.Polinom[i];
            }
        }
        SukuBanyak Y=DivideAndConquerMulti(D+E,F+G);
        SukuBanyak U=DivideAndConquerMulti(D,F);
        SukuBanyak Z=DivideAndConquerMulti(E,G);
        return U + ((Y-U)-Z)*(n) + Z*(n*2);
    }
}

int main(){
    SukuBanyak A;
    A.menu();
    return 0;
}