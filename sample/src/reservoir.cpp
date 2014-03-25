#include "reservoir.hpp"
#include <random>

std::vector<std::string> reservoir(std::istream& fin, int sample_size)
{
    // initialize vector of size sample_size
    std::vector<std::string> reservoir (sample_size);
    std::string line;

    int row_number = 1;

    typedef std::minstd_rand generator;
    generator seed;
    typedef std::uniform_int_distribution<long> distribution;

    while (std::getline(fin, line))
    {
        if (row_number <= sample_size)
        {
            reservoir[row_number - 1] = line;
        }

        else
        {
            distribution d(1, row_number);
            int random_int = d(seed);
            
            if (random_int <= row_number)
            {
               reservoir[random_int - 1] = line;
            } 
        }

        row_number += 1;
    }

    if (row_number < sample_size)
    {
        std::cerr << "Sample size is larger than size of data\n" <<
            "Selecting all data.\n";
    }

    return reservoir;
}
