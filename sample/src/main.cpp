#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h>
#include "reservoir.hpp"

int main(int argc, char* argv[])
{
    std::istream* input;
    std::ifstream infile;  

    int sample_size;
    
    // file piped to program
    if (!isatty(fileno(stdin)))
    {
        input = &std::cin;
        
        if (argc < 2)
        {
            std::cerr << "Not enough arguments given.\n";
            return 1;
        }

        else
        {
            sample_size = atoi(argv[1]);
        }
    }

    // file not piped to program
    else
    {
        // check if there are arguments
        if (argc > 2)
        {
            infile.open(argv[1]);
            input = &infile;

            // check if argument is a file
            if (!infile)
            {
                std::cerr << "File " << argv[1] << " doesn't exist or isn't open for reading.\n";
                return 1;
            }

            sample_size = atoi(argv[2]);
        }

        // no arguments given; error
        else
        {
            std::cerr << "Not enough arguments given.\n";
            return 1;
        }
    } 

    std::vector<std::string> sampled = reservoir(*input, sample_size);

    for (auto it = sampled.begin(); it != sampled.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}
