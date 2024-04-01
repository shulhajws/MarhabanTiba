#include "Misc.hpp"

Misc::Misc(int minMoney, int minWeight, int storageRow, int storageCols, int fieldRow, int fieldCols, int barnRow, int barnCols){
    this->minMoney = minMoney;
    this->minWeight = minWeight;
    this->storageRow = storageRow;
    this->storageCols = storageCols;
    this->fieldRow = fieldRow;
    this->fieldCols = fieldCols;
    this->barnRow = barnRow;
    this->barnCols = barnCols;
}

int Misc::getminMoney(){
    return minMoney;
}
int Misc::getminWeight(){
    return minWeight;
}