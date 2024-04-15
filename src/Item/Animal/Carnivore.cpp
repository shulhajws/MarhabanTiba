#include "Carnivore.hpp"
#include <iostream>

using namespace std;

Carnivore::Carnivore(string code, string name,int harvestWeight,int price): Animal(code,name,"CARNIVORE", harvestWeight,price){
}


void Carnivore::makan(Product* m){
    if (m->getType()=="PRODUCT_ANIMAL"){
        this->animalWeight += m->getAddedWeight(); 
        cout<<"The " <<this->getName()<<" has been fed and its weight becomes "<<this->animalWeight<<endl;
    }
    else{
        throw NotFoodException();
    }
}

int Snake::harvestWeight = 0;
int Snake::price = 0;

Snake::Snake():Carnivore("SNK","SNAKE",Snake::harvestWeight,Snake::price){
}

Snake::Snake(int weight): Carnivore("SNK","SNAKE",Snake::harvestWeight,Snake::price){
    this->setAnimalWeight(weight);
}

Snake::Snake(int harvestWeight,int price): Carnivore("SNK","SNAKE",Snake::harvestWeight,Snake::price){
    Snake::harvestWeight = harvestWeight;
    Snake::price = price;
}