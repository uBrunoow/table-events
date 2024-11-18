#ifndef IS_TEAM_BUSY_H
#define IS_TEAM_BUSY_H
#include "../structs/event_struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_team_busy(struct EventStruct *events, int event_count, const char *team, const char *day, const char *month, const char *year, const char *local) {
    for (int i = 0; i < event_count; i++) {
        if ((strcmp(events[i].team_1, team) == 0 || strcmp(events[i].team_2, team) == 0) &&
            strcmp(events[i].event_date_day, day) == 0 &&
            strcmp(events[i].event_date_month, month) == 0 &&
            strcmp(events[i].event_date_year, year) == 0 &&
            strcmp(events[i].local, local) == 0) {
            return 1; // O time já tem um jogo no mesmo dia e local
        }
    }
    return 0; // O time não está ocupado
}

#endif // IS_TEAM_BUSY_H