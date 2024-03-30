#include "Item.hpp"
#include <iostream>
using namespace std;

Item::Item(int id, string code, string name, string type){
    this->id = id;
    this->code = code;
    this->name = name;
    this->type = type;
}

Item::~Item(){};

bool operator==(const Item& Item1, const Item& Item2){
    // TO BE IMPLEMENTED
}