#ifndef __Animal_HPP__
#define __Animal_HPP__

#include "../Item.hpp"
#include "../Products/Products.hpp"
#include <string>
using namespace std;

class Animal : public Item{
    protected:
        static int animalID;
        int harvestWeight;
        int price;
        int animalWeight;
    public:
        Animal(string code, string name, string type, int harvestWeight, int price);
        void setAnimalWeight(int animalWeight); // buat muat berat hewan
        virtual void makan(Products p)=0;
        bool isHarvestable();
};

#endif