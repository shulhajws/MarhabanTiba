#ifndef __CARNIVORA_HPP__
#define __CARNIVORA_HPP__

#include "Animal.hpp"
#include "../Products/ProductsAnimal.hpp"

class Carnivore : Animal{
    public:
        Carnivore(string kode, string nama,int berat_hewan,int price);
        void makan(Products* m);
};

class Snake : Carnivore{
    public:
        Snake(int berat_panen, int price);
};

#endif