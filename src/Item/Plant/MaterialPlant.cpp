#include "MaterialPlant.hpp"
#include <iostream>
using namespace std;

MaterialPlant::MaterialPlant(int plantID, string code, string name, int harvestDuration) : Plant(plantID, code, name, "MATERIAL_PLANT", harvestDuration){}

int TeakTree::harvestDuration = 0;
int TeakTree::price = 0;
TeakTree::TeakTree() : MaterialPlant(1, "TEK", "TEAK_TREE", TeakTree::harvestDuration){}
TeakTree::TeakTree(int harvestDuration, int price) : MaterialPlant(1, "TEK", "TEAK_TREE", harvestDuration){
    TeakTree::harvestDuration = harvestDuration;
    TeakTree::price = price;
}
TeakTree::TeakTree(int plantAge) : MaterialPlant(1, "TEK", "TEAK_TREE", TeakTree::harvestDuration){
    this->setPlantAge(plantAge);
}

int SandalwoodTree::harvestDuration = 0;
int SandalwoodTree::price = 0;
SandalwoodTree::SandalwoodTree() : MaterialPlant(2, "SDT", "SANDALWOOD_TREE", SandalwoodTree::harvestDuration){}
SandalwoodTree::SandalwoodTree(int harvestDuration, int price) : MaterialPlant(2, "SDT", "SANDALWOOD_TREE", harvestDuration){
    SandalwoodTree::harvestDuration = harvestDuration;
    SandalwoodTree::price = price;
}
SandalwoodTree::SandalwoodTree(int plantAge) : MaterialPlant(2, "SDT", "SANDALWOOD_TREE", SandalwoodTree::harvestDuration){
    this->setPlantAge(plantAge);
}


int AloeTree::harvestDuration = 0;
int AloeTree::price = 0;
AloeTree::AloeTree() : MaterialPlant(3, "ALT", "ALOE_TREE", AloeTree::harvestDuration){}
AloeTree::AloeTree(int harvestDuration, int price) : MaterialPlant(3, "ALT", "ALOE_TREE", harvestDuration){
    AloeTree::harvestDuration = harvestDuration;
    AloeTree::price = price;
}
AloeTree::AloeTree(int plantAge) : MaterialPlant(3, "ALT", "ALOE_TREE", AloeTree::harvestDuration){
    this->setPlantAge(plantAge);
}


int IronwoodTree::harvestDuration = 0;
int IronwoodTree::price = 0;
IronwoodTree::IronwoodTree() : MaterialPlant(4, "IRN", "IRONWOOD_TREE", IronwoodTree::harvestDuration){}
IronwoodTree::IronwoodTree(int harvestDuration, int price) : MaterialPlant(4, "IRN", "IRONWOOD_TREE", harvestDuration){
    IronwoodTree::harvestDuration = harvestDuration;
    IronwoodTree::price = price;
}
IronwoodTree::IronwoodTree(int plantAge) : MaterialPlant(4, "IRN", "IRONWOOD_TREE", IronwoodTree::harvestDuration){
    this->setPlantAge(plantAge);
}
