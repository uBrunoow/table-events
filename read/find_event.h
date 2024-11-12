#ifndef FIND_EVENT_H
#define FIND_EVENT_H
#include "../structs/event_struct.h"
#include "./show_events.h"
#include "../utils/compare_event.h"

void find_event(struct EventStruct *events, int event_count) {
    if (event_count == 0) {
        printf("Nenhum evento disponível.\n");
        return;
    }

    // Ordena os eventos pelo ID
    qsort(events, event_count, sizeof(struct EventStruct), compare_events);

    printf("\nEventos disponíveis: \n");  

    for (int i = 0; i < event_count; i++) {
        show_events(&events[i]);
    }
}

#endif