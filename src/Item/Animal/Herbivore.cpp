#include "Herbivore.hpp"
#include <iostream>

using namespace std;

Herbivore::Herbivore(string code, string name, int harvestWeight, int price) : Animal(price, code,name,"HERBIVORE",harvestWeight){
}

Herbivore::Herbivore(int harvestWeight,string code, string name, int animalWeight) : Animal(code,name,"HERBIVORE",animalWeight,harvestWeight){
}

// ini harusnya produk
void Herbivore::makan(Product* m){
    if (m->getType()=="PRODUCT_FRUIT_PLANT"){
        this->animalWeight += m->getAddedWeight(); // ini nanti diambil dari product
        cout<<"The " <<this->getName()<<" has been fed and its weight becomes "<<this->animalWeight<<endl;
    }
    else{
        cout<<"\033[1;31mHewan hanya bisa makan buah.\033[0m"<<endl;
    }
}

int Cow::harvestWeight = 0;
int Sheep::harvestWeight = 0;
int Horse::harvestWeight = 0;
int Rabbit::harvestWeight = 0;

int Cow::price = 0;
int Sheep::price = 0;
int Horse::price = 0;
int Rabbit::price = 0;


// COW CLASS
Cow::Cow(): Herbivore("COW","COW",harvestWeight, price){
}

Cow::Cow(int berat, int price) : Herbivore("COW","COW",berat, price){
    Cow::harvestWeight = berat;
    Cow::price = price;
}

Cow::Cow(int AnimalWeight) : Herbivore(harvestWeight,"COW","COW",AnimalWeight){
}


// SHEEP CLASS
Sheep::Sheep() : Herbivore("SHP","SHEEP",harvestWeight, price){

}

Sheep::Sheep(int berat, int price) : Herbivore("SHP","SHEEP",berat, price){
    Sheep::harvestWeight = berat;
    Sheep::price = price;
}

Sheep::Sheep(int AnimalWeight) : Herbivore(harvestWeight,"SHP","SHP",AnimalWeight){
}


// HORSE CLASS
Horse::Horse() : Herbivore("HRS","HORSE",harvestWeight, price){
}

Horse::Horse(int AnimalWeight) : Herbivore(harvestWeight,"HRS","HRS",AnimalWeight){
}

Horse::Horse(int berat, int price) : Herbivore("HRS","HORSE",berat, price){
    Horse::harvestWeight = berat;
    Horse::price = price;
}


// RABBIT CLASS

Rabbit::Rabbit() : Herbivore("RBT","RABBIT",harvestWeight, price){
}

Rabbit::Rabbit(int harvestWeight, int price) : Herbivore("RBT","RABBIT",harvestWeight, price){
    Rabbit::harvestWeight = harvestWeight;
    Rabbit::price = price;
}

Rabbit::Rabbit(int AnimalWeight) : Herbivore(harvestWeight,"RBT","RABBIT",AnimalWeight){
}