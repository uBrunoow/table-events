#ifndef CREATE_EVENT_H
#define CREATE_EVENT_H
#include "../structs/event_struct.h"
#include "./scanf_event.h"

void create_event(struct EventStruct event) {
    printf("Criação de eventos\n");
    scanf_event(&event);
}

#endif // CREATE_EVENT_H