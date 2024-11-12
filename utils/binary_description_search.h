#ifndef BINARY_DESCRIPTION_SEARCH_H
#define BINARY_DESCRIPTION_SEARCH_H
#include "../structs/event_struct.h"
#include <string.h>

int compare_descriptions(const struct EventStruct *event, const char *description) {
    return strcmp(event->description, description);
}

int binary_description_search(struct EventStruct *events, int event_count, const char *description) {
    int left = 0, right = event_count - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = compare_descriptions(&events[mid], description);
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

#endif // BINARY_DESCRIPTION_SEARCH_H