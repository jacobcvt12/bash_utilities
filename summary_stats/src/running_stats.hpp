#ifndef STATS_H
#define STATS_H

#include <fstream>
#include <string>

class Stats
{
    private:
        long long n; // row count
        double M1;                  
        double M2;                  
        double M3;
        double M4;
        std::string field_name; // store field name for printing

    public:
        Stats(std::string construct_name);
        std::string GetName() const;
        void Push(double next_value);
        long long RowCount() const;
        double Mean() const;
        double Variance() const;
        double StandardDeviation() const;
        double Skewness() const;
        double Kurtosis() const;
};


#endif
