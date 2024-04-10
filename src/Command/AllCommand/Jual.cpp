#include "Jual.hpp"

void Jual::useCommand(){
    players[currPlayer]->sellItem();
}

string Jual::getName()
{
    return "JUAL";
}