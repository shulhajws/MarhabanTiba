#ifndef __GAME_HPP__
#define __GAME_HPP__

#include <string>
#include <vector>
#include "../Exception/Exception.hpp"
#include "../Player/Player.hpp"
#include "../Player/Mayor.hpp"
#include "../Player/AnimalFarmer.hpp"
#include "../Player/PlantFarmer.hpp"
#include "../FileIO/Loader.hpp"
#include "../Misc/Misc.hpp"

using namespace std;

class Game{
    protected:
        static int currPlayer;
        static int tambahPemain;
        static vector<Player*> players;
    public:
        void startGame();
        void askInput();
        void initiation();
        void inputPlayer();
        bool inputCommand();
        string inputName();
        void sortPlayer();
        bool checkEndGame();
        void playerTurn();
        void splashScreen();
        string lowerCase(const string& str);
        bool nameNotValid(string name);
        ~Game();
};

#endif