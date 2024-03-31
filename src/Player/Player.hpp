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
        bool operator==(string command) const;
        Player(int wealth) : wealth(wealth) {}
        string getName() const;
        // Method untuk membeli barang dari toko
        void buyItem(Shop& shop, const string& itemName, int quantity);
        // Method untuk menjual barang ke toko
        void sellItem(Shop& shop, const string& itemName, int quantity); 
        // Method to query the player's wealth
        int getPlayerWealth ();
        // Declare Shop as a friend class
        friend class Shop;
        
};

#endif