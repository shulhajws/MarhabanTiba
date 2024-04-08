#include "Beli.hpp"

void Beli::useCommand(){
    players[currPlayer]->buyItem();
}

string Beli::getName()
{
    return "BELI";
}