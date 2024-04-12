#ifndef __PRODUCT_HPP__
#define __PRODUCT_HPP__

#include <string>
#include <iostream>
#include "../Item.hpp"

using namespace std;

class Product : public Item {
    protected:
        int productID;
        int addedWeight;
        int priceProduct;

    public:
        Product(int productID, string code, string name, string type, string origin, int added_weight, int priceProduct);
        virtual ~Product();
        int getAddedWeight();
        int getPrice();
        // bool operator==(const Products& other) const;
};

#endif