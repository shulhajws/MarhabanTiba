#include "Loader.hpp"
#include "../Item/Animal/Herbivore.hpp"
#include "../Item/Animal/Carnivore.hpp"
#include "../Item/Animal/Omnivore.hpp"
#include "../Item/Plant/MaterialPlant.hpp"
#include "../Item/Plant/FruitPlant.hpp"
#include "../Item/Product/ProductMaterial.hpp"
#include "../Item/Product/ProductFruitPlant.hpp"
#include "../Item/Product/ProductAnimal.hpp"
#include "../Player/Player.hpp"
#include "../Player/AnimalFarmer.hpp"
#include "../Player/PlantFarmer.hpp"
#include "../Shop/Shop.hpp"
#include "../Exception/Exception.hpp"
#include "../Exception/FileException.hpp"
#include "../Exception/LoaderException.hpp"
#include "../Storage/Storage.hpp"

using namespace std;

string Loader::configPath = "./config";
string Loader::testsPath = "./data";

/* get folder config path */
string Loader::getConfigPath()
{
    return Loader::configPath;
}

/* get tests config path */
string Loader::getTestsPath()
{
    return Loader::testsPath;
}

/* split sentences into vector of words */
vector<string> Loader::getWordsFromSentence(string sentence)
{
    vector<string> words;
    string word = "";

    for (auto cc : sentence)
    {
        if (cc == ' ' || cc=='\n' )
        {
            words.push_back(word);
            word = "";
        }
        else
        {
            word += cc;
        }
    }
    words.push_back(word);
    return words;
}

vector<vector<string>> Loader::getWordsFromFile(string filepath)
{
    vector<vector<string>> vectorOfWords;
    vector<string> words;
    string sentenceLine;
    ifstream configFileToWords(filepath);

    if (!configFileToWords)
    {
        throw FileException(filepath);
    }
    else
    {
        while (getline(configFileToWords, sentenceLine))
        {
            words = getWordsFromSentence(sentenceLine);
            vectorOfWords.push_back(words);
        }
    }
    configFileToWords.close();

    return vectorOfWords;
}

void Loader::configOfAnimal()
{
    vector<vector<string>> vectorOfWords;

    try
    {
        vectorOfWords = Loader::getWordsFromFile(this->configPath + "/animal.txt");

        for (int i = 0; i < vectorOfWords.size(); i++)
        {
            int ID = stoi(vectorOfWords[i][0]);
            int harvestWeight = stoi(vectorOfWords[i][4]);
            int price = stoi(vectorOfWords[i][5]);

            if (ID == 1)
            {
                Cow(harvestWeight, price);
            }
            else if (ID == 2)
            {
                Sheep(harvestWeight, price);
            }
            else if (ID == 3)
            {
                Horse(harvestWeight, price);
            }
            else if (ID == 4)
            {
                Rabbit(harvestWeight, price);
            }
            else if (ID == 5)
            {
                Snake(harvestWeight, price);
            }
            else if (ID == 6)
            {
                Chicken(harvestWeight, price);
            }
            else if (ID == 7)
            {
                Duck(harvestWeight, price);
            }
            else
            {
                cout << "ID tidak terdefinisi. Perbaiki file konfigurasi Anda." << endl;
            }
        }
    }
    catch (FileException &FE)
    {
        cout << FE.what();
        cout << "Pastikan folder konfigurasi anda memiliki file 'animal.txt'" << endl;
    }
}

void Loader::configOfPlant()
{
    vector<vector<string>> vectorOfWords;

    try
    {
        vectorOfWords = Loader::getWordsFromFile(this->configPath + "/plant.txt");

        for (int i = 0; i < vectorOfWords.size(); i++)
        {
            int ID = stoi(vectorOfWords[i][0]);
            int harvestDuration = stoi(vectorOfWords[i][4]);
            int price = stoi(vectorOfWords[i][5]);

            if (ID == 1)
            {
                TeakTree(harvestDuration, price);
            }
            else if (ID == 2)
            {
                SandalwoodTree(harvestDuration, price);
            }
            else if (ID == 3)
            {
                AloeTree(harvestDuration, price);
            }
            else if (ID == 4)
            {
                IronwoodTree(harvestDuration, price);
            }
            else if (ID == 5)
            {
                AppleTree(harvestDuration, price);
            }
            else if (ID == 6)
            {
                OrangeTree(harvestDuration, price);
            }
            else if (ID == 7)
            {
                BananaTree(harvestDuration, price);
            }
            else if (ID == 8)
            {
                GuavaTree(harvestDuration, price);
            }
            else
            {
                cout << "ID tidak terdefinisi. Perbaiki file konfigurasi Anda." << endl;
            }
        }
    }
    catch (FileException &FE)
    {
        cout << FE.what();
        cout << "Pastikan folder konfigurasi anda memiliki file 'plant.txt'" << endl;
    }
}

void Loader::configOfProduct()
{
    vector<vector<string>> vectorOfWords;

    try
    {
        vectorOfWords = Loader::getWordsFromFile(this->configPath + "/product.txt");

        for (int i = 0; i < vectorOfWords.size(); i++)
        {
            int ID = stoi(vectorOfWords[i][0]);
            int addedWeight = stoi(vectorOfWords[i][5]);
            int price = stoi(vectorOfWords[i][6]);

            if (ID == 1)
            {
                TeakWood(addedWeight, price);
            }
            else if (ID == 2)
            {
                SandalwoodWood(addedWeight, price);
            }
            else if (ID == 3)
            {
                AloeWood(addedWeight, price);
            }
            else if (ID == 4)
            {
                IronwoodWood(addedWeight, price);
            }
            else if (ID == 5)
            {
                Apple(addedWeight, price);
            }
            else if (ID == 6)
            {
                Orange(addedWeight, price);
            }
            else if (ID == 7)
            {
                Banana(addedWeight, price);
            }
            else if (ID == 8)
            {
                Guava(addedWeight, price);
            }
            else if (ID == 9)
            {
                CowMeat(addedWeight, price);
            }
            else if (ID == 10)
            {
                SheepMeat(addedWeight, price);
            }
            else if (ID == 11)
            {
                HorseMeat(addedWeight, price);
            }
            else if (ID == 12)
            {
                RabbitMeat(addedWeight, price);
            }
            else if (ID == 13)
            {
                SnakeMeat(addedWeight, price);
            }
            else if (ID == 14)
            {
                ChickenMeat(addedWeight, price);
            }
            else if (ID == 15)
            {
                DuckMeat(addedWeight, price);
            }
             else if (ID == 16)
            {
                ChickenEgg(addedWeight, price);
            }
            else if (ID == 17)
            {
                DuckEgg(addedWeight, price);
            }
            else
            {
                cout << "ID tidak terdefinisi. Perbaiki file konfigurasi Anda." << endl;
            }
        }
    }
    catch (FileException &FE)
    {
        cout << FE.what();
    }
}

void Loader::configOfBuildingRecipes()
{
    vector<vector<string>> vectorOfWords;

    try
    {
        vectorOfWords = Loader::getWordsFromFile(this->configPath + "/recipe.txt");
        
        for (int i = 0; i < vectorOfWords.size(); i++)
        {
            int ID = stoi(vectorOfWords[i][0]);
            int price = stoi(vectorOfWords[i][3]);

            if (ID == 1)
            {
                SmallHouse smallHouse(price);
                for (int j = 4; j < vectorOfWords[i].size(); j += 2)
                {
                    string materialName = vectorOfWords[i][j];
                    int materialQty = stoi(vectorOfWords[i][j + 1]);
                    smallHouse.addRecipeMaterial(materialName, materialQty);
                }
            }
            else if (ID == 2)
            {
                MediumHouse mediumHouse(price);
                for (int j = 4; j < vectorOfWords[i].size(); j += 2)
                {
                    string materialName = vectorOfWords[i][j];
                    int materialQty = stoi(vectorOfWords[i][j + 1]);
                    mediumHouse.addRecipeMaterial(materialName, materialQty);
                }
            }
            else if (ID == 3)
            {
                LargeHouse largeHouse(price);
                for (int j = 4; j < vectorOfWords[i].size(); j += 2)
                {
                    string materialName = vectorOfWords[i][j];
                    int materialQty = stoi(vectorOfWords[i][j + 1]);
                    largeHouse.addRecipeMaterial(materialName, materialQty);
                }
            }
            else if (ID == 4)
            {
                Hotel hotel(price);
                for (int j = 4; j < vectorOfWords[i].size(); j += 2)
                {
                    string materialName = vectorOfWords[i][j];
                    int materialQty = stoi(vectorOfWords[i][j + 1]);
                    hotel.addRecipeMaterial(materialName, materialQty);
                }
            }
            else
            {
                cout << "ID tidak terdefinisi. Perbaiki file konfigurasi Anda." << endl;
            }
        }
    }
    catch (FileException &FE)
    {
        cout << FE.what();
        cout << "Pastikan folder konfigurasi anda memiliki file 'product.txt'" << endl;
    }
}

void Loader::configOfMisc()
{
    vector<vector<string>> vectorOfWords;
    try
    {
        vectorOfWords = Loader::getWordsFromFile(this->configPath + "/misc.txt");
        int minMoney = stoi(vectorOfWords[0][0]);
        int minWeight = stoi(vectorOfWords[1][0]);
        int storageRow = stoi(vectorOfWords[2][0]);
        int storageCols = stoi(vectorOfWords[2][1]);
        int fieldRow = stoi(vectorOfWords[3][0]);
        int fieldCols = stoi(vectorOfWords[3][1]);
        int barnRow = stoi(vectorOfWords[4][0]);
        int barnCols = stoi(vectorOfWords[4][1]);
        Misc(minMoney, minWeight, storageRow, storageCols, fieldRow, fieldCols, barnRow, barnCols);
    }
    catch (FileException &FE)
    {
        cout << FE.what();
        cout << "Pastikan folder konfigurasi anda memiliki file 'misc.txt'" << endl;
    }
}

Building* Loader::buildingConstructor(string itemName){
  if (itemName == "SMALL_HOUSE"){
    return new SmallHouse();
  } else if (itemName == "MEDIUM_HOUSE"){
    return new MediumHouse();
  } else if (itemName == "LARGE_HOUSE"){
    return new LargeHouse();
  } else if (itemName == "HOTEL"){
    return new Hotel();
  } else {
    throw LoaderException();
    return nullptr;
  }
}

Product* Loader::productConstructor(string itemName){
  if(itemName == "TEAK_WOOD"){
    return new TeakWood();
  } else if (itemName == "SANDALWOOD_WOOD"){
    return new SandalwoodWood();
  } else if (itemName == "ALOE_WOOD"){
    return new AloeWood();
  } else if (itemName == "IRONWOOD_WOOD"){
    return new IronwoodWood();
  } else if (itemName == "APPLE"){
    return new Apple();
  } else if (itemName == "ORANGE"){
    return new Orange();
  } else if (itemName == "BANANA"){
    return new Banana();
  } else if (itemName == "GUAVA"){
    return new Guava();
  } else if(itemName == "COW_MEAT"){
    return new CowMeat();
  } else if (itemName == "SHEEP_MEAT"){
    return new SheepMeat();
  } else if (itemName == "HORSE_MEAT"){
    return new HorseMeat();
  } else if (itemName == "RABBIT_MEAT"){
    return new RabbitMeat();
  } else if (itemName == "SNAKE_MEAT"){
    return new SnakeMeat();
  } else if (itemName == "CHICKEN_MEAT"){
    return new ChickenMeat();
  } else if (itemName == "DUCK_MEAT"){
    return new DuckMeat();
  } else if (itemName == "CHICKEN_EGG"){
    return new ChickenEgg();
  } else if (itemName == "DUCK_EGG"){
    return new DuckEgg();
  } else{
    throw LoaderException();
    return nullptr;
  }
}

Item* Loader::itemConstructor(string itemName){
  if (itemName == "TEAK_TREE"){
    return new TeakTree();
  } else if (itemName == "SANDALWOOD_TREE"){
    return new  SandalwoodTree();
  } else if (itemName == "ALOE_TREE"){
    return new AloeTree();
  } else if (itemName == "IRONWOOD_TREE"){
    return new IronwoodTree();
  } else if (itemName == "APPLE_TREE"){
    return new AppleTree();
  } else if (itemName == "ORANGE_TREE"){
    return new OrangeTree();
  } else if (itemName == "BANANA_TREE"){
    return new BananaTree();
  } else if (itemName == "GUAVA_TREE"){
    return new GuavaTree();
  } else if (itemName == "COW"){
    return new Cow();
  } else if (itemName == "SHEEP"){
    return new Sheep();
  } else if (itemName == "HORSE"){
    return new Horse();
  } else if (itemName == "RABBIT"){
    return new Rabbit();
  } else if (itemName == "SNAKE"){
    return new Snake();
  } else if (itemName == "CHICKEN"){
    return new Chicken();
  } else if (itemName == "DUCK"){
    return new Duck();
  } else if (itemName == "SMALL_HOUSE"){
    return new SmallHouse();
  } else if (itemName == "MEDIUM_HOUSE"){
    return new MediumHouse();
  } else if (itemName == "LARGE_HOUSE"){
    return new LargeHouse();
  } else if (itemName == "HOTEL"){
    return new Hotel();
  } else if (itemName == "TEAK_WOOD"){
    return new TeakWood();
  } else if (itemName == "SANDALWOOD_WOOD"){
    return new SandalwoodWood();
  } else if (itemName == "ALOE_WOOD"){
    return new AloeWood();
  } else if (itemName == "IRONWOOD_WOOD"){
    return new IronwoodWood();
  } else if (itemName == "APPLE"){
    return new Apple();
  } else if (itemName == "ORANGE"){
    return new Orange();
  } else if (itemName == "BANANA"){
    return new Banana();
  } else if (itemName == "GUAVA"){
    return new Guava();
  } else if (itemName == "COW_MEAT"){
    return new CowMeat();
  } else if (itemName == "SHEEP_MEAT"){
    return new SheepMeat();
  } else if (itemName == "HORSE_MEAT"){
    return new HorseMeat();
  } else if (itemName == "RABBIT_MEAT"){
    return new RabbitMeat();
  } else if (itemName == "SNAKE_MEAT"){
    return new SnakeMeat();
  } else if (itemName == "CHICKEN_MEAT"){
    return new ChickenMeat();
  } else if (itemName == "DUCK_MEAT"){
    return new DuckMeat();
  } else if (itemName == "CHICKEN_EGG"){
    return new ChickenEgg();
  } else if (itemName == "DUCK_EGG"){
    return new DuckEgg();
  } else {
    throw LoaderException();
    return nullptr;
  }
}


Plant* Loader::plantConstructor(string itemName,  int plantAge = 0){
  if (itemName == "TEAK_TREE"){
    return new TeakTree(plantAge);
  } else if (itemName == "SANDALWOOD_TREE"){
    return new SandalwoodTree(plantAge);
  } else if (itemName == "ALOE_TREE"){
    return new AloeTree(plantAge);
  } else if (itemName == "IRONWOOD_TREE"){
    return new IronwoodTree(plantAge);
  } else if (itemName == "APPLE_TREE"){
    return new AppleTree(plantAge);
  } else if (itemName == "ORANGE_TREE"){
    return new OrangeTree(plantAge);
  } else if (itemName == "BANANA_TREE"){
    return new BananaTree(plantAge);
  } else if(itemName == "GUAVA_TREE"){
    return new GuavaTree(plantAge);
  } else {
    throw LoaderException();
    return nullptr;
  }
}

Animal* Loader::animalConstructor(string itemName, int animalWeight = 0){
  if (itemName == "COW"){
    return new Cow(animalWeight);
  } else if (itemName == "SHEEP"){
    return new Sheep(animalWeight);
  } else if (itemName == "HORSE"){
    return new Horse(animalWeight);
  } else if (itemName == "RABBIT"){
    return new Rabbit(animalWeight);
  } else if (itemName == "SNAKE"){
    return new Snake(animalWeight);
  } else if (itemName == "CHICKEN"){
    return new Chicken(animalWeight);
  } else if (itemName == "DUCK"){
    return new Duck(animalWeight);
  } else {
    throw LoaderException();
    return nullptr;
  }
}

string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\r\n"); 
    size_t end = str.find_last_not_of(" \t\r\n");   

    if (start == std::string::npos || end == std::string::npos) {
        return ""; 
    }

    return str.substr(start, end - start + 1); 
}

vector<Player*> Loader::stateOfPlayer(string statepath, int ctr){
  vector<vector<string>> vectorOfWords;
  vector<Player*> players;

  try {
    vectorOfWords = Loader::getWordsFromFile(statepath);
    ctr = 0;
    int numOfPlayers = stoi(vectorOfWords[0][0]);
    ctr++;

    for(int i = 0; i < numOfPlayers; i++){
      string username = vectorOfWords[ctr][0];
      string type = vectorOfWords[ctr][1];
      int weight = stoi(vectorOfWords[ctr][2]);
      int wealth = stoi(vectorOfWords[ctr][3]);
      ctr++;

      Storage<Item*> inventory;
      Misc m;
      inventory.setRowCols(m.getStorageRow(),m.getStorageCols());
      int numOfInventories = stoi(vectorOfWords[ctr][0]);
      ctr++;

      for(int j = 0; j < numOfInventories; j++) {
        string inventoryItemName = trim(vectorOfWords[ctr][0]);
        Item *newItem = itemConstructor(inventoryItemName);
        inventory = inventory + newItem;
    
        ctr++;
      }
 
      if (type == "Petani"){
        Player* petani = new PlantFarmer(username, wealth, weight);
        petani->setInventory(inventory);
      
        Storage<Plant*> garden;
        garden.setRowCols(m.getFieldRow(),m.getFieldeCols());
        int numOfPlants = stoi(vectorOfWords[ctr][0]);
        ctr++;
        for(int k = 0; k < numOfPlants; k++){
          string plantLoc = trim(vectorOfWords[ctr][0]); 
          string plantName = trim(vectorOfWords[ctr][1]);
          int plantAge = stoi(vectorOfWords[ctr][2]);
          garden.setItem(garden.positionCodetoRow(plantLoc), garden.positionCodetoCol(plantLoc), plantConstructor(plantName, plantAge));
          ctr++;
        }
        PlantFarmer* p = dynamic_cast<PlantFarmer*>(petani);
        p->setGarden(garden);
        players.push_back(p);

      } else if (type == "Peternak"){
        Player* peternak = new AnimalFarmer(username, wealth, weight);
        peternak->setInventory(inventory);

        Storage<Animal*> barn;
        barn.setRowCols(m.getBarnRow(),m.getBarnCols());
        int numOfAnimals = stoi(vectorOfWords[ctr][0]);
        ctr++;
        for(int k = 0; k < numOfAnimals; k++){
          string animalLoc = trim(vectorOfWords[ctr][0]); 
          string animalName = trim(vectorOfWords[ctr][1]);
          int animalWeight = stoi(vectorOfWords[ctr][2]);
          Animal * animal = animalConstructor(animalName, animalWeight);
          barn.setItem(barn.positionCodetoRow(animalLoc), barn.positionCodetoCol(animalLoc), animal);
          ctr++;
        }
        AnimalFarmer* p = dynamic_cast<AnimalFarmer*>(peternak);
        p->setBarn(barn);
        players.push_back(p);

      } else if (type == "Walikota"){
        Player* walikota = new Mayor(username, wealth, weight);
        walikota->setInventory(inventory);
        players.push_back(walikota);
      } else {
        throw LoaderException();
      }
    }

    stateOfShop(statepath,ctr);
  } 
  catch (FileException &FE)
  {
      cout << FE.what();
  }
  catch (LoaderException &LE)
  {
      cout << LE.what();
  }
  return players;
}

void Loader::stateOfShop(string statepath, int ctr){
  vector<vector<string>> vectorOfWords;
  vector<tuple<Building*, int>> building;
  vector<tuple<Product*, int>> product;
  try {
    vectorOfWords = Loader::getWordsFromFile(statepath);

    int numOfShopItems = stoi(vectorOfWords[ctr][0]); ctr++;
    for(int i = 0; i < numOfShopItems; i++){
        string itemName = trim(vectorOfWords[ctr][0]);
        int itemQty = stoi(vectorOfWords[ctr][1]);
        ctr++;
        if(isBuilding(itemName)){
          building.push_back(make_tuple(buildingConstructor(itemName), itemQty));
        }
        else{
          product.push_back(make_tuple(productConstructor(itemName), itemQty));
        }
    }
    Shop(building, product);
  } catch (FileException &FE){
      cout << FE.what();
  }
}

bool Loader::isBuilding(string s){
  return (s=="SMALL_HOUSE"||s=="MEDIUM_HOUSE"||s=="LARGE_HOUSE" || s=="HOTEL");
}