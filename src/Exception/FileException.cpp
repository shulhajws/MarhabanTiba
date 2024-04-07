#include "FileException.hpp"
#include <iostream>
using namespace std;

FileException::FileException(string _path) : Exception(){
  this->path = _path;
}

FileException::FileException(const FileException &FE) : Exception(){
  this->path = FE.path;
}

string FileException::getFileException(){
  return this->path;
}

string FileException::what() {
  cout << "File path: " << getFileException();
  return "\033[1;31mFile name is not valid\n \033[0m";
}