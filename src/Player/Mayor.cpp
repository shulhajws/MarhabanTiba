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