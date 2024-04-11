#include "ProductFruitPlant.hpp"

ProductFruitPlant :: ProductFruitPlant(int productFruitID, string code, string name, string origin, int addedWeight, int price) : Product(productFruitID, code, name, "PRODUCT_FRUIT_Fruit", origin, addedWeight, price){}   

int Apple::addedWeight = 0;
int Apple::price = 0;
Apple::Apple() : ProductFruitPlant(5, "APP", "APPLE", "APPLE_TREE", Apple::addedWeight, Apple::price){}
Apple::Apple(int addedWeight, int price) : ProductFruitPlant(5, "APP", "APPLE", "APPLE_TREE", addedWeight, price){
    Apple::addedWeight = addedWeight;
    Apple::price = price;
}

int Orange::addedWeight = 0;
int Orange::price = 0;
Orange::Orange() : ProductFruitPlant(6, "ORP", "ORANGE", "ORANGE_TREE", Orange::addedWeight, Orange::price){}
Orange::Orange(int addedWeight, int price) : ProductFruitPlant(6, "ORP", "ORANGE", "ORANGE_TREE", addedWeight, price){
    Orange::addedWeight = addedWeight;
    Orange::price = price;
}

int Banana::addedWeight = 0;
int Banana::price = 0;
Banana::Banana() : ProductFruitPlant(7, "BNP", "BANANA", "BANANA_TREE", Banana::addedWeight, Banana::price){}
Banana::Banana(int addedWeight, int price) : ProductFruitPlant(7, "BNP", "BANANA", "BANANA_TREE", addedWeight, price){
    Banana::addedWeight = addedWeight;
    Banana::price = price;
}

int Guava::addedWeight = 0;
int Guava::price = 0;
Guava::Guava() : ProductFruitPlant(8, "GAP", "GUAVA", "GUAVA_TREE", Guava::addedWeight, Guava::price){}
Guava::Guava(int addedWeight, int price) : ProductFruitPlant(8, "GAP", "GUAVA", "GUAVA_TREE", addedWeight, price){
    Guava::addedWeight = addedWeight;
    Guava::price = price;
}

