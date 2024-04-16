#include "Beli.hpp"

void Beli::useCommand(){
    if (players[currPlayer]->getPlayerWealth() > 2){
        players[currPlayer]->buyItem();
    } else {
        cout << "Your current money is " << players[currPlayer]->getPlayerWealth() << " gulden.\033[1;31m\nGo make that money, then you can splurge on whatever you want.\033[0m" << endl;
    }
}

string Beli::getName()
{
    return "BELI";
}


