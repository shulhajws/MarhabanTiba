#include "Tanam.hpp"

void Tanam::useCommand(){
    PlantFarmer* p = dynamic_cast<PlantFarmer*>(players[currPlayer]);
    p->plantCrop();
}

string Tanam::getName()
{
    return "TANAM";
}