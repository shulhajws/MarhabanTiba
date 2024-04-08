#ifndef __MATERIAL_PLANT_HPP__
#define __MATERIAL_PLANT_HPP__

#include "Plant.hpp"
#include <string>
using namespace std;

class MaterialPlant : public Plant {
    public:
        MaterialPlant(int plantID, string code, string name, int harvestDuration, int price);
};

class TeakTree : public MaterialPlant {
    private:
        static int harvestDuration;
        static int price;
    public: 
        TeakTree();
        TeakTree(int harvestDuration, int price);
        TeakTree(int plantAge);
};

class SandalwoodTree : public MaterialPlant {
    private:
        static int harvestDuration;
        static int price;
    public: 
        SandalwoodTree();
        SandalwoodTree(int harvestDuration, int price);
        SandalwoodTree(int plantAge);
};

class AloeTree : public MaterialPlant {
    private:
        static int harvestDuration;
        static int price;
    public: 
        AloeTree();
        AloeTree(int harvestDuration, int price);
        AloeTree(int plantAge);
};

class IronwoodTree : public MaterialPlant {
    private:
        static int harvestDuration;
        static int price;
    public: 
        IronwoodTree();
        IronwoodTree(int harvestDuration, int price);
        IronwoodTree(int plantAge);
};

#endif