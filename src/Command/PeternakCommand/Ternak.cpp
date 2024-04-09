#include "Ternak.hpp"

void Ternak::useCommand(){
    AnimalFarmer* p = dynamic_cast<AnimalFarmer*>(players[currPlayer]);
    p->placeAnimal();
}

string Ternak::getName()
{
    return "TERNAK";
}