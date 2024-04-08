#include "PlantFarmer.hpp"
#include "../Command/PetaniCommand/Tanam.hpp"

#include <iostream>
using namespace std;

PlantFarmer::PlantFarmer() : Player(){
    this->commandList.push_back(new Tanam());
}

PlantFarmer::PlantFarmer(string username, int wealth, int weight) : Player(username, wealth, weight, "Petani") {
    this->commandList.push_back(new Tanam());
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

        cout << "Pilih tanaman dari penyimpanan\n";
        cout << "     ================[ Penyimpanan ]==================\n" << endl;
        inventory.printStorage();

        cout << "Slot: ";
        string slot;
        cin >> slot;

        int row = inventory.positionCodetoRow(slot);
        int col = inventory.positionCodetoCol(slot);

        Item* selectedPlant = inventory.getItemInfo(row, col);

        Plant* selectedPlantType = dynamic_cast<Plant*>(selectedPlant);
        if (selectedPlantType == nullptr) {
            throw InvalidPlantException();
        }

        cout << "\nPilih petak tanah yang akan ditanami\n\n";
        cout << "     ================[ Ladang ]=================\n";
        printGarden();

        // Memproses lokasi petak tanah yang dipilih
        cout << "\nPetak tanah: ";
        string landSlot;
        cin >> landSlot;

        int rowField = landSlot[1] - '0' - 1;
        int colField = landSlot[0] - 'A';

        Plant* selectedPlantType = dynamic_cast<Plant*>(selectedPlant);
        if (selectedPlantType == nullptr) {
            throw InvalidPlantException();
        }

        // Buat objek Plant baru dengan informasi dari selectedPlant
        Garden.setItem(rowField, colField, selectedPlantType); 

        cout << "\nCangkul, cangkul, cangkul yang dalam~!\n";
        cout << selectedPlantType->getName() << " berhasil ditanam!\n";
            
    } catch (NoItemInStorageException& e) {
        cout << e.what()<<endl;
    } catch (GardenFullException& e) {
        cout << e.what()<<endl;
    } catch (InvalidPlantException& e) {
        cout << e.what()<<endl;
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
    cout << "    ================[ Ladang ]=================\n";
    
    Garden.printStorage(); 
    
    // Mencetak indeks garden (hanya yang terdapat di ladang)
    string plantCodes[] = {"ALT", "APL", "BNT", "GAV", "IRN", "ORG", "SDT", "TEK"};
    int numPlantCodes = sizeof(plantCodes) / sizeof(plantCodes[0]);

    for (int i = 0; i < numPlantCodes; ++i) {
        bool found = false;
        string plantName;

        for (int row = 0; row < Garden.getRow(); ++row) {
            for (int col = 0; col < Garden.getCol(); ++col) {
                Item* item = Garden.getItem(row, col);
                if (item != nullptr && item->getCode() == plantCodes[i]) {
                    found = true;
                    plantName = item->getName();
                    break;
                }
            }
            if (found) {
                break;
            }
        }

        if (found) {
            cout << "   - " << plantCodes[i] << ": " << plantName << endl;
        }
    }
}