#ifndef CREATE_EVENT_H
#define CREATE_EVENT_H
#include "../structs/event_struct.h"
#include "./scanf_event.h"
#include "./show_event.h"
#include <stdlib.h>

void create_event(struct EventStruct **events, int *event_count) {
    struct EventStruct event;
    printf("\nCriação de eventos:\n");
    scanf_event(&event);
    show_event(&event);

    *events = realloc(*events, (*event_count + 1) * sizeof(struct EventStruct));
    if (*events == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    (*events)[*event_count] = event;
    (*event_count)++;
}

#endif // CREATE_EVENT_H