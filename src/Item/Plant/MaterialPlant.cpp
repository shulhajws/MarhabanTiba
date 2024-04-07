#include "MaterialPlant.hpp"
#include <iostream>
using namespace std;

MaterialPlant::MaterialPlant(int plantID, string code, string name, int harvestDuration) : Plant(plantID, code, name, "MATERIAL_PLANT", harvestDuration){}

int Teak::harvestDuration = 0;
int Teak::price = 0;
Teak::Teak() : MaterialPlant(1, "TEK", "TEAK_TREE", Teak::harvestDuration){}
Teak::Teak(int harvestDuration, int price) : MaterialPlant(1, "TEK", "TEAK_TREE", harvestDuration){
    Teak::harvestDuration = harvestDuration;
    Teak::price = price;
}
Teak::Teak(int plantAge) : MaterialPlant(1, "TEK", "TEAK_TREE", Teak::harvestDuration){
    this->setPlantAge(plantAge);
}

int Sandalwood::harvestDuration = 0;
int Sandalwood::price = 0;
Sandalwood::Sandalwood() : MaterialPlant(2, "SDT", "SANDALWOOD_TREE", Sandalwood::harvestDuration){}
Sandalwood::Sandalwood(int harvestDuration, int price) : MaterialPlant(2, "SDT", "SANDALWOOD_TREE", harvestDuration){
    Sandalwood::harvestDuration = harvestDuration;
    Sandalwood::price = price;
}
Sandalwood::Sandalwood(int plantAge) : MaterialPlant(2, "SDT", "SANDALWOOD_TREE", Sandalwood::harvestDuration){
    this->setPlantAge(plantAge);
}


int Aloe::harvestDuration = 0;
int Aloe::price = 0;
Aloe::Aloe() : MaterialPlant(3, "ALT", "ALOE_TREE", Aloe::harvestDuration){}
Aloe::Aloe(int harvestDuration, int price) : MaterialPlant(3, "ALT", "ALOE_TREE", harvestDuration){
    Aloe::harvestDuration = harvestDuration;
    Aloe::price = price;
}
Aloe::Aloe(int plantAge) : MaterialPlant(3, "ALT", "ALOE_TREE", Aloe::harvestDuration){
    this->setPlantAge(plantAge);
}


int Ironwood::harvestDuration = 0;
int Ironwood::price = 0;
Ironwood::Ironwood() : MaterialPlant(4, "IRN", "IRONWOOD_TREE", Ironwood::harvestDuration){}
Ironwood::Ironwood(int harvestDuration, int price) : MaterialPlant(4, "IRN", "IRONWOOD_TREE", harvestDuration){
    Ironwood::harvestDuration = harvestDuration;
    Ironwood::price = price;
}
Ironwood::Ironwood(int plantAge) : MaterialPlant(4, "IRN", "IRONWOOD_TREE", Ironwood::harvestDuration){
    this->setPlantAge(plantAge);
}
