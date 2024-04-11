#ifndef __PRODUCT_FRUIT_PLANT_HPP__
#define __PRODUCT_FRUIT_PLANT_HPP__

#include "Product.hpp"

class ProductFruitPlant : public Product {
public:
    ProductFruitPlant(int ProductFruitPlantID, string code, string name, string origin, int addedWeight, int price);
};

class Apple : public ProductFruitPlant {
    private :
        static int addedWeight;
        static int price;
    public:
        Apple();
        Apple(int addedWeight, int price);
};

class Orange : public ProductFruitPlant{
    private :
        static int addedWeight;
        static int price;
    public:
        Orange();
        Orange(int addedWeight, int price);
};

class Banana : public ProductFruitPlant{
    private :
        static int addedWeight;
        static int price;
    public:
        Banana();
        Banana(int addedWeight, int price);
};

class Guava : public ProductFruitPlant{
    private :
        static int addedWeight;
        static int price;
    public:
        Guava();
        Guava(int addedWeight, int price);
};

#endif 