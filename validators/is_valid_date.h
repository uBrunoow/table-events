#ifndef IS_VALID_DATE_H
#define IS_VALID_DATE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_valid_date(const char *day, const char *month, const char *year) {
    int d = atoi(day);
    int m = atoi(month);
    int y = atoi(year);

    if (y < 1900 || y > 2100) return 0;
    if (m < 1 || m > 12) return 0;
    if (d < 1 || d > 31) return 0;

    // Verifica os dias de cada mês
    if ((m == 4 || m == 6 || m == 9 || m == 11) && d > 30) return 0;
    if (m == 2) {
        // Verifica ano bissexto
        int is_leap = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
        if (d > 29 || (d == 29 && !is_leap)) return 0;
    }

    return 1;
}

#endif // IS_VALID_DATE_H