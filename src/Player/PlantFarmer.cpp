#include "PlantFarmer.hpp"
#include "../Command/PetaniCommand/Tanam.hpp"
#include "../Command/PetaniCommand/CetakLadang.hpp"
#include "../Command/AllCommand/Panen.hpp"
#include "../Command/AllCommand/TakeRisk.hpp"
#include "../Item/Plant/FruitPlant.hpp"
#include "../Tax/Tax.hpp"

#include <iostream>
using namespace std;

PlantFarmer::PlantFarmer() : Player(){
    this->commandList.push_back(new Tanam());
    this->commandList.push_back(new CetakLadang());
    this->commandList.push_back(new Panen());
    this->commandList.push_back(new TakeRisk());
    Misc m;
    this->Garden.setRowCols(m.getFieldRow(),m.getFieldeCols());
}

PlantFarmer::PlantFarmer(string username, int wealth, int weight) : Player(username, wealth, weight, "Petani") {
    this->commandList.push_back(new Tanam());
    this->commandList.push_back(new CetakLadang());
    this->commandList.push_back(new Panen());
    this->commandList.push_back(new TakeRisk());
    Misc m;
    this->Garden.setRowCols(m.getFieldRow(),m.getFieldeCols());
}

int PlantFarmer::getKTKP(){
    return 13;
}

void PlantFarmer::setGarden(Storage<Plant*> garden){
    this->Garden = garden;
}

Storage<Plant*> PlantFarmer::getGarden(){
    return this->Garden;
};

int PlantFarmer::calculateTax(){
    Tax t(getKTKP(), wealth,getPlayerAssets());
    if(t.getTax()<=wealth){
        return t.getTax();
    }
    return wealth;
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
        Item* it;

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
                if (!inventory.isItemValid(row,col)){
                    throw InputException();
                }
                it = inventory.getItemInfoInt(row, col);
                if(it->getType()!="MATERIAL_PLANT" && it->getType()!="FRUIT_PLANT"){
                    throw InputException();
                }else{
                    it = inventory.getItem(row, col); 
                }
                break;
            } catch(InputException e){
                cout<<e.what();
            } catch(InvalidSlotException e){
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
                if(!Garden.isItemValid(rowField,colField)){
                    throw InvalidSlotException();
                }
                Garden.setItem(rowField, colField, selectedPlantType); 

                cout << "\nDig, dig, dig deep into the soil~!\n";
                cout << selectedPlantType->getName() << " successfully planted!\n";
                break;
            } catch (ItemNotFoundException e) {
                cout << e.what();
            } catch (InputException e){
                cout << e.what();
            } catch (InvalidSlotException e){
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

void PlantFarmer::plantCropRisk() {
    if (!Garden.isFull()) {
        Plant* apel = new AppleTree();
        Garden = Garden + apel;
        addPlayerWealth(15);
    } else{
        cout<<"Your Garden is full, so the committee decided to compensate you with money."<<endl;
        cout<<"You received 20 gulden as compensation."<<endl;
        addPlayerWealth(20);
    }
}

void PlantFarmer::addPlantYear(){
    for (int i = 0; i < Garden.getRow(); i++) {
        for (int j = 0; j < Garden.getCol(); j++) {
            if (Garden.getItemInfoInt(i,j) != nullptr) {
                Plant *x = Garden.getItemInfoInt(i,j);
                x->addAge();
                Garden.getItem(i,j);
                Garden.setItem(i,j,x);
            }
        }
    }
}

void PlantFarmer::minPlantYear(){
    for (int i = 0; i < Garden.getRow(); i++) {
        for (int j = 0; j < Garden.getCol(); j++) {
            if (Garden.getItemInfoInt(i,j) != nullptr) {
                Plant *x = Garden.getItemInfoInt(i,j);
                x->minAge();
                Garden.getItem(i,j);
                Garden.setItem(i,j,x);
            }
        }
    }
}

void PlantFarmer::harvestCrop() {
    try {
        if (!Garden.isReadytoHarvest()){
            throw HarvestException();
        }
        if (inventory.isFull()){
            throw NotEnoughInventorySpaceException();
        }
        printGarden();
        cout<<"\nChoose the ready-to-harvest crops you have:"<<endl;
        vector<string> garden = Garden.printHarvestedItem();

        int num, capacity;
        while(true){
            try{
                cout<< "\nPlant number you want to harvest: ";
                if(!(cin>> num)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw InputNotIntegerException();
                }
                
                cout<< "How many plots do you want to harvest: "; 
                if(!(cin>> capacity)){
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw InputNotIntegerException();
                }

                if (num<1 || num>garden.size() || capacity<1 || Garden.countItemsHarvested(garden[num-1])<capacity){
                    throw InputException();
                }

                break;
            } catch (InputException e){
                cout << e.what();
            } catch (InputNotIntegerException e){
                cout << e.what();
            }   
        }

        vector<string> selectedPlots;
        int row,col;
    
        cout<<"\nSelect the plots you want to harvest:\n";
        for(int i=0;i<capacity;i++){
            while(true){
                try{
                    string landSlot;
                    cout<<"Plot "<<i+1<<": ";
                    cin>>landSlot;

                    int rowField = Garden.positionCodetoRow(landSlot);
                    int colField = Garden.positionCodetoCol(landSlot);

                    if (!Garden.isItemValid(rowField,colField)){
                    throw InvalidSlotException();
                    }
                    if(Garden.isSlotEmpty(rowField,colField)){
                        throw InputException();
                    }
                    if(!Garden.getItemInfo(landSlot)->isReadyToHarvest() || Garden.isSlotEmpty(rowField,colField) || 
                    !Garden.isItemValid(rowField,colField) || Garden.getItemInfo(landSlot)->getName()!=garden[num-1]){
                        throw InvalidSlotException();
                    }

                    Garden.getItem(rowField,colField);
                    selectedPlots.push_back(landSlot);
                    break;
                } catch(InvalidSlotException e){
                    cout << e.what();
                } catch(InputException e){
                    cout << e.what();
                } catch (ItemNotFoundException e) {
                    cout << e.what();
                }
            }
        }

        Product p;
        vector<Product*> Prod = p.getProduct(garden[num-1]);
        for (int i=0; i<capacity;i++){
            for (auto pro : Prod){
                Item* produk = pro;
                inventory = inventory + produk;
            }
        }
        
        cout<<"\n";
        cout<<capacity<<" plots of "<< garden[num-1] << " plants in plots ";
        for(int i=0;i<selectedPlots.size()-1;i++){
            cout<<selectedPlots[i]<<", ";
        }
        cout<<selectedPlots[selectedPlots.size()-1]<<" have been harvested"<<endl;
         
    } catch (HarvestException e) {
        cout << e.what();
    } catch (NotEnoughInventorySpaceException e){
        cout << e.what();
    }
}

void PlantFarmer::delItemRisk(){
    Garden.deleteItem();
}

void PlantFarmer::printGarden() {
    Garden.printStorage("Field",1); 
    Garden.printLegends();
}

vector<Plant*> PlantFarmer::getListOfPlants() const{
    return this->Garden.getListOfContents();
}