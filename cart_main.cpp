#include "Product.h"
#include "Cart.h"
#include<iostream>

const char ADD_ITEM = 'a';
const char VIEW_CART = 'v';
const char CHECKOUT = 'c';
const char QUIT = 'q';

 std::vector<Product> product_arr = {
    Product('a', "apple", 2.50), 
    Product('b', "banana", 3.00), 
    Product('o', "orange", 4.15)};

void displayMenu()
{
    std::cout << std::endl << "Select an action - (" << ADD_ITEM << ")dd item, (" << VIEW_CART << ")iew cart, (" 
              << CHECKOUT << ")heckout, (" << QUIT << ")uit" << std::endl;
}

char getUserInput()
{
    char action;
    std::cout<<"Action: ";
    std::cin >> action;
    return action;
}

void printAvailableProducts(const std::vector<Product>& product_arr)
{
    std::cout<<"Available Products"<<std::endl;

    for(const Product& product : product_arr)
    {
        std::cout << product.getDisplayName();
    }

    std::cout << std::endl << "----------------------" << std::endl;
    std::cout << "Product to Add: ";

}

void processAddItem(Cart& cart, const std::vector<Product>& product_arr)
{
    char product_input;
    std::cin >> product_input;

    bool product_match = false;
    for(Product product : product_arr)
    {      
        if(product.getId() == product_input)
        {
            cart.addProduct(product);
            product_match = true;
            break;
        }
    }

    if(!product_match)
    {
        std::cout << std::endl << "Input does not match any product ID" << std::endl;
    }

}

void processCheckout(double cart_price)
{
    std::cout << "Pay in Cash: ";

    double payment;
    
    do{
        std::cin>>payment;

        if(payment<cart_price)
        {
            std::cout << "Insufficient funds. Please enter a new amount: ";
        }    
    }
    while((payment - cart_price) < 0);
    
    double change = payment-cart_price;
    std::cout<<"Change : "<< change << std::endl;
}

int main()
{
    
    Cart cart;
    char user_input;

    do 
    {
        displayMenu();
        std::cin>>user_input;

        switch (user_input){
        
            case ADD_ITEM:

                printAvailableProducts(product_arr);
                processAddItem(cart, product_arr);

                break;
                       
            case VIEW_CART:

                cart.viewCart();
                break;
            
            case CHECKOUT:
                
                cart.showTotalPrice();
                processCheckout(cart.getCartPrice());
                break;
            
            case QUIT:
                
                std::cout << "Exiting Checkout" << std::endl;
                break;

            default:
                std::cout << "Invalid input, try again" << std::endl;
        }
    }

    while(user_input!='q');
}