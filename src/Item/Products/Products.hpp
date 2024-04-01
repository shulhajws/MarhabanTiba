#ifndef PRODUCTS_HPP
#define PRODUCTS_HPP

#include <string>
#include <iostream>
#include "../Item.hpp"

using namespace std;

class Products : public Item {
protected:
    string origin;
    double added_weight;
    double price;

public:
    Products(int id, string code, string name, string type, string origin, double added_weight, double price);
    virtual ~Products();
    double getAddedWeight();
    // Operator overloading for ==
    bool operator==(const Products& other) const;
};

#endif