#include "Simpan.hpp"

void Simpan::useCommand(){
    string filepath;
    cout<< "Format: './folder/filename.txt'"<<endl;
    cout<< "Please enter the location to save the game state file: ";
    cin >> filepath;

    Saver save;
    Shop shop;
    save.saveGameState(filepath, players, shop);
}

string Simpan::getName()
{
    return "SIMPAN";
}