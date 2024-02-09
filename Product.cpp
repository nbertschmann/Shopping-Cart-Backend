#include "Product.h"

Product::Product(int ID, std::string Name, double Price) : id(ID), name(Name), price(Price){}

std::string Product::getDisplayName() const
{
    std::ostringstream oss;
    oss << "(" << std::string(1, id) << ")" << name.substr(1) << ": $" << std::fixed << std::setprecision(2) << price << '\n';
    return oss.str();
}

char Product::getId() const
{
    return id;
}

std::string Product::getName() const
{
    return name;
}

double Product::getPrice() const
{
    return price;
}