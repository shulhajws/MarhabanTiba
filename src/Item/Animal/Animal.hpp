#ifndef __Animal_HPP__
#define __Animal_HPP__

#include "../Item.hpp"
#include "../Products/Products.hpp"
#include <string>
using namespace std;

class Animal : public Item{
    protected:
        int animalID;
        int animalWeight;
        int harvestWeight;
    public:
        Animal(string code,string name,string type,int harvestWeight);
        Animal(string code, string name, string type, int harvestWeight, int price);
        Animal(string code, string name, string type, int animalWeight,int harvestWeight,int id);
        void setAnimalWeight(int animalWeight); // buat muat berat hewan
        virtual void makan(Products* p)=0;
        bool isHarvestable();
};

#endif