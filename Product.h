#ifndef PRODUCT_H
#define PRODUCT_H

#include<iostream>
#include<string>

class Product
{ 
    public:
        
        Product(int ID, std::string Name, double Price) 
            : id(ID), name(Name), price(Price){
         }

        void print_details()
        {
            std::cout << "(" << id << ")" << name.substr(1) << ": " << "$" << price << std::endl;
        }

        char getId() const
        {
            return id;
        }

        std::string getName()
        {
            return name;
        }

        double getPrice()
        {
            return price;
        }
    
    private:

        char id;
        std::string name;
        double price;

       
};

#endif // PRODUCT_H