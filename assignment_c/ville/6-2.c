//
// Created by zhiyo on 2024/10/14.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdbool.h>


typedef enum { logCritical, logWarning, logInfo, logVerbose } loglevel;
// Log levels as strings:  "Critical", "Warning", "Info", "Verbose"
// impelement this function
const char *log_level_to_str(loglevel level);
// implement this function
int log(loglevel level, const char *format, ...);


// this (existing) function sets the global log_level variable
void set_log_level(loglevel level);

loglevel current_log_level = logInfo;

const char *log_level_to_str(loglevel level) {
    switch (level) {
        case logCritical:
            return "Critical";
        case logWarning:
            return "Warning";
        case logInfo:
            return "Info";
        case logVerbose:
            return "Verbose";
        default:
            return NULL;
    }
}

int log(loglevel level, const char *format, ...) {
    if(level >= current_log_level) {
        return level;
    }
    printf("LOG[%s]: ", log_level_to_str(level));
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
    return level;
}

