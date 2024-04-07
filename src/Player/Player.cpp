#include "Player.hpp"
#include "../Command/AllCommand/Next.hpp"
#include "../Command/AllCommand/CetakStorage.hpp"
#include "../Command/AllCommand/Makan.hpp"
#include "../Command/AllCommand/Beli.hpp"
#include "../Command/AllCommand/Jual.hpp"
#include <iostream>
using namespace std;

Player::Player(){
    this->commandList.push_back(new Next());
    this->commandList.push_back(new CetakStorage());
    this->commandList.push_back(new Makan());
    this->commandList.push_back(new Jual());
    this->commandList.push_back(new Beli());
    Misc m;
    this->inventory.setRowCols(m.getStorageRow(),m.getStorageCols());
}

Player::Player(string username, int wealth, int weight, string type) : Player(){
    this->username = username;
    this->wealth = wealth;
    this->weight = weight;
    this->type = type;
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

string Player::getType() const{
    return this->type;
}

int Player::getKTKP(){
    return 0;
}

void Player::addPlayerWealth(int money){
    this->wealth += money;
}

void Player::minPlayerWealth(int money){
    this->wealth -= money;
}

int Player::getPlayerWealth() const{
    return this->wealth;
}

int Player::getPlayerWeight() const{
    return this->weight;
}

void Player::displayStorage(){
    inventory.printStorage();
}

void Player::eat() {
    string slot;
    while(true) {
        try {
            cout << "Slot: ";
            cin >> slot;
            int row = inventory.positionCodetoRow(slot);
            int col = inventory.positionCodetoCol(slot);

            Item* storedItem = inventory.getItemInfo(row, col);
            if ((storedItem->getType() == "PRODUCT_FRUIT_PLANT" || storedItem->getType() == "PRODUCT_ANIMAL")) {
                Products* productPtr = dynamic_cast<Products*>(storedItem);
                int addedWeight = productPtr->getAddedWeight();
                weight += addedWeight;
                
                cout << "Player " << username << " has eaten " << storedItem->getName() << ". Weight increased by " << addedWeight << " kg.\n";
                break;
            } else {
                throw ItemNotFoundException();
            }
        } catch (ItemNotFoundException e) {
            cout << e.what()<<endl;
            break;
        }
    }
}

void Player::displayInfo() const {
    cout << "Username: " << this->username << endl;
    cout << "Wealth  : " << this->wealth << endl;
    cout << "Weight  : " << this->weight << endl;
}