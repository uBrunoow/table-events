#ifndef EVENT_STRUCT_H
#define EVENT_STRUCT_H

struct EventStruct {
    int id;
    char event_date_month[2];
    char event_date_year[4];
    char event_date_day[2];
    char event_start_hour[2];
    char event_end_hour[2];
    char team_1[3];
    char team_2[3];
    char local;
};

#endif // EVENT_STRUCT_H