#include "ProductAnimal.hpp"
#include <iostream>
using namespace std;

ProductAnimal :: ProductAnimal (int animalproductID, string code, string name, string origin, int addedWeight, int price): Product(animalproductID, code, name, "PRODUCT_ANIMAL", origin, addedWeight, price){}

int SheepMeat :: addedWeight = 0;
int SheepMeat ::price = 0;
SheepMeat :: SheepMeat(): ProductAnimal(9, "COM", "COW_MEAT", "COW", SheepMeat ::addedWeight, SheepMeat :: price){}
SheepMeat :: SheepMeat(int addedWeight, int price): ProductAnimal(9, "COM", "COW_MEAT", "COW", addedWeight, price){
    SheepMeat :: addedWeight = addedWeight;
    SheepMeat :: price = price;
}

int HorseMeat :: addedWeight = 0;
int HorseMeat ::price = 0;
HorseMeat :: HorseMeat(): ProductAnimal(9, "COM", "COW_MEAT", "COW", HorseMeat ::addedWeight, HorseMeat :: price){}
HorseMeat :: HorseMeat(int addedWeight, int price): ProductAnimal(9, "COM", "COW_MEAT", "COW", addedWeight, price){
    HorseMeat :: addedWeight = addedWeight;
    HorseMeat :: price = price;
}

int RabbitMeat :: addedWeight = 0;
int RabbitMeat ::price = 0;
RabbitMeat :: RabbitMeat(): ProductAnimal(9, "COM", "COW_MEAT", "COW", RabbitMeat ::addedWeight, RabbitMeat :: price){}
RabbitMeat :: RabbitMeat(int addedWeight, int price): ProductAnimal(9, "COM", "COW_MEAT", "COW", addedWeight, price){
    RabbitMeat :: addedWeight = addedWeight;
    RabbitMeat :: price = price;
}

int SnakeMeat :: addedWeight = 0;
int SnakeMeat ::price = 0;
SnakeMeat :: SnakeMeat(): ProductAnimal(9, "COM", "COW_MEAT", "COW", SnakeMeat ::addedWeight, SnakeMeat :: price){}
SnakeMeat :: SnakeMeat(int addedWeight, int price): ProductAnimal(9, "COM", "COW_MEAT", "COW", addedWeight, price){
    SnakeMeat :: addedWeight = addedWeight;
    SnakeMeat :: price = price;
}

int CowMeat :: addedWeight = 0;
int CowMeat ::price = 0;
CowMeat :: CowMeat(): ProductAnimal(9, "COM", "COW_MEAT", "COW", CowMeat ::addedWeight, CowMeat :: price){}
CowMeat :: CowMeat(int addedWeight, int price): ProductAnimal(9, "COM", "COW_MEAT", "COW", addedWeight, price){
    CowMeat :: addedWeight = addedWeight;
    CowMeat :: price = price;
}

int ChickenMeat :: addedWeight = 0;
int ChickenMeat ::price = 0;
ChickenMeat :: ChickenMeat(): ProductAnimal(9, "COM", "COW_MEAT", "COW", ChickenMeat ::addedWeight, ChickenMeat :: price){}
ChickenMeat :: ChickenMeat(int addedWeight, int price): ProductAnimal(9, "COM", "COW_MEAT", "COW", addedWeight, price){
    ChickenMeat :: addedWeight = addedWeight;
    ChickenMeat :: price = price;
}

int DuckMeat :: addedWeight = 0;
int DuckMeat ::price = 0;
DuckMeat :: DuckMeat(): ProductAnimal(9, "COM", "COW_MEAT", "COW", DuckMeat ::addedWeight, DuckMeat :: price){}
DuckMeat :: DuckMeat(int addedWeight, int price): ProductAnimal(9, "COM", "COW_MEAT", "COW", DuckMeat ::addedWeight, DuckMeat :: price){
    DuckMeat :: addedWeight = addedWeight;
    DuckMeat :: price = price;
}

int ChickenEgg :: addedWeight = 0;
int ChickenEgg ::price = 0;
ChickenEgg :: ChickenEgg(): ProductAnimal(9, "COM", "COW_MEAT", "COW", ChickenEgg ::addedWeight, ChickenEgg :: price){}
ChickenEgg :: ChickenEgg(int addedWeight, int price): ProductAnimal(9, "COM", "COW_MEAT", "COW",addedWeight, price){
    ChickenEgg :: addedWeight = addedWeight;
    ChickenEgg :: price = price;
}

int DuckEgg :: addedWeight = 0;
int DuckEgg ::price = 0;
DuckEgg :: DuckEgg(): ProductAnimal(9, "COM", "COW_MEAT", "COW", DuckEgg ::addedWeight, DuckEgg :: price){}
DuckEgg :: DuckEgg(int addedWeight, int price): ProductAnimal(9, "COM", "COW_MEAT", "COW", addedWeight, price){
    DuckEgg :: addedWeight = addedWeight;
    DuckEgg :: price = price;
}
