#include "Tax.hpp"

Tax::Tax(int ktkp,int uang, int harta){
    this->ktkp = ktkp;
    this->uang = uang;
    this->harta = harta;
}

int Tax::totalWealth(){
    return uang+harta;
}

int Tax::countKKP(){
    return (totalWealth()-ktkp);
}

double Tax::countTax(){
    int kkp = countKKP();
    if(kkp>0){
        if(kkp<=6){
            return(0.05);
        }
        else if(kkp<=25){
            return(0.15);
        }
        else if(kkp<=50){
            return(0.25);
        }
        else if(kkp<=500){
            return(0.3);
        }
        else{
            return(0.35);
        }
    }
    else{
        return 0;
    }
}

int Tax::getTax(){
    return countTax() * countKKP(); 
}
void Tax::payTax(Player& p1, Player& walkot){
    int Tax = getTax();
    if (uang>=Tax){
        p1.minPlayerWealth(Tax);
    }
    else{
        p1.minPlayerWealth(uang);
        Tax = uang;
    }
    walkot.addPlayerWealth(Tax);
}