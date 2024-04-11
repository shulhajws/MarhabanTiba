#include "Game.hpp"
#include "../Player/Player.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

int Game::currPlayer;
int Game::tambahPemain = 0;
vector<Player*> Game::players;

void Game::startGame(){
    splashScreen();
    initiation();
    askInput();
    bool endGame = false;
    playerTurn();
    while(!endGame){
        cout << "\nIt's "<<players[currPlayer]->getName()<<"'s turn to play"<<endl;
        endGame = inputCommand();
        sortPlayer();
    }
}

void Game::askInput(){
    bool input = false;
    string option;

    while (!input) {
        try {
            cout << "How do you want to start the game?" << endl;
            cout << "  1. By file input" << endl;
            cout << "  2. Default" << endl;
            cout << "Choose your option: ";
            cout << "\033[1;92m";
            cin >> option;
            cout << "\033[0m";

            if (option != "1" && option != "2") {
                throw InputException();
            } else {
                input = true;
            }
        }
        catch (InputException e) {
            cout<<e.what()<<endl;
        }
    }

    if (option == "1"){ // file input
        int ctr;
        string state;
        cout<<"Enter file location of the state (nameoffile.txt): ";
        cin>>state;
        Loader l;
        l.stateOfPlayer(state,&ctr);
        l.stateOfShop(state,ctr);
    }
    else{ // default input
        inputPlayer();
    }
}

void Game::initiation(){
    Loader load;
    load.configOfAnimal();
    load.configOfPlant();
    load.configOfMisc();
    load.configOfProduct();
    load.configOfBuildingRecipes();
}

void Game::sortPlayer() {
    sort(players.begin(), players.end(), [this](Player* a, Player* b) {
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

bool Game::inputCommand(){
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
            if(checkEndGame()){
                return true;
            }
            if(command=="NEXT"){
               if (currPlayer==players.size()-1){
                    currPlayer = 0;
                }
                else{
                    if(tambahPemain>0){
                        cout<<tambahPemain<<endl;
                        currPlayer += Game::tambahPemain;
                    }
                    currPlayer +=1;
                    Game::tambahPemain = 0;
                }
                break;
            }
        }
        catch(CommandException e){
            cout<<e.what()<<endl;
        }
    }
    return false;
}

void Game::playerTurn(){
    sortPlayer();
    currPlayer = 0;
    cout << "\nHere are the players turns in this round! "<<endl; 
    for(int i = 0;i<players.size();i++){
        cout << i+1 << ". " <<players[i]->getName()<<endl;;
    }

}

bool Game::nameNotValid(string name){
    bool ada = false; // cari nama udah dipakau atau bukan
    for (auto &p : players){
        if (lowerCase(p->getName()) == lowerCase(name)){
            ada = true; 
            throw UsernameException();
        }
    }
    return ada;
}

bool Game::checkEndGame(){
    Misc m;
    if(players[currPlayer]->getPlayerWealth()>=m.getminMoney() && players[currPlayer]->getPlayerWeight()>=m.getminWeight()){
        cout<<"\033[1;33m\n                                    __              \033[0m"<<endl; 
        cout<<"\033[1;33m.----.-----.-----.-----.----.---.-.|  |_.-----.-----.\033[0m"<<endl;
        cout<<"\033[1;33m|  __|  _  |     |  _  |   _|  _  ||   _|-- __|-- __|\033[0m"<<endl;
        cout<<"\033[1;33m|____|_____|__|__|___  |__| |___._||____|_____|_____|\033[0m"<<endl;
        cout<<"\033[1;33m                 |_____|                             \033[0m"<<endl;  

        cout<<"\033[1;33m\n░░░░░░░░░░░░░░░░░░░░░░█████████\033[0m"<<endl;
        cout<<"\033[1;33m░░███████░░░░░░░░░░███▒▒▒▒▒▒▒▒███\033[0m"<<endl;
        cout<<"\033[1;33m░░█▒▒▒▒▒▒█░░░░░░░███▒▒▒▒▒▒▒▒▒▒▒▒▒███\033[0m"<<endl;
        cout<<"\033[1;33m░░░█▒▒▒▒▒▒█░░░░██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██\033[0m"<<endl;
        cout<<"\033[1;33m░░░░█▒▒▒▒▒█░░░██▒▒▒▒▒██▒▒▒▒▒▒██▒▒▒▒▒███\033[0m"<<endl;
        cout<<"\033[1;33m░░░░░█▒▒▒█░░░█▒▒▒▒▒▒████▒▒▒▒████▒▒▒▒▒▒██\033[0m"<<endl;
        cout<<"\033[1;33m░░░█████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██\033[0m"<<endl;
        cout<<"\033[1;33m░░░█▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒██\033[0m"<<endl;
        cout<<"\033[1;33m░██▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒██▒▒▒▒▒▒▒▒▒▒██▒▒▒▒██\033[0m"<<endl;
        cout<<"\033[1;33m██▒▒▒███████████▒▒▒▒▒██▒▒▒▒▒▒▒▒██▒▒▒▒▒██\033[0m"<<endl;
        cout<<"\033[1;33m█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒████████▒▒▒▒▒▒▒██\033[0m"<<endl;
        cout<<"\033[1;33m██▒▒▒▒▒▒▒▒▒▒▒▒▒▒█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██\033[0m"<<endl;
        cout<<"\033[1;33m░█▒▒▒███████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒██\033[0m"<<endl;
        cout<<"\033[1;33m░██▒▒▒▒▒▒▒▒▒▒████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒█\033[0m"<<endl;
        cout<<"\033[1;33m░░████████████░░░█████████████████\033[0m"<<endl;
        cout<<"\nCongratulations "<<players[currPlayer]->getName()<<", you win the game!"<<endl;
        cout<<"KEREN ABIEZZ!!"<<endl;
        return true;
    }
    return false;
}

string Game::lowerCase(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

Game::~Game(){
    for (auto player : players) {
        delete player;
    }
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