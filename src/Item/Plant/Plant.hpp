#ifndef __PLANT_HPP__
#define __PLANT_HPP__

#include "../Item.hpp"
#include <string>
using namespace std;

class Plant : public Item{
    private:    
        static int plantID;
        int harvestDuration;
        int price;
        int plantAge;

    public:
        /**
         * @brief Construct a new Plant object
         *
         * @param plantID 
         * @param plantCode
         * @param name
         * @param type
         * @param harvestDuration
         * @param price
         */
        Plant(string plantCode, string name, string type, int harvestDuration, int price);

        /**
         * @brief Destructor for Plant object
         */
        ~Plant();

        /**
         * @brief add the age of the plant object
         *
         */
        void addAge();

        /**
         * @brief add the age of the plant object
         *
         * @return stating if the plant is ready to harvest
         */
        bool isReadyToHarvest();

        virtual bool isEatable() = 0;

};

#endif