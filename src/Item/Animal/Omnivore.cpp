#include "Omnivore.hpp"
#include <iostream>

using namespace std;

Omnivore::Omnivore(string kode, string nama,int berat_panen,int price): Animal(kode,nama,"Omnivore",berat_panen,price){
}

// ini harusnya produk
void Omnivore::makan(string m){
    if (m=="PRODUCT_ANIMAL" || m=="PRODUCT_FRUIT_PLANT"){
        this->berat_hewan += 10; // ini nanti diambil dari product
    }
    else{
        cout<<"Hewan hanya bisa makan daging dan buah."<<endl;
    }
}

Chicken::Chicken(int berat,int price) : Omnivore("CHK","Chicken",berat,price){
}

Duck::Duck(int berat, int price) : Omnivore("DCK","Chicken",berat,price){
}