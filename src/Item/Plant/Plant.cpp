#include "Plant.hpp"
#include <iostream>
using namespace std;

Plant::Plant(int plantID, string plantCode, string name, string type, int harvestDuration) : Item(plantID, plantCode, name, type){
    this->harvestDuration = harvestDuration;
    this->plantAge = 0;
}

Plant::~Plant(){}

void Plant::addAge(){
    this->plantAge++;
}

void Plant::setPlantAge(int plantAge){
    this->plantAge = plantAge;    
}

bool Plant::isReadyToHarvest(){
    return this->plantAge >= this->harvestDuration;
}