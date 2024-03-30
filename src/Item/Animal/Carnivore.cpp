#include "Carnivore.hpp"
#include <iostream>

using namespace std;

Carnivore::Carnivore(string code, string name,int harvestWeight,int price): Animal(code,name,"CARNIVORE", harvestWeight, price){
}

// ini harusnya produk
void Carnivore::makan(string m){
    if (m=="PRODUCT_ANIMAL"){
        this->harvestWeight += 10; // ini nanti diambil dari product
    }
    else{
        cout<<"Hewan hanya bisa makan daging."<<endl;
    }
}


Snake::Snake(int berat,int price): Carnivore("SNK","Snake",berat,price){}