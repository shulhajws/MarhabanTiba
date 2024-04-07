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

class UsernameException : public Exception {
    public:
        string what() override {
        return "\033[1;31mUsername is already used.\nTry input another username.\n \033[0m";
    }
};

class CommandException : public Exception {
    public:
        string what() override {
        return "\033[1;31mCommand is not valid.\nTry input another command. \033[0m";
    }
};

class ItemNotFoundException : public Exception {
    public:
        string what() override {
        return "\033[1;31mItem not found.\nTry input another slot Item. \033[0m";
    }
};

class NoItemInStorageException : public Exception {
public:
    string what() override {
        return "\033[1;31mCannot plant crop. No item available in storage.\033[0m";
    }
};

class GardenFullException : public Exception {
public:
    string what() override {
        return "\033[1;31mCannot plant crop. Garden is full.\033[0m";
    }
};

class InventoryFullException : public Exception {
public:
    string what() override {
        return "\033[1;31mCannot plant crop. Inventory is full.\033[0m";
    }
};

class InvalidSlotException : public Exception {
public:
    string what() override {
        return "\033[1;31mInvalid slot. Please choose another slot.\033[0m";
    }
};

class InvalidPlantException : public Exception {
public:
    string what() override {
        return "\033[1;31mCannot plant crop. Invalid plant selected.\033[0m";
    }
};

class NotEnoughSpaceException : public Exception {
public:
    string what() override {
        return "\033[1;31mCannot plant crop. Not enough space in the field.\033[0m";
    }
};

// nanti tambah exception disini

#endif