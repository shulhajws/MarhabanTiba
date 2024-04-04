#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <string>
#include <vector>
#include "../Command/Command.hpp"
#include "../Shop/Shop.hpp"
#include "../Item/Item.hpp"
#include "../Item/Building/Building.hpp"
using namespace std;

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
        Player(string username, int wealth, int weight, string type);
        Player(const Player& other);
        virtual ~Player();
        int getPlayerWealth() const;
        virtual void displayInfo() const;
        string getName() const;
        string getType() const;
        void addPlayerWealth(int money);
        void minPlayerWealth(int money);
        virtual int getKTKP();
        // Method untuk membeli barang dari toko
        void buyItem(Shop& shop, const string& itemName, int quantity);
        void sellItem(Shop& shop, const string& itemName, int quantity); 
        void eat();
        void increaseWealth(int amount);
        
        bool operator==(string command) const;
        
};

#endif