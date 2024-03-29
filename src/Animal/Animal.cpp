#include "Animal.hpp"
#include <iostream>

using namespace std;

int Animal::id = 1;


Animal::Animal(string kode,string nama, string tipe, int berat, int harga){
    this->id = Animal::id;
    this->code = kode;
    this->name = nama;
    this->type = tipe;
    this-> harvest_weight = berat;
    this -> price = harga;
    this -> berat_hewan = 0;
    Animal::id += 1;
}

// ini pake exception apa gak
bool Animal::isHarvestable(){
    if(berat_hewan>=harvest_weight){
        cout<<"Hewan siap dipanen"<<endl;
        return true;
    }
    else{
        cout<<"Hewan belum siap dipanen"<<endl;
        return false;
    }
}



