#ifndef __PLANTFARMER_HPP__
#define __PLANTFARMER_HPP__

#include <string>
#include <vector>
#include "Player.hpp"
using namespace std;

class PlantFarmer : public Player{
    private:
        Storage<Plant*> Garden;
    public:
        PlantFarmer();
        PlantFarmer(string username, int wealth, int weight);
        int getKTKP();
        void addPlantYear();
        void setGarden(Storage<Plant*>);
        void displayInfo() const;
        void plantCrop();
        void harvestCrop();
        void printGarden();

};

#endif