#include "../Command.hpp"

using namespace std;

class Ternak : public Command{
public:
    void useCommand();
    string getName();
};