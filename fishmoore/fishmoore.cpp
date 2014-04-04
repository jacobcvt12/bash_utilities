#include "fishmoore.hpp"

void FishMoore::seed(int seed)
{
    mSeed = seed;
}

void FishMoore::rand_num()
{
    int a = 397204094;
    int p = 2147483647;
    
    float random_num = (float)(mSeed) / (float)(p + 1);
    std::cout << random_num;

    mSeed  = (a * mSeed) % p;
}
