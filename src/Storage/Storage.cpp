#include "Storage.hpp"
#include "../Exception/Exception.hpp"
using namespace std;

Storage::Storage(){
    row = 5;
    col = 10;
    vector<int> v(col);
    vector<vector<int> > storageContent(row, v);
    this->storageContent = storageContent;
}

Storage::~Storage(){}

void Storage::setItem(int row, int col, int content){
    if (row >= this->row || col >= this->col || row < 0 || col < 0) {
        cout << "Posisi tidak valid!" << endl;
    } else {
        storageContent[row][col] = content;
    }
}

int Storage::getItemInfo(int row, int col){
    if (row >= this->row || col >= this->col || row < 0 || col < 0) {
        cout << "Posisi tidak valid!" << endl;
        return -1;
    } else {
        return storageContent[row][col];
    }
}

int Storage::getItem(int row, int col){
    if (row >= this->row || col >= this->col || row < 0 || col < 0) {
        cout << "Posisi tidak valid!" << endl;

        return -1;
    } else {
        int deletedValue = storageContent[row][col];
        storageContent[row].erase(storageContent[row].begin() + col);

        return deletedValue;
    }
}

void Storage::printStorage(){
    cout << "     "; // 5 space in the beginning
    for(int i = 0; i < col; i++){
        cout << "   " << static_cast<char>(65 + i) << "  ";
    }
    cout << " " << endl;
    
    for(int j = 0; j < row; j++){
        cout << "     "; // 5 space in the beginning
        for(int i = 0; i < col; i++){
            cout << "+-----";
        }
        cout << "+" << endl;

        int indexing = static_cast<int>(49 + j) - '0';
        if (indexing < 10) {
            cout << "  0" << indexing << " ";
        }

        if (storageContent[row][col] == NULL) {
            for(int i = 0; i < col; i++){
                cout << "|     ";
            }
        } else {
            // print kode
        }
        cout << "|" << endl;
    }

    cout << "     "; // 5 space in the beginning
    for(int i = 0; i < col; i++){
        cout << "+-----";
    }
    cout << "+" << endl;
}