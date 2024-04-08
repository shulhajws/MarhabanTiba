#include "Shop.hpp"
#include "../Item/Animal/Carnivore.hpp"
#include "../Item/Animal/Herbivore.hpp"
#include "../Item/Animal/Omnivore.hpp"
#include "../Item/Plant/FruitPlant.hpp"
#include "../Item/Plant/MaterialPlant.hpp"

using namespace std;

// Shop& Shop::operator+(Item& item) {
//     // Implementation
// }

Shop::Shop(){
    itemsAnimals.push_back(Cow());
    itemsAnimals.push_back(Sheep());
    itemsAnimals.push_back(Horse());
    itemsAnimals.push_back(Rabbit());
    itemsAnimals.push_back(Snake());
    itemsAnimals.push_back(Chicken());
    itemsAnimals.push_back(Duck());

    itemsPlants.push_back(TeakTree());
    itemsPlants.push_back(SandalwoodTree());
    itemsPlants.push_back(AloeTree());
    itemsPlants.push_back(IronwoodTree());
    itemsPlants.push_back(AppleTree());
    itemsPlants.push_back(OrangeTree());
    itemsPlants.push_back(BananaTree());
    itemsPlants.push_back(GuavaTree());
}

Shop::Shop(vector<tuple<Item, int>> items, vector<Plant> plants, vector<Animal> animals){
    this->itemsAnimals = animals;
    this->itemsPlants = plants;
    this->shopItems = items;
}

void Shop :: printShop(){
    cout << "Welcome to MarhabanTiba Shop!" << endl;
    cout << "Here are the things that you can buy: " << endl;
    // Print details of each item available in the shop
    int index = 1;
    for (const auto& item : itemsBuilding) {
        Building building = get<0>(item);
        int stock = get<1>(item);
        cout << index << ". " << building.getName() << " - "<<building.calculatePrice()<<" (" << stock << ")" << endl;
        index++;
    }

    for (const auto& item : itemsAnimalsProducts) {
        ProductsAnimal animal = get<0>(item);
        int stock = get<1>(item);
        cout << index << ". " << animal.getName() << " - "<<"Harga"<<" (" << stock << ")" << endl;
        index++;
    }

    for (const auto& item : itemsPlantsProducts) {
        PlantsProducts plant = get<0>(item);
        int stock = get<1>(item);
        cout << index << ". " << plant.getName() << " - "<<"Harga"<<" (" << stock << ")" << endl;
        index++;
    }

    for (auto& item : itemsAnimals) {
        cout << index <<". "<< item.getName() << " - "<< item.getPrice() <<endl;
        index = index+1;
    }

    for (auto& item : itemsPlants) {
        cout << index <<". "<< item.getName() << " - "<< item.getPrice() <<endl;
        index = index+1;
    }

}

Item& Shop::getItem(int i){
    if (i<=itemsBuilding.size()){
        return get<0>(itemsBuilding[i]);
    }
    else if(i<=itemsAnimalsProducts.size()){
        return get<0>(itemsAnimalsProducts[i]);
    }
    else if(i<=itemsPlantsProducts.size()){
        return get<0>(itemsPlantsProducts[i]);
    }
    else if(i<=itemsAnimals.size()){
        return itemsAnimals[i];
    }
    return itemsPlants[i];
    //exception otw
}
