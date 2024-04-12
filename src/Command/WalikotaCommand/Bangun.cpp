#include "Bangun.hpp"

void Bangun::useCommand(){
    Mayor* p = dynamic_cast<Mayor*>(players[currPlayer]);
    p->buildBuilding();
}

string Bangun::getName()
{
    return "BANGUN";
}