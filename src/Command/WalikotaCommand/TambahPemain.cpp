#include "TambahPemain.hpp"

void TambahPemain::useCommand(){
    if (players[currPlayer]->getPlayerWealth() < 50) {
        cout << "\033[1;31mNot enough money, Please get more money first :)\033[0m" << endl;
    }
    else {
        while(true){
            try {
            cout << "Enter player type: ";
            string pemain;
            cout << "\033[1;92m";
            cin >> pemain;
            cout << "\033[0m";
            if (lowerCase(pemain) != "petani" && lowerCase(pemain) != "peternak") {
                throw InputException();
            }
            else {
                string name = inputName();
                if (lowerCase(pemain) != "peternak") {
                    this->players.push_back(new AnimalFarmer(name, 50, 40));
                }
                else {
                    this->players.push_back(new PlantFarmer(name, 50, 40));
                }
                players[currPlayer]->minPlayerWealth(50);

                if(players[currPlayer]->getName()<name){
                    currPlayer+=1;
                }

                cout << "New Player Added!"<<endl; 
                cout<<"Welcome \""<<pemain<<"\" in MarhabanTiba Kingdom\n";
                break;
            }
            } catch (InputException e) {
                cout << e.what();
            }
        }
    }
}

string TambahPemain::getName() {
    return "TAMBAH_PEMAIN";
}