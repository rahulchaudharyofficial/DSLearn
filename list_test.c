#include "list.h"

void print_int(void *info)
{
    int* data = (int*) info;
    printf("%d \t", *data);
}

int main(int argc, char const *argv[])
{
    master_t *master = create_list();
    for(int i = 1; i <= 10; i++)
    {
        int *j = (int*) malloc(sizeof(int));
        *j = i;
        add(master,j);
    }
    print(print_int,master);
    return 0;
}
