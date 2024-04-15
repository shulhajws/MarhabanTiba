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
    map<string, T> store;
    this->store = store;
}

template<class T>
Storage<T>::~Storage(){}

template<class T>
void Storage<T>::setItem(int row, int col, T content){
    if (row >= this->row || col >= this->col || row < 0 || col < 0 || !isSlotEmpty(row,col)) {
        throw InvalidSlotException();
    } else {
        string position = coltoPositionCode(col) + rowtoPositionCode(row);
        storageContent[row][col] = content;
        store[position] = storageContent[row][col];
    }
}

template<class T>
void Storage<T>::setItemRandom(T content){
    int rowPosition = 0 + (rand() % (row - 1));
    int colPosition = 0 + (rand() % (col - 1));
    string position = coltoPositionCode(colPosition) + rowtoPositionCode(rowPosition);
    storageContent[rowPosition][colPosition] = content;
    store[position] = storageContent[rowPosition][colPosition];
}

template<class T>
Storage<T>& Storage<T>::operator+(T& content){
    bool done = false;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (storageContent[i][j] == nullptr) {
                if(!done){
                    string position = coltoPositionCode(j) + rowtoPositionCode(i);
                    storageContent[i][j] = content;
                    store[position] = storageContent[i][j];
                }
                done = true;
                break;
            }
        }
        if(done){
            break;
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
T Storage<T>::getItemInfo(string position){
    return store[position];
}

template<class T>
T Storage<T>::getItemInfoInt(int row, int col){
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
T Storage<T>::getItemString(string position){
    int rowPosition = positionCodetoRow(position);
    int colPosition = positionCodetoCol(position);
    if(isItemValid(rowPosition ,colPosition)&&storageContent[rowPosition][colPosition]!=NULL){
        T deletedValue = storageContent[rowPosition][colPosition];
        storageContent[rowPosition][colPosition] = nullptr;
        store.erase(position); 
        return deletedValue;
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
    cout << endl;
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
                if (storageContent[i][j]->getName() == item && storageContent[i][j]->isReadyToHarvest()) {
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
    if(countItemsHarvested("SHEEP")>0){
        cout<<i<<". SHP ("<< countItemsHarvested("SHEEP")<<"  plots ready for harvest)"<<endl;
        i++;
        items.push_back("SHEEP");
    }
    if(countItemsHarvested("HORSE")>0){
        cout<<i<<". HRS ("<< countItemsHarvested("HORSE")<<"  plots ready for harvest)"<<endl;
        i++;
        items.push_back("HORSE");
    }
    if(countItemsHarvested("RABBIT")>0){
        cout<<i<<". RBT ("<< countItemsHarvested("RABBIT")<<"  plots ready for harvest)"<<endl;
        i++;
        items.push_back("RABBIT");
    }
    if(countItemsHarvested("CHICKEN")>0){
        cout<<i<<". CHK ("<< countItemsHarvested("CHICKEN")<<"  plots ready for harvest)"<<endl;
        i++;
        items.push_back("CHICKEN");
    }
    if(countItemsHarvested("DUCK")>0){
        cout<<i<<". DCK ("<< countItemsHarvested("DUCK")<<"  plots ready for harvest)"<<endl;
        i++;
        items.push_back("DUCK");
    }

    i = 1;
    if(countItemsHarvested("TEAK_TREE")>0){
        cout<<i<<". TEK ("<< countItemsHarvested("TEAK_TREE")<<"  plots ready for harvest)"<<endl;
        i++;
        items.push_back("TEAK_TREE");
    }
    if(countItemsHarvested("SANDALWOOD_TREE")>0){
        cout<<i<<". SDT ("<< countItemsHarvested("SANDALWOOD_TREE")<<"  plots ready for harvest)"<<endl;
        i++;
        items.push_back("SANDALWOOD_TREE");
    }
    if(countItemsHarvested("ALOE_TREE")>0){
        cout<<i<<". ALT ("<< countItemsHarvested("ALOE_TREE")<<"  plots ready for harvest)"<<endl;
        i++;
        items.push_back("ALOE_TREE");
    }
    if(countItemsHarvested("IRONWOOD_TREE")>0){
        cout<<i<<". IRN ("<< countItemsHarvested("IRONWOOD_TREE")<<"  plots ready for harvest)"<<endl;
        i++;
        items.push_back("IRONWOOD_TREE");
    }
    if(countItemsHarvested("APPLE_TREE")>0){
        cout<<i<<". APL ("<< countItemsHarvested("APPLE_TREE")<<"  plots ready for harvest)"<<endl;
        i++;
        items.push_back("APPLE_TREE");
    }
    if(countItemsHarvested("ORANGE_TREE")>0){
        cout<<i<<". ORG ("<< countItemsHarvested("ORANGE_TREE")<<"  plots ready for harvest)"<<endl;
        i++;
        items.push_back("ORANGE_TREE");
    }
    if(countItemsHarvested("BANANA_TREE")>0){
        cout<<i<<". BNT ("<< countItemsHarvested("BANANA_TREE")<<"  plots ready for harvest)"<<endl;
        i++;
        items.push_back("BANANA_TREE");
    }
    if(countItemsHarvested("GUAVA_TREE")>0){
        cout<<i<<". GAV ("<< countItemsHarvested("GUAVA_TREE")<<"  plots ready for harvest)"<<endl;
        i++;
        items.push_back("GUAVA_TREE");
    }
    return items;
}


template<class T>
int Storage<T>::positionCodetoRow(string position){
    if(position.length()!=3){
        throw InvalidSlotException();
    }
    int x1 = position[1] - '0';
    int x2 = position[2] - '0';
    return (x1*10+x2-1);
}

template<class T>
int Storage<T>::positionCodetoCol(string position){
    if(position.length()!=3){
        throw InvalidSlotException();
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

template<class T>
bool Storage<T>::noAnimalInStorage() const {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (!isSlotEmpty(i, j)) {
                if (dynamic_cast<Animal*>(storageContent[i][j]) != nullptr) {
                    return false; // Ada hewan di penyimpanan
                }
            }
        }
    }
    return true; // Tidak ada hewan di penyimpanan
}

template<class T>
bool Storage<T>::noPlantInStorage() const {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (!isSlotEmpty(i, j)) {
                if (dynamic_cast<Plant*>(storageContent[i][j]) != nullptr) {
                    return false; 
                }
            }
        }
    }
    return true; 
}

template<class T>
bool Storage<T>::noFoodInStorage() const {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (!isSlotEmpty(i, j)) {
                if(storageContent[i][j]->getType() == "PRODUCT_FRUIT_PLANT" || storageContent[i][j]->getType() == "PRODUCT_ANIMAL"){
                    return false;
                    break; 
                } else{
        
                }
            }
        }
    }
    return true; 
}

template<class T>
bool Storage<T>::onlyFruitProd() const {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (!isSlotEmpty(i, j)) {
                if(storageContent[i][j]->getType() == "PRODUCT_FRUIT_PLANT"){
                    return false;
                    break; 
                } else{
        
                }
            }
        }
    }
    return true; 
}

template<class T>
bool Storage<T>::onlyAnimalProd() const {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (!isSlotEmpty(i, j)) {
                if(storageContent[i][j]->getType() == "PRODUCT_ANIMAL"){
                    return false;
                    break; 
                } else{
        
                }
            }
        }
    }
    return true; 
}

// template<class T>
// void Storage<T>::printmap(string position){
//     cout << store[position] << endl;
// }

// int main() {
//     Animal cow("COW", "Cow", "Animal", 50,  100); 
//     Storage<Animal*> s;

//     s.setItemRandom(&cow);
//     s.printStorage("Peternakan", 0);
//     cout << s.getItemInfo("H04")->getCode() << endl;

//     Animal* x = s.getItemString("H04");

//     cout << x->getCode() << endl;
//     s.printStorage("Peternakan", 0);
//     s.printmap("H04");

//     Animal cos("COL", "Cow", "Animal", 50,  100); 
//     s.setItem(3, 7, &cos);
//     s.printStorage("Peternakan", 0);
//     s.printmap("H04");
//     cout << "di atas adalah hasil print map" << endl;
//     cout << s.getItemInfo("H04")->getCode() << endl;

//     Animal* y = s.getItemString("H04");

//     cout << y->getCode() << endl;
//     s.printStorage("Peternakan", 0);
//     s.printmap("H04");
// }