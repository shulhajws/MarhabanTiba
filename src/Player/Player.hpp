#ifndef __PLAYER_HPP__
#define __PLAYER_HPP__

#include <string>
#include <vector>
#include "../Command/Command.hpp"
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
        Player(string username, int wealth, int weight);
        bool operator==(string command) const;
        string getName() const;
        
};

#endif