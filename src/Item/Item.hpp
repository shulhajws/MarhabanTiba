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
        bool operator==(Item& Item2) const;

        string getCode() const;
        string getName() const;
        string getType() const;
};

#endif