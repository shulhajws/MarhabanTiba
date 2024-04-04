#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <string>
#include <vector>
#include "../Command/Command.hpp"
#include "../Shop/Shop.hpp"
#include "../Item/Item.hpp"
#include "../Item/Building/Building.hpp" 
#include "../Storage/Storage.hpp"
#include "../Item/Products/Products.hpp" 
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

        string getName() const;
        int getPlayerWealth() const;
        string getType() const;
        virtual int getKTKP();

        void addPlayerWealth(int money);
        void minPlayerWealth(int money);
        void eat();
        
        bool operator==(string command) const;

        virtual void displayInfo() const;
        
};

#endif