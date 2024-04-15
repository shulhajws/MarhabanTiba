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
        // CONSTRUCTOR 
        PlantFarmer();
        PlantFarmer(string username, int wealth, int weight);

        // GETTER AND SETTER
        int getPlayerAssets();
        int getKTKP();
        vector<Plant*> getListOfPlants() const;
        void setGarden(Storage<Plant*>);

        // CLASS METHOD
        // add  all plant year in Garden
        void addPlantYear();

        // display player info
        void displayInfo() const;

        // "TANAM" method
        void plantCrop();

        // "PANEN" method
        void harvestCrop();

        // print player garden
        void printGarden();

        // calculate player tax
        int calculateTax();

};

#endif