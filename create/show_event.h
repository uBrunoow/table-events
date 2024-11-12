#ifndef SHOW_EVENT_H
#define SHOW_EVENT_H
#include "../structs/event_struct.h"
#include <stdio.h>

void show_event(struct EventStruct *event) {
    printf("\nEvento criado com sucesso!\n");
    printf("ID do evento: %d\n", event->id);
    printf("%s/%s/%s\n", event->event_date_day, event->event_date_month, event->event_date_year);
    printf("%s até %s\n ", event->event_start_hour, event->event_end_hour);
    printf("%sx%s\n", event->team_1, event->team_2);
    printf("%s\n", event->description);
    printf("%s\n", event->local);
    printf("Evento %s\n", event->is_paid ? "pago" : "gratuito");
    if (event->is_paid) {
        printf("Preço do ingresso\n");
        printf("R$%s\n", event->ticket.price.price_reais);
        printf("$%s\n", event->ticket.price.price_dollars);
    }
}

#endif // SHOW_EVENT_H