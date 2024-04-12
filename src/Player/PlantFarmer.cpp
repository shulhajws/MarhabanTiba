#include "PlantFarmer.hpp"
#include "../Command/PetaniCommand/Tanam.hpp"
#include "../Command/PetaniCommand/CetakLadang.hpp"

#include <iostream>
using namespace std;

PlantFarmer::PlantFarmer() : Player(){
    this->commandList.push_back(new Tanam());
    this->commandList.push_back(new CetakLadang());
    Misc m;
    this->Garden.setRowCols(m.getFieldRow(),m.getFieldeCols());
}

PlantFarmer::PlantFarmer(string username, int wealth, int weight) : Player(username, wealth, weight, "Petani") {
    this->commandList.push_back(new Tanam());
    this->commandList.push_back(new CetakLadang());
    Misc m;
    this->Garden.setRowCols(m.getFieldRow(),m.getFieldeCols());
}

int PlantFarmer::getKTKP(){
    return 13;
}

void PlantFarmer::setGarden(Storage<Plant*> garden){
    this->Garden = garden;
}

void PlantFarmer::displayInfo() const {
    cout << "Plant Farmer - ";
    Player::displayInfo();
}

void PlantFarmer::plantCrop() {
    try {
        if (inventory.isEmpty()) {
            throw NoItemInStorageException();
        }

        if (Garden.isFull()) {
            throw GardenFullException();
        }

        cout << "Select a plant from the storage\n";
        inventory.printStorage("Storage",0);

        int row,col;
        Item* it ;

        while(true){
            try{
                cout << "Slot: ";
                string slot;
                cin >> slot;

                row = inventory.positionCodetoRow(slot);
                col = inventory.positionCodetoCol(slot);

                if (inventory.isSlotEmpty(row,col)){
                    throw InputException();
                }
                it = inventory.getItem(row, col);
                if(it->getType()!="MATERIAL_PLANT" && it->getType()!="FRUIT_PLANT"){
                    throw InputException();
                }
                break;
            } catch(InputException e){
                cout<<e.what();
            }

        }

        Plant* selectedPlantType = dynamic_cast<Plant*>(it);
    
        cout << "\nSelect a plot of land to plant\n\n";
        Garden.printStorage("Field",1); 

        while (true){
            try{
                // Memproses lokasi petak tanah yang dipilih
                cout << "\nLand plot: ";
                string landSlot;
                cin >> landSlot;

                int rowField = Garden.positionCodetoRow(landSlot);
                int colField = Garden.positionCodetoCol(landSlot);

                // Buat objek Plant baru dengan informasi dari selectedPlant
                Garden.setItem(rowField, colField, selectedPlantType); 

                cout << "\nDig, dig, dig deep into the soil~!\n";
                cout << selectedPlantType->getName() << " successfully planted!\n";
                break;
            }
            catch(InvalidPlantException e){
                 cout << e.what()<<endl;
            }
            catch (ItemNotFoundException& e) {
                cout << e.what()<<endl;
            }
            catch(InvalidSlotException e){
                cout << e.what();
            }
        }
    } catch (NoItemInStorageException& e) {
        cout << e.what()<<endl;
    } catch (GardenFullException& e) {
        cout << e.what()<<endl;
    } catch (ItemNotFoundException& e) {
        cout << e.what()<<endl;
    }
}

void PlantFarmer::addPlantYear(){
    for (int i = 0; i < Garden.getRow(); i++) {
        for (int j = 0; j < Garden.getCol(); j++) {
            if (Garden.getItemInfo(i,j) != nullptr) {
                 Garden.getItemInfo(i,j)->addAge();
            }
        }
    }
}

void PlantFarmer::harvestCrop() {
    // try {
    //     printGarden();
    //     displayReadyPlants();

    //     int selectedPlantIndex = selectPlantToHarvest();
    //     int numPlots = selectPlotsToHarvest();

    //     vector<string> selectedPlots = selectPlots(numPlots);

    //     harvestSelectedPlots(selectedPlots);

    //     printHarvestResult(selectedPlots);
    // } catch (const InputException& e) {
    //     cout << e.what() << endl;
    // }
}

void PlantFarmer::printGarden() {
    Garden.printStorage("Field",1); 
    Garden.printLegends();
}