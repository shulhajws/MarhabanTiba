#ifndef __ANIMALFARMER_HPP__
#define __ANIMALFARMER_HPP__

#include <string>
#include <vector>
#include "Player.hpp"
using namespace std;

class AnimalFarmer : public Player{
    public:
        AnimalFarmer();
        AnimalFarmer(string username, int wealth, int weight);

        void displayInfo() const override;
        void placeAnimal();
        void feedAnimal();
        void harvestAnimal();
        void printBarn();
        int getKTKP();
};

#endif