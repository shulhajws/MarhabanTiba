#ifndef __MATERIAL_PLANT_HPP__
#define __MATERIAL_PLANT_HPP__

#include "Plant.hpp"
#include <string>
using namespace std;

class MaterialPlant : public Plant {
    public:
        /**
         * @brief Construct a new Material Plant object
         * 
         * @param code
         * @param name
         * @param harvestDuration
         * @param price
         */
        MaterialPlant(string code, string name, int harvestDuration, int price);

        bool isEatable();
};

class Teak : public MaterialPlant {
    private:
        static int harvestDuration;
        static int price;
    public: 
        Teak();
        Teak(int harvestDuration, int price);
};

class Sandalwood : public MaterialPlant {
    private:
        static int harvestDuration;
        static int price;
    public: 
        Sandalwood();
        Sandalwood(int harvestDuration, int price);
};

class Aloe : public MaterialPlant {
    private:
        static int harvestDuration;
        static int price;
    public: 
        Aloe();
        Aloe(int harvestDuration, int price);
};

class Ironwood : public MaterialPlant {
    private:
        static int harvestDuration;
        static int price;
    public: 
        Ironwood();
        Ironwood(int harvestDuration, int price);
};

#endif