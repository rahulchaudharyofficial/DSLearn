#include "common.h"

/*
struct InfoNode
{
    void *info;
    struct InfoNode *next;
    struct InfoNode *previous;
};

struct MasterNode
{
    unsigned int size;
    struct InfoNode *front;
    struct InfoNode *current;
    struct InfoNode *rear;
};
*/
unsigned int master_size(master_t *master)
{
    assert(master != NULL);
    return master->size;
}

bool is_master_empty(master_t *master)
{
    bool isEmpty = false;
    if(master == NULL || ( 
        master->size == 0 && 
        master->current == NULL && 
        master->front == NULL && 
        master->rear == NULL))
        {
            isEmpty = true;
        }

    return isEmpty;
}

void logger(const short log_level,char *message)
{
    switch(log_level)
    {
        case LOG_LEVEL_INFO:
            printf(ANSI_COLOR_YELLOW "%s\n", message,ANSI_COLOR_RESET);
            break;
        case LOG_LEVEL_DEBUG:
            printf(ANSI_COLOR_GREEN "%s\n", message,ANSI_COLOR_RESET);
            break;
        case LOG_LEVEL_ERROR:
            printf(ANSI_COLOR_RED "%s\n", message,ANSI_COLOR_RESET);
            break;
        default:
            printf(ANSI_COLOR_CYAN "%s\n", message,ANSI_COLOR_RESET);
            break;
    }
}

master_t* create_master(void)
{
    master_t *master = (master_t*) malloc(sizeof(master_t));
    if(master)
    {
        master->current = NULL;
        master->front = NULL;
        master->rear = NULL;
        master->size = 0;
        //logger(LOG_LEVEL_INFO, "MasterNode record created successfully\n");
    }
    else
    {
        logger(LOG_LEVEL_ERROR,"MemoryOverflowError: MasterNode memory allocation failed!\n");
    }
    return master;
}

info_t* create_info(void* info)
{
    info_t *inf = (info_t*) malloc(sizeof(info_t));
    if(inf)
    {
        inf->info = info;
        inf->next = NULL;
        inf->previous = NULL;
        //logger(LOG_LEVEL_INFO, "InfoNode record created successfully\n");
    }
    else
    {
        logger(LOG_LEVEL_ERROR,"MemoryOverflowError: MasterNode memory allocation failed!\n");
    }
    return inf;
}

info_t* get_front(master_t* master)
{
    if(master)
        return master->front;
    else
        return NULL;
}

info_t* get_rear(master_t* master)
{
    if(master)
        return master->rear;
    else
        return NULL;
}

info_t* get_current(master_t* master)
{
    if(master)
        return master->current;
    else
        return NULL;
}