#include "Product.h"

class Item
{
    
    public: 
        
        Product product;

        Item(Product& product_) 
            : product(product_){
        }

        void add()
        {
            quantity++;
            update_price();
        }
    
        int getQuantity()
        {
            return quantity;
        }

        double getTotalPrice()
        { 
            return total_price;
        }
    
    private:

        int quantity=1;
        double total_price=product.getPrice();

        void update_price()
        {
            total_price = product.getPrice() * quantity;
        }
};


