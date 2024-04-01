#include "Carnivore.hpp"
#include <iostream>

using namespace std;

Carnivore::Carnivore(string code, string name,int harvestWeight,int price): Animal(code,name,"CARNIVORE", harvestWeight, price){
}

void Carnivore::makan(Products* m){
    if (m->getType()=="PRODUCT_ANIMAL"){
        this->harvestWeight += m->getAddedWeight(); 
    }
    else{
        cout<<"\033[1;31mHewan hanya bisa makan daging.\033[0m"<<endl;
    }
}



Snake::Snake(int harvestWeight,int price): Carnivore("SNK","SNAKE",harvestWeight,price){}