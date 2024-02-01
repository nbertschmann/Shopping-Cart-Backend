#include<vector>
#include "Item.h"
#include "Product.h"

class Cart
{
    public:
        
        std::vector<Item> item_list;

        void addItem(Product& product) 
        {
            bool is_new_item = true;
            
            for(Item& item_ : item_list)
            {
                if(item_.product.getId() == product.getId())
                {
                    item_.add();
                    is_new_item = false;
                    break;
                }
            }

            if(is_new_item)
            {
                Item new_item = Item(product);
                item_list.push_back(new_item);
            }

            updatePrice(product.getPrice());
            showAddedProduct(product);
        }
    
        void showAddedProduct(Product product)
        {
            std::cout << std::endl <<"Added " << product.getName() << " to Cart : " << "$" << product.getPrice() << std::endl;
        }
        
        void showCart()
        {
            std::cout<<"------------------------------"<<std::endl;

            if(item_list.empty())
            {
                std::cout << "Cart is Empty" << std::endl;
            }

            else
            {
                for(Item x : item_list)
                {
                    printItem(x);
                }

                showPrice();
            } 
        }

        void showPrice()
        {
            std::cout << "Total: " << cart_price << std::endl;
        }

        double getCartPrice()
        {
            return cart_price;
        }

        void clearCart()
        {
            item_list.clear();
            cart_price = 0;
        }

    private: 

        double cart_price = 0;
        
        void updatePrice(double price)
        {
            cart_price += price;
        }

        void printItem(Item item)
        {
            std::cout<< item.getQuantity() << " x " << item.product.getName() << ": $" << item.getTotalPrice() << std::endl;
        }
};