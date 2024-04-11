#ifndef __PRODUCT_MATERIAL_HPP__
#define ___PRODUCT_MATERIAL_HPP__

#include "Product.hpp"

class ProductMaterial : public Product {
public:
    ProductMaterial(int materialproduct, string code, string name, string origin, int addedWeight, int price);
};

class TeakWood : public ProductMaterial {
    private :
        static int addedWeight;
        static int price;
    public:
        TeakWood();
        TeakWood(int addedWeight, int price);
};
class SandalwoodWood : public ProductMaterial{
    private :
        static int addedWeight;
        static int price;
    public:
        SandalwoodWood();
        SandalwoodWood (int addedWeight, int price);
};
class AloeWood : public ProductMaterial{
    private :
        static int addedWeight;
        static int price;
    public:
        AloeWood();
        AloeWood(int addedWeight, int price);
};
class IronwoodWood : public ProductMaterial{
    private :
        static int addedWeight;
        static int price;
    public:
        IronwoodWood();
        IronwoodWood(int addedWeight, int price);
};
#endif // ProductMaterial_HPP
