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
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                string name = inputName();
                if (lowerCase(pemain) == "peternak") {
                    this->players.push_back(new AnimalFarmer(name, 50, 0));
                }
                else {
                    this->players.push_back(new PlantFarmer(name, 50, 0));
                }
                players[currPlayer]->minPlayerWealth(50);

                if((players[currPlayer]->getName())>name){
                    Game::tambahPemain += 1;
                }

                cout << "New Player Added!"<<endl; 
                cout<<"Welcome \""<<name<<"\" in MarhabanTiba Kingdom\n";
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
