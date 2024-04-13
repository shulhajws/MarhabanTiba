#include "Simpan.hpp"

void Simpan::useCommand(){
    string filepath;
    cout<< "Game state file will be saved in the 'state' folder. Please enter the filename for the game state file: ";
    cin >> filepath;

    Saver save;
    Shop shop;
    save.saveGameState(filepath, players, shop);
}

string Simpan::getName()
{
    return "SIMPAN";
}