#include "Mayor.hpp"
#include "../Command/WalikotaCommand/Bangun.hpp"
#include "../Command/WalikotaCommand/PungutPajak.hpp"
#include "../Command/WalikotaCommand/TambahPemain.hpp"

Mayor::Mayor() : Player(){
    this->commandList.push_back(new Bangun());
    this->commandList.push_back(new PungutPajak());
    this->commandList.push_back(new TambahPemain());
}

Mayor::Mayor(string username, int wealth, int weight) : Player(username, wealth, weight, "Walikota") {
    this->commandList.push_back(new Bangun());
    this->commandList.push_back(new PungutPajak());
    this->commandList.push_back(new TambahPemain());
}

int Mayor::getKTKP(){
    return 0;
}

int Mayor::getPlayerAssets(){
    return 0;
}

int Mayor::calculateTax(){
    return 0;
}

void Mayor::buildBuilding(){
    Building b;

    cout<<"\nThe building recipes are as follows:\n"<<endl;
    b.printMaterial();
    while(true){
        try{
            string build;
            cout<<"\nRequested Building: ";
            cin>>build;
            if(build!="SMALL_HOUSE"&&build!="MEDIUM_HOUSE"&&build!="LARGE_HOUSE"&&build!="HOTEL"){
                throw InputException();
            }

            map<string, int> material = b.getmaterial(build);
            if(checkMaterialCapacity(material)){
                cout<<build<<" successfully built and now belongs to the mayor!"<<endl;
            }
            else{
                cout<<"You do not have enough resources! still need ";
            }

            int index = 0;
            for (auto it = material.begin(); it != material.end(); ++it) {
                if(checkMaterialCapacity(material)){
                    inventory.deleteItemCount(it->first,it->second);

                } else{
                    if(it->second-inventory.countItems(it->first)>0){
                        if(index==material.size()-1){
                            cout<< "and "<<it->second-inventory.countItems(it->first)<<" "<<it->first<<" !"<<endl;
                        }
                        else{
                            cout<< it->second-inventory.countItems(it->first)<<" "<<it->first<<", ";
                        }
                    }
                }
                ++index;
            }

            Item* building = b.getBuilding(build);
            inventory = inventory + building;
            break;
        } catch (InputException e){
            cout << e.what();
        }
    }

}

bool Mayor::checkMaterialCapacity(map<string, int> material){
    bool enough = true;
    for (auto it = material.begin(); it != material.end(); ++it) {
        if(inventory.countItems(it->first)<it->second){
            enough = false;
        }
    }
    return enough;
}