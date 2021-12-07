#include "list.h"

master_t* create_list()
{
    return create_master();
}

info_t* add(master_t *master, void* inf)
{
    assert(master != NULL);
    info_t* info = create_info(inf);
    assert(info != NULL);

    if(is_master_empty(master))
    {
        master->front = info;
        master->current = info;
        master->rear = info;
    }
    else
    {
        info->previous = master->rear;
        master->rear->next = info;
        master->rear = info;
    }
    master->size += 1;
    return info;
}

void print(fptr_print display, master_t *master)
{
    if(master && !is_master_empty(master))
    {
        info_t *temp = master -> front;
        while(temp != NULL)
        {
            void *info = temp->info;
            if(info)
            {
                display(info);
            }
            else
            {
                printf(" ");
            }
            temp = temp->next;
        }
        printf("\n");
    }
}

bool remove(info_t *node, master_t *master)
{
    bool isRemoved = false;
    if(!is_master_empty(master))
    {
        
    }
    return isRemoved;
}