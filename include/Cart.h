#ifndef CART_H
#define CART_H

#include<vector>
#include <iomanip>
#include <sstream>
#include "Item.h"
#include "Product.h"

class Cart
{
    public:
        
        Cart();
        
        void addProduct(Product& product);
        
        void viewCart() const;

        std::string showTotalPrice() const;

        double getCartPrice() const;

        void clearCart();

    private: 

        std::vector<Item> item_list;
        double cart_price = 0;
        
        void updatePrice(double price);

        std::string showAddedProduct(const Product& product) const;
};


#endif