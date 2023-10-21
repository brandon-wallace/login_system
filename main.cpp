#include "io.h"
#include "menu.h"
#include "login.h"
#include "register.h"
#include <iostream>


int main() 
{
    clearScreen();
    std::cout << "•••••••••••••••••••••••••••••••••••" << '\n';
    std::cout << "•   LOGIN / REGISTRATION SYSTEM   •" << '\n';
    std::cout << "•••••••••••••••••••••••••••••••••••" << '\n';
    
    int selection{ menu() };

    switch (selection)
    {
        case 1:
            login();
            break;
        case 2:
            registerNewUser();
            break;
        case 3:
            std::cout << " Exiting." << '\n'; 
            break;
        default:
            std::cout << " Error!" << '\n'; 
            break;
    }

    return 0;
}
