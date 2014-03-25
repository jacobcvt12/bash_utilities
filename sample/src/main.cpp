#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>

int main(int argc, char* argv[])
{
    std::string line;
    
    // no file piped to program
    if (isatty(fileno(stdin)))
    {
        // check if there are arguments
        if (argc > 1)
        {
            std::ifstream file(argv[1]);

            // check if argument is a file
            if (file)
            {
                while (std::getline(file, line))
                {
                    std::cout << line << std::endl;
                }
            }

            // argument is not a file or file is not open for reading
            else
            {
                std::cerr << "File " << argv[1] << " doesn't exist or isn't open for reading.\n";
            }
        }

        // no arguments given; error
        else
        {
            std::cerr << "No arguments given.\n";
        }
    }

    // file piped to program
    else
    {
        while (std::getline(std::cin, line))
        {
            std::cout << line << std::endl;
        }
    } 

    return 0;
}
