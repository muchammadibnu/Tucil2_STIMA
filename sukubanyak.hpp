#ifndef SUKUBANYAK_HPP
#define SUKUBANYAK_HPP
#include <iostream>
#include <random>
#include <chrono>
#include <time.h>
using namespace std;

class SukuBanyak
{
public:
    SukuBanyak();
    /*I.S. Atribut Polinom, dan size dari SukuBanyak belum dideklarasikan (kosong).
    F.S. size bernilai 0 dan Polinom berisi satu buah elemen bernilai 0.*/
    SukuBanyak(int);
    /*I.S. Atribut Polinom, dan size dari SukuBanyak belum dideklarasikan (kosong) serta n adalah derajat dari polinom yang akan dibuat.
    F.S. size bernilai n dan Polinom berisi n+1 buah elemen bernilai 0.*/
    SukuBanyak(const SukuBanyak&);
    /*I.S. Atribut Polinom, dan size dari SukuBanyak belum dideklarasikan (kosong), P sudah dideklarasikan.
    F.S. Atribut Polinom, dan size merupakan salinan dari atribut Polinom, dan size dari P.*/
    SukuBanyak& operator=(const SukuBanyak&);
    /*I.S. Atribut Polinom, dan size sembarang, P sudah dideklarasikan.
    F.S. Atribut Polinom, dan size merupakan salinan dari atribut Polinom, dan size dari P.*/
    SukuBanyak operator*(const SukuBanyak&);
    /*I.S. P adalah class dengan atribut sembarang.
    F.S. Menghasilkan perkalian polinom antara P dan objek secara BruteForce.*/
    SukuBanyak operator*(int);
    /*I.S. x merupakan derajat dari persamaan polinomial dengan satu suku dan objek sembarang.
    F.S. Menghasilkan perkalian polinom antara objek dengan derajat persamaan polinomial x yang memiliki satu suku.*/
    SukuBanyak operator+(const SukuBanyak&);
    /*I.S. atribut masing-masing bernilai sembarang.
    F.S. Akan menghasilkan pertambahan polinomial antara objek dengan P.*/
    SukuBanyak operator-(const SukuBanyak&);
    /*I.S. atribut masing-masing bernilai sembarang.
    F.S. Akan menghasilkan pengurangan polinomial antara objek dengan P.*/
    void setPolinom();
    /*I.S. Atribut Polinom berisi sembarang.
    F.S. Atribut Polinom diisi oleh nilai random yang tidak nol.*/
    void Multiplication(SukuBanyak&, SukuBanyak&);
    /*I.S. Objek A dan B sembarang.
    F.S. Akan melakukan operasi perkalian A(x) dan B(x) dengan metode BruteForce.*/
    void print();
    /*I.S. Atribut Polinom bernilai sembarang.
    F.S. Akan menampilkan ke layar semua anggota dari Polinom.*/
    void menu();
    /*I.S. Semua objek terkait belum dideklarasikan.
    F.S. Menampilkan menu program dengan berbagai pilihan masukan metode.*/
    ~SukuBanyak();
    /*I.S. objek SukuBanyak sembarang.
    F.S. objek didealokasikan dari memori terkait.*/
public:
    int size;
    /* Derajat tertinggi polinom.*/
    static int count;
    /* Banyak operasi jumlah dan kali.*/
    int* Polinom;
    /* Menampung koefisien polinom dengan indeks menyatakan derajat dari koefisien yang bersangkutan.*/
    static int time;
    /* Menampung waktu yang dibutuhkan dalam implementasi algoritma */
};


#endif