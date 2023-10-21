#include <iostream>
#include <fstream>

// userExists checks if a username exists in database
bool findUser(std::string username)
{
    std::ifstream inputFile{"database.txt"};

    std::string name;
    while (inputFile >> name)
    {
        if (name == username)
        {
            return true;
        }
    }
    return false;
}

// validPassword validates password is correct
bool validPassword(std::string password)
{
    std::ifstream inputFile{"database.txt"};

    std::string user;
    std::string passwd;
    while (inputFile >> user >> passwd)
    {
        if (passwd == password)
        {
            return true;
        }
    }
    return false;
}

// Log a user into system
void login()
{
    std::string username;
    std::cout << "Please enter a username: " << '\n';
    std::cin >> username;

    if (!findUser(username))
    {
        std::cout << "Username does not exist!" << '\n';
        return;
    }

    std::string password;
    std::cout << "Please enter a password: " << '\n';
    std::cin >> password;

    if (!validPassword(password))
    {
        std::cout << "Password is not correct!" << '\n';
        return;
    }

    std::cout << "Login successful." << '\n';
}
