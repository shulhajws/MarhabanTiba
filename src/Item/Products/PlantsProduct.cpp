#include "PlantsProducts.hpp"

PlantsProducts::PlantsProducts(int id, string code, string name, string type, string origin, double added_weight, double price)
    : Products(id, code, name, type, origin, added_weight, price) {}

PlantsProducts::~PlantsProducts() {}

bool PlantsProducts::operator==(const PlantsProducts& other) const {
    // Check if all attributes are equal
    return Products::operator==(other);
}
