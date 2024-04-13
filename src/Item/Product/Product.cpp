#include "Product.hpp"
#include "ProductAnimal.hpp"
#include "ProductFruitPlant.hpp"
#include "ProductMaterial.hpp"

Product::Product(int productID, string code, string name, string type, string origin, int addedWeight, int priceProduct) : Item(0,code, name, type,priceProduct){
    this->productID = productID;
    this->addedWeight = addedWeight;
    this->priceProduct = priceProduct;
    this->origin = origin;
}  

Product::Product(){
    product.push_back(new TeakWood());
    product.push_back(new SandalwoodWood());
    product.push_back(new AloeWood());
    product.push_back(new IronwoodWood());
    product.push_back(new Apple());
    product.push_back(new Orange());
    product.push_back(new Banana());
    product.push_back(new Guava());
    product.push_back(new CowMeat());
    product.push_back(new SheepMeat());
    product.push_back(new HorseMeat());
    product.push_back(new RabbitMeat());
    product.push_back(new SnakeMeat());
    product.push_back(new ChickenMeat());
    product.push_back(new DuckMeat());
    product.push_back(new ChickenEgg());
    product.push_back(new DuckEgg());
}
Product :: ~Product(){}

vector<Product*> Product::getProduct(string prod){
    vector<Product*> products;
    for (auto pr : product){
        if(pr->origin == prod){
            products.push_back(pr);
        }
    }
    return products;
}

int Product :: getPrice (){
    return priceProduct;
}

int Product :: getAddedWeight(){
    return addedWeight;
}


