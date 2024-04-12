#ifndef __ITEM_HPP__
#define __ITEM_HPP__

#include <string>
using namespace std;

class Item{
    protected:
        int id;
        string code;
        string name;
        string type;
        int price;
    public:
        Item();
        Item(string code, string name, string type);
        Item(int id, string code, string name, string type, int price);
        virtual ~Item();
        bool operator==(Item& Item2) const;
        bool isReadyToHarvest();
        int getPrice() const;
        string getCode() const;
        string getName() const;
        string getType() const;
};

#endif