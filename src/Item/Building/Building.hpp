#ifndef BUILDING_HPP
#define BUILDING_HPP

#include "../Item.hpp"
#include <map>
#include <string>
#include <iostream>
using namespace std;

class Building : public Item {
private:
    int recipeId;
    string recipeCode;
    string recipeName;
    map<string, pair<int,int>> materials;

public:
    Building(int id, string code, string name, string type, int recipeId, string recipeCode, string recipeName);
    ~Building();
    void recipe();
    void recipe(int recipe_id, string recipe_code, string recipe_name);
    void addRecipeMaterial(string recipeMaterial, int material, int price);
    int calculatePrice();
};

#endif // BUILDING_HPP
