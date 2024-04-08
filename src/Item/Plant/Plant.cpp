#include "Plant.hpp"
#include <iostream>
using namespace std;

Plant::Plant(int plantID, string plantCode, string name, string type, int harvestDuration, int price) : Item(plantID, plantCode, name, type){
    this->harvestDuration = harvestDuration;
    this->plantAge = 0;
    this->price = price;
}

Plant::~Plant(){}

int Plant::getPrice(){
    return price;
}

void Plant::addAge(){
    this->plantAge++;
}

void Plant::setPlantAge(int plantAge){
    this->plantAge = plantAge;    
}

bool Plant::isReadyToHarvest(){
    return this->plantAge >= this->harvestDuration;
}