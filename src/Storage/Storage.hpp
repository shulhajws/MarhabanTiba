#ifndef _STORAGE_HPP_
#define _STORAGE_HPP_

#include <iostream>
#include <vector> //dynamic array
#include <string>
#include <map> //dictionary pairs
#include "../Item/Animal/Animal.hpp"
#include "../Item/Plant/Plant.hpp"
#include "../Item/Item.hpp"

using namespace std;

template<class T>
class Storage {
    private :
        //player storageOwner;
        int row;
        int col;
        vector<vector<T> > storageContent;
        map<string, T> store;
    public :
        Storage();
        ~Storage();
        void setItem(int row, int col, T content);
        T getItemInfo(int row, int col);
        T getItem(int row, int col);
        bool isItemValid(int row, int col);
        void printStorage();
        bool operator==(const T& other) const;
        int positionCodetoRow(string position);
        int positionCodetoCol(string position);
};

#endif