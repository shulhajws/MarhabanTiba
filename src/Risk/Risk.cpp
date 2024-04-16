#include "Risk.hpp"

void Risk::initializeRisks(){
    risk.push_back(new DiseaseOutbreak());
    risk.push_back(new HarvestFestivalBonus());
    risk.push_back(new GoodFarmerBlessing());
    risk.push_back(new EquipmentBreakdown());
    risk.push_back(new WildAnimalAttacks());
    risk.push_back(new NotScamMLM());
    risk.push_back(new IftarTime());
    risk.push_back(new BedahRumahShow());
}

void Risk::getRandomRisk(Player* p){
    initializeRisks();
    cout<<"\033[1;95m\nYou take a risk!"<<endl;
    int randomNumber = rand() % risk.size();
    cout<<"You got "<<risk[randomNumber]->getName()<< "\033[0m"<<endl;
    risk[randomNumber]->useRisk(p);
}

void Risk::useRisk(Player* p){
}

string Risk::getName(){
    return "Risk";
}

void HarvestFestivalBonus::useRisk(Player* p) {
    cout << "\033[1;96mYou've received a bonus from the harvest festival!" << endl; 
    cout << "You got 50 extra gulden\033[0m" << endl; 

    p->addPlayerWealth(50);
}

string HarvestFestivalBonus::getName() {
    return "Harvest Festival Bonus";
}


void GoodFarmerBlessing :: useRisk(Player* player) {
    cout << "\033[1;96mYour farm is blessed because you are a good farmer!" << endl;

    if(player->getType()=="Peternak"){
        AnimalFarmer* p = dynamic_cast<AnimalFarmer*>(player);
        cout << "As an animal farmer, you received a Cow and 15 gulden as a reward!\033[0m" << endl;
        p->placeAnimalRisk();
    }
    else{
        PlantFarmer* p = dynamic_cast<PlantFarmer*>(player);
        cout << "As an plant farmer, you received a Apple Tree and 15 gulden as a reward!\033[0m" << endl;
        p->plantCropRisk();
    }
}

string GoodFarmerBlessing :: getName() {
    return "Good Weather Blessing";
}

void EquipmentBreakdown :: useRisk(Player* player) {
    cout << "\033[1;31mYour farming equipment has broken down!" << endl;
    cout << "You have to pay 20 gulden for maintenance." << endl;
    int playerWealth = player->getPlayerWealth();

    if (playerWealth >= 20) {
        cout << "Deducting 20 gulden from your wealth. \033[0m" << endl;
        player->minPlayerWealth(20); 
    } else {
        cout << "Unfortunately, you don't have enough wealth to cover the full cost." << endl;

        if (playerWealth > 0) {
            cout << "You'll pay as much as you can (" << playerWealth << " gulden).\033[0m" << endl;
            player->minPlayerWealth(playerWealth);
        } else {
            cout << "You have no wealth left. The equipment remains broken.\033[0m" << endl;
        }
    }
    
}

string EquipmentBreakdown :: getName() {
    return "Equipment Breakdown";
}

void WildAnimalAttacks :: useRisk(Player* player)  {
    cout << "\033[1;31mWild animals are attacking your farm!" << endl;
    if(player->getType()=="Peternak"){
        AnimalFarmer* p = dynamic_cast<AnimalFarmer*>(player);
        cout << "One of your animals was eaten by wild animals.\033[0m" << endl;
        p->delItemRisk();
    }
    else{
        PlantFarmer* p = dynamic_cast<PlantFarmer*>(player);
        cout << "One of your plant was eaten by wild animals.\033[0m" << endl;
        p->delItemRisk();
    }
}

string WildAnimalAttacks :: getName() {
    return "Wild Animal Attacks";
}

void DiseaseOutbreak :: useRisk(Player* player) {
    cout << "\033[1;31mYour garden have been infected by a disease!" << endl;
    if(player->getType()=="Peternak"){
        AnimalFarmer* p = dynamic_cast<AnimalFarmer*>(player);
        cout << "Your animal is getting sick, all of your animal weights decreased by 2.\033[0m" << endl;
        p->minAnimalWeight();
    }
    else{
        PlantFarmer* p = dynamic_cast<PlantFarmer*>(player);
        cout << "Your plant is getting sick, all of your plant years decreased by 1.\033[0m" << endl;
        p->minPlantYear();
    }
}

string DiseaseOutbreak :: getName() {
    return "Disease Outbreak";
}

void NotScamMLM :: useRisk(Player* player) {
    cout << "\033[1;96mYou invested some money to join a multi-level marketing. Dreaming your farm to be as great as those in Nuu Zee Land." << endl;
    cout << "You join an MLM and suddenly your wealth is double dripper.\033[0m" << endl;
    int wealth = player->getPlayerWealth();
    cout << "Your before now is " << wealth << " gulden." << endl;
    player->addPlayerWealth(wealth);
    cout << "Your wealth now is " << player->getPlayerWealth() << " gulden. Thanks the Mayor!\033[0m" << endl;
}

string NotScamMLM :: getName() {
    return "MLM Anti Scam";
}

void IftarTime :: useRisk(Player* player) {
    cout << "\033[1;96mIt's iftar time in MarhabanTiba kingdom. The kingdom is giving you 3 chicken eggs and 3 duck eggs for your iftar.\033[0m" << endl;
    for (int i = 0; i < 3; i++) {
        player->setIteminInventory(new ChickenEgg());
        player->setIteminInventory(new DuckEgg());
    }
    player->displayStorage();
}

string IftarTime :: getName() {
    return "Iftar Time";
}

void BedahRumahShow :: useRisk(Player* player) {
    cout << "\033[1;96mCongrats! You got some surprise from MarhabanTiba Ent. They are renovating your houses to hotels.\033[0m" << endl;
    player->upgradeBuildingRisk();
    player->displayStorage();
}

string BedahRumahShow :: getName() {
    return "Bedah Rumah Show";
}