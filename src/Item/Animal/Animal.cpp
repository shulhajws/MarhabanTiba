#include "Animal.hpp"
#include <iostream>

using namespace std;


Animal::Animal(string code, string name, string type, int harvestWeight, int price): Item(0,code, name,type,price){
    this->harvestWeight = harvestWeight;
    this->price = price;
}


Animal::~Animal(){}

void Animal::makan(Product* p){}

int Animal::getPrice(){
    return price;
}

void Animal::setAnimalWeight(int weight){
    this->animalWeight = weight; 
}

bool Animal::isReadyToHarvest(){
    if(animalWeight>=harvestWeight){
        return true;
    }
    else{
        return false;
    }
}



