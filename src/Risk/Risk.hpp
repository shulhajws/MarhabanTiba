#ifndef RISK_HPP
#define RISK_HPP
#include <iostream>
using namespace std;

#include "../Game/Game.hpp"

class Risk : Game {
    public:
        virtual void useRisk() = 0;
        virtual string getName() = 0;
};

class HarvestFestivalBonus : public Risk {
    public:
        void useRisk() override;
        string getName() override;
};

class GoodFarmerBlessing : public Risk {
    public:
            void useRisk() override;
            string getName() override;
};

class EquipmentBreakdown : public Risk {
    public:
        void useRisk() override;
        string getName() override;
};

class WildAnimalAttacks : public Risk {
    public:
        void useRisk() override;
        string getName() override;
};

class DiseaseOutbreak : public Risk {
    public:
        void useRisk() override;
        string getName() override;
};


#endif