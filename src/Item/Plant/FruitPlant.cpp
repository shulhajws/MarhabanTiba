#include "FruitPlant.hpp"
#include <iostream>
using namespace std;

FruitPlant::FruitPlant(int plantID, string code, string name, int harvestDuration) : Plant(plantID, code, name, "FRUIT_PLANT", harvestDuration){}

int AppleTree::harvestDuration = 0;
int AppleTree::price = 0;
AppleTree::AppleTree() : FruitPlant(5, "APL", "APPLE_TREE", AppleTree::harvestDuration){}
AppleTree::AppleTree(int harvestDuration, int price) : FruitPlant(5, "APL", "APPLE_TREE", harvestDuration){
    AppleTree::harvestDuration = harvestDuration;
    AppleTree::price = price;
}
AppleTree::AppleTree(int plantAge) : FruitPlant(5, "APL", "APPLE_TREE", AppleTree::harvestDuration){
    this->setPlantAge(plantAge);
}

int OrangeTree::harvestDuration = 0;
int OrangeTree::price = 0;
OrangeTree::OrangeTree() :  FruitPlant(6, "ORG", "ORANGE_TREE", OrangeTree::harvestDuration){}
OrangeTree::OrangeTree(int harvestDuration, int price) : FruitPlant(6, "ORG", "ORANGE_TREE", harvestDuration){
    OrangeTree::harvestDuration = harvestDuration;
    OrangeTree::price = price;
}
OrangeTree::OrangeTree(int plantAge) :  FruitPlant(6, "ORG", "ORANGE_TREE", OrangeTree::harvestDuration){
    this->setPlantAge(plantAge);
}

int BananaTree::harvestDuration = 0;
int BananaTree::price = 0;
BananaTree::BananaTree() : FruitPlant(7, "BNT", "BANANA_TREE", BananaTree::harvestDuration){}
BananaTree::BananaTree(int harvestDuration, int price) : FruitPlant(7, "BNT", "BANANA_TREE", harvestDuration){
    BananaTree::harvestDuration = harvestDuration;
    BananaTree::price = price;
}
BananaTree::BananaTree(int plantAge) : FruitPlant(7, "BNT", "BANANA_TREE", BananaTree::harvestDuration){
    this->setPlantAge(plantAge);
}

int GuavaTree::harvestDuration = 0;
int GuavaTree::price = 0;
GuavaTree::GuavaTree() : FruitPlant(8, "GAV", "GUAVA_TREE", GuavaTree::harvestDuration){}
GuavaTree::GuavaTree(int harvestDuration, int price) : FruitPlant(8, "GAV", "GUAVA_TREE", harvestDuration){
    GuavaTree::harvestDuration = harvestDuration;
    GuavaTree::price = price;
}
GuavaTree::GuavaTree(int plantAge) : FruitPlant(8, "GAV", "GUAVA_TREE", GuavaTree::harvestDuration){
    this->setPlantAge(plantAge);
}

