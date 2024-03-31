#include "PlantFarmer.hpp"
#include "../Command/PetaniCommand/Tanam.hpp"

PlantFarmer::PlantFarmer() : Player(){
    this->commandList.push_back(new Tanam());
}

PlantFarmer::PlantFarmer(string username, int wealth, int weight) : Player(username, wealth, weight) {
    this->commandList.push_back(new Tanam());
}