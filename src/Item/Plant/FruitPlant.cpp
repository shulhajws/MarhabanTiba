#include "FruitPlant.hpp"
#include <iostream>
using namespace std;

FruitPlant::FruitPlant(string code, string name, int harvestDuration, int price) : Plant(code, name, "MATERIAL_PLANT", harvestDuration, price){}

bool FruitPlant::isEatable(){
    return true;
}

Apple::Apple(int harvestDuration, int price) : FruitPlant("APL", "APPLE_TREE", harvestDuration, price){}

Orange::Orange(int harvestDuration, int price) : FruitPlant("ORG", "ORANGE_TREE", harvestDuration, price){}

Banana::Banana(int harvestDuration, int price) : FruitPlant("BNT", "BANANA_TREE", harvestDuration, price){}

Guava::Guava(int harvestDuration, int price) : FruitPlant("GAV", "GUAVA_TREE", harvestDuration, price){}
