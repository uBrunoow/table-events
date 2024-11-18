#ifndef DELETE_EVENT_H
#define DELETE_EVENT_H
#include "../structs/event_struct.h"
#include "../utils/compare_event.h"
#include "../utils/binary_search.h"
#include "../show/show_events.h"
#include <stdio.h>
#include <stdlib.h>

void delete_event(struct EventStruct *events, int *event_count) {
    if (*event_count == 0) {
        printf("Nenhum evento disponível.\n");
        return;
    }

    // Ordena os eventos pelo ID
    qsort(events, *event_count, sizeof(struct EventStruct), compare_events);

    // Busca binária pelo ID
    int search_id;
    printf("Digite o ID do evento que deseja deletar: ");
    scanf("%d", &search_id);

    int index = binary_search(events, *event_count, search_id);
    if (index != -1) {
        printf("Evento encontrado:\n");
        show_events(&events[index]);

        // Remove o evento do array
        for (int i = index; i < *event_count - 1; i++) {
            events[i] = events[i + 1];
        }

        // Decrementa a contagem de eventos
        (*event_count)--;

        // Realoca a memória para o array de eventos
        events = realloc(events, (*event_count) * sizeof(struct EventStruct));
        if (events == NULL && *event_count > 0) {
            printf("Erro ao realocar memória.\n");
            exit(1);
        }

        printf("Evento deletado com sucesso.\n");
    } else {
        printf("Evento com ID %d não encontrado.\n", search_id);
    }
}

#endif // !DELETE_EVENT_H