#ifndef __OMNIVORE_HPP__
#define __OMNIVORE_HPP__

#include "Animal.hpp"
#include "../Products/Products.hpp"

class Omnivore : public Animal{
    private:
        int berat_hewan;
        string nama;
    public:
        Omnivore(int harvestWeight, string kode, string nama);
        Omnivore(string kode, string nama,int berat_panen,int price);
        Omnivore(int harvestWeight,string kode, string nama,int animalweight);
        void makan(Products* m);
};

class Chicken : public Omnivore{
    private:
        static int harvestWeight;
        static int price;
    public:
        Chicken();
        Chicken(int berat_panen, int price);
        Chicken(int animalweight);
};

class Duck : public Omnivore{
    private:
        static int harvestWeight;
        static int price;
    public:
        Duck();
        Duck(int berat_panen, int price);
        Duck(int animalweight);
        
};

#endif