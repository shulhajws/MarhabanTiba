#include "AnimalFarmer.hpp"
#include "../Command/PeternakCommand/KasihMakan.hpp"
#include "../Command/PeternakCommand/Ternak.hpp"
#include "../Command/PeternakCommand/CetakPeternakan.hpp"

#include <iostream>
using namespace std;

AnimalFarmer::AnimalFarmer() : Player(){
    this->commandList.push_back(new KasihMakan());
    this->commandList.push_back(new Ternak());
    this->commandList.push_back(new CetakPeternakan());
    Misc m;
    this->Barn.setRowCols(m.getBarnRow(),m.getBarnCols());
}

AnimalFarmer::AnimalFarmer(string username, int wealth, int weight) : Player(username, wealth, weight, "Peternak") {
    this->commandList.push_back(new KasihMakan());
    this->commandList.push_back(new Ternak());
    this->commandList.push_back(new CetakPeternakan());
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

        cout<<"test"<<endl;
        if (Barn.isFull()) {
            throw BarnFullException();
        }
        cout<<"test"<<endl;
        cout << "Select a animal from the storage\n";
        inventory.printStorage("Storage");

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
        printBarn();

        while (true){
            try{
                // Memproses lokasi petak tanah yang dipilih
                cout << "\nLand plot: ";
                string landSlot;
                cin >> landSlot;

                int rowBarn = Barn.positionCodetoRow(landSlot);
                int colBarn = Barn.positionCodetoCol(landSlot);

                // Buat objek Plant baru dengan informasi dari selectedPlant
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
    cout << this->getName() <<" is feeding animals." << endl;
}

void AnimalFarmer::harvestAnimal() {
    cout << this->getName() <<" is harvesting animals." << endl;
}

void AnimalFarmer::printBarn() {
    Barn.printStorage("Barn"); 
}