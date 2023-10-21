#include <iostream>

// clearScreen clears the terminal
void clearScreen()
{
#ifdef __linux__ 
    system("clear");
#elifdef __APPLE__ 
    system("clear");
#elifdef _WIN32
    system("cls");
#else
    return;
#endif
}

// isNumber validates input is a number
bool isNumber(int input)
{
    std::string str = std::to_string(input);
    for (char& c : str) 
    {
        if (isdigit(c) == true)
            return true;
    }
    return false;
}

// menu displays an enumerated list of options to select from 
int menu()
{
    std::cout << " Please select a number (1-3)."
           " \n 1) Login"
           " \n 2) Register"
           " \n 3) Exit"
           " \n\n Selection: ";
    int selection{3};
    std::cin >> selection;

    return selection;
}
