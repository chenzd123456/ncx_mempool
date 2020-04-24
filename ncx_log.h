#ifndef _NCX_LOG_H_
#define _NCX_LOG_H_

#define LOG_LEVEL 2

#define LV_TRACE 1
#define LV_DEBUG 2
#define LV_INFO  4
#define LV_ERROR 8
#define LV_ALERT 16

#define log_(level, format, ...) \
    do { \
        if ( level >= LOG_LEVEL ) {\
            fprintf(stderr, "[%c] [%s:%d] "format"\n", \
                         #level[3],  __FUNCTION__, __LINE__, ##__VA_ARGS__); \
        } \
    } while(0)

#define trace(format, ...) log_(LV_TRACE, format, ##__VA_ARGS__)
#define debug(format, ...) log_(LV_DEBUG, format, ##__VA_ARGS__)
#define info(format, ...)  log_(LV_INFO , format, ##__VA_ARGS__)
#define error(format, ...) log_(LV_ERROR, format, ##__VA_ARGS__)
#define alert(format, ...) log_(LV_ALERT, format, ##__VA_ARGS__)

#endif
