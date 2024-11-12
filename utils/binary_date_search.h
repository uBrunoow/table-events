#ifndef BINARY_DATE_SEARCH_H
#define BINARY_DATE_SEARCH_H
#include "../structs/event_struct.h"
#include <string.h>

int compare_dates(const struct EventStruct *event, const char *day, const char *month, const char *year) {
    int cmp_day = strcmp(event->event_date_day, day);
    int cmp_month = strcmp(event->event_date_month, month);
    int cmp_year = strcmp(event->event_date_year, year);

    if (cmp_year != 0) return cmp_year;
    if (cmp_month != 0) return cmp_month;
    return cmp_day;
}

int binary_date_search(struct EventStruct *events, int event_count, const char *day, const char *month, const char *year) {
    int left = 0, right = event_count - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = compare_dates(&events[mid], day, month, year);
        if (cmp == 0) {
            return mid; // Retorna o índice do evento encontrado
        } else if (cmp < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Retorna -1 se o evento não for encontrado
}

#endif // BINARY_DATE_SEARCH_H