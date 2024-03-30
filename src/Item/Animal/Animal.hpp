#ifndef __Animal_HPP__
#define __Animal_HPP__

#include "../Item.hpp"
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
        virtual void makan()=0;
        bool isHarvestable();
};

#endif