#ifndef __ANIMALFARMER_HPP__
#define __ANIMALFARMER_HPP__

#include <string>
#include <vector>
#include "Player.hpp"

class AnimalFarmer : public Player{
    private:
        Storage<Animal*> Barn;
    public:
        AnimalFarmer();
        AnimalFarmer(string username, int wealth, int weight);
        
        int getKTKP() override;
        void setBarn(Storage<Animal*>);

        void displayInfo() const override;
        void placeAnimal();
        void feedAnimal();
        void harvestAnimal();
        void printBarn();
        vector<Animal*> getListOfAnimals() const;
};

#endif