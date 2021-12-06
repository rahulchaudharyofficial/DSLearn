#ifndef _LIST_H_
#define _LIST_H_
    #include "common.h"
    #include<stdbool.h>
    
    master_t* create_list();
    info_t* add(master_t *master, void* info);

#endif