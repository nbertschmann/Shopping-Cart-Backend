#ifndef PRODUCT_H
#define PRODUCT_H

#include<iostream>
#include<string>
#include <iomanip>
#include <sstream>

class Product
{ 
    public:
        
        Product(int ID, std::string Name, double Price) 
            : id(ID), name(Name), price(Price){
         }

        std::string getDisplayName() const
        {
            std::ostringstream oss;
            oss << "(" << std::string(1, id) << ")" << name.substr(1) << ": $" << std::fixed << std::setprecision(2) << price << '\n';
            return oss.str();
    
        }

        char getId() const
        {
            return id;
        }

        std::string getName() const
        {
            return name;
        }

        double getPrice() const
        {
            return price;
        }
    
    private:

        char id;
        std::string name;
        double price;
};

#endif // PRODUCT_H