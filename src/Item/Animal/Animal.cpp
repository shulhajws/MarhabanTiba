#include "Animal.hpp"
#include <iostream>

using namespace std;

int Animal::animalID = 1;

Animal::Animal(string code, string name, string type, int weight, int price) : Item(Animal::animalID, code, name, type){
    this-> harvestWeight = weight;
    this -> price = price;
    this -> animalWeight = 0;
    Animal::animalID += 1;
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



