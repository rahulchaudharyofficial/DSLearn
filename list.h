#ifndef _LIST_H_
#define _LIST_H_
    #include "common.h"    

    typedef void (*fptr_print)(void*);
    typedef bool (*fptr_find)(info_t*, void*);
    master_t* create_list();
    info_t* add_node(master_t *master, void* info);
    void print(master_t *master, fptr_print display);
    bool remove_node(master_t *master,info_t *node);
    info_t* find_node(master_t *master, void *data, fptr_find finder);
#endif