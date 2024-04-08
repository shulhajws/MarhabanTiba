#ifndef PRODUCTS_ANIMAL_HPP
#define PRODUCTS_ANIMAL_HPP

#include "Products.hpp"

class ProductsAnimal : public Products {
private:
    string animalType;

public:
    ProductsAnimal(int id, string code, string name, string type, string origin, double added_weight, double price);
    ~ProductsAnimal();

    // Operator overloading for ==
    bool operator==(const ProductsAnimal& other) const;
};

#endif // PRODUCTS_ANIMAL_HPP
