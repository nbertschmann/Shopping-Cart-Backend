#include "Product.h"
#include <iomanip>
#include <sstream>

class Item
{

    public: 

        Product product;
        
        Item(Product& product) : product(product), quantity(1){
        }

        void add()
        {
            quantity++;
        }

        double getItemPrice() const
        { 
            return product.getPrice() * quantity;
        }

        std::string getItemInfo() const
        {
            std::ostringstream oss;
            oss << std::fixed << std::setprecision(2) << quantity << " x " << product.getName() << ": $" << getItemPrice();

            return oss.str();
        }

    private:
 
        int quantity;

};


