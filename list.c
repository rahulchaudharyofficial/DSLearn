#include "list.h"

master_t* create_list()
{
    return create_master();
}

info_t* add_node(master_t *master, void* inf)
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

void print(master_t *master, fptr_print display)
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

bool remove_node(master_t *master,info_t *node)
{
    bool isRemoved = false;
    if(!is_master_empty(master))
    {
        info_t * temp = master->front;
        while(temp != node)
        {
            temp = temp->next;
        }
        if(master_size(master) == 1)
        {
            master->current = NULL;
            master->front = NULL;
            master->rear = NULL;
        }
        else
        {
            temp->previous->next = temp->next;
        }
        master->size-=1;
        //free(temp->info);
        free(temp);
        isRemoved = true;
    }
    return isRemoved;
}

info_t* find_node(master_t *master, void* data, fptr_find finder)
{
    info_t *temp = NULL;
    bool found = false;
    if(!is_master_empty(master))
    {
        temp = master->front;
        while(temp != NULL)
        {
            if(finder(temp, data))
            {
                found = true;
                break;
            }
            temp = temp->next;
        }
        // If failed to find then reset return item to NULL
        if(!found)
        {
            temp = NULL;
        }
    }
    return temp;
}

void cleanup(master_t *master)
{
    if(!is_master_empty(master))
    {
        while(master->front != NULL)
        {
            remove_node(master, master->front);   
        }
    }
    if(master != NULL)
        free(master);
}