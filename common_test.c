#include "common.h"

int main(int argc, char const *argv[])
{
    master_t *master = create_master();
    free(master);
    return 0;
}
