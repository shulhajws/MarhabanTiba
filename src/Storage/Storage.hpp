#ifndef _STORAGE_HPP_
#define _STORAGE_HPP_

#include <iostream>
#include <vector> //dynamic array
#include <string>
#include <map> //dictionary pairs
#include "../Item/Animal/Animal.hpp"
#include "../Item/Plant/Plant.hpp"
#include "../Item/Item.hpp"
#include "../Exception/Exception.hpp"

using namespace std;

template<class T>
class Storage {
    private :
        int row;
        int col;
        vector<vector<T> > storageContent;
        map<string, T> store;
    public :
        Storage();
        ~Storage();
        void setItem(int row, int col, T content);
        void setItemRandom(T content);
        Storage<T>& operator+(T& content);
        void setRowCols(int row, int cols);
        int getRow() const;
        int getCol() const;
        T getItemInfo(string position);
        T getItemInfoInt(int row, int col);
        T getItem(int row, int col);
        T getItemString(string position);
        bool isItemValid(int row, int col);
        bool isSlotEmpty(int row, int col) const;
        void printStorage(string name, int color);
        void printLegends();
        int positionCodetoRow(string position);
        int positionCodetoCol(string position);
        string rowtoPositionCode(int row);
        string coltoPositionCode(int col);
        int getAvailableSlots();
        int countItems(string item);
        int countItemsHarvested(string item);
        int getTotalAssets();
        bool isReadytoHarvest();
        void deleteItemCount (string item,int count);
        vector<string> printHarvestedItem();
        bool isEmpty() const;
        bool isFull() const;
        bool hasItem(const T& type) const;
        int countFilledCells() const;
        vector<T> getListOfContents() const;
        bool noAnimalInStorage() const;
        bool noPlantInStorage() const;
        bool noFoodInStorage() const;
        bool onlyAnimalProd() const;
        bool onlyFruitProd() const ;
        void printmap(string position);
};

#endif