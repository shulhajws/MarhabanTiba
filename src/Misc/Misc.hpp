#ifndef __MISC_HPP__
#define __MISC_HPP__

#include <string>
using namespace std;

class Misc{
    private:
        static int minMoney;
        static int minWeight;
        static int storageRow;
        static int storageCols;
        static int fieldRow;
        static int fieldCols;
        static int barnRow;
        static int barnCols;
    public:
        Misc();
        Misc(int minMoney, int minWeight, int storageRow, int storageCols, int fieldRow, int fieldCols, int barnRow, int barnCols);
        int getminMoney();
        int getminWeight();
        int getStorageRow() const;
        int getStorageCols() const;
};

#endif