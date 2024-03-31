#include "Mayor.hpp"
#include "../Command/WalikotaCommand/Bangun.hpp"
#include "../Command/WalikotaCommand/PungutPajak.hpp"

Mayor::Mayor() : Player(){
    this->commandList.push_back(new Bangun());
    this->commandList.push_back(new PungutPajak());
}

Mayor::Mayor(string username, int wealth, int weight) : Player(username, wealth, weight) {
    this->commandList.push_back(new Bangun());
    this->commandList.push_back(new PungutPajak());
}