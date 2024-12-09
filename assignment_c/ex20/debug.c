//
// Created by zhiyo on 2024/10/12.
//

#include <stdarg.h>
#include <stdio.h>
static int debug_level_set;

void set_debug_level(int debug_level){
    debug_level_set = debug_level;
}

int dprintf(int debug_level, const char *fmt, ...){
    setbuf(stdout, NULL);
    setbuf(stdin, NULL);
    if (debug_level <= debug_level_set) {
        fprintf(stderr, "[DBG%d]", debug_level);
        va_list args;
        va_start(args, fmt);
        vfprintf(stderr, fmt, args);
        va_end(args);
       return 1;
    }
    return 0;
}
