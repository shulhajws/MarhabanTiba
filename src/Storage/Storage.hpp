#ifndef _GRIDSTORAGE_HPP_
#define _GRIDSTORAGE_HPP_

#include <iostream>
#include <vector> //dynamic array
#include <string>
#include <map> //dictionary pairs

using namespace std;

// template<class T>
class Storage {
    private :
        //player storageOwner;
        int row;
        int col;
        vector<vector<int> > storageContent;
        map<string, int> store;
    public :
        Storage();
        ~Storage();
        void setItem(int row, int col, int content);
        int getItemInfo(int row, int col);
        int getItem(int row, int col);
        void printStorage();
};

#endif