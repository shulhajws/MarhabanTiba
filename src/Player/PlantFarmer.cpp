#include "PlantFarmer.hpp"
#include "../Command/PetaniCommand/Tanam.hpp"

#include <iostream>
using namespace std;

PlantFarmer::PlantFarmer() : Player(){
    this->commandList.push_back(new Tanam());
}

PlantFarmer::PlantFarmer(string username, int wealth, int weight) : Player(username, wealth, weight, "Petani") {
    this->commandList.push_back(new Tanam());
}

int PlantFarmer::getKTKP(){
    return 13;
}

void PlantFarmer::displayInfo() const {
    cout << "Plant Farmer - ";
    Player::displayInfo();
}

void PlantFarmer::plantCrop() {
    cout << this->getName() <<" is planting crops." << endl;
}

void PlantFarmer::harvestCrop() {
    cout << this->getName() <<" is harvesting crops." << endl;
}

void PlantFarmer::printGarden() {
    cout << this->getName() <<"'s garden is being printed." << endl;
}