#include "Building.hpp"

Building::Building(int id, std::string code, std::string name, std::string type, int recipeId, std::string recipeCode, std::string recipeName)
    : Item(id, code, name, type), recipeId(recipeId), recipeCode(recipeCode), recipeName(recipeName) {}

Building::~Building() {}

void Building::recipe() {
    // Implementation of recipe
}

void Building::recipe(int recipe_id, string recipe_code, string recipe_name) {
    recipeId = recipe_id;
    recipeCode = recipe_code;
    recipeName = recipe_name;
}

void Building::addRecipeMaterial(string recipeMaterial, int material, int price) {
    materials[recipeMaterial] = make_pair(material, price);
}

int Building::calculatePrice() {
    // Implementation of price calculation
    int totalPrice = 0;
    for (const auto& pair : materials) {
        // Calculate price based on material, its quantity and price 
        totalPrice += pair.second.first * pair.second.second;
    }
    return totalPrice;
}

