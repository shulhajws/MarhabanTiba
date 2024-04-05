#include "Animal.hpp"
#include <iostream>

using namespace std;


Animal::Animal(string code,string name, string type, int harvestWeight): Item(animalID, code, name, type){
    this->animalWeight = 0;
    this->harvestWeight = harvestWeight;
}

Animal::Animal(string code, string name, string type, int harvestWeight, int price): Item(animalID, code, name, type){
    this -> animalWeight = 0;
    this-> animalID = id;
    this->harvestWeight = harvestWeight;
}

Animal::Animal(string code, string name, string type, int animalWeight, int harvestWeight,int id): Item(code, name, type){
    this -> animalWeight = animalWeight;
     this->harvestWeight = harvestWeight;
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

void Animal::setAnimalWeight(int berat){
    animalWeight = berat;
}


