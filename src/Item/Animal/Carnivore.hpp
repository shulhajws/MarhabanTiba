#ifndef __CARNIVORA_HPP__
#define __CARNIVORA_HPP__

#include "Animal.hpp"
#include "../Product/ProductAnimal.hpp"
#include "../../Exception/Exception.hpp"

class Carnivore : public Animal{
    public:
        Carnivore(string kode, string nama,int harvestweight, int price);
        void makan(Product* m);
};

class Snake : public Carnivore{
    private:
        static int harvestWeight;
        static int price;
    public:
        Snake();
        Snake(int harvestWeight, int price);
        Snake(int animalweight);
};

#endif