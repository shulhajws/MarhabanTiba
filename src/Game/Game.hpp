#ifndef __OMNIVORE_HPP__
#define __OMNIVORE_HPP__

#include <string>
#include <vector>
#include "../Exception/Exception.hpp"
#include "../Player/Player.hpp"
#include "../Player/Mayor.hpp"
#include "../Player/AnimalFarmer.hpp"
#include "../Player/PlantFarmer.hpp"

using namespace std;

class Game{
    protected:
        int currPlayer;
        static vector<Player*> players;
    public:
        void startGame();
        void askInput();
        void inputPlayer();
        void inputCommand();
        string inputName();
        void sortPlayer();
        void playerTurn();
        void splashScreen();
        Player& getCurrentPlayer();
        string lowerCase(const string& str);
        bool nameNotValid(string name);
        ~Game();
};

#endif