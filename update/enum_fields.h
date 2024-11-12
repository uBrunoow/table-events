#ifndef EVENT_FIELDS_H
#define EVENT_FIELDS_H

typedef enum {
    EVENT_DATE_DAY,
    EVENT_DATE_MONTH,
    EVENT_DATE_YEAR,
    EVENT_START_HOUR,
    EVENT_END_HOUR,
    TEAM_1,
    TEAM_2,
    DESCRIPTION,
    LOCAL,
    IS_PAID
} EventField;

#endif // EVENT_FIELDS_H