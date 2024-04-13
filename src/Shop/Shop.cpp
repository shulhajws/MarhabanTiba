#include "Shop.hpp"
#include "../Item/Animal/Carnivore.hpp"
#include "../Item/Animal/Herbivore.hpp"
#include "../Item/Animal/Omnivore.hpp"
#include "../Item/Plant/FruitPlant.hpp"
#include "../Item/Plant/MaterialPlant.hpp"
#include "../Item/Product/ProductAnimal.hpp"
#include "../Item/Product/ProductFruitPlant.hpp"
#include "../Item/Product/ProductMaterial.hpp"


using namespace std;
vector<tuple<Building*, int>> Shop::itemsBuilding;
vector<tuple<Product*, int>> Shop::product;


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

Shop::Shop(vector<tuple<Building*, int>> building, vector<tuple<Product*, int>> product){
    this->itemsBuilding = building;
    this->product = product;
}

vector<tuple<Building*, int>> Shop::getItemsBuilding() const{
    return this->itemsBuilding;
}

vector<tuple<Product*, int>> Shop::getItemsProduct() const{
    return this->product;
}

void Shop :: printShop(){
    cout << "Welcome to MarhabanTiba Shop!" << endl;
    cout << "Here are the things that you can buy: " << endl;
    // Print details of each item available in the shop
    int index = 1;
    for (const auto& item : itemsBuilding) {
        Building building = *get<0>(item);
        int stock = get<1>(item);
        cout << index << ". " << building.getName() << " - "<<building.getPrice()<<" (" << stock << ")" << endl;
        index++;
    }

    for (const auto& item : product) {
        Product prod = *get<0>(item);
        int stock = get<1>(item);
        cout << index << ". " << prod.getName() << " - "<<prod.getPrice()<<" (" << stock << ")" << endl;
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
    return (itemsAnimals.size() + product.size() + itemsBuilding.size()+itemsPlants.size());
}

Item* Shop::getItem(int i){
    int x2 = itemsBuilding.size();
    int x3 = product.size() + itemsBuilding.size();    
    int x4 = itemsAnimals.size() + product.size() + itemsBuilding.size();

    if (i<=itemsBuilding.size() && itemsBuilding.size()!= 0){
        return get<0>(itemsBuilding[i-1]);
    }
    else if(i<= product.size() + x2 && product.size()!= 0){
        return get<0>(product[i-x2-1]);
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
    for (auto& item : itemsBuilding) {
        Building building = *get<0>(item);
        if(building.getCode()==b.getCode()){
            get<1>(item) += 1;
            found = true;
        }
    }

    if(!found){
        itemsBuilding.push_back(make_tuple(&b, 1));
    }

}

void Shop::addProduct(Product b){
    bool found = false;
    for (auto& item : product) {
        Product prod = *get<0>(item);
        if(prod.getCode()==b.getCode()){
            get<1>(item) += 1;
            found = true;
        }
    }

    if(!found){
        product.push_back(make_tuple(&b,1));
    }

}

void Shop::minBuilding(Building b, int num) {
    for (auto it = itemsBuilding.begin(); it != itemsBuilding.end(); ++it) {
        if (get<0>(*it)->getCode() == b.getCode()) {
            get<1>(*it) -= num; 
            if (get<1>(*it)<= 0) {
                it = itemsBuilding.erase(it); 
            }
            break;  
        }
    }
}

void Shop::minProduct(Product b, int num) {
    for (auto it = product.begin(); it != product.end(); ++it) {
        if (get<0>(*it)->getCode()  == b.getCode()) {
            get<1>(*it) -= num;  
            if (get<1>(*it) <= 0) {
                it = product.erase(it); 
            }
            break;  
        }
    }
}

void Shop::minItems(Item& item, int num){
    if(item.getType()=="CARNIVORE" ||item.getType()=="OMNIVORE" || item.getType()=="HERBIVORE" || 
    item.getType()=="MATERIAL_PLANT" || item.getType()=="FRUIT_PLANT"){
    }
    else if(item.getType() =="BUILDING"|| item.getType()=="SMALL_HOUSE" || item.getType()=="MEDIUM_HOUSE" || 
    item.getType()=="LARGE_HOUSE" || item.getType()=="HOTEL"){
        Building* building = dynamic_cast<Building*>(&item);
        minBuilding(*building,num);
    }
    else{
        Product* prod = dynamic_cast<Product*>(&item);
        minProduct(*prod,num);
    }
}

int Shop::getCapacity(Item& item) {
    if (item.getType() == "CARNIVORE" || item.getType() == "OMNIVORE" || 
        item.getType() == "HERBIVORE" || item.getType() == "MATERIAL_PLANT" || 
        item.getType() == "FRUIT_PLANT") {
        return 999999; 
    }
    else if (item.getType() == "SMALL_HOUSE" || item.getType() == "MEDIUM_HOUSE" || 
             item.getType() == "LARGE_HOUSE" || item.getType() == "HOTEL") {
        for (const auto& it : itemsBuilding) {
            Building prod = *get<0>(it);  
            int stock = get<1>(it);
            if (prod.getCode() == item.getCode()) {
                return stock;  
            }
        }
    }
    else {
        for (const auto& it : product) {
            Product prod = *get<0>(it);
            int stock = get<1>(it);
            if (prod.getCode() == item.getCode()) {
                return stock;
            }
        }
        
    }
    return 0;  
}

bool Shop::isBuilding(Item& item){
    cout << "masuk name "<<item.getName()<<"masuk type"<<item.getType()<<endl;
    if (item.getName() == "SMALL_HOUSE" || item.getName() == "MEDIUM_HOUSE" || item.getName()=="LARGE_HOUSE" || 
    item.getName()=="HOTEL"|| item.getType()=="BUILDING" || item.getType() == "SMALL_HOUSE" || item.getType() == "MEDIUM_HOUSE" || 
    item.getType() == "LARGE_HOUSE" || item.getType() == "HOTEL") {
        return true;
    }else{
        return false;
    }
}
Shop& Shop::operator+(Item& item) {
    if(item.getType()=="CARNIVORE" ||item.getType()=="OMNIVORE" || 
    item.getType()=="HERBIVORE" || item.getType()=="MATERIAL_PLANT" || 
    item.getType()=="FRUIT_PLANT"){
        // do nothing
    }
    else if(item.getType()=="SMALL_HOUSE" || item.getType()=="MEDIUM_HOUSE" || 
    item.getType()=="LARGE_HOUSE" || item.getType()=="HOTEL"){
        Building* building = dynamic_cast<Building*>(&item);
        addBuilding(*building);
    }
    else{
        Product* prod = dynamic_cast<Product*>(&item);
        addProduct(*prod);
    }
    return *this;
}