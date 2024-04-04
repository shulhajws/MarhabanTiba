#ifndef __CARNIVORA_HPP__
#define __CARNIVORA_HPP__

#include "Animal.hpp"
#include "../Products/ProductsAnimal.hpp"

class Carnivore : Animal{
    public:
        Carnivore(int harvestWeight,string kode, string nama);
        Carnivore(string kode, string nama,int harvestweight,int price);
        Carnivore(int harvestWeight,string kode, string nama,int animalweight);
        void makan(Products* m);
};

class Snake : Carnivore{
    private:
        static int harvestWeight;
        static int price;
    public:
        Snake();
        Snake(int berat_panen, int price);
        Snake(int animalweight);
};

#endif