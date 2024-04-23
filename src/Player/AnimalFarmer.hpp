#ifndef __ANIMALFARMER_HPP__
#define __ANIMALFARMER_HPP__

#include <string>
#include <vector>
#include "Player.hpp"

class AnimalFarmer : public Player{
    private:
        Storage<Animal*> Barn;
    public:
        // CONSTRUCTOR
        AnimalFarmer();
        AnimalFarmer(string username, int wealth, int weight);
        
        // GETTER
        int getKTKP();
        void setBarn(Storage<Animal*>);
        int getPlayerAssets();
        vector<Animal*> getListOfAnimals() const;
        Storage<Animal*> getBarn();

        /// CLASS METHOD
        // Display player info
        void displayInfo() const override;

        // Place Animal in Barn Method
        void placeAnimal();

        // Place Animal for risk in Barn Method
        void placeAnimalRisk();

        // Feed Animal method
        void feedAnimal();

        // min Animal Weight
        void minAnimalWeight();

        // Harvesting Animal Method
        void harvestAnimal();

        // Deleting Animal Risk
        void delItemRisk();

        // Print Player Barn
        void printBarn();

        // Calculate Player Tax
        int calculateTax();
};

#endif