#include "Shop.hpp"
#include <algorithm>
#include "../Building/Building.hpp"
#include "../Item/Item.hpp"
#include <iostream>
#include "../Player/Player.hpp"
using namespace std;

Shop& Shop::operator+(Item& item) {
    // Implementation
}

void Shop :: printShop(){
    cout << "Selamat datang di toko!" << endl;
    cout << "Berikut merupakan hal yang dapat Anda Beli" << endl;
    // Print details of each item available in the shop
    int index = 1;
    for (const auto& item : itemsBuilding) {
        Building building = get<0>(item);
        int stock = get<1>(item);
        cout << index << ". " << building.getName() << "-"<<building.calculatePrice()<<" (" << stock << ")" << endl;
        index++;
    }
    index = index+1;
    for (const auto& item : items) {
        if (item.getType()!= "BUILDING"){
            cout << index <<". "<< item.getName() <<endl;
        }
    }
}
