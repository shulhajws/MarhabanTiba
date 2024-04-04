#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include <exception>
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

// nanti tambah exception disini

#endif