#include "Item.hpp"
#include <iostream>
using namespace std;

Item::Item(int id, string code, string name, string type){
    this->id = id;
    this->code = code;
    this->name = name;
    this->type = type;
}

Item::Item( string code, string name, string type){
    this->id = 0;
    this->code = code;
    this->name = name;
    this->type = type;
}

Item::~Item(){};

// bool operator==(const Item& Item1, const Item& Item2){
//     // TO BE IMPLEMENTED
// }

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
