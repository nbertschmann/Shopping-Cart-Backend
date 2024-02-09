#ifndef PRODUCT_H
#define PRODUCT_H

#include<iostream>
#include<string>
#include<iomanip>
#include<sstream>

class Product
{ 
    public:
        
        Product(int ID, std::string Name, double Price);

        std::string getDisplayName() const;

        char getId() const;

        std::string getName() const;

        double getPrice() const;
    
    private:

        char id;
        std::string name;
        double price;
};

#endif // PRODUCT_H