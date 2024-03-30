#ifndef __FRUIT_PLANT_HPP__
#define __FRUIT_PLANT_HPP__

#include "Plant.hpp"
#include <string>
using namespace std;

class FruitPlant : public Plant {
    public:
        /**
         * @brief Construct a new Material Plant object
         * 
         * @param code
         * @param name
         * @param harvestDuration
         * @param price
         */
        FruitPlant(string code, string name, int harvestDuration, int price);

        bool isEatable();
};

class Apple : public FruitPlant {
    public: 
        Apple(int harvestDuration, int price);
};

class Orange : public FruitPlant {
    public: 
        Orange(int harvestDuration, int price);
};

class Banana : public FruitPlant {
    public: 
        Banana(int harvestDuration, int price);
};

class Guava : public FruitPlant {
    public: 
        Guava(int harvestDuration, int price);
};

#endif