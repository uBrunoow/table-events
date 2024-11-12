#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H
#include "../structs/event_struct.h"

int binary_search(struct EventStruct *events, int event_count, int search_id) {
    int left = 0, right = event_count - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (events[mid].id == search_id) {
            return mid; // Retorna o índice do evento encontrado
        } else if (events[mid].id < search_id) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Retorna -1 se o evento não for encontrado
}

#endif // BINARY_SEARCH_H