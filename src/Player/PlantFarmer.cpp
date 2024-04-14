#include "PlantFarmer.hpp"
#include "../Command/PetaniCommand/Tanam.hpp"
#include "../Command/PetaniCommand/CetakLadang.hpp"
#include "../Command/AllCommand/Panen.hpp"

#include <iostream>
using namespace std;

PlantFarmer::PlantFarmer() : Player(){
    this->commandList.push_back(new Tanam());
    this->commandList.push_back(new CetakLadang());
    this->commandList.push_back(new Panen());
    Misc m;
    this->Garden.setRowCols(m.getFieldRow(),m.getFieldeCols());
}

PlantFarmer::PlantFarmer(string username, int wealth, int weight) : Player(username, wealth, weight, "Petani") {
    this->commandList.push_back(new Tanam());
    this->commandList.push_back(new CetakLadang());
    this->commandList.push_back(new Panen());
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

int PlantFarmer::getPlayerAssets(){
    return inventory.getTotalAssets() + Garden.getTotalAssets();
}

void PlantFarmer::plantCrop() {
    try {
        if (inventory.isEmpty()) {
            throw NoItemInStorageException();
        }

        if (Garden.isFull()) {
            throw GardenFullException();
        }

        if (inventory.noPlantInStorage()){
            throw NoPlantInStorageException();
        }else{
            cout << "Select a plant from the storage\n";
            inventory.printStorage("Storage",0);
        }

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
            } catch (InvalidPlantException e){
                cout << e.what();
            } catch (ItemNotFoundException e) {
                cout << e.what();
            } catch(InvalidSlotException e){
                cout << e.what();
            }
        }
    } catch (NoItemInStorageException& e) {
        cout << e.what();
    } catch (GardenFullException& e) {
        cout << e.what();
    } catch (ItemNotFoundException& e) {
        cout << e.what();
    } catch (NoPlantInStorageException& e) {
        cout << e.what();
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
    try {
        if (!Garden.isReadytoHarvest()){
            throw HarvestException();
        }
        printGarden();
        cout<<"\nChoose the ready-to-harvest crops you have:"<<endl;
        vector<string> garden = Garden.printHarvestedItem();

        int num, capacity;
        while(true){
            try{
                cout<< "\nPlant number you want to harvest:";
                cin >> num ;
                cout<< "How many plots do you want to harvest:"; 
                cin >> capacity ;
                if (num<0 || num>garden.size() || Garden.countItemsHarvested(garden[num-1])<capacity){
                    throw InputException();
                }
                else{
                    break;
                }
            } catch (InputException e){
                cout << e.what();
            }
        }

        vector<string> selectedPlots;
    
        cout<<"Select the plots you want to harvest:\n";
        for(int i=0;i<capacity;i++){
            while(true){
                try{
                    string landSlot;
                    cout<<"Plot "<<i+1<<":";
                    cin>>landSlot;

                    int rowField = Garden.positionCodetoRow(landSlot);
                    int colField = Garden.positionCodetoCol(landSlot);

                    if(!Garden.getItemInfo(rowField,colField)->isReadyToHarvest() || Garden.isSlotEmpty(rowField,colField)){
                        throw InvalidSlotException();
                    }

                    Garden.getItem(rowField,colField);
                    selectedPlots.push_back(landSlot);
                    break;
                } catch(InvalidSlotException e){
                    cout << e.what();
                }
            }
        }

        Product p;
        vector<Product*> Prod = p.getProduct(garden[num-1]);
        for (auto pro : Prod){
            Item* produk = pro;
            inventory = inventory + produk;
        }
        
        cout<<"\n";
        cout<<capacity<<" plots of "<< garden[num-1] << " plants in plots ";
        for(int i=0;i<selectedPlots.size()-1;i++){
            cout<<selectedPlots[i]<<", ";
        }
        cout<<selectedPlots[selectedPlots.size()-1]<<" have been harvested";
    } catch (HarvestException e) {
        cout << e.what();
    }
}

void PlantFarmer::printGarden() {
    Garden.printStorage("Field",1); 
    Garden.printLegends();
}

vector<Plant*> PlantFarmer::getListOfPlants() const{
    return this->Garden.getListOfContents();
}