#ifndef UPDATE_EVENT_BY_FIELD_H
#define UPDATE_EVENT_BY_FIELD_H
#include "../structs/event_struct.h"
#include "./enum_fields.h"
#include <stdio.h>
#include <string.h>

void update_event_by_field(struct EventStruct *event, EventField field) {
    switch (field) {
        case EVENT_DATE_DAY:
            printf("Digite o novo dia do evento: ");
            scanf("%2s", event->event_date_day);
            break;
        case EVENT_DATE_MONTH:
            printf("Digite o novo mês do evento: ");
            scanf("%2s", event->event_date_month);
            break;
        case EVENT_DATE_YEAR:
            printf("Digite o novo ano do evento: ");
            scanf("%4s", event->event_date_year);
            break;
        case EVENT_START_HOUR:
            printf("Digite a nova hora de início do evento: ");
            scanf("%5s", event->event_start_hour);
            break;
        case EVENT_END_HOUR:
            printf("Digite a nova hora de fim do evento: ");
            scanf("%5s", event->event_end_hour);
            break;
        case TEAM_1:
            printf("Digite o novo time 1 do evento: ");
            scanf("%3s", event->team_1);
            break;
        case TEAM_2:
            printf("Digite o novo time 2 do evento: ");
            scanf("%3s", event->team_2);
            break;
        case DESCRIPTION:
            printf("Digite a nova descrição do evento: ");
            scanf("%99s", event->description);
            break;
        case LOCAL:
            printf("Digite a nova localização do evento: ");
            scanf("%99s", event->local);
            break;
        case IS_PAID:
            printf("O evento é pago? (0 para gratuito, 1 para pago): ");
            scanf("%d", &event->is_paid);
            if (event->is_paid) {
                printf("Digite o novo preço do ingresso em reais: ");
                scanf("%9s", event->ticket.price.price_reais);
                // Converte o preço de reais para dólares
                float price_reais = atof(event->ticket.price.price_reais);
                float price_dollars = price_reais * 5;
                snprintf(event->ticket.price.price_dollars, sizeof(event->ticket.price.price_dollars), "%.2f", price_dollars);
                printf("Preço do ingresso em dólares: %s\n", event->ticket.price.price_dollars);
            }
            break;
        default:
            printf("Campo inválido.\n");
            break;
    }
}

#endif // !UPDATE_EVENT_BY_FIELD_H