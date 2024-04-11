#ifndef __PRODUCT_ANIMAL_HPP__
#define __PRODUCT_ANIMAL_HPP__

#include "Product.hpp"

class ProductAnimal : public Product {
public:
    ProductAnimal(int animalproductID, string code, string name, string origin, int addedWeight, int price);
};

class SheepMeat : public ProductAnimal {
    private :
        static int addedWeight;
        static int price;
    public:
        SheepMeat();
        SheepMeat(int addedWeight, int price);
};

class HorseMeat : public ProductAnimal {
    private :
        static int addedWeight;
        static int price;
    public:
        HorseMeat();
        HorseMeat(int addedWeight, int price);
};

class RabbitMeat : public ProductAnimal {
    private :
        static int addedWeight;
        static int price;
    public:
        RabbitMeat();
        RabbitMeat(int addedWeight, int price);
};

class SnakeMeat : public ProductAnimal {
    private :
        static int addedWeight;
        static int price;
    public:
        SnakeMeat();
        SnakeMeat(int addedWeight, int price);
};

class CowMeat : public ProductAnimal {
    private :
        static int addedWeight;
        static int price;
    public:
        CowMeat();
        CowMeat(int addedWeight, int price);
};

class ChickenMeat : public ProductAnimal{
    private :
        static int addedWeight;
        static int price;
    public:
        ChickenMeat();
        ChickenMeat(int addedWeight, int price);
};

class DuckMeat : public ProductAnimal{
    private :
        static int addedWeight;
        static int price;
    public:
        DuckMeat();
        DuckMeat(int addedWeight, int price);
};

class ChickenEgg : public ProductAnimal{
    private :
        static int addedWeight;
        static int price;
    public:
        ChickenEgg();
        ChickenEgg(int addedWeight, int price);
};

class DuckEgg : public ProductAnimal{
    private :
        static int addedWeight;
        static int price;
    public:
        DuckEgg();
        DuckEgg(int addedWeight, int price);
};

#endif // PRODUCT_ANIMAL_HPP