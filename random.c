#include "random.h"

int get_random_int()
{
    int r;
    srand(time(0));
    r = rand();
    return r;
}

int get_random_number(int min, int max)
{
    return ((rand() % (max - min)) + min);
}