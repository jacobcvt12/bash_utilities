#ifndef WRS_H
#define WRS_H

#include <string>
#include <vector>
#include <iostream>

std::vector<std::string> wrs(std::istream& fin, int sample_size, 
        int header_flag, int field_number, std::string delimiter);

float weight(std::string str, int field_number, std::string delimiter);

#endif
