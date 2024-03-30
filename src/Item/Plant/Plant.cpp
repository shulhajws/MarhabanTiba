#include "Plant.hpp"
#include <iostream>
using namespace std;

int Plant::plantID = 1;

Plant::Plant(string code, string name, string type, int harvestDuration, int price) : Item(Plant::plantID, code, name, type){
    this->harvestDuration = harvestDuration;
    this->price = price;
    this->plantAge = 0;
    Plant::plantID += 1;
};

Plant::~Plant(){}

void Plant::addAge(){
    this->plantAge++;
}

bool Plant::isReadyToHarvest(){
    return this->plantAge >= this->harvestDuration;
}