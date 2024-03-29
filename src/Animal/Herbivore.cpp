#include "Herbivore.hpp"
#include <iostream>

using namespace std;


Herbivore::Herbivore(string kode, string nama,int berat_panen, int price) : Animal(kode,nama,"HERBIVORE",berat_panen,price){
}

// ini harusnya produk
void Herbivore::makan(string m){
    if (m=="PRODUCT_FRUIT_PLANT"){
        this->berat_hewan += 10; // ini nanti diambil dari product
    }
    else{
        cout<<"Hewan hanya bisa makan buah."<<endl;
    }
}


Cow::Cow(int berat, int price) : Herbivore("COW","Cow",berat,price){
}

Sheep::Sheep(int berat, int price) : Herbivore("SHP","Sheep",berat,price){
}


Horse::Horse(int berat, int price) : Herbivore("HRS","Horse",berat,price){
}


Rabbit::Rabbit(int berat, int price) : Herbivore("RBT","Rabbit",berat,price){
}