#ifndef __PRODUCT_HPP__
#define __PRODUCT_HPP__

#include <string>
#include <iostream>
#include <vector>
#include "../Item.hpp"

using namespace std;

class Product : public Item {
    private:
        int productID;
        int addedWeight;
        int priceProduct;
        string origin;
        vector<Product*> product;

    public:
        Product();
        Product(int productID, string code, string name, string type, string origin, int added_weight, int priceProduct);
        virtual ~Product();
        int getAddedWeight();
        int getPrice();
        vector<Product*> getProduct(string prod);
        // bool operator==(const Products& other) const;
};

#endif