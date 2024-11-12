#ifndef FIND_EVENT_BY_DATE_H
#define FIND_EVENT_BY_DATE_H
#include "../structs/event_struct.h"
#include "./show_events.h"
#include "../utils/compare_event.h"
#include "../utils/binary_date_search.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../validators/is_valid_date.h"


void find_event_by_date(struct EventStruct *events, int event_count) {
    if (event_count == 0) {
        printf("Nenhum evento disponível.\n");
        return;
    }

    // Ordena os eventos pelo ID
    qsort(events, event_count, sizeof(struct EventStruct), compare_events);

    // Busca binária pelo ID
    char event_date_day[3];
    char event_date_month[3];
    char event_date_year[5];
    
    do {
        printf("Digite o dia do evento: ");
        scanf("%3s", event_date_day);
        printf("Digite o mês do evento: ");
        scanf("%3s", event_date_month);
        printf("Digite o ano do evento: ");
        scanf("%5s", event_date_year);
        if (!is_valid_date(event_date_day, event_date_month, event_date_year)) {
            printf("Data inválida. Por favor, tente novamente.\n");
        }
    } while (!is_valid_date(event_date_day, event_date_month, event_date_year));

    int index = binary_date_search(events, event_count,event_date_day, event_date_month, event_date_year);
    if (index != -1) {
        printf("Evento encontrado:\n");
        show_events(&events[index]);
    } else {
        printf("Evento com a data %3s/%3s/%5s não encontrado.\n", event_date_day, event_date_month, event_date_year);
    }
}

#endif // FIND_EVENT_BY_DATE_H