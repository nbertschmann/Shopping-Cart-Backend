#include "Cart.h"

Cart::Cart() : item_list(), cart_price(0) {}

void Cart::addProduct(Product& product) 
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

void Cart::viewCart() const
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

std::string Cart::showTotalPrice() const
{
    std::ostringstream oss;
    oss << "Total: $" << std::fixed << std::setprecision(2) << cart_price << '\n';
    return oss.str();
}

double Cart::getCartPrice() const
{
    return cart_price;
}

void Cart::clearCart()
{
    item_list.clear();
    cart_price = 0;
}

void Cart::updatePrice(double price)
{
    cart_price += price;
}

std::string Cart::showAddedProduct(const Product& product) const
{
    std::ostringstream oss;
    oss << "\nAdded " << product.getName() << " to Cart : $" << std::fixed << std::setprecision(2) << product.getPrice() << "\n";
    return oss.str();
}