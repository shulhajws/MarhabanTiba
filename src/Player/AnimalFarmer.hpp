#ifndef __ANIMALFARMER_HPP__
#define __ANIMALFARMER_HPP__

#include <string>
#include <vector>
#include "Player.hpp"
using namespace std;

class AnimalFarmer : public Player{
    public:
        AnimalFarmer();
        AnimalFarmer(string username, int wealth, int weight);
};

#endif