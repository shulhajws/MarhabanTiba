#ifndef BUILDING_HPP
#define BUILDING_HPP

#include "../Item.hpp"
#include <map>
#include <string>
#include <iostream>
using namespace std;

class Building : public Item {
    public:
        Building(int id, string code, string name, string type);
        ~Building();
        int calculatePrice();
};

class SmallHouse : public Building {
    private:
        static int price;
        static map<string, int> materials;

    public:
        SmallHouse();
        SmallHouse(int price);
        void addRecipeMaterial(string materialName, int materialQty);
};

class MediumHouse : public Building {
    private:
        static int price;
        static map<string, int> materials;

    public:
        MediumHouse();
        MediumHouse(int price);
        void addRecipeMaterial(string materialName, int materialQty);
};

class LargeHouse : public Building {
    private:
        static int price;
        static map<string, int> materials;

    public:
        LargeHouse();
        LargeHouse(int price);
        void addRecipeMaterial(string materialName, int materialQty);
};

class Hotel : public Building {
    private:
        static int price;
        static map<string, int> materials;

    public:
        Hotel();
        Hotel(int price);
        void addRecipeMaterial(string materialName, int materialQty);
};

#endif 
