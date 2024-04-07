#ifndef __LOADER_HPP__
#define __LOADER_HPP__

#include "../Item/Animal/Animal.hpp"
#include "../Item/Animal/Herbivore.hpp"
#include "../Item/Animal/Carnivore.hpp"
#include "../Item/Animal/Omnivore.hpp"
#include "../Item/Plant/Plant.hpp"
#include "../Item/Plant/MaterialPlant.hpp"
#include "../Item/Plant/FruitPlant.hpp"
#include "../Item/Products/Products.hpp"
#include "../Item/Products/MaterialProducts.hpp"
#include "../Item/Products/PlantsProducts.hpp"
#include "../Item/Products/ProductsAnimal.hpp"
#include  "../Item/Building/Building.hpp"
#include "../misc/Misc.hpp"
#include "../Player/Player.hpp"
#include "../Shop/Shop.hpp"
#include "../Exception/FileException.hpp"

#include "string.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Loader
{
protected:
  static string configPath;
  static string testsPath;

public:
  // getter for configPath
  static string getConfigPath();
  // getter for testsPath
  static string getTestsPath();
  // get count of test file
//   int countOfTestFile(string path);
  // split words from sentences to a vector of string
  vector<string> getWordsFromSentence(string);
  // read each words from file
  vector<vector<string>> getWordsFromFile(string);
  // vector of animal
  vector<Animal> configOfAnimal();
  // vector of plant
  vector<Plant> configOfPlant();
  // vector of products
  vector<Products> configOfProducts();
  // vector of recipe (building)
  vector<Building> configOfBuildingRecipes();
  // get misc
  Misc configOfMisc();
  // vector of Player
  vector<Player> stateOfPlayer();  
  // get shop
  Shop stateOfShop();


};

#endif