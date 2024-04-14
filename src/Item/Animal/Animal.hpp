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
        Animal(string code, string name, string type, int harvestWeight, int price);
        ~Animal();
        virtual void makan(Product* p);
        void setAnimalWeight(int weight);
        int getPrice();
        bool isReadyToHarvest();
};

#endif