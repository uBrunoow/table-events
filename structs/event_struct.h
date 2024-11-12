#ifndef EVENT_STRUCT_H
#define EVENT_STRUCT_H

struct EventStruct {
    int id;
    char event_date_day[3];
    char event_date_month[3];
    char event_date_year[5];
    char event_start_hour[6];
    char event_end_hour[6];
    char team_1[4];
    char team_2[4];
    char description[100];
    char local[100];
    int is_paid; // 0 for free, 1 for paid
    union event_ticket {
        struct event_ticket_price {
            char price_reais[10];
            char price_dollars[10];
        } price;
    } ticket;
};

#endif // EVENT_STRUCT_H