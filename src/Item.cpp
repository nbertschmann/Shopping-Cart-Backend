#include "Item.h"

Item::Item(Product& product) : product(product), quantity(1) {}

void Item::add()
{
    quantity++;
}

double Item::getItemPrice() const
{ 
    return product.getPrice() * quantity;
}

std::string Item::getItemInfo() const
{
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(2) << quantity << " x " << product.getName() << ": $" << getItemPrice();

    return oss.str();
}