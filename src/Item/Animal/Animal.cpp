#include "Animal.hpp"
#include <iostream>

using namespace std;


Animal::Animal(int price, string code,string name, string type, int harvestWeight): Item(animalID, code, name, type){
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

bool Animal::isHarvestable(){
    if(animalWeight>=harvestWeight){
        cout<<"Hewan siap dipanen"<<endl;
        return true;
    }
    else{
        cout<<"\033[1;31mHewan belum siap dipanen\033[0m"<<endl;
        return false;
    }
}



