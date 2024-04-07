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
    FileException(string);
    FileException(const FileException &); // cctor

    string getFileException();
    string what();
};

#endif