#include "Player.hpp"
#include "../Command/AllCommand/Next.hpp"
#include "../Command/AllCommand/CetakStorage.hpp"
#include "../Command/AllCommand/Makan.hpp"
#include "../Command/AllCommand/Beli.hpp"
#include "../Command/AllCommand/Jual.hpp"
#include "../Command/AllCommand/Simpan.hpp"
#include <iostream>
using namespace std;

Player::Player(){
    this->commandList.push_back(new Next());
    this->commandList.push_back(new CetakStorage());
    this->commandList.push_back(new Makan());
    this->commandList.push_back(new Jual());
    this->commandList.push_back(new Beli());
    this->commandList.push_back(new Simpan());
    Misc m;
    this->inventory.setRowCols(m.getStorageRow(),m.getStorageCols());
}

Player::Player(string username, int wealth, int weight, string type) : Player(){
    this->username = username;
    this->wealth = wealth;
    this->weight = weight;
    this->type = type;
}

bool Player::operator==(string command) const{
    bool ada = false; // cari command punya player atau bukan
    for (auto &c : commandList){
        if (c->getName() == command){
            ada = true; // command ada
            c->useCommand();
        }
    }
    return ada;
}


Player::Player(const Player& other) : Player(){
    this->username = other.username;
    this->wealth = other.wealth;
    this->weight = other.weight;
}

Player::~Player() {
    for (Command* cmd : commandList) {
        delete cmd;
    }
}

string Player::getName() const{
    return this->username;
}

string Player::getType() const{
    return this->type;
}

int Player::getKTKP(){
    return 0;
}

int Player::getPlayerAssets(){
    return inventory.getTotalAssets();
}

void Player::setInventory(Storage<Item*> inventory){
    this->inventory = inventory;
}

void Player::addPlayerWealth(int money){
    this->wealth += money;
}

void Player::minPlayerWealth(int money){
    this->wealth -= money;
}

int Player::getPlayerWealth() const{
    return this->wealth;
}

int Player::getPlayerWeight() const{
    return this->weight;
}

void Player::displayStorage(){
    inventory.printStorage("Storage",0);
    cout<<"Total Empty Slot: "<<inventory.getAvailableSlots()<<endl;
}

bool Player::inventoryEmpty() const{
    return inventory.isEmpty();
}

void Player::eat() {
    string slot;

    try {
        if (inventory.isEmpty()) {
            throw NoItemInStorageException();
        }

        if (inventory.noFoodInStorage()){
            throw NoFoodInStorageException();
        }

        while(true) {
            try {
                cout << "Slot: ";
                cin >> slot;
                int row = inventory.positionCodetoRow(slot);
                int col = inventory.positionCodetoCol(slot);
                cout << row<< col<< endl;
                if (!inventory.isItemValid(row,col)){
                    throw InvalidSlotException();
                }
                if(inventory.isSlotEmpty(row,col)){
                    throw InputException();
                }

                Item* storedItem = inventory.getItemInfo(slot);
                if ((storedItem->getType() == "PRODUCT_FRUIT_PLANT" || storedItem->getType() == "PRODUCT_ANIMAL")) {
                    storedItem = inventory.getItem(row, col);
                    Product* productPtr = dynamic_cast<Product*>(storedItem);
                    int addedWeight = productPtr->getAddedWeight();
                    weight += addedWeight;
                    
                    cout << "Player " << username << " has eaten " << storedItem->getName() << ". Weight increased by " << addedWeight << " kg.\n";
                    break;
                } else {
                    throw ItemNotFoundException();
                }
            } catch (ItemNotFoundException e) {
                cout << "bukan makanan"<<endl;
                cout << e.what();
            } catch (InputException e){
                cout << e.what();
            } catch (InvalidSlotException e){
                cout<< e.what();
            }
        }
    } catch (NoFoodInStorageException e) {
        cout << e.what();
    } catch (NoItemInStorageException e) {
        cout << e.what();
    }
}
void Player::buyItem(){
    Shop s;
    s.printShop();
    cout<<"\nYour money: "<<wealth<<endl;
    cout<<"Available storage slots: "<<inventory.getAvailableSlots()<<endl;
    
    int buy,capacity;
    Item* tempItembuy = nullptr;

    while (true){
        try{
            cout<<"\nItem to be purchased: ";
            if (!(cin >> buy)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InputNotIntegerException();
            }

            cout<<"Capacity: ";
            while (!(cin >> capacity)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw InputNotIntegerException();
            }

            if((int)buy>(int)s.totalItem()||(int)buy<1){
                throw ItemNotFoundException();
            }
            if (capacity>inventory.getAvailableSlots()){
                throw NotEnoughInventorySpaceException();
            }
            if(s.getItem(buy)->getPrice()*capacity>wealth){
                throw NotEnoughMoneyException();
            }
            if(capacity<1|| capacity>(s.getCapacity(*(s.getItem(buy))))+1){
                cout << s.getCapacity(*(s.getItem(buy)))<<endl;
                throw InputException();
            }
            if(type=="Walikota" && s.isBuilding(*(s.getItem(buy)))){
                throw BuyException();
            }

            inventory.printStorage("Storage",0);

            string slot; 
            int success = 0;
            int row,col;
            while(true){
                try{
                    cout<<"\nFormat 'loc1,loc2,loc3,..'";
                    cout<<"\nSlot: ";
                    cin>>slot;
                    vector<string> slots;
                    if(capacity>1){
                        slots = splitbyComa(slot);
                        if(hasDuplicates(slots)){
                            throw InputException();
                        }
                    }
                    else{
                        slots.push_back(slot);
                    }
                    if (capacity!= slots.size()){
                        throw InputException();
                    }
                    for (int i=0;i<slots.size();i++){
                        row = inventory.positionCodetoRow(slots[i]);
                        col = inventory.positionCodetoCol(slots[i]);
                        inventory.isItemValid(row,col);
                        if (!inventory.isSlotEmpty(row,col)){
                            throw InvalidSlotException();
                        }
                     }
                    for (int i=0;i<slots.size();i++){
                        row = inventory.positionCodetoRow(slots[i]);
                        col = inventory.positionCodetoCol(slots[i]);
                        inventory.setItem(row,col,s.getItem(buy));
                        minPlayerWealth(s.getItem(buy)->getPrice());
                        success +=1;
                    }
                    if(success==capacity){
                        tempItembuy = s.getItem(buy);
                        s.minItems(*s.getItem(buy),capacity);
                    }
                    break;
                } catch(InputException e){
                    cout<<e.what();
                } catch(InvalidSlotException e){
                    cout<<e.what();
                }
            }
            if(success == capacity){
                inventory.printStorage("Storage",0);
                cout<<"\n Congratulations! You have successfully purchased "<<capacity<<" "<<tempItembuy->getName()<<". You have "<<wealth<<" gulden remaining."<<endl;
            }
            break;
        } catch (ItemNotFoundException e){
            cout << e.what();
        } catch (InputException e){
            cout << e.what();
        } catch (InputNotIntegerException e){
            cout << e.what();
        } catch (NotEnoughInventorySpaceException e){
            cout << e.what();
        } catch (NotEnoughMoneyException e){
            cout << e.what();
        } catch (BuyException e){
            cout << e.what();
        }
    } 
    
}

void Player::sellItem(){
    Shop s;
    Item* tempItemsell;

    cout<<"Here is your storage\n"<<endl;
    inventory.printStorage("Storage",0);
    if(inventory.isEmpty() ){
        cout<<"Your storage is empty!"<<endl;
        return;
    }else{
        cout<<"Please choose item you want to sell!"<<endl;
        while(true){
            try{
                string slot;
                cout<<"\nFormat 'loc1,loc2,loc3,..'";
                cout<<"\nSlot: ";
                cin>>slot;
                vector<string> slots;

                slots = splitbyComa(slot);
                if(hasDuplicates(slots)){
                    throw InvalidSlotException();
                }
                int row,col;
                for (int i=0;i<slots.size();i++){
                    row = inventory.positionCodetoRow(slots[i]);
                    col = inventory.positionCodetoCol(slots[i]);
                    inventory.isItemValid(row,col);
                    if(inventory.isSlotEmpty(row,col)){
                        throw InvalidSlotException();
                    }if(type!="Walikota" && s.isBuilding(*inventory.getItemInfo(slots[i]))){
                        cout<< "\nYou cannot sell building as a farmer !"<<endl;
                        throw SellException();
                    }
                }
                int money = 0;
                for (int i=0;i<slots.size();i++){
                    row = inventory.positionCodetoRow(slots[i]);
                    col = inventory.positionCodetoCol(slots[i]);
                    tempItemsell = (inventory.getItem(row,col));
                    addPlayerWealth(tempItemsell->getPrice());
                    money += tempItemsell->getPrice();
                    s = s + tempItemsell;
                }

                cout<<"Your items have been sold successfully! You earned "<<money<<" guilders!"<<endl;
                break;

            } catch(InvalidSlotException e){
                cout << e.what();
            } catch(ItemNotFoundException e){
                cout << e.what();
            } catch(SellException e){
                cout << e.what();
            }
        
        }
    }
}

bool Player::hasDuplicates(const vector<string>& slots) {
    for (int i = 0; i < slots.size(); ++i) {
        for (int j = i + 1; j < slots.size(); ++j) {
            if (slots[i] == slots[j]) {
                return true;  
            }
        }
    }
    return false;  
}

vector<string> Player::splitbyComa(const string& input) { // bentar masih ngebug ntar dilanjut
    vector<string> items;
    int start = 0;
    int end = input.find(",");

    while (end != string::npos) {
        string item = input.substr(start, end - start);

        item.erase(0, item.find_first_not_of(" \t"));
        items.push_back(item);

        start = end + 1;
        end = input.find(",", start);
    }

    string lastItem = input.substr(start);
    lastItem.erase(0, lastItem.find_first_not_of(" \t"));
    items.push_back(lastItem);

    return items;
}

int Player::itemInInventories() const{
    return this->inventory.countFilledCells();
}

void Player::displayInfo() const {
    cout << "Username: " << this->username << endl;
    cout << "Wealth  : " << this->wealth << endl;
    cout << "Weight  : " << this->weight << endl;
}

vector<Item*> Player::getListOfItems() const{
    return this->inventory.getListOfContents();
}