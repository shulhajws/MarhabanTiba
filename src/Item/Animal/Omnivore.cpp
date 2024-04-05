#include "Omnivore.hpp"
#include <iostream>

using namespace std;

Omnivore::Omnivore(int harvestWeight,string kode, string nama): Animal(kode,nama,"Omnivore",harvestWeight){
}

Omnivore::Omnivore(string kode, string nama,int harvestWeight,int price): Animal(kode,nama,"Omnivore",harvestWeight,price){
}

Omnivore::Omnivore(int harvestWeight,string kode, string nama,int animalweight): Animal(kode,nama,"Omnivore",animalweight,harvestWeight,0){
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
Chicken::Chicken() : Omnivore(harvestWeight,"CHK","CHK"){
}

Chicken::Chicken(int harvestWeight,int price) : Omnivore("CHK","Chicken",harvestWeight,price){
    Chicken::harvestWeight = harvestWeight;
    Chicken::price = price;
}

Chicken::Chicken(int animalweight) : Omnivore(harvestWeight,"CHK","Chicken",animalweight){
}


// DUCK CLASS
Duck::Duck() : Omnivore(harvestWeight,"DCK","DCK"){
}

Duck::Duck(int harvestWeight, int price) : Omnivore("DCK","Chicken",harvestWeight,price){
    Duck::harvestWeight = harvestWeight;
    Duck::price = price;
}

Duck::Duck(int animalweight) : Omnivore(harvestWeight,"DCK","Chicken",animalweight){
}