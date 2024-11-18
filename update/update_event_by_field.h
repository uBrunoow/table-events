#ifndef UPDATE_EVENT_BY_FIELD_H
#define UPDATE_EVENT_BY_FIELD_H
#include "../structs/event_struct.h"
#include "./enum_fields.h"
#include <stdio.h>
#include <string.h>
#include "../validators/is_valid_date.h"

void update_event_by_field(struct EventStruct *event, EventField field, struct EventStruct *events, int event_count) {    
    switch (field) {
        case EVENT_DATE_DAY:
            do{ 
                printf("Digite o novo dia do evento: ");
                scanf("%2s", event->event_date_day);
                // Limpa o buffer de entrada para evitar problemas com entradas longas
                while (getchar() != '\n');

                if (strlen(event->event_date_day) != 2 || !is_valid_date(event->event_date_day, event->event_date_month, event->event_date_year)) {
                    printf("Data inválida. Por favor, tente novamente.\n");
                }
            } while (!is_valid_date(event->event_date_day, event->event_date_month, event->event_date_year));
            break;
        case EVENT_DATE_MONTH:
            do {
                printf("Digite o novo mês do evento: ");
                scanf("%2s", event->event_date_month);

                if (!is_valid_date(event->event_date_day, event->event_date_month, event->event_date_year)) {
                    printf("Data inválida. Por favor, tente novamente.\n");
                }
            } while (!is_valid_date(event->event_date_day, event->event_date_month, event->event_date_year));
            break;
        case EVENT_DATE_YEAR:
            do{
                printf("Digite o novo ano do evento: ");
                scanf("%4s", event->event_date_year);
                if (!is_valid_date(event->event_date_day, event->event_date_month, event->event_date_year)) {
                    printf("Data inválida. Por favor, tente novamente.\n");
                }
            } while (!is_valid_date(event->event_date_day, event->event_date_month, event->event_date_year));
            break;
        case EVENT_START_HOUR:
            do {
                printf("Digite a nova hora de início do evento: (00:00) ");
                scanf("%5s", event->event_end_hour);
                if (!is_valid_time(event->event_end_hour)) {
                    printf("Horário inválido. Por favor, tente novamente.\n");
                }
            } while (!is_valid_time(event->event_end_hour));

            break;
        case EVENT_END_HOUR:
            do {
                printf("Digite a nova hora de fim do evento: (00:00) ");
                scanf("%5s", event->event_end_hour);
                if (!is_valid_time(event->event_end_hour)) {
                    printf("Horário inválido. Por favor, tente novamente.\n");
                }
            } while (!is_valid_time(event->event_end_hour));
            break;
        case TEAM_1:
            do {
                char temp_team_1[50]; // Variável temporária para armazenar o novo time
                printf("Digite o novo time n° 1 do evento: (ABC) ");
                scanf("%49s", temp_team_1); // Supondo que event->team_1 tenha tamanho 50
                
                if (is_team_busy(events, event_count, temp_team_1, event->event_date_day, event->event_date_month, event->event_date_year, event->local) == 1) {
                    printf("O time 1 já tem um jogo no mesmo dia e local. Por favor, tente novamente.\n");
                } else {
                    strcpy(event->team_1, temp_team_1); // Atualiza o campo do time apenas se não estiver ocupado
                    break;
                }
            } while (1);
            break;
        case TEAM_2:
            do {
                char temp_team_2[50]; // Variável temporária para armazenar o novo time
                printf("Digite o novo time n° 2 do evento: (ABC) ");
                scanf("%49s", temp_team_2); // Supondo que event->team_2 tenha tamanho 50
                
                if (is_team_busy(events, event_count, temp_team_2, event->event_date_day, event->event_date_month, event->event_date_year, event->local) == 1) {
                    printf("O time 2 já tem um jogo no mesmo dia e local. Por favor, tente novamente.\n");
                } else {
                    strcpy(event->team_2, temp_team_2); // Atualiza o campo do time apenas se não estiver ocupado
                    break;
                }
            } while (1);
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