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

        string getCode() const;
        string getName() const;
        string getType() const;
};

#endif