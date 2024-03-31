#include "../Command.hpp"

using namespace std;

class KasihMakan : public Command{
public:
    void useCommand();
    string getName();
};