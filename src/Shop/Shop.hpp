#ifndef SHOP_HPP
#define SHOP_HPP
#include <iostream>
using namespace std;

#include "../Item/Item.hpp"
#include "../Item/Animal/Animal.hpp"
#include "../Item/Plant/Plant.hpp"
#include "../Item/Building/Building.hpp"
#include "../Item/Product/Product.hpp"

#include <vector>
#include <tuple>

class Shop {
    private:
        static vector<tuple<Building*, int>> itemsBuilding;
        static vector<tuple<Product*, int>> product;
        vector<Plant*> itemsPlants;
        vector<Animal*> itemsAnimals;
    public:
        Shop();
        Shop(vector<tuple<Building*, int>> building, vector<tuple<Product*, int>> product);
        Shop& operator+(Item* item);
        vector<tuple<Building*, int>> getItemsBuilding() const;
        vector<tuple<Product*, int>> getItemsProduct() const;
        int totalItem();
        int cheapestItemPrice();
        void addBuilding(Building* b);
        void minBuilding(Building b, int num);
        void addProduct(Product* p);
        void minProduct(Product p, int num);
        void minItems(Item& item,int num);
        int getCapacity (Item& item);
        Item* getItem(int i);
        Item* getNewItem(int i);
        void printShop();
        bool isBuilding(Item& item);
};

#endif // SHOP_HPP
