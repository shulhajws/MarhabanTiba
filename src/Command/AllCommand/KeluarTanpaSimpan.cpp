#include "KeluarTanpaSimpan.hpp"
#include <cstdlib>
#include <chrono>   
#include <thread>   

using namespace this_thread;
using namespace chrono;

void KeluarTanpaSimpan::useCommand(){
    cout << "Thanks for playing! Hope to see you soon in another journey!"<< endl;
    exit(0);
}

string KeluarTanpaSimpan::getName()
{
    return "KELUAR_TANPA_SIMPAN";
}