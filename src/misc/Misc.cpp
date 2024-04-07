#include "Misc.hpp"

int Misc::minMoney;
int Misc::minWeight;
int Misc::storageRow;
int Misc::storageCols;
int Misc::fieldRow;
int Misc::fieldCols;
int Misc::barnRow;
int Misc::barnCols;

Misc::Misc(){

}

Misc::Misc(int minMoney, int minWeight, int storageRow, int storageCols, int fieldRow, int fieldCols, int barnRow, int barnCols){
    Misc::minMoney = minMoney;
    Misc::minWeight = minWeight;
    Misc::storageRow = storageRow;
    Misc::storageCols = storageCols;
    Misc::fieldRow = fieldRow;
    Misc::fieldCols = fieldCols;
    Misc::barnRow = barnRow;
    Misc::barnCols = barnCols;
}

int Misc::getminMoney(){
    return Misc::minMoney;
}
int Misc::getminWeight(){
    return Misc::minWeight;
}
int Misc::getStorageRow() const{
    return Misc::storageRow;
}
int Misc::getStorageCols() const{
    return Misc::storageCols;
}