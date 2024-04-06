#include "Loader.hpp"
using namespace std;

string Loader::configPath = "./config";
string Loader::testsPath = "./test";

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
        plants.push_back(Teak(harvestDuration, price));
    } else if (ID == 2) {
        plants.push_back(Sandalwood(harvestDuration, price));
    } else if (ID == 3) {
        plants.push_back(Aloe(harvestDuration, price));
    } else if (ID == 4) {
        plants.push_back(Ironwood(harvestDuration, price));
    } else if (ID == 5) {
        plants.push_back(Apple(harvestDuration, price));
    } else if (ID == 6) {
        plants.push_back(Orange(harvestDuration, price));
    } else if (ID == 7) {
        plants.push_back(Banana(harvestDuration, price));
    } else if (ID == 8) {
        plants.push_back(Guava(harvestDuration, price));
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
  vector<Building> building;
  return building;
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

// vector<Player> stateOfPlayer(){
//   //TO DO
// }

/* tester function */
// void Loader::displayAnimalConfig()
// {
//   vector<Animal> animals = this->configOfAnimal();

//   cout << "List of Tool: " << endl;
//   for (int i = 0; i < animals.size(); i++)
//   {
//     cout << i + 1 << "." << endl;
//     animals[i].display();
//     cout << endl;
//   }
//   cout << endl;
// }