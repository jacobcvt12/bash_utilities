#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <stdlib.h>
#include <getopt.h>
#include "reservoir.hpp"

// add in argument parsing
// http://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html

int main(int argc, char* argv[])
{
    std::istream* input;
    std::ifstream infile;  

    int sample_size;

    std::string input_device;
    
    // file piped to program
    if (!isatty(fileno(stdin)))
    {
        input = &std::cin;
        input_device = "stdin";
        
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
            input_device = argv[1];
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

    std::cerr << " from " << input_device << std::endl;

    for (auto it = sampled.begin(); it != sampled.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}
