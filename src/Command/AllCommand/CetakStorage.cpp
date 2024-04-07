#include "CetakStorage.hpp"

void CetakStorage::useCommand(){
    players[currPlayer]->displayStorage();
}

string CetakStorage::getName(){
    return "CETAK_PENYIMPANAN";
}