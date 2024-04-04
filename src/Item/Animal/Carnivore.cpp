#include "Carnivore.hpp"
#include <iostream>

using namespace std;

Carnivore::Carnivore(int harvestWeight,string code, string name): Animal(code,name,"CARNIVORE",harvestWeight){
}

Carnivore::Carnivore(string code, string name,int harvestWeight,int price): Animal(code,name,"CARNIVORE", harvestWeight, price){
}

Carnivore::Carnivore(int harvestWeight,string code, string name,int animalWeight): Animal(code,name,"CARNIVORE", animalWeight,harvestWeight,0){
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

Snake::Snake():Carnivore(harvestWeight,"SNK","SNK"){
}

Snake::Snake(int animalweight): Carnivore(harvestWeight,"SNK","SNAKE",animalweight){
}

Snake::Snake(int harvestWeight,int price): Carnivore("SNK","SNAKE",harvestWeight,price){
    Snake::harvestWeight = harvestWeight;
    Snake::price = price;
}