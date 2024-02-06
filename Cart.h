#include<vector>
#include <iomanip>
#include <sstream>
#include "Item.h"
#include "Product.h"

class Cart
{
    public:
        
        Cart() : item_list(), cart_price(0) {}
        
        void addProduct(Product& product) 
        {
            bool is_new_item = true;
            
            for(Item& item : item_list)
            {
                if(item.product.getId() == product.getId())
                {
                    item.add();
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
            std::cout <<showAddedProduct(product);
        }
        
        void viewCart() const
        {
            std::cout<<SeparatorLine<<std::endl;

            if(item_list.empty())
            {
                std::cout << CartEmptyMessage << std::endl;
            }
  
            for(const Item x : item_list)
            {
                std::cout << x.getItemInfo() << std::endl;
            }

            std::cout << showTotalPrice();
           
        }

        std::string showTotalPrice() const
        {
            std::ostringstream oss;
            oss << "Total: $" << std::fixed << std::setprecision(2) << cart_price << '\n';
            return oss.str();
        }

        double getCartPrice() const
        {
            return cart_price;
        }

        void clearCart()
        {
            item_list.clear();
            cart_price = 0;
        }

    private: 

        std::vector<Item> item_list;
        double cart_price = 0;

        static const std::string SeparatorLine;
        static const std::string CartEmptyMessage;
        
        void updatePrice(double price)
        {
            cart_price += price;
        }

        std::string showAddedProduct(const Product& product) const
        {
            std::ostringstream oss;
            oss << "\nAdded " << product.getName() << " to Cart : $" << std::fixed << std::setprecision(2) << product.getPrice() << "\n";
            return oss.str();
        }
};

const std::string Cart::SeparatorLine = "------------------------------";
const std::string Cart::CartEmptyMessage = "Cart is Empty";