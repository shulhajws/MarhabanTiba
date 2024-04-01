#ifndef __MISC_HPP__
#define __MISC_HPP__

#include <string>
using namespace std;

class Misc{
    private:
        int minMoney;
        int minWeight;
        int storageRow;
        int storageCols;
        int fieldRow;
        int fieldCols;
        int barnRow;
        int barnCols;
    public:
        Misc(int minMoney, int minWeight, int storageRow, int storageCols, int fieldRow, int fieldCols, int barnRow, int barnCols);
        int getminMoney();
        int getminWeight();
};

#endif