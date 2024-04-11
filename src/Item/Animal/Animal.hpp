#ifndef __Animal_HPP__
#define __Animal_HPP__

#include "../Item.hpp"
#include "../Product/Product.hpp"
#include <string>
using namespace std;

class Animal : public Item{
    protected:
        int animalID;
        int animalWeight;
        int harvestWeight;
        int price;

    public:
        Animal(int price, string code, string name,string type,int harvestWeight);
        Animal(string code, string name, string type, int animalWeight,int harvestWeight);
        ~Animal();
        virtual void makan(Product* p);
        int getPrice();
        bool isReadyToHarvest();
};

#endif