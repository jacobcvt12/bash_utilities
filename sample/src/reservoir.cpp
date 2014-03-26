#include "reservoir.hpp"
#include <random>

std::vector<std::string> reservoir(std::istream& fin, int sample_size)
{
    // initialize vector of size sample_size
    std::vector<std::string> reservoir (sample_size);
    std::string line;

    int row_number = 0;
    int random_int;

    std::mt19937 rng;
    rng.seed(std::random_device()());
   
    while (std::getline(fin, line))
    {
        if (row_number < sample_size)
        {
            reservoir[row_number] = line;
        }

        else
        {
            std::uniform_int_distribution<std::mt19937::result_type> dist(0, row_number - 1);
            random_int = dist(rng);
            
            if (random_int < sample_size)
            {
               reservoir[random_int] = line;
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
