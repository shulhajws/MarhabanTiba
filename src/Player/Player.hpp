#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <string>
#include <vector>
#include "../Command/Command.hpp"
#include "../Shop/Shop.hpp"
#include "../Item/Item.hpp"
#include "../Item/Building/Building.hpp" 
#include "../Storage/Storage.hpp"
#include "../Item/Product/Product.hpp" 
#include "../Misc/Misc.hpp"

using namespace std;

class Player{
    protected:
        string username;
        int wealth;
        int weight;
        Storage<Item*> inventory;
        vector<Command*> commandList;
        string code;
        string name;
        string type;

    public:
        Player();
        Player(string username, int wealth, int weight, string type);
        Player(const Player& other);
        virtual ~Player();

        string getName() const;
        int getPlayerWealth() const;
        int getPlayerWeight() const;
        bool inventoryEmpty();
        string getType() const;
        virtual int getKTKP();
        void setInventory(Storage<Item*>);
        void displayStorage();
        void addPlayerWealth(int money);
        void minPlayerWealth(int money);
        void eat();
        void buyItem();
        void sellItem();
        vector<string> splitbyComa(const string& input);
        bool operator==(string command) const;

        virtual void displayInfo() const;
        
};

#endif