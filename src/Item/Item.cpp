#include "Item.hpp"
#include <iostream>
using namespace std;

Item::Item(int id, string code, string name, string type, int price){
    this->id = id;
    this->code = code;
    this->name = name;
    this->type = type;
    this->price = price;
}

Item::Item( string code, string name, string type){
    this->id = 0;
    this->code = code;
    this->name = name;
    this->type = type;
}

Item::~Item(){};

bool Item::operator==(Item& Item2) const{
    if(this->code == Item2.getCode() && this->name == Item2.getName() && this->type==Item2.getType()){
        return true;
    }
    return false;
}

string Item::getCode() const {
    return code;
}

// Implementation of getName() method
string Item::getName() const {
    return name;
}
// Implementation of getType() method
string Item::getType() const {
    return type;
}

int Item::getPrice() const {
    return price;
}
