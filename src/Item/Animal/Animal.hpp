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
        Animal(string code, string name, string type, int animalWeight,int harvestWeight);
        ~Animal();
        virtual void makan(Products* p);
        bool isHarvestable();
};

#endif