#include "PungutPajak.hpp"
#include <algorithm>

void PungutPajak::useCommand(){
    cout<<"\033[1;96mThe mayor is going to take all of the player's tax!\033[0m"<<endl;
    cout<<"\033[1;96mHere is the detail: \033[0m"<<endl;

    vector<pair<Player*, int>> playerTaxes;
    
    int i = 0;
    int total = 0;
    for (auto &p : players){
        if (p->getType()!="Walikota"){
            i++;
            Tax t(p->getKTKP(),p->getPlayerWealth(),p->getPlayerAssets()); 
            playerTaxes.emplace_back(p, p->calculateTax());
            total+= t.getTax();
            t.payTax(*p,*players[currPlayer]);
        }
    }

    sort(playerTaxes.begin(), playerTaxes.end(), [](const auto &a, const auto &b) {
        if (a.second != b.second) {
            return a.second > b.second; 
        } else {
            return a.first->getName() < b.first->getName(); 
        }
    });

    if (i==0){
        cout<<"\033[1;96mNo details found.\033[0m"<<endl;
    } else{
        i = 1;
        for (auto player : playerTaxes) {
            cout << i << ". " << player.first->getName() << " - " << player.first->getType() << " : " << player.second << " gulden." << endl;
            i++;
        }
        cout<<"\033[1;96mThe kingdom receives an income of "<<total<<" guilders.\033[0m"<<endl;
        cout<<"\033[1;96mUse it wisely and don't corrupt it!\033[0m"<<endl;
    }

}

string PungutPajak::getName()
{
    return "PUNGUT_PAJAK";
}