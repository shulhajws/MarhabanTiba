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
        cout<<"\033[1;31mHewan hanya bisa makan daging.\033[0m"<<endl;
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