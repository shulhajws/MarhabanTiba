#include "Loader.hpp"
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
        if (cc == ' ')
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

vector<Animal> Loader::configOfAnimal()
{
    vector<vector<string>> vectorOfWords;
    vector<Animal> animals;

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
                animals.push_back(Cow(harvestWeight, price));
            }
            else if (ID == 2)
            {
                animals.push_back(Sheep(harvestWeight, price));
            }
            else if (ID == 3)
            {
                animals.push_back(Horse(harvestWeight, price));
            }
            else if (ID == 4)
            {
                animals.push_back(Rabbit(harvestWeight, price));
            }
            else if (ID == 5)
            {
                animals.push_back(Snake(harvestWeight, price));
            }
            else if (ID == 6)
            {
                animals.push_back(Chicken(harvestWeight, price));
            }
            else if (ID == 7)
            {
                animals.push_back(Duck(harvestWeight, price));
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
    return animals;
}

vector<Plant> Loader::configOfPlant()
{
    vector<vector<string>> vectorOfWords;
    vector<Plant> plants;

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
                plants.push_back(TeakTree(harvestDuration, price));
            }
            else if (ID == 2)
            {
                plants.push_back(SandalwoodTree(harvestDuration, price));
            }
            else if (ID == 3)
            {
                plants.push_back(AloeTree(harvestDuration, price));
            }
            else if (ID == 4)
            {
                plants.push_back(IronwoodTree(harvestDuration, price));
            }
            else if (ID == 5)
            {
                plants.push_back(AppleTree(harvestDuration, price));
            }
            else if (ID == 6)
            {
                plants.push_back(OrangeTree(harvestDuration, price));
            }
            else if (ID == 7)
            {
                plants.push_back(BananaTree(harvestDuration, price));
            }
            else if (ID == 8)
            {
                plants.push_back(GuavaTree(harvestDuration, price));
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
    return plants;
}

vector<Product> Loader::configOfProduct()
{
    vector<vector<string>> vectorOfWords;
    vector<Product> products;

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
                products.push_back(TeakWood(addedWeight, price));
            }
            else if (ID == 2)
            {
                products.push_back(SandalwoodWood(addedWeight, price));
            }
            else if (ID == 3)
            {
                products.push_back(AloeWood(addedWeight, price));
            }
            else if (ID == 4)
            {
                products.push_back(IronwoodWood(addedWeight, price));
            }
            else if (ID == 5)
            {
                products.push_back(Apple(addedWeight, price));
            }
            else if (ID == 6)
            {
                products.push_back(Orange(addedWeight, price));
            }
            else if (ID == 7)
            {
                products.push_back(Banana(addedWeight, price));
            }
            else if (ID == 8)
            {
                products.push_back(Guava(addedWeight, price));
            }
            else if (ID == 9)
            {
                products.push_back(CowMeat(addedWeight, price));
            }
            else if (ID == 10)
            {
                products.push_back(SheepMeat(addedWeight, price));
            }
            else if (ID == 11)
            {
                products.push_back(HorseMeat(addedWeight, price));
            }
            else if (ID == 12)
            {
                products.push_back(RabbitMeat(addedWeight, price));
            }
            else if (ID == 13)
            {
                products.push_back(SnakeMeat(addedWeight, price));
            }
            else if (ID == 14)
            {
                products.push_back(ChickenMeat(addedWeight, price));
            }
            else if (ID == 15)
            {
                products.push_back(DuckMeat(addedWeight, price));
            }
             else if (ID == 16)
            {
                products.push_back(ChickenEgg(addedWeight, price));
            }
            else if (ID == 17)
            {
                products.push_back(DuckEgg(addedWeight, price));
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
    return products;
}

vector<Building> Loader::configOfBuildingRecipes()
{
    vector<vector<string>> vectorOfWords;
    vector<Building> buildings;

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
                buildings.push_back(smallHouse);
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
                buildings.push_back(mediumHouse);
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
                buildings.push_back(largeHouse);
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
                buildings.push_back(hotel);
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
    return buildings;
}

Misc Loader::configOfMisc()
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
        return Misc(minMoney, minWeight, storageRow, storageCols, fieldRow, fieldCols, barnRow, barnCols);
    }
    catch (FileException &FE)
    {
        cout << FE.what();
        return Misc();
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
  } else if(itemName == "COW MEAT"){
    return new CowMeat();
  } else if (itemName == "SHEEP MEAT"){
    return new SheepMeat();
  } else if (itemName == "HORSE MEAT"){
    return new HorseMeat();
  } else if (itemName == "RABBIT MEAT"){
    return new RabbitMeat();
  } else if (itemName == "SNAKE MEAT"){
    return new SnakeMeat();
  } else if (itemName == "CHICKEN MEAT"){
    return new ChickenMeat();
  } else if (itemName == "DUCK MEAT"){
    return new DuckMeat();
  } else if (itemName == "CHICKEN EGG"){
    return new ChickenEgg();
  } else if (itemName == "DUCK EGG"){
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

vector<Player> Loader::stateOfPlayer(string statepath, int* ctr){
  vector<vector<string>> vectorOfWords;
  vector<Player> players;

  // string stateFilename = this->testsPath + "/" + statepath;
  // cout<<stateFilename;
  try {
    vectorOfWords = Loader::getWordsFromFile(this->testsPath + "/" + statepath + ".txt");
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
        inventory.setItem(0, 0, itemConstructor(inventoryItem));
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
          garden.setItem(garden.positionCodetoRow(plantLoc), garden.positionCodetoCol(plantLoc), plantConstructor(plantName, plantAge));
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
          barn.setItem(barn.positionCodetoRow(animalLoc), barn.positionCodetoCol(animalLoc), animalConstructor(animalName, animalWeight));
          *ctr++;
        }
        peternak.setBarn(barn);
        players.push_back(peternak);
      } else if (type == "Walikota"){
        Mayor walikota(username, wealth, weight);
        walikota.setInventory(inventory);
        players.push_back(walikota);
      } else {
        throw LoaderException();
      }
    }
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

Shop Loader::stateOfShop(string statepath, int ctr){
  vector<vector<string>> vectorOfWords;
  vector<tuple<Building*, int*>> building;
  vector<tuple<Product*, int*>> product;

  try {
    vectorOfWords = Loader::getWordsFromFile(this->testsPath + "/" + statepath);

    int numOfShopItems = stoi(vectorOfWords[ctr][0]); ctr++;
    for(int i = 0; i < numOfShopItems; i++){
        string itemName = vectorOfWords[ctr][0];
        int itemQty = stoi(vectorOfWords[ctr][1]);
        ctr++;
        if(isBuilding(itemName)){
          building.push_back(make_tuple(buildingConstructor(itemName), &itemQty));
        }
        else{
          product.push_back(make_tuple(productConstructor(itemName), &itemQty));
        }
    }
    return Shop(building, product);
  } catch (FileException &FE){
      cout << FE.what();
      return Shop();
  }
}

bool Loader::isBuilding(string s){
  return (s=="SMALL_HOUSE"||s=="MEDIUM_HOUSE"||s=="LARGE_HOUSE" || s=="HOTEL");
}