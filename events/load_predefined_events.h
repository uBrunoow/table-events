#ifndef LOAD_PREDEFINED_EVENTS_H
#define LOAD_PREDEFINED_EVENTS_H

#include <stdio.h>
#include <stdlib.h>
#include "../structs/event_struct.h"

void load_predefined_events(const char *filename, struct EventStruct **events, int *event_count) {
    printf("Tentando abrir o arquivo: %s\n", filename); // Mensagem de depuração
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo para leitura"); // Usar perror para mais detalhes
        return;
    }

    struct EventStruct temp_event;
    int result;
    while ((result = fscanf(file, "%d,%2s,%2s,%4s,%5s,%5s,%3s,%3s,%99[^,],%99[^,],%d,%9s\n",
                            &temp_event.id,
                            temp_event.event_date_day,
                            temp_event.event_date_month,
                            temp_event.event_date_year,
                            temp_event.event_start_hour,
                            temp_event.event_end_hour,
                            temp_event.team_1,
                            temp_event.team_2,
                            temp_event.description,
                            temp_event.local,
                            &temp_event.is_paid,
                            temp_event.ticket.price.price_reais)) == 12) {
        // Calcular manualmente o valor de price.price_dollars
        float price_reais = atof(temp_event.ticket.price.price_reais);
        float price_dollars = price_reais * 5;
        snprintf(temp_event.ticket.price.price_dollars, sizeof(temp_event.ticket.price.price_dollars), "%.2f", price_dollars);

        printf("Lendo evento: ID=%d, Data=%s/%s/%s\n", temp_event.id, temp_event.event_date_day, temp_event.event_date_month, temp_event.event_date_year);
        struct EventStruct *new_events = realloc(*events, (*event_count + 1) * sizeof(struct EventStruct));
        if (new_events == NULL) {
            printf("Erro ao alocar memória.\n");
            fclose(file);
            return;
        }
        *events = new_events;
        (*events)[*event_count] = temp_event;
        (*event_count)++;

        printf("Evento %d carregado com sucesso.\n", *event_count);
    }

    if (result != EOF) {
        printf("Erro ao ler o evento. fscanf retornou %d\n", result);
        printf("ID: %d\n", temp_event.id);
        printf("Data: %s/%s/%s\n", temp_event.event_date_day, temp_event.event_date_month, temp_event.event_date_year);
        printf("Hora de início: %s\n", temp_event.event_start_hour);
        printf("Hora de fim: %s\n", temp_event.event_end_hour);
        printf("Time 1: %s\n", temp_event.team_1);
        printf("Time 2: %s\n", temp_event.team_2);
        printf("Descrição: %s\n", temp_event.description);
        printf("Local: %s\n", temp_event.local);
        printf("Pago: %d\n", temp_event.is_paid);
        printf("Preço em reais: %s\n", temp_event.ticket.price.price_reais);
        printf("Preço em dólares: %s\n", temp_event.ticket.price.price_dollars);
    }

    fclose(file);
    printf("Eventos pré-cadastrados carregados com sucesso.\n");

    // Imprimir os eventos carregados
    for (int i = 0; i < *event_count; i++) {
        printf("Evento %d:\n", i + 1);
        printf("ID: %d\n", (*events)[i].id);
        printf("Data: %s/%s/%s\n", (*events)[i].event_date_day, (*events)[i].event_date_month, (*events)[i].event_date_year);
        printf("Hora de início: %s\n", (*events)[i].event_start_hour);
        printf("Hora de fim: %s\n", (*events)[i].event_end_hour);
        printf("Time 1: %s\n", (*events)[i].team_1);
        printf("Time 2: %s\n", (*events)[i].team_2);
        printf("Descrição: %s\n", (*events)[i].description);
        printf("Local: %s\n", (*events)[i].local);
        printf("Pago: %d\n", (*events)[i].is_paid);
        printf("Preço em reais: %s\n", (*events)[i].ticket.price.price_reais);
        printf("Preço em dólares: %s\n", (*events)[i].ticket.price.price_dollars);
        printf("\n");
    }
}

#endif // LOAD_PREDEFINED_EVENTS_H