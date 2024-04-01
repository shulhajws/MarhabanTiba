#include "Omnivore.hpp"
#include <iostream>

using namespace std;

Omnivore::Omnivore(string kode, string nama,int berat_panen,int price): Animal(kode,nama,"Omnivore",berat_panen,price){
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

Chicken::Chicken(int berat,int price) : Omnivore("CHK","Chicken",berat,price){
}

Duck::Duck(int berat, int price) : Omnivore("DCK","Chicken",berat,price){
}