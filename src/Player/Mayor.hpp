#ifndef __MAYOR_HPP__
#define __MAYOR_HPP__

#include <string>
#include <vector>
#include "Player.hpp"
#include "../Item/Building/Building.hpp"
#include "../Storage/Storage.hpp"

using namespace std;

class Mayor : public Player{
    public:
        // CONSTRUCTOR
        Mayor();
        Mayor(string username, int wealth, int weight);

        // GETTER
        int getKTKP();
        int getPlayerAssets();

        // CLASS METHOD
        // Calculate player Tax
        int calculateTax();

        // build a building method
        void buildBuilding();

        // check player material for build a building
        bool checkMaterialCapacity(map<string, int> material);
};

#endif