#include <iostream>
#include <fstream>

// passwordsMatch confirms is spelled correctly
bool passwordsMatch(std::string password, std::string confirm_password)
{
    return password == confirm_password;
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
    std::cout << " Please enter a username: " << '\n';
    std::cin >> username;

    if (userExists(username))
    {
        std::cout << " Username already exists!" << '\n';
        return;
    }

    std::cout << " Enter your password: ";
    std::string password{};
    std::cin >> password;

    std::cout << " Confirm your password: ";
    std::string confirmPassword{};
    std::cin >> confirmPassword;

    if (!passwordsMatch(password, confirmPassword))
    {
        std::cout << " Passwords do not match." << '\n';
        return;
    }

    std::ofstream file("database.txt", std::ios::app);
    file << username << " " << password << '\n';

    std::cout << " User has been registered successfully." << '\n';
}
