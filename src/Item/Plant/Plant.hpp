#ifndef __PLANT_HPP__
#define __PLANT_HPP__

#include "../Item.hpp"
#include <string>
using namespace std;

class Plant : public Item{
    protected:    
        int plantID;
        int harvestDuration;
        int plantAge;
        int price;

    public:
        Plant(int plantID, string plantCode, string name, string type, int harvestDuration, int price);
        ~Plant();
        int getPrice();
        void addAge();
        void minAge();
        int getPlantAge();
        void setPlantAge(int plantAge);
        bool isReadyToHarvest();
};

#endif