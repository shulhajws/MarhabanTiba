#include "../Command.hpp"

using namespace std;

class Beli : public Command{
public:
    void useCommand();
    string getName();
};