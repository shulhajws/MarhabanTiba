#ifndef __FRUIT_PLANT_HPP__
#define __FRUIT_PLANT_HPP__

#include "Plant.hpp"
#include <string>
using namespace std;

class FruitPlant : public Plant {
    public:
        FruitPlant(int plantID, string code, string name, int harvestDuration);
};

class Apple : public FruitPlant {
    private:
        static int harvestDuration;
        static int price;
    public: 
        Apple();
        Apple(int harvestDuration, int price);
        Apple(int plantAge);
};

class Orange : public FruitPlant {
    private:
        static int harvestDuration;
        static int price;
    public: 
        Orange();
        Orange(int harvestDuration, int price);
        Orange(int plantAge);
};

class Banana : public FruitPlant {
    private:
        static int harvestDuration;
        static int price;
    public: 
        Banana();
        Banana(int harvestDuration, int price);
        Banana(int plantAge);
};

class Guava : public FruitPlant {
    private:
        static int harvestDuration;
        static int price;
    public: 
        Guava();
        Guava(int harvestDuration, int price);
        Guava(int plantAge);
};

#endif