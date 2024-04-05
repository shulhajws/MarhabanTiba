#include "Carnivore.hpp"
#include <iostream>

using namespace std;

Carnivore::Carnivore(string code, string name,int harvestWeight): Animal(code,name,"CARNIVORE", harvestWeight){
}

Carnivore::Carnivore(int harvestWeight,string code, string name,int animalWeight): Animal(code,name,"CARNIVORE", animalWeight,harvestWeight){
}

void Carnivore::makan(Products* m){
    if (m->getType()=="PRODUCT_ANIMAL"){
        this->animalWeight += m->getAddedWeight(); 
    }
    else{
        cout<<"\033[1;31mHewan hanya bisa makan daging.\033[0m"<<endl;
    }
}

int Snake::harvestWeight = 0;
int Snake::price = 0;

Snake::Snake():Carnivore("SNK","SNK",harvestWeight){
}

Snake::Snake(int animalweight): Carnivore(harvestWeight,"SNK","SNAKE",animalweight){
}

Snake::Snake(int harvestWeight,int price): Carnivore("SNK","SNAKE",harvestWeight){
    Snake::harvestWeight = harvestWeight;
    Snake::price = price;
}