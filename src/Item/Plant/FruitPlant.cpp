#include "FruitPlant.hpp"
#include <iostream>
using namespace std;

FruitPlant::FruitPlant(int plantID, string code, string name, int harvestDuration) : Plant(plantID, code, name, "FRUIT_PLANT", harvestDuration){}

int Apple::harvestDuration = 0;
int Apple::price = 0;
Apple::Apple() : FruitPlant(5, "APL", "APPLE_TREE", Apple::harvestDuration){}
Apple::Apple(int harvestDuration, int price) : FruitPlant(5, "APL", "APPLE_TREE", harvestDuration){
    Apple::harvestDuration = harvestDuration;
    Apple::price = price;
}
Apple::Apple(int plantAge) : FruitPlant(5, "APL", "APPLE_TREE", Apple::harvestDuration){
    this->setPlantAge(plantAge);
}

int Orange::harvestDuration = 0;
int Orange::price = 0;
Orange::Orange() :  FruitPlant(6, "ORG", "ORANGE_TREE", Orange::harvestDuration){}
Orange::Orange(int harvestDuration, int price) : FruitPlant(6, "ORG", "ORANGE_TREE", harvestDuration){
    Orange::harvestDuration = harvestDuration;
    Orange::price = price;
}
Orange::Orange(int plantAge) :  FruitPlant(6, "ORG", "ORANGE_TREE", Orange::harvestDuration){
    this->setPlantAge(plantAge);
}

int Banana::harvestDuration = 0;
int Banana::price = 0;
Banana::Banana() : FruitPlant(7, "BNT", "BANANA_TREE", Banana::harvestDuration){}
Banana::Banana(int harvestDuration, int price) : FruitPlant(7, "BNT", "BANANA_TREE", harvestDuration){
    Banana::harvestDuration = harvestDuration;
    Banana::price = price;
}
Banana::Banana(int plantAge) : FruitPlant(7, "BNT", "BANANA_TREE", Banana::harvestDuration){
    this->setPlantAge(plantAge);
}

int Guava::harvestDuration = 0;
int Guava::price = 0;
Guava::Guava() : FruitPlant(8, "GAV", "GUAVA_TREE", Guava::harvestDuration){}
Guava::Guava(int harvestDuration, int price) : FruitPlant(8, "GAV", "GUAVA_TREE", harvestDuration){
    Guava::harvestDuration = harvestDuration;
    Guava::price = price;
}
Guava::Guava(int plantAge) : FruitPlant(8, "GAV", "GUAVA_TREE", Guava::harvestDuration){
    this->setPlantAge(plantAge);
}

