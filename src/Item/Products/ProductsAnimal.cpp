
#include "ProductsAnimal.hpp"


ProductsAnimal::ProductsAnimal(int id, string code, string name, string type, string origin, double added_weight, double price)
    : Products(id, code, name, type, origin, added_weight, price) {}

ProductsAnimal::~ProductsAnimal(){

}

// Operator overloading for ==
// bool ProductsAnimal::operator==(const ProductsAnimal& other) const{

// }


