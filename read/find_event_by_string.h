#ifndef FIND_EVENT_BY_STRING_H
#define FIND_EVENT_BY_STRING_H
#include "../structs/event_struct.h"
#include "./show_events.h"
#include "../utils/compare_event.h"
#include "../utils/binary_description_search.h"

void find_event_by_string(struct EventStruct *events, int event_count) {
    if (event_count == 0) {
        printf("Nenhum evento disponível.\n");
        return;
    }

    // Ordena os eventos pelo ID
    qsort(events, event_count, sizeof(struct EventStruct), compare_events);

    // Busca binária pelo ID
    char description[100];
    printf("Digite a descrição do evento que deseja buscar: ");
    scanf("%99s", description);

    int index = binary_description_search(events, event_count, description);
    if (index != -1) {
        printf("Evento encontrado:\n");
        show_events(&events[index]);
    } else {
        printf("Evento com a descrição %99s não encontrado.\n", description);
    }
}

#endif // FIND_EVENT_BY_STRING_H