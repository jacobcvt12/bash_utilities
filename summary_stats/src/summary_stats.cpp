#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>

int main(int argc, char* argv[])
{
    /*
     * Default values for arguments
     */

    std::string delimiter = "|"; 
    std::string fields;
    int hflag = 0; // flag for header
    int field_low = 0; // first field
    int field_high = 0; // last field

    int c;

    // Parse options passed via shell

    while ((c = getopt(argc, argv, "d:f:h")) != -1)
    switch(c)
    {
        case 'd':
            delimiter = optarg;
            break;
        case 'f':
            fields = optarg;
            // parse arguments
            break;
        case 'h':
            hflag = 1;
            break;
        case '?':
            std::cerr << "Unknown option -" << optopt << std::endl;
            return 1;
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
    
    return 0;
}
