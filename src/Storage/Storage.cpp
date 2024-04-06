#include "Storage.hpp"
#include "../Exception/Exception.hpp"
using namespace std;

template class Storage<Item*>;

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
    if (row >= this->row || col >= this->col || row < 0 || col < 0) {
        cout << "Posisi tidak valid!" << endl;
    } else {
        storageContent[row][col] = content;
    }
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
T Storage<T>::getItemInfo(int row, int col){
    return storageContent[row][col];
}

template<class T>
bool Storage<T>::isItemValid(int row, int col){
    if (row >= this->row || col >= this->col || row < 0 || col < 0) {
        cout << "Posisi tidak valid!" << endl;
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
void Storage<T>::printStorage(){
    cout << "     "; // 5 space in the beginning
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
            if (storageContent[j][m] == NULL) {
                cout << "|     ";
            } else {
                cout << "|     ";
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
int Storage<T>::positionCodetoRow(string position){
    if(position.length()!=3){
        throw ItemNotFoundException();
    }
    char row = position[0];
    return row - 'A';
}

template<class T>
int Storage<T>::positionCodetoCol(string position){
    if(position.length()!=3){
        throw ItemNotFoundException();
    }
    return ((position[1]*10+position[2])-1);
}

// bool operator==(const MyClass& other) const {
//         return value == other.value;
//     }