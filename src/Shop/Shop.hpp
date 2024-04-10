#ifndef SHOP_HPP
#define SHOP_HPP
#include <iostream>
using namespace std;

#include "../Item/Item.hpp"
#include "../Item/Animal/Animal.hpp"
#include "../Item/Plant/Plant.hpp"
#include "../Item/Building/Building.hpp"
#include "../Item/Products/Products.hpp"

#include <vector>
#include <tuple>

class Shop {
private:
    static vector<tuple<Building*, int*>> itemsBuilding;
    vector<Plant*> itemsPlants;
    vector<Animal*> itemsAnimals;
    static vector<tuple<Products*, int*>> products;

public:
    Shop();
    Shop(vector<tuple<Building*, int*>> building, vector<tuple<Products*, int*>> products);
    Shop& operator+(Item& item);
    int totalItem();
    void addBuilding(Building b);
    void addProducts(Products p);
    Item* getItem(int i);
    void printShop();
};

#endif // SHOP_HPP
