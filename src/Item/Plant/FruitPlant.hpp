#ifndef __FRUIT_PLANT_HPP__
#define __FRUIT_PLANT_HPP__

#include "Plant.hpp"
#include <string>
using namespace std;

class FruitPlant : public Plant {
    public:
        FruitPlant(int plantID, string code, string name, int harvestDuration, int price);
};

class AppleTree : public FruitPlant {
    private:
        static int harvestDuration;
        static int price;
    public: 
        AppleTree();
        AppleTree(int harvestDuration, int price);
        AppleTree(int plantAge);
};

class OrangeTree : public FruitPlant {
    private:
        static int harvestDuration;
        static int price;
    public: 
        OrangeTree();
        OrangeTree(int harvestDuration, int price);
        OrangeTree(int plantAge);
};

class BananaTree : public FruitPlant {
    private:
        static int harvestDuration;
        static int price;
    public: 
        BananaTree();
        BananaTree(int harvestDuration, int price);
        BananaTree(int plantAge);
};

class GuavaTree : public FruitPlant {
    private:
        static int harvestDuration;
        static int price;
    public: 
        GuavaTree();
        GuavaTree(int harvestDuration, int price);
        GuavaTree(int plantAge);
};

#endif