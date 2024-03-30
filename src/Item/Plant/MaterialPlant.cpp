#include "MaterialPlant.hpp"
#include <iostream>
using namespace std;

MaterialPlant::MaterialPlant(string code, string name, int harvestDuration, int price) : Plant(code, name, "MATERIAL_PLANT", harvestDuration, price){}

bool MaterialPlant::isEatable(){
    return false;
}

Teak::Teak(int harvestDuration, int price) : MaterialPlant("TEK", "TEAK_TREE", harvestDuration, price){}

Sandalwood::Sandalwood(int harvestDuration, int price) : MaterialPlant("SDT", "SANDALWOOD_TREE", harvestDuration, price){}

Aloe::Aloe(int harvestDuration, int price) : MaterialPlant("ALT", "ALOE_TREE", harvestDuration, price){}

Ironwood::Ironwood(int harvestDuration, int price) : MaterialPlant("IRN", "IRONWOOD_TREE", harvestDuration, price){}
