#include "wrs.hpp"
#include "comma.hpp"
#include <random>
#include <cmath>

std::vector<std::string> wrs(std::istream& fin, int sample_size,
        int header_flag, int field_number, std::string delimiter)
{
    // this whole section is a duplicate of srs.cpp
    // turn it into an option and add one or two custom methods
    // to inherited object to reduce code base?
    // would be helpful when adding with replacement as well
    std::vector<std::string> reservoir (sample_size);
    std::vector<float> weight_keys (sample_size);
    std::string line;

    int row_number = 0;

    std::mt19937 rng;
    int seed = std::random_device()();
    rng.seed(seed);

    std::string header;
    
    // if file is flagged as having a header,
    // remove first line and store it in header
    if (header_flag == 1)
    {
        std::getline(fin, header);
    }

    int sample_num = 0;
    float key;
    std::pair<float, int> min_key (-1.0, 0);    

    while (std::getline(fin, line))
    {
        key = pow(rng(),
            1.0 / weight(line, field_number, delimiter));

        if (key < min_key.first || min_key.first < 0.0)
        {
            min_key.first = key;
            min_key.second = sample_num;
        }

        if (row_number < sample_size)
        {
            reservoir[row_number] = line;
            weight_keys[row_number] = key;
            
        }

        else
        {

        }

        sample_num++;
        row_number++;
    }

    return reservoir;
}

float weight(std::string str, int field_number, std::string delimiter)
{
    float weight = -1.0;
    int pos = 0;
    int col_num = 1;

    while ((pos = str.find(delimiter) != std::string::npos))
    {
        if (col_num == field_number)
        {
            weight = std::stof(str.substr(0, pos));
            break;
        }
        str.erase(0, pos + delimiter.length());
        col_num++;
    }

    if (weight < 0.0)
    {
        std::cerr << "Weight is either not found or is less than zero.\n" <<
            "Setting weight to zero for this row.\n" <<
            "(Zero probability of selection).\n\n";
    }

    return weight;
}
