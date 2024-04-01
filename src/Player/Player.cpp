#include "Player.hpp"
#include "../Command/AllCommand/Next.hpp"
#include "../Command/AllCommand/CetakStorage.hpp"
#include "../Command/AllCommand/Makan.hpp"
#include "../Command/AllCommand/Beli.hpp"
#include "../Command/AllCommand/Jual.hpp"
#include "../Shop/Shop.hpp"
#include "../Item/Item.hpp"
#include "../Building/Building.hpp"
#include <iostream>
using namespace std;

Player::Player(){
    this->commandList.push_back(new Next());
    this->commandList.push_back(new CetakStorage());
    this->commandList.push_back(new Makan());
    this->commandList.push_back(new Jual());
    this->commandList.push_back(new Beli());
}

Player::Player(string username, int wealth, int weight) : Player(){
    this->username = username;
    this->wealth = wealth;
    this->weight = weight;
}

bool Player::operator==(string command) const{
    bool ada = false; // cari command punya player atau bukan
    for (auto &c : commandList){
        if (c->getName() == command){
            ada = true; // command ada
            c->useCommand();
        }
    }
    return ada;
}


Player::Player(const Player& other) : Player(){
    this->username = other.username;
    this->wealth = other.wealth;
    this->weight = other.weight;
}

Player::~Player() {
    for (auto& c : commandList) {
        delete c;
    }
}

string Player::getName() const{
    return this->username;
}

int Player::getWealth() const{
    return this->wealth;
}

void Player::displayInfo() const {
    cout << "Username: " << this->username << endl;
    cout << "Wealth  : " << this->wealth << endl;
    cout << "Weight  : " << this->weight << endl;
}

int Player::calculateTax() const {
    return wealth * 0.1; // Dummy 
}

void Player :: buyItem(Shop& shop, const string& itemName, int quantity){
    cout << "Player bought item: " << itemName << endl;
    //item di storage orang ini bertambah
}

void Player :: sellItem(Shop& shop, const string& itemName, int quantity){
    cout << "Player sell item: " << itemName << endl;
    //item di storage orang ini berkurang
}

void Player::eat() {
    weight += 1;
    cout << "Player ate something" << endl;
}

void Player::increaseWealth(int amount) {
    wealth += amount;
}
