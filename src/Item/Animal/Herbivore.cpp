#include "Herbivore.hpp"
#include <iostream>

using namespace std;

Herbivore::Herbivore(string code, string name, int harvestWeight, int price) : Animal(code,name,"HERBIVORE",harvestWeight,price){
}

// ini harusnya produk
void Herbivore::makan(Product* m){
    if (m->getType()=="PRODUCT_FRUIT_PLANT"){
        this->animalWeight += m->getAddedWeight(); // ini nanti diambil dari product
        cout<<"The " <<this->getName()<<" has been fed and its weight becomes "<<this->animalWeight<<endl;
    }
    else{
        throw NotFoodException();
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
Cow::Cow(): Herbivore("COW","COW",Cow::harvestWeight, Cow::price){
}

Cow::Cow(int berat, int price) : Herbivore("COW","COW",Cow::harvestWeight, Cow::price){
    Cow::harvestWeight = berat;
    Cow::price = price;
}

Cow::Cow(int weight) : Herbivore("COW","COW",Cow::harvestWeight, Cow::price){
    this->setAnimalWeight(weight);
}


// SHEEP CLASS
Sheep::Sheep() : Herbivore("SHP","SHEEP",Sheep::harvestWeight, Sheep::price){

}

Sheep::Sheep(int berat, int price) : Herbivore("SHP","SHEEP",Sheep::harvestWeight, Sheep::price){
    Sheep::harvestWeight = berat;
    Sheep::price = price;
}

Sheep::Sheep(int weight) : Herbivore("SHP","SHEEP",Sheep::harvestWeight, Sheep::price){
    this->setAnimalWeight(weight);
}


// HORSE CLASS
Horse::Horse() : Herbivore("HRS","HORSE",Horse::harvestWeight, Horse::price){
}

Horse::Horse(int weight) : Herbivore("HRS","HORSE",Horse::harvestWeight, Horse::price){
    this->setAnimalWeight(weight);
}

Horse::Horse(int berat, int price) : Herbivore("HRS","HORSE",Horse::harvestWeight, Horse::price){
    Horse::harvestWeight = berat;
    Horse::price = price;
}


// RABBIT CLASS

Rabbit::Rabbit() : Herbivore("RBT","RABBIT",Rabbit::harvestWeight, Rabbit::price){
}

Rabbit::Rabbit(int harvestWeight, int price) : Herbivore("RBT","RABBIT",Rabbit::harvestWeight, Rabbit::price){
    Rabbit::harvestWeight = harvestWeight;
    Rabbit::price = price;
}

Rabbit::Rabbit(int weight) :Herbivore("RBT","RABBIT",Rabbit::harvestWeight, Rabbit::price){
    this->setAnimalWeight(weight);
}