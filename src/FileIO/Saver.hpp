#ifndef __SAVER_HPP__
#define __SAVER_HPP__

#include "../Item/Animal/Animal.hpp"
#include "../Item/Animal/Herbivore.hpp"
#include "../Item/Animal/Carnivore.hpp"
#include "../Item/Animal/Omnivore.hpp"
#include "../Item/Plant/Plant.hpp"
#include "../Item/Plant/MaterialPlant.hpp"
#include "../Item/Plant/FruitPlant.hpp"
#include "../Item/Product/Product.hpp"
#include "../Item/Product/ProductMaterial.hpp"
#include "../Item/Product/ProductFruitPlant.hpp"
#include "../Item/Product/ProductAnimal.hpp"
#include "../Item/Building/Building.hpp"
#include "../Misc/Misc.hpp"
#include "../Player/Player.hpp"
#include "../Player/AnimalFarmer.hpp"
#include "../Player/PlantFarmer.hpp"
#include "../Player/Mayor.hpp"
#include "../Shop/Shop.hpp"
#include "../Exception/Exception.hpp"
#include "../Exception/FileException.hpp"
#include "../Exception/LoaderException.hpp"
#include "../Storage/Storage.hpp"

#include "string.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>

class Saver
{
private:
    static string testsPath;

public: 
    static string getTestsPath();
    void saveGameState(string filepath, const vector<Player*>&, const Shop&);

};

#endif