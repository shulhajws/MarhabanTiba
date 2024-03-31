#include "../Command.hpp"

using namespace std;

class Makan : public Command{
public:
    void useCommand();
    string getName();
};