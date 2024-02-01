#include "Product.h"
#include "Cart.h"
#include<iostream>

int main()
{
    Product arr[] = {Product('a', "apple", 2.50), Product('b', "banana", 3.00), Product('o', "orange", 4.15)};
    Cart cart;
    
    char user_input;

    do 
    {
        std::cout<< std::endl << "Select an action - (a)dd item, (v)iew cart, (c)heckout"<<std::endl;
        std::cout<<"Action: ";
        std::cin>>user_input;

        bool product_match = false;
        double change;

        switch (user_input){
        
            case 'a':
                
                std::cout<<"Available Products"<<std::endl;
                
                for(Product product : arr)
                {
                    product.print_details();
                }

                std::cout << std::endl << "----------------------" << std::endl;
                std::cout << "Product to Add: ";

                char product_input;
                std::cin >> product_input;

                for(Product product : arr)
                {      
                    if(product.getId() == product_input)
                    {
                        cart.addItem(product);
                        product_match = true;
                        break;
                    }
                }

                if(!product_match)
                {
                    std::cout << std::endl << "Input does not match any product ID" << std::endl;
                }

                break;
                    
            case 'v':

                cart.showCart();
                break;
            
            case 'c':
                
                cart.showPrice();
                std::cout << "Pay in Cash: ";

                double payment;
                std::cin>>payment;
                
                change = payment - cart.getCartPrice();
                
                while(change < 0)
                {
                    std::cout<<"Insufficient Funds, try again: ";
                    std::cin>>payment;
                    change = payment - cart.getCartPrice();
                }
                
                std::cout<<"Change : "<< change;

                break;
            
            case 'q':
                
                std::cout << "Exiting Checkout" << std::endl;
                break;

            default:
                std::cout << "Invalid input, try again" << std::endl;
        }
    }

    while(user_input!='q');
}