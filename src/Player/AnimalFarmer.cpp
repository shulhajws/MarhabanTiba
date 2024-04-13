#include "AnimalFarmer.hpp"
#include "../Command/PeternakCommand/KasihMakan.hpp"
#include "../Command/PeternakCommand/Ternak.hpp"
#include "../Command/PeternakCommand/CetakPeternakan.hpp"
#include "../Command/AllCommand/Panen.hpp"

#include <iostream>
using namespace std;

AnimalFarmer::AnimalFarmer() : Player(){
    this->commandList.push_back(new KasihMakan());
    this->commandList.push_back(new Ternak());
    this->commandList.push_back(new CetakPeternakan());
    this->commandList.push_back(new Panen());
    Misc m;
    this->Barn.setRowCols(m.getBarnRow(),m.getBarnCols());
}

AnimalFarmer::AnimalFarmer(string username, int wealth, int weight) : Player(username, wealth, weight, "Peternak") {
    this->commandList.push_back(new KasihMakan());
    this->commandList.push_back(new Ternak());
    this->commandList.push_back(new CetakPeternakan());
    this->commandList.push_back(new Panen());
    Misc m;
    this->Barn.setRowCols(m.getBarnRow(),m.getBarnCols());
}

int AnimalFarmer::getKTKP(){
    return 11;
}

void AnimalFarmer::setBarn(Storage<Animal*> barn){
    this->Barn = barn;
}

void AnimalFarmer::displayInfo() const {
    cout << "Animal Farmer - ";
    Player::displayInfo();
}

void AnimalFarmer::placeAnimal() {
    Misc m;
    try {
        if (inventory.isEmpty()) {
            throw NoItemInStorageException();
        }

        if (Barn.isFull()) {
            throw BarnFullException();
        }

        cout << "Select a animal from the storage\n";
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
                if(it->getType()!="CARNIVORE" && it->getType()!="HERBIVORE" && it->getType()!="OMNIVORE"){
                    throw InputException();
                }
                break;
            } catch(InputException e){
                cout<<e.what();
            }

        }

        Animal* selectedAnimalType = dynamic_cast<Animal*>(it);
    
        cout << "\nSelect a plot of land to live\n\n";
        Barn.printStorage("Barn",1); 

        while (true){
            try{
                // Memproses lokasi petak tanah yang dipilih
                cout << "\nLand plot: ";
                string landSlot;
                cin >> landSlot;

                int rowBarn = Barn.positionCodetoRow(landSlot);
                int colBarn = Barn.positionCodetoCol(landSlot);

                Barn.setItem(rowBarn, colBarn, selectedAnimalType); 

                cout << "\nThere was a farmer who had a "<< selectedAnimalType->getName()<<", Ee-i-ee-i-o"<<endl;
                cout << "This "<<selectedAnimalType->getName() << " has now become yours!\n";
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

void AnimalFarmer::feedAnimal() {
    try {
        if (inventory.isEmpty()||Barn.isEmpty()) {
            throw NoItemInStorageException();
        }
        while (true) {
            cout << "\nSelect a plot of land to live\n\n";
            Barn.printStorage("Barn",1); 
            // Memproses lokasi petak tanah yang dipilih
            cout << "\nLand plot: ";
            string landSlot;
            cin >> landSlot;

            int rowBarn = Barn.positionCodetoRow(landSlot);
            int colBarn = Barn.positionCodetoCol(landSlot);

            if (Barn.isSlotEmpty(rowBarn,colBarn)){
                throw InputException();
            }
            Animal* it = Barn.getItemInfo(rowBarn, colBarn);

            cout<<"You choose to feed the "<< it->getName()<<endl;
            cout<<"Choose the food to be given:"<<endl;
            inventory.printStorage("Storage",0);

            cout << "Slot: ";
            string slot;
            cin >> slot;

            int row = inventory.positionCodetoRow(slot);
            int col = inventory.positionCodetoCol(slot);
            if (inventory.isSlotEmpty(row,col)){
                throw InputException();
            }

            Item* food = inventory.getItem(row,col);
            Product* prod = dynamic_cast<Product*>(food);

            it->makan(prod);   
            break;
        
        }
    } catch (NoItemInStorageException& e){
        cout<<e.what();
    } catch (InputException e) {
        cout << e.what();
    }

}

void AnimalFarmer::harvestAnimal() {
    try {
        if (!Barn.isReadytoHarvest()){
            throw HarvestException();
        }
        printBarn();
        cout<<"\nChoose the ready-to-harvest animal you have:"<<endl;
        vector<string> barn = Barn.printHarvestedItem();

        int num, capacity;
        while(true){
            try{
                cout<< "\nAnimal number you want to harvest:";
                cin >> num ;
                cout<< "How many plots do you want to harvest:"; 
                cin >> capacity ;
                if (num<0 || num>barn.size() || Barn.countItemsHarvested(barn[num-1])<capacity){
                    throw InputException();
                }
                else{
                    break;
                }
            }catch(InputException e){
                cout<<e.what();
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

                    int rowField = Barn.positionCodetoRow(landSlot);
                    int colField = Barn.positionCodetoCol(landSlot);

                    if(!Barn.getItemInfo(rowField,colField)->isReadyToHarvest() || Barn.isSlotEmpty(rowField,colField)){
                        throw InvalidSlotException();
                    }

                    Barn.getItem(rowField,colField);
                    selectedPlots.push_back(landSlot);
                    break;
                }
                catch(InvalidSlotException e){
                    cout<<e.what()<<endl;
                }
            }
        }
        
        cout<<"\n";
        cout<<capacity<<" plots of "<< barn[num-1] << " animal in plots ";
        for(int i=0;i<selectedPlots.size()-1;i++){
            cout<<selectedPlots[i]<<", ";
        }
        cout<<selectedPlots[selectedPlots.size()-1]<<" have been harvested";
    } catch (HarvestException e) {
        cout << e.what() << endl;
    }
}

void AnimalFarmer::printBarn() {
    Barn.printStorage("Barn",1); 
    Barn.printLegends();
}

vector<Animal*> AnimalFarmer::getListOfAnimals() const{
    return this->Barn.getListOfContents();
}