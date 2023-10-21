#include <fstream>
#include <iostream>
#include <string>

// openFile creates a new file if it does not exist
void openFile()
{
    std::ifstream filename{ "database.txt" };

    if (!filename)
    {
        std::ofstream newFile{ "database.txt" };
    }
}
