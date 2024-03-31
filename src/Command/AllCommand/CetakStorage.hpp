#include "../Command.hpp"

using namespace std;

class CetakStorage : public Command{
public:
    void useCommand();
    string getName();
};