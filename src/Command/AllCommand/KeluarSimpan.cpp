#include "KeluarSimpan.hpp"
#include <cstdlib>
#include <chrono>   
#include <thread>   

using namespace this_thread;
using namespace chrono;

void KeluarSimpan::useCommand(){
    string filepath;
    cout << "Format: './folder/filename.txt'" << endl;
    cout << "Please enter the location to save the game state file: ";
    cin >> filepath;

    Saver save;
    Shop shop;
    save.saveGameState(filepath, players, shop);

    cout << "Saving game state at " << filepath << endl;
    cout << "3..." << endl;
    sleep_for(seconds(1));  // Pause for 1 second
    cout << "2..." << endl;
    sleep_for(seconds(1));  // Pause for 1 second
    cout << "1..." << endl;
    sleep_for(seconds(1));  // Pause for 1 second

    cout << "Game state succesfully saved!\n" << "Thanks for playing and don't forget to continue your journey!"<< endl;
    exit(0);
}

string KeluarSimpan::getName()
{
    return "KELUAR_DAN_SIMPAN";
}