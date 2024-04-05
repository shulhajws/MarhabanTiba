#include "Omnivore.hpp"
#include <iostream>

using namespace std;

Omnivore::Omnivore(string kode, string nama,int harvestWeight): Animal(kode,nama,"Omnivore",harvestWeight){
}

Omnivore::Omnivore(int harvestWeight,string kode, string nama,int animalweight): Animal(kode,nama,"Omnivore",animalweight,harvestWeight){
}

// ini harusnya produk
void Omnivore::makan(Products* m){
    if (m->getType()=="PRODUCT_ANIMAL" || m->getType()=="PRODUCT_FRUIT_PLANT"){
        this->berat_hewan += m->getAddedWeight(); 
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
Chicken::Chicken() : Omnivore("CHK","CHK",harvestWeight){
}

Chicken::Chicken(int harvestWeight,int price) : Omnivore("CHK","Chicken",harvestWeight){
    Chicken::harvestWeight = harvestWeight;
    Chicken::price = price;
}

Chicken::Chicken(int animalweight) : Omnivore(harvestWeight,"CHK","Chicken",animalweight){
}


// DUCK CLASS
Duck::Duck() : Omnivore("DCK","DCK",harvestWeight){
}

Duck::Duck(int harvestWeight, int price) : Omnivore("DCK","Chicken",harvestWeight){
    Duck::harvestWeight = harvestWeight;
    Duck::price = price;
}

Duck::Duck(int animalweight) : Omnivore(harvestWeight,"DCK","Chicken",animalweight){
}