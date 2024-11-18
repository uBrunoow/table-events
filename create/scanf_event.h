#ifndef SCANF_EVENT_H
#define SCANF_EVENT_H
#include "../structs/event_struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/compare_event.h"
#include "../validators/is_valid_date.h"
#include "../validators/is_valid_time.h"
#include "../validators/is_team_busy.h"

void scanf_event(struct EventStruct *events, int event_count) {
    // Ordena os eventos pelo ID
    qsort(events, event_count, sizeof(struct EventStruct), compare_events);

    // Encontra o último ID e incrementa
    int new_id = (event_count > 0) ? events[event_count - 1].id + 1 : 1;

    struct EventStruct new_event;
    new_event.id = new_id;

    printf("ID do evento: %d\n", new_event.id);

    do {
        printf("Dia do evento: (DD) ");
        scanf("%2s", new_event.event_date_day);
        printf("Mês do evento: (MM) ");
        scanf("%2s", new_event.event_date_month);
        printf("Ano do evento: (YYYY) ");
        scanf("%4s", new_event.event_date_year);
        if (!is_valid_date(new_event.event_date_day, new_event.event_date_month, new_event.event_date_year)) {
            printf("Data inválida. Por favor, tente novamente.\n");
        }
    } while (!is_valid_date(new_event.event_date_day, new_event.event_date_month, new_event.event_date_year));

    do {
        printf("Hora de ínicio do evento: (00:00) ");
        scanf("%5s", new_event.event_start_hour);
        if (!is_valid_time(new_event.event_start_hour)) {
            printf("Horário inválido. Por favor, tente novamente.\n");
        }
    } while (!is_valid_time(new_event.event_start_hour));

    do {
        printf("Hora de fim do evento: (00:00) ");
        scanf("%5s", new_event.event_end_hour);
        if (!is_valid_time(new_event.event_end_hour)) {
            printf("Horário inválido. Por favor, tente novamente.\n");
        }
    } while (!is_valid_time(new_event.event_end_hour));

    // Consumir o caractere de nova linha deixado pelo scanf anterior
    getchar();

    printf("Localização do evento: ");
    fgets(new_event.local, sizeof(new_event.local), stdin);

    // Remove o caractere de nova linha, se presente
    new_event.local[strcspn(new_event.local, "\n")] = '\0';

    do {
        printf("Time n° 1 do evento: (ABC) ");
        scanf("%3s", new_event.team_1);
        
        if (is_team_busy(events, event_count, new_event.team_1, new_event.event_date_day, new_event.event_date_month, new_event.event_date_year, new_event.local) == 1) {
            printf("O time 1 já tem um jogo no mesmo dia e local. Por favor, tente novamente.\n");
        }
    } while (is_team_busy(events, event_count, new_event.team_1, new_event.event_date_day, new_event.event_date_month, new_event.event_date_year, new_event.local) == 1);

    do {
        printf("Time n° 2 do evento: (ABC) ");
        scanf("%3s", new_event.team_2);
        if (is_team_busy(events, event_count, new_event.team_2, new_event.event_date_day, new_event.event_date_month, new_event.event_date_year, new_event.local) == 1) {
            printf("O time 2 já tem um jogo no mesmo dia e local. Por favor, tente novamente.\n");
        }
    } while (is_team_busy(events, event_count, new_event.team_2, new_event.event_date_day, new_event.event_date_month, new_event.event_date_year, new_event.local) == 1);

    // Consumir o caractere de nova linha deixado pelo scanf anterior
    getchar();

    printf("Descrição do evento: ");
    fgets(new_event.description, sizeof(new_event.description), stdin);

    // Remove o caractere de nova linha, se presente
    new_event.description[strcspn(new_event.description, "\n")] = '\0';

    printf("O evento é pago? (0 para gratuito, 1 para pago): ");
    scanf("%d", &new_event.is_paid);

    if (new_event.is_paid) {
        printf("Preço do ingresso em reais: ");
        scanf("%9s", new_event.ticket.price.price_reais);

        // Converte o preço de reais para dólares
        float price_reais = atof(new_event.ticket.price.price_reais);
        float price_dollars = price_reais * 5;
        snprintf(new_event.ticket.price.price_dollars, sizeof(new_event.ticket.price.price_dollars), "%.2f", price_dollars);

        printf("Preço do ingresso em dólares: %s\n", new_event.ticket.price.price_dollars);
    }

    // Adiciona o novo evento ao array de eventos
    events[event_count] = new_event;
}

#endif // SCANF_EVENT_H