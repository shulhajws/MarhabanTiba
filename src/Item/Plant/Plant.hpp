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

    public:
        Plant(int plantID, string plantCode, string name, string type, int harvestDuration);
        ~Plant();

        void addAge();
        void setPlantAge(int plantAge);
        bool isReadyToHarvest();
};

#endif