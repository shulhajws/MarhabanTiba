#include "Panen.hpp"

void Panen::useCommand(){
    if(players[currPlayer]->getType()=="Petani"){
        PlantFarmer* p = dynamic_cast<PlantFarmer*>(players[currPlayer]);
        p->harvestCrop();
    } else{
        AnimalFarmer* p = dynamic_cast<AnimalFarmer*>(players[currPlayer]);
        p->harvestAnimal();
    }
}

string Panen::getName()
{
    return "PANEN";
}