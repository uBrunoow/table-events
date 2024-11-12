#ifndef CREATE_EVENT_H
#define CREATE_EVENT_H
#include "../structs/event_struct.h"
#include "./scanf_event.h"
#include "./show_event.h"
#include <stdlib.h>

void create_event(struct EventStruct **events, int *event_count) {
    printf("\nCriação de eventos:\n");

    *events = realloc(*events, (*event_count + 1) * sizeof(struct EventStruct));
    if (*events == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    scanf_event(*events, *event_count);
    show_event(&(*events)[*event_count]);

    (*event_count)++;
}

#endif // CREATE_EVENT_H