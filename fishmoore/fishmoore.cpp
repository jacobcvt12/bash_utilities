#include <iostream>
#include <iomanip>
#include "fishmoore.hpp"

void FishMoore::seed(long seed)
{
    mSeed = seed;
}

void FishMoore::rand_num()
{
    long a = 397204094;
    long p = 2147483647;

    mSeed  = (a * mSeed) % p;
    
    float random_num = (float)(mSeed) / (float)(p + 1);
    std::cout << std::setprecision(5) << random_num << std::endl;
}
