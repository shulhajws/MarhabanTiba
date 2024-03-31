#include "../Command.hpp"

using namespace std;

class Next : public Command{
public:
    void useCommand();
    string getName();
};