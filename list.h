#ifndef _LIST_H_
#define _LIST_H_
    #include "common.h"    

    typedef void (*fptr_print)(void*);

    master_t* create_list();
    info_t* add(master_t *master, void* info);
    void print(fptr_print display,master_t *master);
    bool remove(info_t *node, master_t *master);
#endif