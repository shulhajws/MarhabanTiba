#ifndef __OMNIVORE_HPP__
#define __OMNIVORE_HPP__

#include "Animal.hpp"
#include "../Product/Product.hpp"

class Omnivore : public Animal{
    private:
        int berat_hewan;
        string nama;
    public:
        Omnivore(string kode, string nama,int harvestWeight,int price);
        void makan(Product* m);
};

class Chicken : public Omnivore{
    private:
        static int harvestWeight;
        static int price;
    public:
        Chicken();
        Chicken(int harvestWeight, int price);
        Chicken(int animalweight);
};

class Duck : public Omnivore{
    private:
        static int harvestWeight;
        static int price;
    public:
        Duck();
        Duck(int harvestWeight, int price);
        Duck(int animalweight);
        
};

#endif