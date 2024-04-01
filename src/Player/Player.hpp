#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <string>
#include <vector>
#include "../Command/Command.hpp"
#include "../Shop/Shop.hpp"
using namespace std;

class Shop; // Forward declaration of Shop class

class Player{
    protected:
        string username;
        int wealth;
        int weight;
        // storage
        vector<Command*> commandList;
        string code;
        string name;
        string type;

    public:
        Player();
        Player(string username, int wealth, int weight);
        Player(const Player& other);
        virtual ~Player();

        string getName() const;
        int getWealth() const;
        friend class Shop;

        virtual void displayInfo() const;
        int calculateTax() const;
        void buyItem(Shop& shop, const string& itemName, int quantity);
        void sellItem(Shop& shop, const string& itemName, int quantity); 
        void eat();
        void increaseWealth(int amount);
        
        bool operator==(string command) const;
        
};

#endif