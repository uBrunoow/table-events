#ifndef SAVE_EVENTS_H
#define SAVE_EVENTS_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../structs/event_struct.h"

void save_events(struct EventStruct *events, int event_count) {
    // Obter a data e hora atual
    time_t now = time(NULL);
    struct tm *t = localtime(&now);

    // Formatar a data e hora em uma string
    char timestamp[20];
    strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", t);

    // Criar o nome do arquivo com o timestamp
    char filename[50];

    #ifdef _WIN32
        snprintf(filename, sizeof(filename), "events/saved/saved_%s.txt", timestamp);
    #else
        snprintf(filename, sizeof(filename), "../events/saved/saved_%s.txt", timestamp);
    #endif
    
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }

    for (int i = 0; i < event_count; i++) {
        fprintf(file, "%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%d,%s,%s\n",
                events[i].id,
                events[i].event_date_day,
                events[i].event_date_month,
                events[i].event_date_year,
                events[i].event_start_hour,
                events[i].event_end_hour,
                events[i].team_1,
                events[i].team_2,
                events[i].description,
                events[i].local,
                events[i].is_paid,
                events[i].ticket.price.price_reais,
                events[i].ticket.price.price_dollars);
    }

    fclose(file);
    printf("Eventos salvos com sucesso no arquivo: %s\n", filename);
}

#endif // SAVE_EVENTS_H