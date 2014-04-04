#include "fishmoore.hpp"
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FishMoore rng;
    int seed = 0;

    if (argc > 1)
    {
        seed = atoi(argv[2]);
    }

    rng.seed(seed);

    for (int i = 0; i < 10; i++)
    {
        rng.rand_num();
    }

    return 0;
}
