#include "MaterialProducts.hpp"

MaterialProducts::MaterialProducts(int id, string code, string name, string type, string origin, double added_weight, double price)
    : Products(id, code, name, type, origin, added_weight, price) {}

MaterialProducts::~MaterialProducts() {}

bool MaterialProducts::operator==(const MaterialProducts& other) const {
    // Check if all attributes are equal
    return Products::operator==(other);
}
