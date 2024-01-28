#include<iostream>

int main()
{
    char user_input;
    
    do 
    {
        std::cout<<"Select an action - (a)dd item, (v)iew cart, (c)heckout"<<std::endl;
        std::cout<<"Action: ";
        std::cin>>user_input;

        switch (user_input)
        {
        case 'a':
            std::cout<<user_input<<std::endl;
            break;
        
        case 'v':
            break;
        
        case 'c':
            break;
        case 'q':
            std::cout<<"Exiting Checkout"<<std::endl;
            break;

        default:
            std::cout<<"Invalid input, try again" << std::endl;
        }
    }

    while(user_input!='q');
}