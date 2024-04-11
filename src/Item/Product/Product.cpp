#include "Product.hpp"

Product::Product(int productID, string code, string name, string type, string origin, int addedWeight, int priceProduct) : Item(code, name, type){
    this->productID = productID;
    this->addedWeight = addedWeight;
    this->priceProduct = priceProduct;
}  

Product :: ~Product(){}

int Product :: getPrice (){
    return priceProduct;
}

int Product :: getAddedWeight(){
    return addedWeight;
}


