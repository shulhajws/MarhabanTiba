#ifndef __HERBIVORE_HPP__
#define __HERBIVORE_HPP__

#include "Animal.hpp"
#include "../Products/Products.hpp"

class Herbivore : public Animal{
    public:
        Herbivore(int harvestWeight,string kode, string nama);
        Herbivore(string kode, string nama,int harvestweight,int price);
        Herbivore(int harvestWeight,string code, string name, int animalWeight); 
        void makan(Products* p);
};

class Cow : public Herbivore{
    private:
        static int harvestWeight;
        static int price;
    public:
        Cow();
        Cow(int berat_panen, int price);
        Cow(int animalweight);

};

class Sheep : public Herbivore{
    private:
        static int harvestWeight;
        static int price;
    public:
        Sheep();
        Sheep(int berat_panen, int price);
        Sheep(int animalweight);
};

class Horse : public Herbivore{
    private:
        static int harvestWeight;
        static int price;
    public:
        Horse();
        Horse(int berat_panen, int price);
        Horse(int animalweight);
};

class Rabbit : public Herbivore{
    private:
        static int harvestWeight;
        static int price;
    public:
        Rabbit();
        Rabbit(int berat_panen, int price);
        Rabbit(int animalweight);
};

#endif