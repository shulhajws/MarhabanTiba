#ifndef __FILEEXCEPTION_HPP__
#define __FILEEXCEPTION_HPP__

#include "Exception.hpp"
#include <string>
using namespace std;


class FileException : public Exception
{
    protected:
        string path;
    public:
        FileException(string _path) : Exception(){
            this->path = _path;
        }
        
        FileException(const FileException &FE) : Exception(){
            this->path = FE.path;
        }

        string getFileException(){
            return this->path;
        }

        string what() override {
            cout << "File path: " << getFileException();
            return "\033[1;31mFile name is not valid\n \033[0m";
        }
};

#endif