#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include <exception>
#include <string>
using namespace std;

class Exception {
public:
    virtual string what() = 0;
};

class InputException : public Exception {
public:
    string what() override {
        return "\033[1;31mInput is not valid.\nPlease try another input.\n\033[0m";
    }
};

class InputNotIntegerException : public Exception {
public:
    string what() override {
        return "\033[1;31mInput is not valid.\nPlease enter only an integer.\n\033[0m";
    }
};

class UsernameException : public Exception {
public:
    string what() override {
        return "\033[1;31mWhoopsie daisy! Someone has already claimed that username. \nYou wouldn't want a doppelgänger, would you? 😄\nHow about trying something as unique as yourself?\n\033[0m";
    }
};

class CommandException : public Exception {
public:
    string what() override {
        return "\033[1;31mWhoops! That command seems to have lost its way. \nHow about a different one?\n\033[0m";
    }
};

class ItemNotFoundException : public Exception {
public:
    string what() override {
        return "\033[1;31mItem not found.\nIt seems like the item you're after is playing a game of hide and seek.\nPlease try selecting a different item.\n\033[0m";
    }
};

class NoItemInStorageException : public Exception {
public:
    string what() override {
        return "\033[1;31mBummer! The storage seems to be as empty as a ghost town. \nUnable to proceed with this command.\n\033[0m";
    }
};

class NoAnimalInStorageException : public Exception {
public:
    string what() override {
        return "\033[1;31mOh dear! It appears you don't have any furry friends.\nCommand cannot be executed without animals.\n\033[0m";
    }
};

class NoPlantInStorageException : public Exception {
public:
    string what() override {
        return "\033[1;31mCannot do this command.\nNo plant available in storage.\n\033[0m";
    }
};

class GardenFullException : public Exception {
public:
    string what() override {
        return "\033[1;31mWoooahh your garden is so full.\nBut, there is no room four your new plants.\n\033[0m";
    }
};

class BarnEmptyException : public Exception {
public:
    string what() override {
        return "\033[1;31mYour barn is as silent as a library at midnight. \nNo mooing or clucking here! 🐮🐔\n\033[0m";
    }
};

class BarnFullException : public Exception {
public:
    string what() override {
        return "\033[1;31mYour're a successful farmer! The barn is as crammed as rush hour traffic. \nSadly, no room for additional animals.\n\033[0m";
    }
};

class InvalidSlotException : public Exception {
public:
    string what() override {
        return "\033[1;31mYou've selected an invalid slot. \nPlease choose a different one.\n\033[0m";
    }
};

class NotEnoughItemStockException : public Exception {
public:
    string what() override {
        return "\033[1;31mNot enough stock available for this item.\nPlease check the available quantity.\n\033[0m";
    }
};

class NotEnoughInventorySpaceException : public Exception {
public:
    string what() override {
        return "\033[1;31mCannot save item. \nNot enough space in the Storage.\n\033[0m";
    }
};

class NotEnoughMoneyException : public Exception {
public:
    string what() override {
        return "\033[1;31mYour wallet feels lighter than air. 💸 \nIt seems we're a bit short on gulden for this transaction. \n\033[0m";
    }
};

class HarvestException : public Exception {
public:
    string what() override {
        return "\033[1;31mLooks like we're out of luck! \nThere's nothing ready for harvest, so we can't proceed.\n\033[0m";
    }
};

class MayorBuyException : public Exception {
public:
    string what() override {
        return "\033[1;31mUh-oh! The Honorable Mayor is unable to purchase any buildings.\nIt's time to take matters and build your own!\n\033[0m";   
    }
};

class SellException : public Exception {
public:
    string what() override {
        return "\033[1;31mUnable to sell this Item, Please sell another item.\n\033[0m";
    }
};

class NoFoodInStorageException : public Exception {
public:
    string what() override {
        return "\033[1;31mFeeling hungry?.There's nothing to eat in the storage.\nIt's time to go grocery shopping.\n\033[0m";
    }
};

class NotFoodException : public Exception {
public:
    string what() override {
        return "\033[1;31mYour animal is refusing to eat that 🐔!\nPlease choose another food option.\n\033[0m";
    }
};

class SellInventoryBuildingForFarmerException : public Exception {
public:
    string what() override {
        return "\033[1;31mYour inventory only contains buildings, so you cannot sell buildings. Please purchase or harvest instead.\n\033[0m";
    }
};

// nanti tambah exception disini

#endif