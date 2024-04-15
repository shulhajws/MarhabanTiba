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
        int getKTKP() override;
        void setBarn(Storage<Animal*>);
        int getPlayerAssets();
        vector<Animal*> getListOfAnimals() const;

        /// CLASS METHOD
        // Display player info
        void displayInfo() const override;

        // Place Animal in Barn Method
        void placeAnimal();

        // Feed Animal method
        void feedAnimal();

        // Harvesting Animal Method
        void harvestAnimal();

        // Print Player Barn
        void printBarn();

        // Calculate Player Tax
        int calculateTax();
};

#endif