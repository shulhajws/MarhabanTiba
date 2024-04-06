#include "Makan.hpp"

void Makan::useCommand(){;
    players[currPlayer]->displayStorage();
    players[currPlayer]->eat();
}

string Makan::getName()
{
    return "MAKAN";
}