#include "reservoir.hpp"
#include "comma.hpp"
#include <random>

std::vector<std::string> reservoir(std::istream& fin, int sample_size, int header_flag)
{
    // initialize vector of size sample_size
    std::vector<std::string> reservoir (sample_size);
    std::string line;

    int row_number = 0;
    int random_int;

    std::mt19937 rng;
    int seed = std::random_device()();
    rng.seed(seed);
        
    std::string header;

    // if file as flagged as having a header,
    // remove first line and store it in header
    if (header_flag == 1)
    {
        std::getline(fin, header);
    }
   
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

    // this creates a new locale based on the current application default
    // (which is either the one given on startup, but can be overriden with
    // std::locale::global) - then extends it with an extra facet that 
    // controls numeric output.
    std::locale comma_locale(std::locale(), new comma_numpunct());

    // tell cerr to use our new locale
    std::cerr.imbue(comma_locale);

    std::cerr << "Seed: " << seed << std::endl;

    if (row_number < sample_size)
    {
        std::cerr << "Sample size is larger than size of data\n" <<
            "Selecting all data.\n";
        reservoir.resize(row_number);
    }

    std::cerr << "Sampled " << reservoir.size() << " items of " << row_number;

    if (header_flag == 1)
    {
        reservoir.insert(reservoir.begin(), header);
    }

    return reservoir;
}
