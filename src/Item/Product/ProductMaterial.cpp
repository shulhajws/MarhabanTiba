#include "ProductMaterial.hpp"
#include <iostream>
using namespace std;

ProductMaterial :: ProductMaterial(int materialproductID, string code, string name, string origin, int addedWeight, int price) : Product(materialproductID, code, name, "PRODUCT_MATERIAL_PLANT", origin, addedWeight, price){}

int TeakWood::addedWeight = 0;
int TeakWood::price = 0;
TeakWood::TeakWood() : ProductMaterial(1, "TAW", "TEAK_WOOD", "TEAK_TREE", TeakWood::addedWeight, TeakWood::price){}
TeakWood :: TeakWood(int addedWeight, int price) : ProductMaterial(1, "TAW", "TEAK_WOOD", "TEAK_TREE", addedWeight, price){
    TeakWood::addedWeight = addedWeight;
    TeakWood::price = price;
}

int SandalwoodWood::addedWeight = 0;
int SandalwoodWood::price = 0;
SandalwoodWood::SandalwoodWood() : ProductMaterial(2, "SDT", "SANDALWOOD_WOOD", "SANDALWOOD_TREE", SandalwoodWood::addedWeight, SandalwoodWood::price){}
SandalwoodWood::SandalwoodWood(int addedWeight, int price) : ProductMaterial(2, "SDT", "SANDALWOOD_WOOD", "SANDALWOOD_TREE", addedWeight, price){
    SandalwoodWood::addedWeight = addedWeight;
    SandalwoodWood::price = price;
}

int AloeWood::addedWeight = 0;
int AloeWood::price = 0;
AloeWood::AloeWood() : ProductMaterial(3, "ALW", "ALOE_WOOD", "ALOE_TREE", AloeWood::addedWeight, AloeWood::price){}
AloeWood::AloeWood(int addedWeight, int price) : ProductMaterial(3, "ALW", "ALOE_WOOD", "ALOE_TREE", addedWeight, price){
    AloeWood::addedWeight = addedWeight;
    AloeWood::price = price;
}

int IronwoodWood::addedWeight = 0;
int IronwoodWood::price = 0;
IronwoodWood::IronwoodWood() : ProductMaterial(4, "IRW", "IRONWOOD_WOOD", "IRONWOOD_TREE", IronwoodWood::addedWeight, IronwoodWood::price){}
IronwoodWood::IronwoodWood(int addedWeight, int price) : ProductMaterial(4, "IRW", "IRONWOOD_WOOD", "IRONWOOD_TREE", addedWeight, price){
    IronwoodWood::addedWeight = addedWeight;
    IronwoodWood::price = price;
}

