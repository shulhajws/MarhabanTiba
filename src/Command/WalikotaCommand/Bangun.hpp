#include "../Command.hpp"

using namespace std;

class Bangun : public Command{
public:
    void useCommand();
    string getName();
};