#include "Animal.hpp"
#include <iostream>

using namespace std;


Animal::Animal(int price, string code, string name, string type, int harvestWeight): Item(0,code, name,type,price){
    this->animalWeight = 0;
    this->harvestWeight = harvestWeight;
    this->price = price;
}


Animal::Animal(string code, string name, string type, int animalWeight, int harvestWeight): Item(code, name, type){
    this -> animalWeight = animalWeight;
    this->harvestWeight = harvestWeight;
}

Animal::~Animal(){}

void Animal::makan(Products* p){}

int Animal::getPrice(){
    return price;
}

bool Animal::isReadyToHarvest(){
    if(animalWeight>=harvestWeight){
        return true;
    }
    else{
        return false;
    }
}



