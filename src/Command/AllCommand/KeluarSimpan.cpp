#include "KeluarSimpan.hpp"

void KeluarSimpan::useCommand(){
    string filepath;
    cout<< "Format: './folder/filename.txt'"<<endl;
    cout<< "Please enter the location to save the game state file: ";
    cin >> filepath;

    Saver save;
    Shop shop;
    save.saveGameState(filepath, players, shop);

    cout<< "Saving the game state at " << filepath << endl;
    sleep(1);
    cout<< "3..." << endl;
    sleep(1);
    cout<< "2..." << endl;
    sleep(1);
    cout<< "1..." << endl;
    sleep(1);
    cout<< "Game state saved!" << endl;
    cout<< "Thank you for playing! Don't forget to continue your journey!" << endl;
    exit(0);
}

string KeluarSimpan::getName()
{
    return "KELUAR_SIMPAN";
}