#ifndef MATERIALPRODUCTS_HPP
#define MATERIALPRODUCTS_HPP

#include "Products.hpp"

class MaterialProducts : public Products {
public:
    MaterialProducts(int id, string code, string name, string type, string origin, double added_weight, double price);
    ~MaterialProducts();

    // Operator overloading for ==
    bool operator==(const MaterialProducts& other) const;
};

#endif // MATERIALPRODUCTS_HPP
