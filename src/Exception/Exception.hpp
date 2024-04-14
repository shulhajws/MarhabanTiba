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
            return "\033[1;31mInput is not valid.\nPlease try another input.\n \033[0m";
        }
};

class InputNotIntegerException : public Exception {
    public:
        string what() override {
            return "\033[1;31mInput is not valid.\nPlease enter only an integer.\n \033[0m";
        }
};

class UsernameException : public Exception {
    public:
        string what() override {
        return "\033[1;31mUsername is already used.\nTry input another username.\n \033[0m";
    }
};

class CommandException : public Exception {
    public:
        string what() override {
        return "\033[1;31mCommand is not valid.\nTry input another command.\n \033[0m";
    }
};

class ItemNotFoundException : public Exception {
    public:
        string what() override {
        return "\033[1;31mItem not found.\nPlease try another input.\n \033[0m";
    }
};

class NoItemInStorageException : public Exception {
public:
    string what() override {
        return "\033[1;31mCannot do this command. No item available in storage.\n \033[0m";
    }
};

class NoAnimalInStorageException : public Exception {
public:
    string what() override {
        return "\033[1;31mCannot do this command. No animal available in storage.\n \033[0m";
    }
};

class NoPlantInStorageException : public Exception {
public:
    string what() override {
        return "\033[1;31mCannot do this command. No plant available in storage.\n \033[0m";
    }
};

class GardenFullException : public Exception {
public:
    string what() override {
        return "\033[1;31mCannot plant crop. Garden is full.\n \033[0m";
    }
};

class BarnFullException : public Exception {
public:
    string what() override {
        return "\033[1;31mCannot place animal. Barn is full.\n \033[0m";
    }
};

class InventoryFullException : public Exception {
public:
    string what() override {
        return "\033[1;31mCannot plant crop. Inventory is full.\n \033[0m";
    }
};

class InvalidSlotException : public Exception {
public:
    string what() override {
        return "\033[1;31mInvalid slot. Please choose another slot.\n \033[0m";
    }
};

class InvalidPlantException : public Exception {
public:
    string what() override {
        return "\033[1;31mCannot plant crop. Invalid plant selected.\n \033[0m";
    }
};

class NotEnoughSpaceException : public Exception {
public:
    string what() override {
        return "\033[1;31mCannot plant crop. Not enough space in the field.\n \033[0m";
    }
};

class NotEnoughInventorySpaceException : public Exception {
public:
    string what() override {
        return "\033[1;31mCannot save item. Not enough space in the Storage.\n \033[0m";
    }
};

class NotEnoughMoneyException : public Exception {
public:
    string what() override {
        return "\033[1;31mCannot buy item. Not enough money.\n \033[0m";
    }
};

class HarvestException : public Exception {
public:
    string what() override {
        return "\033[1;31mUnable to proceed with harvesting, nothing is ready for harvest.\n \033[0m";
    }
};

class BuyException : public Exception {
public:
    string what() override {
        return "\033[1;31mUnable to buy this Item, Please buy another item.\n \033[0m";
    }
};

class SellException : public Exception {
public:
    string what() override {
        return "\033[1;31mUnable to sell this Item, Please sell another item.\n \033[0m";
    }
};

// nanti tambah exception disini

#endif