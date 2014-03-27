#ifndef COMMA_H
#define COMMA_H

#include <locale>
#include <iomanip>

class comma_numpunct : public std::numpunct<char>
{
    protected:
        virtual char do_thousands_sep() const;

        virtual std::string do_grouping() const;
};

#endif
