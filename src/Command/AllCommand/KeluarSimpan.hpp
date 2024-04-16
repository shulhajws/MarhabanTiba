#include "../Command.hpp"
#include "../../Game/Game.hpp"
#include "../../Shop/Shop.hpp"
#include "../../FileIO/Saver.hpp"
#include <cstdlib>
#include <chrono>   
#include <thread>   

using namespace std;
using namespace this_thread;
using namespace chrono;

class KeluarSimpan : public Command,Game{
public:
    void useCommand();
    string getName();
};