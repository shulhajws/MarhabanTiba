#include "Shop.hpp"
#include "../Item/Animal/Carnivore.hpp"
#include "../Item/Animal/Herbivore.hpp"
#include "../Item/Animal/Omnivore.hpp"
#include "../Item/Plant/FruitPlant.hpp"
#include "../Item/Plant/MaterialPlant.hpp"

using namespace std;
vector<tuple<Building*, int*>> Shop::itemsBuilding;
vector<tuple<Products*, int*>> Shop::products;


Shop::Shop(){
    itemsAnimals.push_back(new Cow());
    itemsAnimals.push_back(new Sheep());
    itemsAnimals.push_back(new Horse());
    itemsAnimals.push_back(new Rabbit());
    itemsAnimals.push_back(new Snake());
    itemsAnimals.push_back(new Chicken());
    itemsAnimals.push_back(new Duck());

    itemsPlants.push_back(new TeakTree());
    itemsPlants.push_back(new SandalwoodTree());
    itemsPlants.push_back(new AloeTree());
    itemsPlants.push_back(new IronwoodTree());
    itemsPlants.push_back(new AppleTree());
    itemsPlants.push_back(new OrangeTree());
    itemsPlants.push_back(new BananaTree());
    itemsPlants.push_back(new GuavaTree());
}

Shop::Shop(vector<tuple<Building*, int*>> building, vector<tuple<Products*, int*>> products){
    this->itemsBuilding = building;
    this->products = products;
}

void Shop :: printShop(){
    cout << "Welcome to MarhabanTiba Shop!" << endl;
    cout << "Here are the things that you can buy: " << endl;
    // Print details of each item available in the shop
    int index = 1;
    for (const auto& item : itemsBuilding) {
        Building building = *get<0>(item);
        int stock = *get<1>(item);
        cout << index << ". " << building.getName() << " - "<<building.calculatePrice()<<" (" << stock << ")" << endl;
        index++;
    }

    for (const auto& item : products) {
        Products prod = *get<0>(item);
        int stock = *get<1>(item);
        cout << index << ". " << prod.getName() << " - "<<"Harga"<<" (" << stock << ")" << endl;
        index++;
    }

    for (auto& item : itemsAnimals) {
        cout << index <<". "<< item->getName() << " - "<< item->getPrice() <<endl;
        index = index+1;
    }

    for (auto& item : itemsPlants) {
        cout << index <<". "<< item->getName() << " - "<< item->getPrice() <<endl;
        index = index+1;
    }

}

int Shop::totalItem(){
    return (itemsAnimals.size() + products.size() + itemsBuilding.size()+itemsPlants.size());
}

Item* Shop::getItem(int i){
    int x2 = itemsBuilding.size();
    int x3 = products.size() + itemsBuilding.size();    
    int x4 = itemsAnimals.size() + products.size() + itemsBuilding.size();

    if (i<=itemsBuilding.size() && itemsBuilding.size()!= 0){
        return get<0>(itemsBuilding[i-1]);
    }
    else if(i<= products.size() + x2 && products.size()!= 0){
        return get<0>(products[i-x2-1]);
    }
    else if(i<= itemsAnimals.size() + x3 && itemsAnimals.size()!= 0){
        return itemsAnimals[i-x3-1];
    }
    else if(i<= itemsPlants.size() + x4 && itemsPlants.size()!= 0){
        return itemsPlants[i-x4-1];
    }
    return nullptr;
}

void Shop::addBuilding(Building b){
    bool found = false;
    for (const auto& item : itemsBuilding) {
        Building building = *get<0>(item);
        if(building.getCode()==b.getCode()){
            *get<1>(item) += 1;
            found = true;
        }
    }

    if(!found){
        int num = 1;
        itemsBuilding.push_back(make_tuple(&b, &num));
    }

}

void Shop::addProducts(Products b){
    bool found = false;
    for (const auto& item : products) {
        Products prod = *get<0>(item);
        if(prod.getCode()==b.getCode()){
            *get<1>(item) += 1;
            found = true;
        }
    }

    if(!found){
        int num = 1;
        products.push_back(make_tuple(&b, &num));
    }

}

Shop& Shop::operator+(Item& item) {
    if(item.getType()=="CARNIVORE" ||item.getType()=="OMNIVORE" || item.getType()=="HERBIVORE" || item.getType()=="MATERIAL_PLANT" || item.getType()=="FRUIT_PLANT"){
        // do nothing
    }
    else if(item.getType()=="SMALL_HOUSE" || item.getType()=="MEDIUM_HOUSE" || item.getType()=="LARGE_HOUSE" || item.getType()=="HOTEL"){
        Building* building = dynamic_cast<Building*>(&item);
        addBuilding(*building);
    }
    else{
        Products* prod = dynamic_cast<Products*>(&item);
        addProducts(*prod);
    }
    return *this;
}