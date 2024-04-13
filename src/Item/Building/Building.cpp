#include "Building.hpp"
using namespace std;

Building::Building() : Item(){
    houses.push_back(new SmallHouse());
    houses.push_back(new MediumHouse());
    houses.push_back(new LargeHouse());
    houses.push_back(new Hotel());
}

Building::Building(int id, string code, string name, string type,int price) : Item(id, code, name, type,price){}

Building::~Building() {}

void Building::printMaterial(){
   for (auto house : houses) {
        house->printMaterial(); 
   }
}

int Building::getMoney(string s){
    for (const auto house : houses) {
        if(house->getName()==s){
            return house->getPrice();
        }
    }
    return 0;
}

Building* Building::getBuilding(string s){
    for (const auto house : houses) {
        if(house->getName()==s){
            return house;
        }
    }
    return 0;
}

map<string, int> Building::getmaterial(string b){
    map<string, int> Building;
    for (const auto house : houses) {
            if(house->getName()==b){
                return house->getmaterial(b);
            }
    }
    return Building;
}

int SmallHouse::price = 0;
map<string, int> SmallHouse::materials;
SmallHouse::SmallHouse() : Building(1, "SMH", "SMALL_HOUSE", "BUILDING",SmallHouse::price ){}
SmallHouse::SmallHouse(int price) : Building(1, "SMH", "SMALL_HOUSE", "BUILDING",SmallHouse::price){
    SmallHouse::price = price;
}
void SmallHouse::addRecipeMaterial(string materialName, int materialQty) {
    SmallHouse::materials.insert({materialName, materialQty});
}
map<string, int> SmallHouse::getmaterial(string b){
    return SmallHouse::materials;
}
void SmallHouse::printMaterial(){
    cout<<"1. "<<this->getName()<<" ("<<this->getPrice()<<" gulden, ";
    int index = 0;
    for (auto it = materials.begin(); it != materials.end(); ++it) {
        if (index == materials.size()-1) { 
            cout << it->first << " " << it->second << ")"<<endl;
            break;
        }
        else{
            cout << it->first << " " << it->second << ", ";
        }
        ++index;
    }
}

int MediumHouse::price = 0;
map<string, int> MediumHouse::materials;
MediumHouse::MediumHouse() : Building(2, "MDH", "MEDIUM_HOUSE", "BUILDING",MediumHouse::price){}
MediumHouse::MediumHouse(int price) : Building(2, "MDH", "MEDIUM_HOUSE", "BUILDING",MediumHouse::price){
    MediumHouse::price = price;
}
void MediumHouse::addRecipeMaterial(string materialName, int materialQty) {
    MediumHouse::materials.insert({materialName, materialQty});
}
map<string, int> MediumHouse::getmaterial(string b){
    return MediumHouse::materials;
}
void MediumHouse::printMaterial(){
    cout<<"2. "<<this->getName()<<" ("<<this->getPrice()<<" gulden, ";
    int index = 0;
    for (auto it = materials.begin(); it != materials.end(); ++it) {
        if (index == materials.size()-1) { 
            cout << it->first << " " << it->second << ")"<<endl;
            break;
        }
        else{
            cout << it->first << " " << it->second << ", ";
        }
        ++index;
    }
}

int LargeHouse::price = 0;
map<string, int> LargeHouse::materials;
LargeHouse::LargeHouse() : Building(3, "LRH", "LARGE_HOUSE", "BUILDING",LargeHouse::price){}
LargeHouse::LargeHouse(int price) : Building(3, "LRH", "LARGE_HOUSE", "BUILDING",LargeHouse::price){
    LargeHouse::price = price;
}
void LargeHouse::addRecipeMaterial(string materialName, int materialQty) {
    LargeHouse::materials.insert({materialName, materialQty});
}
map<string, int> LargeHouse::getmaterial(string b){
    return LargeHouse::materials;
}
void LargeHouse::printMaterial(){
    cout<<"3. "<<this->getName()<<" ("<<this->getPrice()<<" gulden, ";
    int index = 0;
    for (auto it = materials.begin(); it != materials.end(); ++it) {
        if (index == materials.size()-1) { 
            cout << it->first << " " << it->second << ")"<<endl;
            break;
        }
        else{
            cout << it->first << " " << it->second << ", ";
        }
        ++index;
    }
}

int Hotel::price = 0;
map<string, int> Hotel::materials;
Hotel::Hotel() : Building(4, "HTL", "HOTEL", "BUILDING",Hotel::price){}
Hotel::Hotel(int price) : Building(4, "HTL", "HOTEL", "BUILDING",Hotel::price){
    Hotel::price = price;
}
void Hotel::addRecipeMaterial(string materialName, int materialQty) {
    Hotel::materials.insert({materialName, materialQty});
}

void Hotel::printMaterial(){
    cout<<"4. "<<this->getName()<<" ("<<this->getPrice()<<" gulden, ";
    int index = 0;
    for (auto it = materials.begin(); it != materials.end(); ++it) {
        if (index == materials.size()-1) { 
            cout << it->first << " " << it->second << ")"<<endl;
            break;
        }
        else{
            cout << it->first << " " << it->second << ", ";
        }
        ++index;
    }
}

map<string, int> Hotel::getmaterial(string b){
    return Hotel::materials;
}


