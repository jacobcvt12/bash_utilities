#include <cmath>
#include "running_stats.hpp"

// Constructor
Stats::Stats(std::string construct_name)
{
    field_name = construct_name;
    n = 0;
    M1 = 0.0;
    M2 = 0.0;
    M3 = 0.0;
    M4 = 0.0;
}

// Incremement running variance with additional value
void Stats::Push(double next_value)
{
    double delta, delta_n, delta_n2, term1;

    long long n1 = n;
    n++;
    delta = next_value - M1;
    delta_n = delta / n;
    delta_n2 = delta_n * delta_n;
    term1 = delta * delta_n * n1;
    M1 += delta_n;
    M4 += term1 * delta_n2 * (n*n - 3*n + 3) + 6 * delta_n2 * M2 - 4 * delta_n * M3;
    M3 += term1 * delta_n * (n - 2) - 3 * delta_n * M2;
    M2 += term1;
}

std::string Stats::GetName() const
{
    return field_name;
}

long long Stats::RowCount() const
{
    return n;
}

double Stats::Mean() const
{
    return M1;
}

double Stats::Variance() const
{
    return M2/(n - 1.0);
}

double Stats::StandardDeviation() const
{
    return sqrt(Variance());
}

double Stats::Skewness() const
{
    return sqrt(double(n)) * M3/ pow(M2, 1.5);
}

double Stats::Kurtosis() const
{
    return double(n)*M4 / (M2*M2) - 3.0;
}
