#ifndef RISK_HPP
#define RISK_HPP
#include <iostream>
using namespace std;

#include "../Player/Player.hpp"
#include "../Player/AnimalFarmer.hpp"
#include "../Player/PlantFarmer.hpp"
#include "../Item/Product/ProductAnimal.hpp"

class Risk{
    private:
        vector<Risk*> risk;
    public:
        void initializeRisks();
        void getRandomRisk(Player*);
        virtual void useRisk(Player*);
        virtual string getName();
};

class HarvestFestivalBonus : public Risk {
    public:
        void useRisk(Player*) override;
        string getName() override;
};

class GoodFarmerBlessing : public Risk {
    public:
            void useRisk(Player*) override;
            string getName() override;
};

class EquipmentBreakdown : public Risk {
    public:
        void useRisk(Player*) override;
        string getName() override;
};

class WildAnimalAttacks : public Risk {
    public:
        void useRisk(Player*) override;
        string getName() override;
};

class DiseaseOutbreak : public Risk {
    public:
        void useRisk(Player*) override;
        string getName() override;
};

class NotScamMLM : public Risk {
    public:
        void useRisk(Player*) override;
        string getName() override;
};

class IftarTime : public Risk {
    public:
        void useRisk(Player*) override;
        string getName() override;
};

class BedahRumahShow : public Risk {
    public:
        void useRisk(Player*) override;
        string getName() override;
};

class GainWeightInEid : public Risk {
    public:
        void useRisk(Player*) override;
        string getName() override;
};

class RamadanDiet : public Risk {
    public:
        void useRisk(Player*) override;
        string getName() override;
};



#endif