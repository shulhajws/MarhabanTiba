#include "Building.hpp"
using namespace std;

Building::Building(int id, string code, string name, string type) : Item(id, code, name, type){}

Building::~Building() {}

int Building::calculatePrice(){
    return 0;
}

int SmallHouse::price = 0;
map<string, int> SmallHouse::materials;
SmallHouse::SmallHouse() : Building(1, "SMH", "SMALL_HOUSE", "BUILDING"){}
SmallHouse::SmallHouse(int price) : Building(1, "SMH", "SMALL_HOUSE", "BUILDING"){
    SmallHouse::price = price;
}
void SmallHouse::addRecipeMaterial(string materialName, int materialQty) {
    SmallHouse::materials.insert({materialName, materialQty});
}

int MediumHouse::price = 0;
map<string, int> MediumHouse::materials;
MediumHouse::MediumHouse() : Building(2, "MDH", "MEDIUM_HOUSE", "BUILDING"){}
MediumHouse::MediumHouse(int price) : Building(2, "MDH", "MEDIUM_HOUSE", "BUILDING"){
    MediumHouse::price = price;
}
void MediumHouse::addRecipeMaterial(string materialName, int materialQty) {
    MediumHouse::materials.insert({materialName, materialQty});
}

int LargeHouse::price = 0;
map<string, int> LargeHouse::materials;
LargeHouse::LargeHouse() : Building(3, "LRH", "LARGE_HOUSE", "BUILDING"){}
LargeHouse::LargeHouse(int price) : Building(3, "LRH", "LARGE_HOUSE", "BUILDING"){
    LargeHouse::price = price;
}
void LargeHouse::addRecipeMaterial(string materialName, int materialQty) {
    LargeHouse::materials.insert({materialName, materialQty});
}

int Hotel::price = 0;
map<string, int> Hotel::materials;
Hotel::Hotel() : Building(4, "HTL", "HOTEL", "BUILDING"){}
Hotel::Hotel(int price) : Building(4, "HTL", "HOTEL", "BUILDING"){
    Hotel::price = price;
}
void Hotel::addRecipeMaterial(string materialName, int materialQty) {
    Hotel::materials.insert({materialName, materialQty});
}


