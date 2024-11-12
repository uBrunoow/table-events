#ifndef SCANF_EVENT_H
#define SCANF_EVENT_H
#include "../structs/event_struct.h"
#include <stdio.h>
#include <stdlib.h>

void scanf_event(struct EventStruct *event) {
    printf("ID do evento: ");
    scanf("%d", &event->id);
    printf("\n");

    printf("Dia do evento: (DD) ");
    scanf("%2s", event->event_date_day);
    printf("\n");

    printf("Mês do evento: (MM) ");
    scanf("%2s", event->event_date_month);
    printf("\n");

    printf("Ano do evento: (YYYY) ");
    scanf("%4s", event->event_date_year);
    printf("\n");

    printf("Hora de ínicio do evento: (00:00) ");
    scanf("%5s", event->event_start_hour);
    printf("\n");

    printf("Hora de fim do evento: (00:00) ");
    scanf("%5s", event->event_end_hour);
    printf("\n");

    printf("Time n° 1 do evento: (ABC) ");
    scanf("%3s", event->team_1);
    printf("\n");

    printf("Time n° 2 do evento: (ABC) ");
    scanf("%3s", event->team_2);
    printf("\n");

    printf("Descrição do evento: ");
    scanf("%99s", event->description);
    printf("\n");

    printf("Localização do evento: ");
    scanf("%99s", event->local);
    printf("\n");

    printf("O evento é pago? (0 para gratuito, 1 para pago): ");
    scanf("%d", &event->is_paid);
    printf("\n");

    if (event->is_paid) {
        printf("Preço do ingresso em reais: ");
        scanf("%9s", event->ticket.price.price_reais);
        printf("\n");

        // Converte o preço de reais para dólares
        float price_reais = atof(event->ticket.price.price_reais);
        float price_dollars = price_reais * 5;
        snprintf(event->ticket.price.price_dollars, sizeof(event->ticket.price.price_dollars), "%.2f", price_dollars);

        printf("Preço do ingresso em dólares: %s\n", event->ticket.price.price_dollars);
    }
}

#endif // SCANF_EVENT_H