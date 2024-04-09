#include "Storage.hpp"
#include "../Exception/Exception.hpp"
#include "../Item/Animal/Animal.hpp"
#include "../Item/Plant/Plant.hpp"
#include "../Item/Products/Products.hpp"
#include "../Item/Building/Building.hpp"
#include "../Item/Item.hpp"
using namespace std;

template class Storage<Item*>;
template class Storage<Plant*>;
template class Storage<Animal*>;

template<class T>
Storage<T>::Storage(){
    row = 5;
    col = 10;
    vector<T> v(col);
    vector<vector<T> > storageContent(row, v);
    this->storageContent = storageContent;
}

template<class T>
Storage<T>::~Storage(){}

template<class T>
void Storage<T>::setItem(int row, int col, T content){
    if (row >= this->row || col >= this->col || row < 0 || col < 0 || !isSlotEmpty(row,col)) {
        throw InvalidSlotException();
    } else {
        storageContent[row][col] = content;
    }
}

template<class T>
void Storage<T>::setItemRandom(T content){
    int rowPosition = 0 + (rand() % row);
    int colPosition = 0 + (rand() % col);
    storageContent[rowPosition][colPosition] = content;
}

template<class T>
void Storage<T>::setRowCols(int row, int col){
    this->row = row;
    this->col = col;
    this->storageContent.clear();
    vector<T> v(col);
    vector<vector<T> > storageContent(row, v);
    this->storageContent = storageContent;
}

template<class T>
int Storage<T>::getRow() const {
    return row;
}

template<class T>
int Storage<T>::getCol() const {
    return col;
}

template<class T>
T Storage<T>::getItemInfo(int row, int col){
    return storageContent[row][col];
}

template<class T>
bool Storage<T>::isItemValid(int row, int col){
    if (row >= this->row || col >= this->col || row < 0 || col < 0) {
        return false;
    } 
    else{
        return true;
    }
}

template<class T>
bool Storage<T>::isSlotEmpty(int row, int col){
    if (storageContent[row][col]!=nullptr) {
        return false;
    } 
    else{
        return true;
    }
}

template<class T>
T Storage<T>::getItem(int row, int col){
    if(isItemValid(row,col)&&storageContent[row][col]!=NULL){
        T deletedValue = storageContent[row][col];
        storageContent[row].erase(storageContent[row].begin() + col);
        return deletedValue;
    }
    else{
        throw ItemNotFoundException();
    }
}

template<class T>
bool Storage<T>::isEmpty() const {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (storageContent[i][j] != nullptr) {
                return false; 
            }
        }
    }
    return true;
}

template<class T>
bool Storage<T>::isFull() const {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (storageContent[i][j] == nullptr) {
                return false; 
            }
        }
    }
    return true; 
}

template<class T>
bool Storage<T>::hasItem(const T& type) const{
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (storageContent[i][j] != nullptr && storageContent[i][j] == type) {
                return true; // Item ditemukan
            }
        }
    }
    return false; 
}

template<class T>
void Storage<T>::printStorage(string name){
    cout << "      "; // 5 space in the beginning
    int len = 6*col - name.length() -4;
    for(int i = 0; i < len/2; i++){
        cout << "=";
    }
    cout << "[ "<<name<<" ]";

    for(int i = 0; i < len/2; i++){
        cout << "=";
    }

    cout << "\n     "; // 5 space in the beginning
    for(int i = 0; i < col; i++){
        cout << "   " << static_cast<char>(65 + i) << "  ";
    }
    cout << " " << endl;

    for(int j = 0; j < row; j++){
        cout << "     "; // 5 space in the beginning
        for(int k = 0; k < col; k++){
            cout << "+-----";
        }
        cout << "+" << endl;

        int indexing = static_cast<int>(49 + j) - 48;
        if (indexing > 0  && indexing < 10) {
            cout << "  0" << indexing << " ";
        } else if (indexing >= 10){
            cout << "  " << indexing << " ";
        }

        for (int m = 0; m < col; m++) {
            if (storageContent[j][m] == nullptr) {
            cout << "|     ";
            } else {
                cout << "| "<< storageContent[j][m]->getCode()<<" ";
            }
        }

        cout << "|" << endl;
    }

    cout << "     "; // 5 space in the beginning
    for(int i = 0; i < col; i++){
        cout << "+-----";
    }
    cout << "+" << endl;
}

template<class T>
bool Storage<T>::operator==(const T& other) const{
    return true;
}

template<class T>
int Storage<T>::getAvailableSlots(){
    int num = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (storageContent[i][j] == nullptr) {
                num+=1; 
            }
        }
    }
    return num;
}

template<class T>
int Storage<T>::positionCodetoRow(string position){
    if(position.length()!=3){
        throw ItemNotFoundException();
    }
    int x1 = position[1] - '0';
    int x2 = position[2] - '0';
    return (x1*10+x2-1);
}

template<class T>
int Storage<T>::positionCodetoCol(string position){
    if(position.length()!=3){
        throw ItemNotFoundException();
    }
    char row = position[0];
    return row - 'A';
}