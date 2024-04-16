#ifndef __LOADER_HPP__
#define __LOADER_HPP__

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <tuple>

#include "../Item/Animal/Animal.hpp"
#include "../Item/Plant/Plant.hpp"
#include "../Item/Product/Product.hpp"
#include "../Item/Building/Building.hpp"
#include "../Misc/Misc.hpp"
#include "../Player/Mayor.hpp"

class Loader
{
private:
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
    void configOfAnimal();
    // vector of plant
    void configOfPlant();
    // vector of products
    void configOfProduct();
    // vector of recipe (building)
    void configOfBuildingRecipes();
    // get misc
    void configOfMisc();
    // item constructor
    Item* itemConstructor(string);
    // building constructor
    Building* buildingConstructor(string);
    // product constructor
    Product* productConstructor(string itemName);
    // plant constructor
    Plant* plantConstructor(string, int);
    // animal constructor
    Animal* animalConstructor(string itemName, int animalWeight);
    // vector of Player
    vector<Player*> stateOfPlayer(string filepath, int lineCounter);
    // get shop
    void stateOfShop(string filepath, int lineCounter);
    bool isBuilding(string);
};

#endif