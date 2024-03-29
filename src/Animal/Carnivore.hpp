#ifndef __HERBIVORA_HPP__
#define __HERBIVORA_HPP__

#include "Animal.hpp"

class Carnivore : Animal{
    public:
        Carnivore(string kode, string nama,int berat_hewan,int price);
        void makan(string m);
};

class Snake : Carnivore{
    public:
        Snake(int berat_panen, int price);
};

#endif