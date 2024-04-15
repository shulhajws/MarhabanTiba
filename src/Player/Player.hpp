#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <string>
#include <vector>
#include <limits>
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
        // CLASS CONSTRUCTOR AND DESTRUCTOR
        Player();
        Player(string username, int wealth, int weight, string type);
        Player(const Player& other);
        virtual ~Player();

        // GETTER AND SETTER
        string getName() const;
        int getPlayerWealth() const;
        int getPlayerWeight() const;
        string getType() const;
        vector<Item*> getListOfItems() const;
        void setInventory(Storage<Item*>);

        // CLASS METHOD
        // Player Storage Method
        void displayStorage();
        bool inventoryEmpty() const;
        int itemInInventories() const;

        // Adding and Reduce Player Money
        void addPlayerWealth(int money);
        void minPlayerWealth(int money);

        // Eat method
        void eat();

        // Buy and Sell method
        void buyItem();
        void sellItem();

        // Method for handle input
        bool hasDuplicates(const vector<string>& slots);
        vector<string> splitbyComa(const string& input);;

        // OPERATOR OVERLOADING
        bool operator==(string command) const;
        
        // VIRTUAL METHOD
        virtual void displayInfo() const;
        virtual int getPlayerAssets()=0;
        virtual int getKTKP()=0;
        virtual int calculateTax()=0;
        
};

#endif