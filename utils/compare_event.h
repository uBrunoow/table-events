#ifndef COMPARE_EVENT_H
#define COMPARE_EVENT_H
#include "../structs/event_struct.h"

int compare_events(const void *a, const void *b) {
    struct EventStruct *eventA = (struct EventStruct *)a;
    struct EventStruct *eventB = (struct EventStruct *)b;
    return eventA->id - eventB->id;
}

#endif // COMPARE_EVENT_H