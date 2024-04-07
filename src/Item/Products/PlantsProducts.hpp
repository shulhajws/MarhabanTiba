#ifndef PLANTSPRODUCTS_HPP
#define PLANTSPRODUCTS_HPP

#include <iostream>
#include "../Item.hpp"
#include "Products.hpp"
using namespace std;

class PlantsProducts : public Products {
public:
    PlantsProducts(int id, string code, string name, string type, string origin, double added_weight, double price);
    ~PlantsProducts();

    // Operator overloading for ==
    bool operator==(const PlantsProducts& other) const;
};

#endif // PLANTSPRODUCTS_HPP
