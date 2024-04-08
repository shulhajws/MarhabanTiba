#include "Loader.hpp"
using namespace std;

string Loader::configPath = "./config";
string Loader::testsPath = "./data";

/* get folder config path */
string Loader::getConfigPath(){
  return Loader::configPath;
}

/* get tests config path */
string Loader::getTestsPath(){
  return Loader::testsPath;
}

/* split sentences into vector of words */
vector<string> Loader::getWordsFromSentence(string sentence) {
  vector<string> words;
  string word = "";

  for (auto cc : sentence){
    if (cc == ' '){
      words.push_back(word);
      word = "";
    }
    else{
      word += cc;
    }
  }
  words.push_back(word);
  return words;
}

vector<vector<string>> Loader::getWordsFromFile(string filepath) {
  vector<vector<string>> vectorOfWords;
  vector<string> words;
  string sentenceLine;
  ifstream configFileToWords(filepath);
  
  if (!configFileToWords){
    throw FileException(filepath);
  } else{
    while (getline(configFileToWords, sentenceLine)){
      words = getWordsFromSentence(sentenceLine);
      vectorOfWords.push_back(words);
    }
  }
  configFileToWords.close();

  return vectorOfWords;
}

vector<Animal> Loader::configOfAnimal(){
  vector<vector<string>> vectorOfWords;

  try {
    vectorOfWords = Loader::getWordsFromFile(this->configPath + "/animal.txt");
  } catch (FileException &FE){
    cout << FE.what();
  }
  
  vector<Animal> animals;
  for (int i = 0; i < vectorOfWords.size(); i++){
    int ID = stoi(vectorOfWords[i][0]);
    int harvestWeight = stoi(vectorOfWords[i][4]);
    int price =  stoi(vectorOfWords[i][5]);
    
    if (ID == 1) {
        animals.push_back(Cow(harvestWeight, price));
    } else if (ID == 2) {
        animals.push_back(Sheep(harvestWeight, price));
    } else if (ID == 3) {
        animals.push_back(Horse(harvestWeight, price));
    } else if (ID == 4) {
        animals.push_back(Rabbit(harvestWeight, price));
    } else if (ID == 5) {
        animals.push_back(Snake(harvestWeight, price));
    } else if (ID == 6) {
        animals.push_back(Chicken(harvestWeight, price));
    } else if (ID == 7) {
        animals.push_back(Duck(harvestWeight, price));
    } else {
        // throw exception ? / print out mssge?
    }     
  }
  return animals;
}

vector<Plant> Loader::configOfPlant(){
  vector<vector<string>> vectorOfWords;

  try {
    vectorOfWords = Loader::getWordsFromFile(this->configPath + "/plant.txt");
  } catch (FileException &FE){
    cout << FE.what();
  }
  
  vector<Plant> plants;

  for (int i = 0; i < vectorOfWords.size(); i++){
    int ID = stoi(vectorOfWords[i][0]);
    int harvestDuration = stoi(vectorOfWords[i][4]);
    int price =  stoi(vectorOfWords[i][5]);
    
    if (ID == 1) {
        plants.push_back(TeakTree(harvestDuration, price));
    } else if (ID == 2) {
        plants.push_back(SandalwoodTree(harvestDuration, price));
    } else if (ID == 3) {
        plants.push_back(AloeTree(harvestDuration, price));
    } else if (ID == 4) {
        plants.push_back(IronwoodTree(harvestDuration, price));
    } else if (ID == 5) {
        plants.push_back(AppleTree(harvestDuration, price));
    } else if (ID == 6) {
        plants.push_back(OrangeTree(harvestDuration, price));
    } else if (ID == 7) {
        plants.push_back(BananaTree(harvestDuration, price));
    } else if (ID == 8) {
        plants.push_back(GuavaTree(harvestDuration, price));
    } else {
        // throw exception ? / print out mssge?
    }     
  }
  return plants;
}

vector<Products> Loader::configOfProducts(){
  vector<Products> products;
  return products;
  //TO DO
}

vector<Building> Loader::configOfBuildingRecipes(){
  vector<vector<string>> vectorOfWords;

  try {
    vectorOfWords = Loader::getWordsFromFile(this->configPath + "/recipe.txt");
  } catch (FileException &FE){
    cout << FE.what();
  }
  
  vector<Building> buildings;
  for (int i = 0; i < vectorOfWords.size(); i++){
    int ID = stoi(vectorOfWords[i][0]);
    int price = stoi(vectorOfWords[i][3]);
    
    if (ID == 1) {
      SmallHouse smallHouse(price);
      for (int j = 4; j < vectorOfWords[i].size(); j += 2) {
        string materialName = vectorOfWords[i][j];
        int materialQty = stoi(vectorOfWords[i][j + 1]);
        smallHouse.addRecipeMaterial(materialName, materialQty);
      }
      buildings.push_back(smallHouse);
    } else if (ID == 2) {
      MediumHouse mediumHouse(price);
      for (int j = 4; j < vectorOfWords[i].size(); j += 2) {
        string materialName = vectorOfWords[i][j];
        int materialQty = stoi(vectorOfWords[i][j + 1]);
        mediumHouse.addRecipeMaterial(materialName, materialQty);
      }
      buildings.push_back(mediumHouse);
    } else if (ID == 3) {
      LargeHouse largeHouse(price);
      for (int j = 4; j < vectorOfWords[i].size(); j += 2) {
        string materialName = vectorOfWords[i][j];
        int materialQty = stoi(vectorOfWords[i][j + 1]);
        largeHouse.addRecipeMaterial(materialName, materialQty);
      }
      buildings.push_back(largeHouse);
    } else if (ID == 4) {
      Hotel hotel(price);
      for (int j = 4; j < vectorOfWords[i].size(); j += 2) {
        string materialName = vectorOfWords[i][j];
        int materialQty = stoi(vectorOfWords[i][j + 1]);
        hotel.addRecipeMaterial(materialName, materialQty);
      }
      buildings.push_back(hotel);
    } else {
        // throw exception ? / print out mssge?
    }     
  }

  return buildings;
  //TO DO
}

Misc Loader::configOfMisc(){
  vector<vector<string>> vectorOfWords;
  try {
    vectorOfWords = Loader::getWordsFromFile(this->configPath + "/misc.txt");
  } catch (FileException &FE){
    cout << FE.what();
  }

  int minMoney = stoi(vectorOfWords[0][0]);
  int minWeight = stoi(vectorOfWords[1][0]);
  int storageRow = stoi(vectorOfWords[2][0]);
  int storageCols = stoi(vectorOfWords[2][1]);
  int fieldRow = stoi(vectorOfWords[3][0]);
  int fieldCols = stoi(vectorOfWords[3][1]);
  int barnRow = stoi(vectorOfWords[4][0]);
  int barnCols = stoi(vectorOfWords[4][1]);
  return Misc(minMoney, minWeight, storageRow, storageCols, fieldRow, fieldCols, barnRow, barnCols);
}

Item Loader::itemConstructor(string itemName){
  if (itemName == "TEAK_TREE"){
    return TeakTree();
  } else if (itemName == "SANDALWOOD_TREE"){
    return SandalwoodTree();
  } else if (itemName == "ALOE_TREE"){
    return AloeTree();
  } else if (itemName == "IRONWOOD_TREE"){
    return IronwoodTree();
  } else if (itemName == "APPLE_TREE"){
    return AppleTree();
  } else if (itemName == "ORANGE_TREE"){
    return OrangeTree();
  } else if (itemName == "BANANA_TREE"){
    return BananaTree();
  } else if (itemName == "GUAVA_TREE"){
    return GuavaTree();
  } else if (itemName == "COW"){
    return Cow();
  } else if (itemName == "SHEEP"){
    return Sheep();
  } else if (itemName == "HORSE"){
    return Horse();
  } else if (itemName == "RABBIT"){
    return Rabbit();
  } else if (itemName == "SNAKE"){
    return Snake();
  } else if (itemName == "CHICKEN"){
    return Chicken();
  } else if (itemName == "DUCK"){
    return Duck();
  } else if (itemName == "SMALL_HOUSE"){
    return SmallHouse();
  } else if (itemName == "MEDIUM_HOUSE"){
    return MediumHouse();
  } else if (itemName == "LARGE_HOUSE"){
    return LargeHouse();
  } else if (itemName == "HOTEL"){
    return Hotel();
  // } else if (itemName == "TEAK_WOOD"){
  //   return Sandalwood();
  // } else if (itemName == "SANDALWOOD_WOOD"){
  //   return Sandalwood();
  // } else if (itemName == "ALOE_WOOD"){
  //   return Sandalwood();
  // } else if (itemName == "IRONWOOD_WOOD"){
  //   return Sandalwood();
  // } else if (itemName == "APPLE"){
  //   return Sandalwood();
  // } else if (itemName == "ORANGE"){
  //   return Sandalwood();
  // } else if (itemName == "BANANA"){
  //   return Sandalwood();
  // } else if (itemName == "GUAVA"){
  //   return Sandalwood();
  } else if (itemName == "COW_MEAT"){
    return Cow();
  } else if (itemName == "SHEEP_MEAT"){
    return Sheep();
  } else if (itemName == "HORSE_MEAT"){
    return Horse();
  } else if (itemName == "RABBIT_MEAT"){
    return Rabbit();
  } else if (itemName == "SNAKE_MEAT"){
    return Snake();
  } else if (itemName == "CHICKEN_MEAT"){
    return Chicken();
  } else if (itemName == "DUCK_MEAT"){
    return Duck();
  } else if (itemName == "CHICKEN_EGG"){
    return Chicken();
  } else if (itemName == "DUCK_EGG"){
    return Duck();
  } else {
    // throw something
  }
}

Plant Loader::plantConstructor(string itemName,  int plantAge = 0){
  if (itemName == "TEAK_TREE"){
    return TeakTree(plantAge);
  } else if (itemName == "SANDALWOOD_TREE"){
    return SandalwoodTree(plantAge);
  } else if (itemName == "ALOE_TREE"){
    return AloeTree(plantAge);
  } else if (itemName == "IRONWOOD_TREE"){
    return IronwoodTree(plantAge);
  } else if (itemName == "APPLE_TREE"){
    return AppleTree(plantAge);
  } else if (itemName == "ORANGE_TREE"){
    return OrangeTree(plantAge);
  } else if (itemName == "BANANA_TREE"){
    return BananaTree(plantAge);
  } else if (itemName == "GUAVA_TREE"){
    return GuavaTree(plantAge);
  }
}

Animal Loader::animalConstructor(string itemName, int animalWeight = 0){
  if (itemName == "COW"){
    return Cow(animalWeight);
  } else if (itemName == "SHEEP"){
    return Sheep(animalWeight);
  } else if (itemName == "HORSE"){
    return Horse(animalWeight);
  } else if (itemName == "RABBIT"){
    return Rabbit(animalWeight);
  } else if (itemName == "SNAKE"){
    return Snake(animalWeight);
  } else if (itemName == "CHICKEN"){
    return Chicken(animalWeight);
  } else if (itemName == "DUCK"){
    return Duck(animalWeight);
  }
}

vector<Player> Loader::stateOfPlayer(string statepath, int* ctr){
  vector<vector<string>> vectorOfWords;
  vector<Player> players;

  try {
    vectorOfWords = Loader::getWordsFromFile(this->testsPath + "/" + statepath);
  } catch (FileException &FE){
    cout << FE.what();
  }

  *ctr = 0;
  int numOfPlayers = stoi(vectorOfWords[0][0]);
  *ctr++;
  for(int i = 0; i < numOfPlayers; i++){
    string username = vectorOfWords[*ctr][0];
    string type = vectorOfWords[*ctr][1];
    int weight = stoi(vectorOfWords[*ctr][2]);
    int wealth = stoi(vectorOfWords[*ctr][3]);
    *ctr++;

    Storage<Item*> inventory;
    int numOfInventories = stoi(vectorOfWords[*ctr][0]);
    *ctr++;
    for(int j = 0; j < numOfInventories; j++){
      string inventoryItem = vectorOfWords[*ctr][0];
      inventory.setItem(0, 0, &itemConstructor(inventoryItem));
      *ctr++;
    }
    
    if (type == "Petani"){
      PlantFarmer petani(username, wealth, weight);
      petani.setInventory(inventory);
    
      Storage<Plant*> garden;
      int numOfPlants = stoi(vectorOfWords[*ctr][0]);
      *ctr++;
      for(int k = 0; k < numOfPlants; k++){
        string plantLoc = vectorOfWords[*ctr][0]; 
        string plantName = vectorOfWords[*ctr][1];
        int plantAge = stoi(vectorOfWords[*ctr][2]);
        garden.setItem(0, 0, &plantConstructor(plantName, plantAge));
        *ctr++;
      }
      petani.setGarden(garden);
      players.push_back(petani);
    } else if (type == "Peternak"){
      AnimalFarmer peternak(username, wealth, weight);
      peternak.setInventory(inventory);

      Storage<Animal*> barn;
      int numOfAnimals = stoi(vectorOfWords[*ctr][0]);
      *ctr++;
      for(int k = 0; k < numOfAnimals; k++){
        string animalLoc = vectorOfWords[*ctr][0]; 
        string animalName = vectorOfWords[*ctr][1];
        int animalWeight = stoi(vectorOfWords[*ctr][2]);
        barn.setItem(0, 0, &animalConstructor(animalName, animalWeight));
        *ctr++;
      }
      peternak.setBarn(barn);
      players.push_back(peternak);
    } else if (type == "Walikota"){
      Mayor walikota(username, wealth, weight);
      walikota.setInventory(inventory);
      players.push_back(walikota);
    } else {
      // throw something
    }
  }
}

Shop Loader::stateOfShop(string statepath, int ctr){
  vector<vector<string>> vectorOfWords;
  vector<tuple<Item, int>> shopItems;
  vector<Animal> animals = Loader::configOfAnimal();
  vector<Plant> plants = Loader::configOfPlant();

  try {
    vectorOfWords = Loader::getWordsFromFile(this->testsPath + "/" + statepath);
  } catch (FileException &FE){
    cout << FE.what();
  }

  int numOfShopItems = stoi(vectorOfWords[ctr][0]); ctr++;
  for(int i = 0; i < numOfShopItems; i++){
      string itemName = vectorOfWords[ctr][0];
      int itemQty = stoi(vectorOfWords[ctr][1]);
      ctr++;
      shopItems.push_back(make_tuple(itemConstructor(itemName), itemQty));
  }

  return Shop(shopItems, plants, animals);
}