#ifndef _COMMON_H_
#define _COMMON_H_

    /*
        * Include common libraries
     */

    #include<stdio.h>
    #include<stdlib.h>
    #include<stdbool.h>
    
    typedef struct InfoNode info_t;
    typedef struct MasterNode master_t;

    #define ANSI_COLOR_RED     "\x1b[31m"
    #define ANSI_COLOR_GREEN   "\x1b[32m"
    #define ANSI_COLOR_YELLOW  "\x1b[33m"
    #define ANSI_COLOR_BLUE    "\x1b[34m"
    #define ANSI_COLOR_MAGENTA "\x1b[35m"
    #define ANSI_COLOR_CYAN    "\x1b[36m"
    #define ANSI_COLOR_RESET   "\x1b[0m"
    
    //Define Logging Level Constant
    #define LOG_LEVEL_INFO 1
    #define LOG_LEVEL_ERROR 2
    #define LOG_LEVEL_DEBUG 3

    enum LOGGING_LEVEL
    {
        LOGGING_INFO = 1,
        LOGGING_ERROR = 2,
        LOGGING_DEBUG = 3
    };

    void logger(const short log_level,char *message);

    master_t* create_master(void);
    info_t* create_info(void*);
    unsigned int master_size(master_t*);
    bool is_master_empty(master_t*);
#endif