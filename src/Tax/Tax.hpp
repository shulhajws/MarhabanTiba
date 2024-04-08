#ifndef __TAX_HPP__
#define __TAX_HPP__

#include "../Player/Player.hpp"

class Tax{
    protected:
        int ktkp;
        int uang;
        int harta; // menunggu storage
    public:
        Tax (int ktkp,int uang, int harta);
        int totalWealth();
        int countKKP();
        double countTax();
        int getTax();
        void payTax(Player& p,Player& walkot);
};

#endif