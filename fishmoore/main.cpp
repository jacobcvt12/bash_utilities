#include "fishmoore.hpp"
#include <stdlib.h>

int main(int argc, char* argv[])
{
    FishMoore rng;
    int seed = 0;

    if (argc > 1)
    {
        seed = atol(argv[1]);
    }

    rng.seed(seed);

    for (int i = 0; i < atoi(argv[2]); i++)
    {
        rng.rand_num();
    }

    return 0;
}
