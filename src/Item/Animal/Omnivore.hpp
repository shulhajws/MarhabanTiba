#ifndef __OMNIVORE_HPP__
#define __OMNIVORE_HPP__

#include "Animal.hpp"

class Omnivore : Animal{
    private:
        int berat_hewan;
        string nama;
    public:
        Omnivore(string kode, string nama,int berat_panen,int price);
        void makan(string m);
};

class Chicken : Omnivore{
    public:
        Chicken(int berat_panen, int price);
};

class Duck : Omnivore{
    public:
        Duck(int berat_panen, int price);
};

#endif