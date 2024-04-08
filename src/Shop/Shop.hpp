#ifndef SHOP_HPP
#define SHOP_HPP
#include <iostream>
using namespace std;

#include "../Item/Animal/Animal.hpp"
#include "../Item/Plant/Plant.hpp"
#include "../Item/Building/Building.hpp"
#include "../Item/Plant/Plant.hpp"
#include "../Item/Products/PlantsProducts.hpp"
#include "../Item/Products/ProductsAnimal.hpp"
#include <vector>
#include <tuple>

class Shop {
private:
    vector<tuple<Item, int>> shopItems;
    // vector <Item> items;
    // vector<tuple<Building, int>> itemsBuilding;
    vector<Plant> itemsPlants;
    vector<Animal> itemsAnimals;
    // vector<tuple<PlantsProducts, int>> itemsPlantsProducts;
    // vector<tuple<ProductsAnimal, int>> itemsAnimalsProducts;

public:
    Shop(vector<tuple<Item, int>>, vector<Plant>, vector<Animal>);
    Shop& operator+(Item& item);
    void printShop();
};

#endif // SHOP_HPP
