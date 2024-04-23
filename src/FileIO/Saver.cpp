#include "Saver.hpp"
using namespace std;

string Saver::testsPath = "./data";

string Saver::getTestsPath()
{
    return Saver::testsPath;
}

void Saver::saveGameState(string filepath, const vector<Player*>& players, const Shop& shop){
    try
    {
        string statepath = filepath;
        ofstream oState(statepath);

        if (!oState)
        {
            throw FileException(filepath);
        }
        else {
            oState << players.size() << endl;
            for (const auto& player : players)
            {
                // player general description
                oState << player->getName() << " ";
                oState << player->getType() << " ";
                oState << player->getPlayerWeight() << " ";
                oState << player->getPlayerWealth() << endl;

                // player inventory
                if (player->inventoryEmpty())
                {
                    oState << 0 << endl;
                }
                else 
                {
                    oState << player->itemInInventories() << endl;
                    vector<Item*> items = player->getListOfItems();
                    for (const auto& item : items)
                    {
                        oState << item->getName() << endl;
                    }
                }

                // farmer storage
                if (player->getType() == "Petani")
                {   
                    PlantFarmer* petani = dynamic_cast<PlantFarmer*>(player);
                    // vector<Plant*> plants = petani->getListOfPlants();
                    Storage<Plant*> garden = petani->getGarden();
                    if (garden.isEmpty())
                    {
                        oState << 0 << endl;
                    }
                    else 
                    {
                        oState << garden.countFilledCells() << endl;
                        for(int i = 0; i < garden.getRow(); i++){
                            for(int j = 0; j < garden.getCol(); j++){
                                if (!garden.isSlotEmpty(i, j)) {
                                    oState << garden.coltoPositionCode(j) << garden.rowtoPositionCode(i) << " " << garden.getItemInfoInt(i, j)->getName() << garden.rowtoPositionCode(i) << " " << garden.getItemInfoInt(i, j)->getPlantAge() << endl;
                                }
                            }
                        }
                        // for (const auto& plant : plants)
                        // {

                        //     oState << plant->getName() << endl;
                        // }
                    }
                }
                else if (player->getType() == "Peternak")
                {
                    AnimalFarmer* peternak = dynamic_cast<AnimalFarmer*>(player);
                    // vector<Animal*> animals = peternak->getListOfAnimals();
                    Storage<Animal*> barn = peternak->getBarn();
                    if (barn.isEmpty())
                    {
                        oState << 0 << endl;
                    }
                    else 
                    {
                        oState << barn.countFilledCells() << endl;
                        for(int i = 0; i < barn.getRow(); i++){
                            for(int j = 0; j < barn.getCol(); j++){
                                if (!barn.isSlotEmpty(i, j)) {
                                    oState << barn.coltoPositionCode(j) << barn.rowtoPositionCode(i) << " " << barn.getItemInfoInt(i, j)->getName() << " " << barn.getItemInfoInt(i, j)->getAnimalWeight() << endl;
                                }
                            }
                        }
                        // for (const auto& animal : animals)
                        // {
                        //     oState << animal->getName() << endl;
                        // }
                    }
                }
            }

            // shop state
            int itemsInShop = shop.getItemsBuilding().size() + shop.getItemsProduct().size();
            oState << itemsInShop << endl;
            for (const auto& shopBuilding : shop.getItemsBuilding())
            {
                Building building = *get<0>(shopBuilding);
                oState << building.getName() << " " << get<1>(shopBuilding) << endl;
            }
            for (const auto& shopProduct : shop.getItemsProduct())
            {
                Product product = *get<0>(shopProduct);
                oState << product.getName() << " " << get<1>(shopProduct) << endl;
            }
        }
    }
    catch(FileException& FE)
    {
        cout << FE.what();
    }
}