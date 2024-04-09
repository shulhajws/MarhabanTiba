#include "CetakLadang.hpp"

void CetakLadang::useCommand(){
    PlantFarmer* p = dynamic_cast<PlantFarmer*>(players[currPlayer]);
    p->printGarden();
}

string CetakLadang::getName(){
    return "CETAK_LADANG";
}