#ifndef _COMMAND_HPP_
#define _COMMAND_HPP_

#include <string>
#include <iostream>
using namespace std;

class Command{
public:
    virtual void useCommand() = 0;
    virtual string getName() = 0;
};

#endif