#include "TakeRisk.hpp"

void TakeRisk::useCommand(){
    if(Game::risk == false){
        Risk r;
        r.getRandomRisk(players[currPlayer]);
        Game::risk = true;
    } else{
        cout<<"You have already taken a risk. You can take another risk in the next round."<<endl;
    }
}

string TakeRisk::getName()
{
    return "RISK";
}