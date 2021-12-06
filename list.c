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