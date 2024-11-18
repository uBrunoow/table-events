#ifndef FIND_EVENT_BY_ID_H
#define FIND_EVENT_BY_ID_H
#include "../structs/event_struct.h"
#include "../show/show_events.h"
#include "../utils/compare_event.h"
#include "../utils/binary_search.h"

void find_event_by_id(struct EventStruct *events, int event_count) {
    if (event_count == 0) {
        printf("Nenhum evento disponível.\n");
        return;
    }

    // Ordena os eventos pelo ID
    qsort(events, event_count, sizeof(struct EventStruct), compare_events);

    // Busca binária pelo ID
    int search_id;
    printf("Digite o ID do evento que deseja buscar: ");
    scanf("%d", &search_id);

    int index = binary_search(events, event_count, search_id);
    if (index != -1) {
        printf("Evento encontrado:\n");
        show_events(&events[index]);
    } else {
        printf("Evento com ID %d não encontrado.\n", search_id);
    }
}

#endif // FIND_EVENT_BY_ID_H