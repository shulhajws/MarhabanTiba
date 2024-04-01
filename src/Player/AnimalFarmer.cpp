#include "AnimalFarmer.hpp"
#include "../Command/PeternakCommand/KasihMakan.hpp"
#include "../Command/PeternakCommand/Ternak.hpp"

#include <iostream>
using namespace std;

AnimalFarmer::AnimalFarmer() : Player(){
    this->commandList.push_back(new KasihMakan());
    this->commandList.push_back(new Ternak());
}

AnimalFarmer::AnimalFarmer(string username, int wealth, int weight) : Player(username, wealth, weight, "Peternak") {
    this->commandList.push_back(new KasihMakan());
    this->commandList.push_back(new Ternak());
}

int AnimalFarmer::getKTKP(){
    return 11;
}

void AnimalFarmer::displayInfo() const {
    cout << "Animal Farmer - ";
    Player::displayInfo();
}

void AnimalFarmer::placeAnimal() {
    cout << this->getName() <<"is placing animals in the barn." << endl;
}

void AnimalFarmer::feedAnimal() {
    cout << this->getName() <<" is feeding animals." << endl;
}

void AnimalFarmer::harvestAnimal() {
    cout << this->getName() <<" is harvesting animals." << endl;
}

void AnimalFarmer::printBarn() {
    cout << this->getName() <<"s barn is being printed." << endl;
}