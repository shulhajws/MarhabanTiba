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
    public:
        Item(string code, string name, string type);
        Item(int id, string code, string name, string type);
        virtual ~Item();
        friend bool operator==(const Item& Item1, const Item& Item2);
        // Method to get the name of the item
        string getName() const;
        // Method to get the type of the item
        string getType() const;
};

#endif