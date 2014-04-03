#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "reservoir.hpp"

// add in argument parsing
// http://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html

int main(int argc, char* argv[])
{
    int sample_size;
    int nflag = 0;
    int hflag = 0;
    int c;

    while ((c = getopt(argc, argv, "hn:")) != -1)
    switch(c)
    {
        case 'h':
            hflag = 1;
            break;
        case 'n':
            nflag = 1;
            sample_size = atoi(optarg);
            break;
        case '?':
            if (optopt == 'n')
                std::cerr << "Option -n requires an argument.\n";
            else
                std::cerr << "Unknown option -" << optopt << std::endl;
               
            return 1;
    }

    if (nflag == 0)
    {
        std::cerr << "Must enter a sample size.\n";

        return 1;
    }


    std::istream* input;
    std::ifstream infile;  
    std::string input_device;
    
    // file piped to program
    if (!isatty(fileno(stdin)))
    {
        input = &std::cin;
        input_device = "stdin";
    }

    // file not piped to program
    else
    {
        int index;
        opterr = 0;
        int file_counter = 0; // there should only be one file. error if more

        for (index = optind; index < argc; index++)
        {
            file_counter++;
            if (file_counter != 1)
            {
                std::cerr << "Must supply one and only one file.\n";
                return 1;
            }

            infile.open(argv[index]);
            input_device = argv[index];
            input = &infile;

            // check if argument is a file
            if (!infile)
            {
                std::cerr << "File " << argv[index] << " doesn't exist or isn't open for reading.\n";
                return 1;
            }

        }
    }
    
    std::vector<std::string> sampled = reservoir(*input, sample_size, hflag);

    std::cerr << " from " << input_device << std::endl;

    for (auto it = sampled.begin(); it != sampled.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}
