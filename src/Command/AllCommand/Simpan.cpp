#include "Simpan.hpp"

void Simpan::useCommand(){
    string filepath;
    cout << "Berkas state game akan disimpan pada folder 'state'. Masukkan nama file berkas state game: ";
    cin >> filepath;

    Saver save;
    Shop shop;
    save.saveGameState(filepath, players, shop);
}

string Simpan::getName()
{
    return "SIMPAN";
}