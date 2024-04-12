#include "CetakPeternakan.hpp"

void CetakPeternakan::useCommand(){
    AnimalFarmer* p = dynamic_cast<AnimalFarmer*>(players[currPlayer]);
    p->printBarn();
}

string CetakPeternakan::getName(){
    return "CETAK_PETERNAKAN";
}