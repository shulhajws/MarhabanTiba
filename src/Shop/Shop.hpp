#ifndef SHOP_HPP
#define SHOP_HPP
#include <iostream>
using namespace std;

#include "../Item/Animal/Animal.hpp"
#include "../Item/Plant/Plant.hpp"
#include "../Building/Building.hpp"
#include "../Item/Plant/Plant.hpp"
#include "../Products/PlantsProducts.hpp"
#include "../Products/ProductsAnimal.hpp"
#include <vector>
#include <tuple>

class Shop {
private:
    vector <Item> items;
    vector<tuple<Building, int>> itemsBuilding;
    vector<Plant> itemsPlants;
    vector<Animal> itemsAnimals;
    vector<tuple<PlantsProducts, int>> itemsPlantsProducts;
    vector<tuple<ProductsAnimal, int>> itemsAnimalsProducts;

public:
    Shop& operator+(Item& item);
    void printShop();
    int getPlayerWealth(const Player& player) const;
};

#endif // SHOP_HPP
