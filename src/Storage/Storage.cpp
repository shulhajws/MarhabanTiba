#include "Storage.hpp"
#include "../Exception/Exception.hpp"
#include "../Item/Animal/Animal.hpp"
#include "../Item/Plant/Plant.hpp"
#include "../Item/Product/Product.hpp"
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
Storage<T>& Storage<T>::operator+(T& content){
    bool done = false;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (storageContent[i][j] == nullptr) {
                if(!done){
                    storageContent[i][j] = content;
                }
                done = true;
                break;
            }
            if(done){
                break;
            }
        }
    }
    return *this;
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
bool Storage<T>::isSlotEmpty(int row, int col) const{
    if (storageContent[row][col]!=nullptr) {
        return false;
    } 
    else{
        return true;
    }
}

template<class T>
T Storage<T>::getItem(int row, int col){
    if(isItemValid(row,col)){
        if(storageContent[row][col]!=NULL){
        T deletedValue = storageContent[row][col];
        storageContent[row][col] = nullptr;
        return deletedValue;
        }
    }
    else{
        throw ItemNotFoundException();
    }
    return nullptr;
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
void Storage<T>::printStorage(string name, int color){ // 1: print w/color 2: print w/o color
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
                if(color==1){
                    if(storageContent[j][m]->isReadyToHarvest()){
                        cout << "| \033[1;92m"<< storageContent[j][m]->getCode()<<"\033[0m ";
                    }
                    else{
                        cout << "| \033[1;31m"<< storageContent[j][m]->getCode()<<"\033[0m ";
                    }
                }else{
                    cout << "| "<< storageContent[j][m]->getCode()<<" ";
                }
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
void Storage<T>::printLegends(){
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (storageContent[i][j] != nullptr) {
                cout<<"     - "<<coltoPositionCode(j)<<rowtoPositionCode(i)<<": "<<storageContent[i][j]->getName()<<endl;
            }
        }
    }
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
int Storage<T>::getTotalAssets(){
    int num = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if(storageContent[i][j]!=nullptr){
                num+=storageContent[i][j]->getPrice();
            }
        }
    }
    return num;
}

template<class T>
int Storage<T>::countItems(string item){
    int num = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if(storageContent[i][j]!=nullptr){
                if (storageContent[i][j]->getName() == item) {
                    num+=1; 
                }
            }
        }
    }
    return num;
}

template<class T>
int Storage<T>::countItemsHarvested(string item){
    int num = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if(storageContent[i][j]!=nullptr){
                if (storageContent[i][j]->getCode() == item && storageContent[i][j]->isReadyToHarvest()) {
                    num+=1; 
                }
            }
        }
    }
    return num;
}

template<class T>
void Storage<T>::deleteItemCount(string item,int count){
    int num = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if(storageContent[i][j]!=nullptr){
                if (storageContent[i][j]->getName() == item) {
                    storageContent[row][col] = nullptr;
                    num+=1; 
                }
            }
            if(count==num){
                break;
            }
        }
    }
}

template<class T>
bool Storage<T>::isReadytoHarvest(){
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if(storageContent[i][j]!=nullptr){
                if (storageContent[i][j]->isReadyToHarvest()) {
                    return true; 
                }
            }
        }
    }
    return false;
}

template<class T>
vector<string> Storage<T>::printHarvestedItem(){ 
    vector<string> items;
    int i = 1;
    if(countItemsHarvested("COW")>0){
        cout<<i<<". COW ("<< countItemsHarvested("COW")<<"  plots ready for harvest)"<<endl;
        i++;
        items.push_back("COW");
    }
    if(countItemsHarvested("SHP")>0){
        cout<<i<<". SHP ("<< countItemsHarvested("SHP")<<"  plots ready for harvest)"<<endl;
        i++;
        items.push_back("SHP");
    }
    if(countItemsHarvested("HRS")>0){
        cout<<i<<". HRS ("<< countItemsHarvested("HRS")<<"  plots ready for harvest)"<<endl;
        i++;
        items.push_back("HRS");
    }
    if(countItemsHarvested("RBT")>0){
        cout<<i<<". RBT ("<< countItemsHarvested("RBT")<<"  plots ready for harvest)"<<endl;
        i++;
        items.push_back("RBT");
    }
    if(countItemsHarvested("CHK")>0){
        cout<<i<<". CHK ("<< countItemsHarvested("CHK")<<"  plots ready for harvest)"<<endl;
        i++;
        items.push_back("CHK");
    }
    if(countItemsHarvested("DCK")>0){
        cout<<i<<". DCK ("<< countItemsHarvested("DCK")<<"  plots ready for harvest)"<<endl;
        i++;
        items.push_back("DCK");
    }

    i = 1;
    if(countItemsHarvested("TEK")>0){
        cout<<i<<". TEK ("<< countItemsHarvested("TEK")<<"  plots ready for harvest)"<<endl;
        i++;
        items.push_back("TEK");
    }
    if(countItemsHarvested("SDT")>0){
        cout<<i<<". SDT ("<< countItemsHarvested("SDT")<<"  plots ready for harvest)"<<endl;
        i++;
        items.push_back("SDT");
    }
    if(countItemsHarvested("ALT")>0){
        cout<<i<<". ALT ("<< countItemsHarvested("ALT")<<"  plots ready for harvest)"<<endl;
        i++;
        items.push_back("ALT");
    }
    if(countItemsHarvested("IRN")>0){
        cout<<i<<". IRN ("<< countItemsHarvested("IRN")<<"  plots ready for harvest)"<<endl;
        i++;
        items.push_back("IRN");
    }
    if(countItemsHarvested("APL")>0){
        cout<<i<<". APL ("<< countItemsHarvested("APL")<<"  plots ready for harvest)"<<endl;
        i++;
        items.push_back("APL");
    }
    if(countItemsHarvested("ORG")>0){
        cout<<i<<". ORG ("<< countItemsHarvested("ORG")<<"  plots ready for harvest)"<<endl;
        i++;
        items.push_back("ORG");
    }
    if(countItemsHarvested("BNT")>0){
        cout<<i<<". BNT ("<< countItemsHarvested("BNT")<<"  plots ready for harvest)"<<endl;
        i++;
        items.push_back("BNT");
    }
    if(countItemsHarvested("GAV")>0){
        cout<<i<<". GAV ("<< countItemsHarvested("BNT")<<"  plots ready for harvest)"<<endl;
        i++;
        items.push_back("GAV ");
    }
    return items;
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

template<class T>
string Storage<T>::rowtoPositionCode(int row){
    string position;
    if (row < 9) {
        position = "0" + to_string(row + 1);
    } else {
        position = to_string(row + 1);
    }
    return position;
}

template<class T>
string Storage<T>::coltoPositionCode(int col){
    return string(1, static_cast<char>('A' + col));
}

template<class T>
int Storage<T>::countFilledCells() const{
    int count = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (!isSlotEmpty(i, j)) {
                count++;
            }
        }
    }
    return count;
}

template<class T>
vector<T> Storage<T>::getListOfContents() const{
    vector<T> allItems;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (!isSlotEmpty(i, j)) {
                allItems.push_back(storageContent[i][j]);
            }
        }
    }
    return allItems;
}   