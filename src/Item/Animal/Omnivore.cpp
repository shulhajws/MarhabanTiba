#include "Omnivore.hpp"
#include <iostream>

using namespace std;

Omnivore::Omnivore(string kode, string nama,int harvestWeight, int price): Animal(kode,nama,"Omnivore",harvestWeight,price){
}


void Omnivore::makan(Product* m){
    if (m->getType()=="PRODUCT_ANIMAL" || m->getType()=="PRODUCT_FRUIT_PLANT"){
        this->berat_hewan += m->getAddedWeight(); 
        cout<<"The " <<this->getName()<<" has been fed and its weight becomes "<<this->animalWeight<<endl;
    }
    else{
        cout<<"Hewan hanya bisa makan daging dan buah."<<endl;
    }
}

int Chicken::harvestWeight = 0;
int Duck::harvestWeight = 0;

int Chicken::price = 0;
int Duck::price = 0;


// CHICKEN CLASS
Chicken::Chicken() : Omnivore("CHK","CHICKEN",Chicken::price, Chicken::price){
}

Chicken::Chicken(int harvestWeight,int price) : Omnivore("CHK","CHICKEN",Chicken::price, Chicken::price){
    Chicken::harvestWeight = harvestWeight;
    Chicken::price = price;
}

Chicken::Chicken(int weight) : Omnivore("CHK","CHICKEN",Chicken::price, Chicken::price){
    this->setAnimalWeight(weight);
}


// DUCK CLASS
Duck::Duck() : Omnivore("DCK","DUCK",Duck::harvestWeight, Duck::price){
}

Duck::Duck(int harvestWeight, int price) : Omnivore("DCK","DUCK",Duck::harvestWeight, Duck::price){
    Duck::harvestWeight = harvestWeight;
    Duck::price = price;
}

Duck::Duck(int weight) : Omnivore("DCK","DUCK",Duck::harvestWeight, Duck::price){
    this->setAnimalWeight(weight);
}