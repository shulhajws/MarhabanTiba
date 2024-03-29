#ifndef __HERBIVORe_HPP__
#define __HERBIVORe_HPP__

#include "Animal.hpp"

class Herbivore : Animal{
    public:
        Herbivore(string kode, string nama,int berat_hewan,int price);
        /// harusnya ada kelas produk 
        void makan(string makanan);
};

class Cow : Herbivore{
    public:
        Cow(int berat_panen, int price);

};

class Sheep : Herbivore{
    public:
        Sheep(int berat_panen, int price);
};

class Horse : Herbivore{
    public:
        Horse(int berat_panen, int price);
};

class Rabbit : Herbivore{
    public:
        Rabbit(int berat_panen, int price);
};

#endif