#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "srs.hpp"

int main(int argc, char* argv[])
{
    /*
     * Default values for arguments
     */

    std::string delimiter = "|"; 
    int weight_field = 1; 
    std::string method = "srs"; 

    int sample_size;
    int nflag = 0; // flag for sample size
    int hflag = 0; // flag for header

    int c;

    // Parse options passed via shell

    while ((c = getopt(argc, argv, "d:hm:n:w:")) != -1)
    switch(c)
    {
        case 'd':
            delimiter = optarg;
            break;
        case 'h':
            hflag = 1;
            break;
        case 'm':
            method = optarg;
        case 'n':
            nflag = 1;
            sample_size = atoi(optarg);
            break;
        case 'w':
            weight_field = atoi(optarg);
        case '?':
            if (optopt == 'n')
                std::cerr << "Option -n requires an argument.\n";
            else
                std::cerr << "Unknown option -" << optopt << std::endl;
               
            return 1;
    }

    if (nflag == 0)
    {
        // If user doesn't specify a sample size
        // Return error and end
        std::cerr << "Must enter a sample size.\n";

        return 1;
    }

    if (method != "srs" && method != "wrs")
    {
        // Method has to be srs (default) or wrs
        std::cerr << "Method must be srs or wrs.\n";
    }


    if (!isatty(fileno(stdin)))
    {
        // file piped to program
        std::istream& input = std::cin; // pass stdin to input
    }

    else
    {
        // file not piped to program

        if (argc - optind > 1)
        {
            // there should only be one file. error if more

            std::cerr << "Must supply one and only one file.\n";
            return 1;
        }

        std::ifstream infile;  

        // open file
        infile.open(argv[optind]);

        // check if argument is a file
        if (!infile)
        {
            std::cerr << "File " << 
                argv[optind] << 
                " doesn't exist or isn't open for reading.\n";

            return 1;
        }
        
        // pass file to input
        std::istream& input = infile;

    }
    
    // call srs function on input and store output in 
    // std::vector sampled. Note, this means that resulting
    // sample must be smalled enough to fit into memory! Even 
    // though the initial data does not have to fit into
    // memory and is read from disk.
    std::vector<std::string> sampled = srs(input, sample_size, hflag);

    // loop over sample and print to stdout
    for (auto it = sampled.begin(); it != sampled.end(); ++it)
    {
        std::cout << *it << std::endl;
    }

    return 0;
}
