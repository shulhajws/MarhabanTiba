#include "AnimalFarmer.hpp"
#include "../Command/PeternakCommand/KasihMakan.hpp"
#include "../Command/PeternakCommand/Ternak.hpp"
#include "../Command/PeternakCommand/CetakPeternakan.hpp"
#include "../Command/AllCommand/Panen.hpp"
#include "../Item/Animal/Animal.hpp"
#include "../Item/Animal/Herbivore.hpp"
#include "../Command/AllCommand/TakeRisk.hpp"
#include "../Tax/Tax.hpp"

#include <iostream>
using namespace std;

AnimalFarmer::AnimalFarmer() : Player(){
    this->commandList.push_back(new KasihMakan());
    this->commandList.push_back(new Ternak());
    this->commandList.push_back(new CetakPeternakan());
    this->commandList.push_back(new Panen());
    this->commandList.push_back(new TakeRisk());
    Misc m;
    this->Barn.setRowCols(m.getBarnRow(),m.getBarnCols());
}

AnimalFarmer::AnimalFarmer(string username, int wealth, int weight) : Player(username, wealth, weight, "Peternak") {
    this->commandList.push_back(new KasihMakan());
    this->commandList.push_back(new Ternak());
    this->commandList.push_back(new CetakPeternakan());
    this->commandList.push_back(new Panen());
    this->commandList.push_back(new TakeRisk());
    Misc m;
    this->Barn.setRowCols(m.getBarnRow(),m.getBarnCols());
}

int AnimalFarmer::getKTKP(){
    return 11;
}

void AnimalFarmer::setBarn(Storage<Animal*> barn){
    this->Barn = barn;
}

int AnimalFarmer::calculateTax(){
    Tax t(getKTKP(), wealth,getPlayerAssets());
    return t.getTax();
}

void AnimalFarmer::displayInfo() const {
    cout<< "Animal Farmer - ";
    Player::displayInfo();
}

int AnimalFarmer::getPlayerAssets(){
    return inventory.getTotalAssets() + Barn.getTotalAssets();
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

        if (inventory.noAnimalInStorage()){
            throw NoAnimalInStorageException();
        }else{
            cout<< "Select a animal from the storage\n";
            inventory.printStorage("Storage",0);
        }

        int row,col;
        Item* it ;
        string slot;

        while(true){
            try{
                cout<< "Slot: ";
                cin >> slot;
                cout << "You want to place your animal in slot " << slot << " in your barn." << endl; 

                row = inventory.positionCodetoRow(slot);
                col = inventory.positionCodetoCol(slot);

                if (!inventory.isItemValid(row,col)){
                    throw InvalidSlotException();
                }
                if(inventory.isSlotEmpty(row,col)){
                    throw InputException();
                }
                
                it = inventory.getItem(row, col);
                if(it->getType()!="CARNIVORE" && it->getType()!="HERBIVORE" && it->getType()!="OMNIVORE"){
                    throw InputException();
                }
                break;
            } catch (ItemNotFoundException e){
                cout << e.what();
            } catch (InputException e){
                cout << e.what();
            } catch (InvalidSlotException e){
                cout<< e.what();
            }
        }

        Animal* selectedAnimalType = dynamic_cast<Animal*>(it);
    
        cout<< "\nSelect a plot of land to live\n\n";
        Barn.printStorage("Barn",1); 

        while (true){
            try{
                // Memproses lokasi petak tanah yang dipilih
                cout<< "\nLand plot: ";
                string landSlot;
                cin >> landSlot;

                int rowBarn = Barn.positionCodetoRow(landSlot);
                int colBarn = Barn.positionCodetoCol(landSlot);

                Barn.setItem(rowBarn, colBarn, selectedAnimalType); 

                cout<< "\nThere was a farmer who had a "<< selectedAnimalType->getName()<<", Ee-i-ee-i-o"<<endl;
                cout<< "This "<<selectedAnimalType->getName() << " has now become yours!\n";
                break;
            } catch (ItemNotFoundException e) {
                cout<< e.what()<<endl;
            } catch (InputException e){
                cout << e.what();
            } catch (InvalidSlotException e){
                cout<< e.what();
            }
        }
    } catch (NoItemInStorageException& e) {
        cout<< e.what()<<endl;
    }  catch (ItemNotFoundException& e) {
        cout<< e.what()<<endl;
    } catch (BarnFullException& e) {
        cout<< e.what()<<endl;
    } catch (NoAnimalInStorageException& e) {
        cout<< e.what()<<endl;
    }
}

void AnimalFarmer::placeAnimalRisk() {
    if (!Barn.isFull()) {
        Animal* sapi = new Cow();
        Barn = Barn + sapi;
        addPlayerWealth(15);
    } else{
        cout<<"Your barn is full, so the committee decided to compensate you with money."<<endl;
        cout<<"You received 20 gulden as compensation."<<endl;
        addPlayerWealth(20);
    }
}

void AnimalFarmer::feedAnimal() {
    try {
        if (inventory.isEmpty()) {
            throw NoItemInStorageException();
        }
        if (Barn.isEmpty()) {
            throw BarnEmptyException();
        }
        if (inventory.noFoodInStorage()){
            throw NoFoodInStorageException();
        }
        if (inventory.noFoodInStorage()){
            throw NoFoodInStorageException();
        }
        while (true) {
            cout<< "\nSelect a plot of land to live\n\n";
            Barn.printStorage("Barn",1); 
            int rowBarn, colBarn;
            string landSlot;
        
            // Memproses lokasi petak tanah yang dipilih
            while(true){
                try{
                    cout<< "\nLand plot: ";
                    cin >> landSlot;

                    rowBarn = Barn.positionCodetoRow(landSlot);
                    colBarn = Barn.positionCodetoCol(landSlot);

                    if (!Barn.isItemValid(rowBarn,colBarn)){
                        throw InvalidSlotException();
                    }

                    if (Barn.isSlotEmpty(rowBarn,colBarn)){
                        throw InputException();
                    }
                    break;
                    
                } catch (InputException e) {
                    cout << e.what();
                } catch (InvalidSlotException e) {
                    cout << e.what();
                } catch (ItemNotFoundException e) {
                    cout << e.what();
                }
            
            }
            Animal* it = Barn.getItemInfo(landSlot);

            cout<<"You choose to feed the "<< it->getName()<<endl;
            cout<<"Choose the food to be given (pick one):"<<endl;
            inventory.printStorage("Storage",0);

            cout<< "Slot: ";
            string slot;
            cin >> slot;

            int row = inventory.positionCodetoRow(slot);
            int col = inventory.positionCodetoCol(slot);
            
            if (!inventory.isItemValid(rowBarn,colBarn)){
                throw InvalidSlotException();
            }

            if (inventory.isSlotEmpty(row,col)){
                throw InputException();
            }

            Item* food = inventory.getItemInfo(slot);
            if(food->getType()=="PRODUCT_ANIMAL"||food->getType()=="PRODUCT_FRUIT_PLANT"){
                food = inventory.getItemInfoInt(row,col);
                if(it->getType()=="CARNIVORE"&&!inventory.onlyAnimalProd()){
                    throw NotFoodException();
                }
                if(it->getType()=="HERBIVORE"&&!inventory.onlyFruitProd()){
                    throw NotFoodException();
                }
                Product* prod = dynamic_cast<Product*>(food);
                it->makan(prod);
                food = inventory.getItem(row,col);
            }
            else{
                throw NotFoodException();
            } 
            break;
        
        }
    } catch (BarnEmptyException e){
        cout << e.what();
    } catch (NoItemInStorageException& e){
        cout << e.what();
    } catch (InputException e) {
        cout << e.what();
    } catch (InvalidSlotException e) {
        cout << e.what();
    } catch (NotFoodException e) {
        cout << e.what();
    } catch (NoFoodInStorageException e) {
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
        vector<string> garden = Barn.printHarvestedItem();

        int num, capacity;
        while(true){
            try{
                cout<< "\nAnimal number you want to harvest: ";
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

                if (num<1 || num> garden.size() || capacity<1 || Barn.countItemsHarvested(garden[num-1])<capacity){
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
                
                    int rowField = Barn.positionCodetoRow(landSlot);
                    int colField = Barn.positionCodetoCol(landSlot);
                    
                    if (!Barn.isItemValid(rowField,colField)){
                    throw InvalidSlotException();
                    }
                    if(Barn.isSlotEmpty(rowField,colField)){
                        throw InputException();
                    }
                    if(!Barn.getItemInfo(landSlot)->isReadyToHarvest() || Barn.isSlotEmpty(rowField,colField) || !Barn.isItemValid(rowField,colField)){
                        throw InvalidSlotException();
                    }

                    Barn.getItem(rowField,colField);
                    selectedPlots.push_back(landSlot);
                    break;
                } catch(InvalidSlotException e){
                    cout << e.what();
                } catch (InputException e){
                    cout << e.what();
                } catch (ItemNotFoundException e){
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
        cout<<capacity<<" plots of "<< garden[num-1] << " animals in plots ";
        for(int i=0;i<selectedPlots.size()-1;i++){
            cout<<selectedPlots[i]<<", ";
        }
        cout<<selectedPlots[selectedPlots.size()-1]<<" have been harvested"<<endl;
    } catch (HarvestException e) {
        cout << e.what();
    } 
}

void AnimalFarmer::minAnimalWeight(){
    for (int i = 0; i < Barn.getRow(); i++) {
        for (int j = 0; j < Barn.getCol(); j++) {
            if (Barn.getItemInfoInt(i,j) != nullptr) {
                Animal *x = Barn.getItemInfoInt(i,j);
                x->minWeight();
                Barn.getItem(i,j);
                Barn.setItem(i,j,x);
            }
        }
    }
}

void AnimalFarmer::delItemRisk(){
    Barn.deleteItem();
}

void AnimalFarmer::printBarn() {
    Barn.printStorage("Barn",1); 
    Barn.printLegends();
}

vector<Animal*> AnimalFarmer::getListOfAnimals() const{
    return this->Barn.getListOfContents();
}