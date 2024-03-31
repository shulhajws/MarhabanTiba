#include "AnimalFarmer.hpp"
#include "../Command/PeternakCommand/KasihMakan.hpp"
#include "../Command/PeternakCommand/Ternak.hpp"

AnimalFarmer::AnimalFarmer() : Player(){
    this->commandList.push_back(new KasihMakan());
    this->commandList.push_back(new Ternak());
}

AnimalFarmer::AnimalFarmer(string username, int wealth, int weight) : Player(username, wealth, weight) {
    this->commandList.push_back(new KasihMakan());
    this->commandList.push_back(new Ternak());
}