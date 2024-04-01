#include "Herbivore.hpp"
#include <iostream>

using namespace std;


Herbivore::Herbivore(string code, string name, int harvestWeight, int price) : Animal(code,name,"HERBIVORE",harvestWeight,price){
}

// ini harusnya produk
void Herbivore::makan(Products* m){
    if (m->getType()=="PRODUCT_FRUIT_PLANT"){
        this->animalWeight += m->getAddedWeight(); // ini nanti diambil dari product
    }
    else{
        cout<<"\033[1;31mHewan hanya bisa makan buah.\033[0m"<<endl;
    }
}


Cow::Cow(int berat, int price) : Herbivore("COW","COW",berat,price){
}

Sheep::Sheep(int berat, int price) : Herbivore("SHP","SHEEP",berat,price){
}


Horse::Horse(int berat, int price) : Herbivore("HRS","HORSE",berat,price){
}


Rabbit::Rabbit(int berat, int price) : Herbivore("RBT","RABBIT",berat,price){
}