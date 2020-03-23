#ifndef DIVIDEANDCONQUER_HPP
#define DIVIDEANDCONQUER_HPP
#include "sukubanyak.hpp"
class DivideAndConquer: public SukuBanyak
{
public:
    DivideAndConquer(); 
    /*I.S. Atribut Polinom, dan size dari SukuBanyak belum dideklarasikan (kosong).
    F.S. size bernilai 0 dan Polinom berisi satu buah elemen bernilai 0.*/
    DivideAndConquer(int); 
    /*I.S. Atribut Polinom, dan size dari SukuBanyak belum dideklarasikan (kosong) serta n adalah derajat dari polinom yang akan dibuat.
    F.S. size bernilai n dan Polinom berisi n+1 buah elemen bernilai 0.*/
    void Multiplication(SukuBanyak&, SukuBanyak&);
    /*I.S. Objek A dan B sembarang.
    F.S. Akan melakukan operasi perkalian A(x) dan B(x) dengan metode Divide and Conquer.*/
    SukuBanyak DivideAndConquerMulti(SukuBanyak, SukuBanyak);
    /*I.S. objek A dan B sembarang.
    F.S. Menghasilkan objek hasil perkalian polinom A dan B secara rekursif dengan metode Divide and Conquer.*/
};
/* cara pakai ada pada readme.txt */
#endif