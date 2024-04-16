#include "Risk.hpp"

void Risk::initializeRisks(){
    risk.push_back(new DiseaseOutbreak());
    risk.push_back(new HarvestFestivalBonus());
    risk.push_back(new GoodFarmerBlessing());
    risk.push_back(new EquipmentBreakdown());
    risk.push_back(new WildAnimalAttacks());
}

void Risk::getRandomRisk(Player* p){
    initializeRisks();
    cout<<"You take a risk!"<<endl;
    int randomNumber = rand() % risk.size();
    cout<<"You got "<<risk[randomNumber]->getName()<<endl;
    risk[randomNumber]->useRisk(p);
}

void Risk::useRisk(Player* p){
}

string Risk::getName(){
    return "Risk";
}

void HarvestFestivalBonus::useRisk(Player* p) {
    cout << "You've received a bonus from the harvest festival!" << endl; 
    cout << "You got 50 extra gulden\n" << endl; 

    p->addPlayerWealth(50);
}

string HarvestFestivalBonus::getName() {
    return "Harvest Festival Bonus";
}


void GoodFarmerBlessing :: useRisk(Player* player) {
    cout << "Your farm is blessed because you are a good farmer!" << endl;

    if(player->getType()=="Peternak"){
        AnimalFarmer* p = dynamic_cast<AnimalFarmer*>(player);
        cout << "As an animal farmer, you received a Cow and 15 gulden as a reward!\n" << endl;
        p->placeAnimalRisk();
    }
    else{
        PlantFarmer* p = dynamic_cast<PlantFarmer*>(player);
        cout << "As an plant farmer, you received a Apple Tree and 15 gulden as a reward!\n" << endl;
        p->plantCropRisk();
    }
}

string GoodFarmerBlessing :: getName() {
    return "Good Weather Blessing";
}

void EquipmentBreakdown :: useRisk(Player* player) {
    cout << "Your farming equipment has broken down!" << endl;
    cout << "You have to pay 20 gulden for maintenance." << endl;
    int playerWealth = player->getPlayerWealth();

    if (playerWealth >= 20) {
        cout << "Deducting 20 gulden from your wealth." << endl;
        player->minPlayerWealth(20); 
    } else {
        cout << "Unfortunately, you don't have enough wealth to cover the full cost." << endl;

        if (playerWealth > 0) {
            cout << "You'll pay as much as you can (" << playerWealth << " gulden)." << endl;
            player->minPlayerWealth(playerWealth);
        } else {
            cout << "You have no wealth left. The equipment remains broken." << endl;
        }
    }
    
}

string EquipmentBreakdown :: getName() {
    return "Equipment Breakdown";
}

void WildAnimalAttacks :: useRisk(Player* player)  {
    cout << "Wild animals are attacking your farm!" << endl;
    if(player->getType()=="Peternak"){
        AnimalFarmer* p = dynamic_cast<AnimalFarmer*>(player);
        cout << "One of your animals was eaten by wild animals.\n" << endl;
        p->delItemRisk();
    }
    else{
        PlantFarmer* p = dynamic_cast<PlantFarmer*>(player);
        cout << "One of your plant was eaten by wild animal\n" << endl;
        p->delItemRisk();
    }
}

string WildAnimalAttacks :: getName() {
    return "Wild Animal Attacks";
}

void DiseaseOutbreak :: useRisk(Player* player) {
    cout << "Your garden have been infected by a disease!" << endl;
    if(player->getType()=="Peternak"){
        AnimalFarmer* p = dynamic_cast<AnimalFarmer*>(player);
        cout << "Your animal is getting sick, all of your animal weights decreased by 2\n" << endl;
        p->minAnimalWeight();
    }
    else{
        PlantFarmer* p = dynamic_cast<PlantFarmer*>(player);
        cout << "Your plant is getting sick, all of your plant years decreased by 1\n" << endl;
        p->minPlantYear();
    }
}

string DiseaseOutbreak :: getName() {
    return "Disease Outbreak";
}