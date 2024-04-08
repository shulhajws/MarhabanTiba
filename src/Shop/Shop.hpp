#ifndef SHOP_HPP
#define SHOP_HPP
#include <iostream>
using namespace std;

#include "../Item/Item.hpp"
#include "../Item/Animal/Animal.hpp"
#include "../Item/Plant/Plant.hpp"
#include "../Item/Building/Building.hpp"
#include "../Item/Products/PlantsProducts.hpp"
#include "../Item/Products/ProductsAnimal.hpp"

#include <vector>
#include <tuple>

class Shop {
private:
    vector<tuple<Building, int>> itemsBuilding;
    vector<Plant> itemsPlants;
    vector<Animal> itemsAnimals;
    vector<tuple<PlantsProducts, int>> itemsPlantsProducts;
    vector<tuple<ProductsAnimal, int>> itemsAnimalsProducts;
    vector<tuple<Item, int>> shopItems; 

public:
    Shop();
    Shop(vector<tuple<Item, int>> items, vector<Plant> plants, vector<Animal> animals);
    Shop& operator+(Item& item);
    Item& getItem(int i);
    void printShop();
};

#endif // SHOP_HPP
