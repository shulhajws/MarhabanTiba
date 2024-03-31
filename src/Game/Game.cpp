#include "Game.hpp"
#include "../Player/Player.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

void Game::startGame(){
    splashScreen();
    askInput();
    bool endGame = false;
    while(!endGame){
        playerTurn(); 
        int size = players.size(); // asumsi tambahan mainnya di next round
        for (int i = 0;i<size;i++){
            cout << "\nIt's "<<players[i]->getName()<<"'s turn to play"<<endl;
            inputCommand();
        }
        currPlayer = 0;
        break; // sementara karena blm bikin endgame
    }
}

void Game::askInput(){
    bool input = false;
    int option;

    while (!input) {
        try {
            cout << "How do you want to start the game?" << endl;
            cout << "  1. By file input" << endl;
            cout << "  2. Default" << endl;
            cout << "Choose your option: ";
            cout << "\033[1;92m";
            cin >> option;
            cout << "\033[0m";

            if (cin.fail() || (option != 1 && option != 2)) {
                throw InputException();
            } else {
                input = true;
            }
        }
        catch (InputException e) {
            cout<<e.what()<<endl;
        }
    }

    if (option == 1){ // file input

    }
    else{ // default input
        inputPlayer();
    }
}

void Game::sortPlayer() {
    std::sort(players.begin(), players.end(), [this](Player* a, Player* b) {
        return a->getName() < b->getName();
    });
}

void Game::inputPlayer(){
    string Walkot, Petani, Peternak;
     cout << "\nPlease Input All The Players!!" << endl;
    cout << "Input the Mayor" << endl;
    Walkot = inputName();
    this->players.push_back(new Mayor(Walkot,50,40));

    cout << "\nInput Animal Farmer"<<endl;
    Peternak = inputName();
    this->players.push_back(new AnimalFarmer(Peternak,50,40));

    cout << "\nInput Plant Farmer" <<endl;
    Petani = inputName();
    this->players.push_back(new PlantFarmer(Petani,50,40));
}

string Game::inputName(){
    string name;
    while (true){
        cout << "Enter username: ";
        cout << "\033[1;92m";
        cin >> name;
        cout << "\033[0m";
        try{
            if(!nameNotValid(name)){
                return name;
                break;
            }
        }
        catch(UsernameException e){
            cout<<e.what()<<endl;
        }
    }
}

void Game::inputCommand(){
    string command;
    while (true){
        cout << "\nEnter command > ";
        cout << "\033[1;92m";
        cin >> command;
        cout << "\033[0m";
        try{
            if (!(*players[currPlayer] == command)) {
                throw CommandException();
            }
            if(command=="NEXT"){
                currPlayer+=1;
                break;
            }
        }
        catch(CommandException e){
            cout<<e.what()<<endl;
        }
    }
}

void Game::playerTurn(){
    sortPlayer();
    currPlayer = 0;
    cout << "\nHere are the players turns in this round! "<<endl; // gatau ini tiap round beda-beda apa gimana dah
    for(int i = 0;i<players.size();i++){
        cout << i+1 << ". " <<players[i]->getName()<<endl;;
    }

}

bool Game::nameNotValid(string name){
    bool ada = false; // cari nama udah dipakau atau bukan
    for (auto &p : players){
        if (p->getName() == name){
            ada = true; 
            throw UsernameException();
        }
    }
    return ada;
}


void Game::splashScreen(){
cout << "\033[1;95m";
cout << "   /\\                                                        /\\" << endl;
cout << "  |  |                                                      |  |" << endl;
cout << " /----\\                    Let's Harvest                   /----\\" << endl;
cout << "[______]              In MarhabanTiba Kingdom!            [______]" << endl;
cout << " |    |         _____                        _____         |    |" << endl;
cout << " |[]  |        [     ]                      [     ]        |  []|" << endl;
cout << " |    |       [_______][ ][ ][ ][][ ][ ][ ][_______]       |    |" << endl;
cout << " |    [ ][ ][ ]|     |  ,----------------,  |     |[ ][ ][ ]    |" << endl;
cout << " |             |     |/'    ____..____    '\\|     |             |" << endl;
cout << "  \\  []        |     |    /'    ||    '\\    |     |        []  /" << endl;
cout << "   |      []   |     |   |o     ||     o|   |     |  []       |" << endl;
cout << "   |           |  _  |   |     _||_     |   |  _  |           |" << endl;
cout << "   |   []      | (_) |   |    (_||_)    |   | (_) |       []  |" << endl;
cout << "   |           |     |   |     (||)     |   |     |           |" << endl;
cout << "   |           |     |   |      ||      |   |     |           |" << endl;
cout << " /''           |     |   |o     ||     o|   |     |           ''\\" << endl;
cout << "[_____________[_______]--'------''------'--[_______]_____________]" << endl;
cout << endl;
cout << "\033[0m";
}