#ifndef __MATERIAL_PLANT_HPP__
#define __MATERIAL_PLANT_HPP__

#include "Plant.hpp"
#include <string>
using namespace std;

class MaterialPlant : public Plant {
    public:
        MaterialPlant(int plantID, string code, string name, int harvestDuration);
};

class Teak : public MaterialPlant {
    private:
        static int harvestDuration;
        static int price;
    public: 
        Teak();
        Teak(int harvestDuration, int price);
        Teak(int plantAge);
};

class Sandalwood : public MaterialPlant {
    private:
        static int harvestDuration;
        static int price;
    public: 
        Sandalwood();
        Sandalwood(int harvestDuration, int price);
        Sandalwood(int plantAge);
};

class Aloe : public MaterialPlant {
    private:
        static int harvestDuration;
        static int price;
    public: 
        Aloe();
        Aloe(int harvestDuration, int price);
        Aloe(int plantAge);
};

class Ironwood : public MaterialPlant {
    private:
        static int harvestDuration;
        static int price;
    public: 
        Ironwood();
        Ironwood(int harvestDuration, int price);
        Ironwood(int plantAge);
};

#endif