#ifndef _COMMAND_HPP_
#define _COMMAND_HPP_

#include <string>
#include <iostream>
#include "../Exception/Exception.hpp"

using namespace std;

class Command{
public:
    virtual ~Command();
    virtual void useCommand() = 0;
    virtual string getName() = 0;
};

#endif