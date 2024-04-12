#ifndef BUILDING_HPP
#define BUILDING_HPP

#include "../Item.hpp"
#include <map>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Building : public Item {
    private:
        int price;
        map<string, int> materials;
        vector<Building*> houses;
    public:
        Building();
        Building(int id, string code, string name, string type, int price);
        ~Building();
        int getMoney(string s);
        virtual void printMaterial();
        virtual map<string, int> getmaterial(string b);
};

class SmallHouse : public Building {
    private:
        static int price;
        static map<string, int> materials;

    public:
        SmallHouse();
        SmallHouse(int price);
        map<string, int> getmaterial(string b);
        void printMaterial();
        void addRecipeMaterial(string materialName, int materialQty);
};

class MediumHouse : public Building {
    private:
        static int price;
        static map<string, int> materials;

    public:
        MediumHouse();
        MediumHouse(int price);
        map<string, int> getmaterial(string b);
        void printMaterial();
        void addRecipeMaterial(string materialName, int materialQty);
};

class LargeHouse : public Building {
    private:
        static int price;
        static map<string, int> materials;

    public:
        LargeHouse();
        LargeHouse(int price);
        map<string, int> getmaterial(string b);
        void printMaterial();
        void addRecipeMaterial(string materialName, int materialQty);
};

class Hotel : public Building {
    private:
        static int price;
        static map<string, int> materials;

    public:
        Hotel();
        Hotel(int price);
        map<string, int> getmaterial(string b);
        void printMaterial();
        void addRecipeMaterial(string materialName, int materialQty);
};

#endif 
