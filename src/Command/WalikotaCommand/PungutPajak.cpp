#include "PungutPajak.hpp"

void PungutPajak::useCommand(){
    cout<<"\033[1;96mThe mayor is going to take all of the player's tax!\033[0m"<<endl;
    cout<<"\033[1;96mHere is the detail: \033[0m"<<endl;
    int i = 0;
    int total = 0;
    for (auto &p : players){
        if (p->getType()!="Walikota"){
            i++;
            Tax t(p->getKTKP(),p->getPlayerWealth(),0); // harta masih 0 sementara
            cout<<i<<". "<<p->getName()<<" - "<<p->getType()<<" : "<<t.getTax()<<" gulden."<<endl;
            total+= t.getTax();
            t.payTax(*p,*players[currPlayer]);
        }
    }

    if (i==0){
        cout<<"\033[1;96mNo details found.\033[0m"<<endl;
    }

    cout<<"\033[1;96mThe kingdom receives an income of "<<total<<" guilders.\033[0m"<<endl;
    cout<<"\033[1;96mUse it wisely and don't corrupt it!\033[0m"<<endl;
}

string PungutPajak::getName()
{
    return "PUNGUT_PAJAK";
}