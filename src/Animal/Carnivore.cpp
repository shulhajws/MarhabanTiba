#include "Carnivore.hpp"
#include <iostream>

using namespace std;

Carnivore::Carnivore(string kode, string nama,int berat_panen,int price): Animal(kode,nama,"CARNIVORE", berat_panen, price){

}

// ini harusnya produk
void Carnivore::makan(string m){
    if (m=="PRODUCT_ANIMAL"){
        this->berat_hewan += 10; // ini nanti diambil dari product
    }
    else{
        cout<<"Hewan hanya bisa makan daging."<<endl;
    }
}


Snake::Snake(int berat,int price): Carnivore("SNK","Snake",berat,price){}