#include "Products.hpp"

Products::Products(int id, string code, string name, string type): Item(code, name, type) {};

Products::Products(int id, string code, string name, string type, string origin, double added_weight, double price): Item(id, code, name, type,price), origin(origin), added_weight(added_weight), price(price) {}

Products::~Products() {}

double Products::getAddedWeight(){
    return added_weight;
}

bool Products::operator==(const Products& other) const {
    // Check if all attributes are equal
    return (id == other.id && code == other.code && name == other.name && type == other.type &&
            origin == other.origin && added_weight == other.added_weight && price == other.price);
}
