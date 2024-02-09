#ifndef ITEM_H
#define ITEM_H

#include "Product.h"
#include <iomanip>
#include <sstream>

class Item
{

    public: 

        Product product;
        
        Item(Product& product);

        void add();

        double getItemPrice() const;

        std::string getItemInfo() const;

    private:
 
        int quantity;

};


#endif