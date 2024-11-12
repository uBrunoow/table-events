#ifndef IS_VALID_TIME_H
#define IS_VALID_TIME_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_valid_time(const char *time) {
    int h, m;
    if (sscanf(time, "%2d:%2d", &h, &m) != 2) return 0;
    if (h < 0 || h > 23) return 0;
    if (m < 0 || m > 59) return 0;
    return 1;
}

#endif // IS_VALID_TIME_H