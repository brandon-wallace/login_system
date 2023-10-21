#include <iostream>
#include <fstream>

// validatePassword checks the spelling of the password
bool validatePassword(std::string password1, std::string password2)
{
    return password1 == password2;
}

// userExists checks if a username exists in database
bool userExists(std::string username)
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

// registerNewUser registers a new user
void registerNewUser()
{
    std::string username;
    std::cout << "Please enter a username: " << '\n';
    std::cin >> username;

    if (userExists(username))
    {
        std::cout << "Username already exists!" << '\n';
        return;
    }

    std::string password;
    std::cout << "Please enter a password: " << '\n';
    std::cin >> password;

    std::string confirmPassword;
    std::cout << "Please confirm your password: " << '\n';
    std::cin >> confirmPassword;

    if (!validatePassword(password, confirmPassword))
    {
        std::cout << "Passwords do not match." << '\n';
        return;
    }

    std::ofstream file("database.txt", std::ios::app);
    file << username << " " << password << '\n';

    std::cout << "User has been registered successfully." << '\n';
}
