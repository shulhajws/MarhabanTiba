#ifndef __LOADEREXCEPTION_HPP__
#define __LOADEREXCEPTION_HPP__

#include "Exception.hpp"
#include <string>
#include <iostream>
using namespace std;


class LoaderException : public Exception
{
    private:
        string _inputName;
    public:
        LoaderException(){}
        string what() override 
        {
            cout << this->_inputName << "\033[1;31m tidak terdefinisi pada permainan ini.\n";
            return "Cek kembali file Anda.\n \033[0m";
        }
};

#endif