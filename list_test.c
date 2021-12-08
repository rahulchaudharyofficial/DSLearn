#include "list.h"

void print_int(void *info)
{
    int* data = (int*) info;
    printf("%d \t", *data);
}

bool finder(info_t *node, void *data)
{
    bool found = false;
    if(node != NULL && data != NULL)
    {
        int *info = (int*) data;
        int *node_data = (int*) node->info;
        if(node_data != NULL && *node_data == *info)
            found = true;
    }
    return found;
}

int main(int argc, char const *argv[])
{
    master_t *master = create_list();
    for(int i = 1; i <= 10; i++)
    {
        int *j = (int*) malloc(sizeof(int));
        *j = i;
        add_node(master,j);
    }
    print(master, print_int);
    
    int *data = (int*) malloc(sizeof(int));
    *data = 10;
    info_t *node = find_node(master, data, finder);
    remove_node(master,node);

    *data = 6;
    node = find_node(master, data, finder);
    remove_node(master,node);
    print(master, print_int);
    cleanup(master);
    print(master,print_int);
    return 0;
}
