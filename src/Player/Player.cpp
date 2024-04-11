#include "Player.hpp"
#include "../Command/AllCommand/Next.hpp"
#include "../Command/AllCommand/CetakStorage.hpp"
#include "../Command/AllCommand/Makan.hpp"
#include "../Command/AllCommand/Beli.hpp"
#include "../Command/AllCommand/Jual.hpp"
#include <iostream>
using namespace std;

Player::Player(){
    this->commandList.push_back(new Next());
    this->commandList.push_back(new CetakStorage());
    this->commandList.push_back(new Makan());
    this->commandList.push_back(new Jual());
    this->commandList.push_back(new Beli());
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

bool Player::inventoryEmpty(){
    return inventory.isEmpty();
}

void Player::eat() {
    string slot;
    while(true) {
        try {
            if (inventory.isEmpty()) {
                throw NoItemInStorageException();
            }

            cout << "Slot: ";
            cin >> slot;
            int row = inventory.positionCodetoRow(slot);
            int col = inventory.positionCodetoCol(slot);

            Item* storedItem = inventory.getItemInfo(row, col);
            if ((storedItem->getType() == "PRODUCT_FRUIT_PLANT" || storedItem->getType() == "PRODUCT_ANIMAL")) {
                Product* productPtr = dynamic_cast<Product*>(storedItem);
                int addedWeight = productPtr->getAddedWeight();
                weight += addedWeight;
                
                cout << "Player " << username << " has eaten " << storedItem->getName() << ". Weight increased by " << addedWeight << " kg.\n";
                break;
            } else {
                throw ItemNotFoundException();
            }
        } catch (ItemNotFoundException e) {
            cout << e.what()<<endl;
            break;
        } catch (NoItemInStorageException e) {
            cout << e.what()<<endl;
            break;
        }
    }
}

void Player::buyItem(){
    Shop s;
    s.printShop();
    cout<<"\nYour money: "<<wealth<<endl;
    cout<<"Available storage slots: "<<inventory.getAvailableSlots()<<endl;
    
    int buy,capacity;

    while (true){
        try{
            cout<<"\nItem to be purchased: ";
            cin>>buy;
            cout<<"Capacity: ";
            cin>>capacity;
            if((int)buy>(int)s.totalItem()||(int)buy<1){
                throw ItemNotFoundException();
            }
            if (capacity>inventory.getAvailableSlots()){
                throw NotEnoughInventorySpaceException();
            }
            if(s.getItem(buy)->getPrice()*capacity>wealth){
                throw NotEnoughMoneyException();
            }
            if(capacity<1){
                throw InputException();
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
                    break;
                } catch(InputException e){
                    cout<<e.what();
                } catch(InvalidSlotException e){
                    cout<<e.what();
                }
            }
            if(success == capacity){
                inventory.printStorage("Storage",0);
                cout<<"\n Congratulations! You have successfully purchased "<<capacity<<" "<<s.getItem(buy)->getName()<<". You have "<<wealth<<" gulden remaining."<<endl;
            }
            break;
        } catch(ItemNotFoundException e){
            cout<<e.what()<<endl;
        }
        catch(InputException e){
            cout<<e.what();
        }
        catch(NotEnoughInventorySpaceException e){
            cout<<e.what()<<endl;
        }
        catch(NotEnoughMoneyException e){
            cout<<e.what()<<endl;
        }
    } 
    
}

void Player::sellItem(){
    Shop s;
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
                int row,col;
                for (int i=0;i<slots.size();i++){
                    row = inventory.positionCodetoRow(slots[i]);
                    col = inventory.positionCodetoCol(slots[i]);
                    inventory.isItemValid(row,col);
                    if(inventory.isSlotEmpty(row,col)){
                        throw InvalidSlotException();
                    }
                }

                int money = 0;
                for (int i=0;i<slots.size();i++){
                    row = inventory.positionCodetoRow(slots[i]);
                    col = inventory.positionCodetoCol(slots[i]);
                    Item* it = (inventory.getItem(row,col));
                    addPlayerWealth(it->getPrice());
                    money += it->getPrice();
                    s = s + *it;
                }

                cout<<"Your items have been sold successfully! You earned "<<money<<" guilders!"<<endl;
                break;

            } catch(InvalidSlotException e){
                cout<<e.what()<<endl;
            } catch(ItemNotFoundException e){
                cout<<e.what()<<endl;
            }
        
        }
    }
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

void Player::displayInfo() const {
    cout << "Username: " << this->username << endl;
    cout << "Wealth  : " << this->wealth << endl;
    cout << "Weight  : " << this->weight << endl;
}