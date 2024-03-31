#ifndef _EXCEPTION_HPP_
#define _EXCEPTION_HPP_

#include <exception>
using namespace std;

struct InputException : public exception {
    const char *what() const throw(){
        return "\033[1;31mOption input is not valid.\nPlease input only 1 or 2.\n \033[0m";
    }
};

struct UsernameException : public exception {
    const char *what() const throw(){
        return "\033[1;31mUsername is already used.\nTry input another username.\n \033[0m";
    }
};

struct CommandException : public exception {
    const char *what() const throw(){
        return "\033[1;31mCommand is not valid.\nTry input another command. \033[0m";
    }
};

// nanti tambah exception disini

#endif