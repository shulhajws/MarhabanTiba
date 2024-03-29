#ifndef __Animal_HPP__
#define __Animal_HPP__

#include <string>
using namespace std;

class Animal{
    protected:
        static int id;
        string code;
        string name;
        string type;
        int harvest_weight;
        int price;
        int berat_hewan;
    public:
        Animal(string kode, string nama, string tipe, int berat_panen, int harga);
        virtual void makan()=0;
        bool isHarvestable();
};

#endif