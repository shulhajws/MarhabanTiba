#include "../Command.hpp"

using namespace std;

class Panen : public Command{
public:
    void useCommand();
    string getName();
};