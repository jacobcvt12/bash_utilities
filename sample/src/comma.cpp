#include "comma.hpp"

char comma_numpunct::do_thousands_sep() const
{
    return ',';
}

std::string comma_numpunct::do_grouping() const
{
    return "\03";
}
