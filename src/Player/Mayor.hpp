#ifndef __MAYOR_HPP__
#define __MAYOR_HPP__

#include <string>
#include <vector>
#include "Player.hpp"
#include "../Item/Building/Building.hpp"

using namespace std;

class Mayor : public Player{
    public:
        Mayor();
        Mayor(string username, int wealth, int weight);
        void buildBuilding();
        bool checkMaterialCapacity(map<string, int> material);
};

#endif