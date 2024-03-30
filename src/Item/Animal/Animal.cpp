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

// ini pake exception apa gak
bool Animal::isHarvestable(){
    if(animalWeight>=harvestWeight){
        cout<<"Hewan siap dipanen"<<endl;
        return true;
    }
    else{
        cout<<"Hewan belum siap dipanen"<<endl;
        return false;
    }
}



