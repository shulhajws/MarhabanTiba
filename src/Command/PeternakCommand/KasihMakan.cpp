#include "KasihMakan.hpp"

void KasihMakan::useCommand(){
    AnimalFarmer* p = dynamic_cast<AnimalFarmer*>(players[currPlayer]);
    p->feedAnimal();
}

string KasihMakan::getName()
{
    return "KASIH_MAKAN";
}