#include "Products.hpp"

Products::Products(int id, string code, string name, string type, string origin, double added_weight, double price)
    : Item(id, code, name, type), origin(origin), added_weight(added_weight), price(price) {}

Products::~Products() {}

bool Products::operator==(const Products& other) const {
    // Check if all attributes are equal
    return (id == other.id && code == other.code && name == other.name && type == other.type &&
            origin == other.origin && added_weight == other.added_weight && price == other.price);
}
