#ifndef UPDATE_EVENT_H
#define UPDATE_EVENT_H
#include "../structs/event_struct.h"
#include "../show/show_events.h"
#include "../utils/compare_event.h"
#include "../utils/binary_search.h"
#include "./update_event_by_field.h"
#include "./enum_fields.h"

void update_event(struct EventStruct *events, int event_count) {
    if (event_count == 0) {
        printf("Nenhum evento disponível.\n");
        return;
    }

    // Ordena os eventos pelo ID
    qsort(events, event_count, sizeof(struct EventStruct), compare_events);

    // Busca binária pelo ID
    int search_id;
    printf("Digite o ID do evento que deseja buscar: ");
    scanf("%d", &search_id);

    int index = binary_search(events, event_count, search_id);
    if (index != -1) {
        printf("Evento encontrado:\n");
        show_events(&events[index]);

        int selected_option = 0;

        while (selected_option != 10) {
          printf("\n Escolha o que deseja editar no evento %d\n", search_id);
          printf(" -------------------------------- \n");
          printf("( 1 ) Editar o dia do evento. \n");
          printf("( 2 ) Editar o mês do evento. \n");
          printf("( 3 ) Editar o ano do evento. \n");
          printf("( 4 ) Editar a hora de ínicio do evento. \n");
          printf("( 5 ) Editar a hora de fim do evento. \n");
          printf("( 6 ) Editar o time 1 do evento. \n");
          printf("( 7 ) Editar o time 2 do evento. \n");
          printf("( 8 ) Editar a descrição do evento. \n");
          printf("( 9 ) Editar o local do evento. \n");
          printf("( 10 ) Sair do programa. \n");
          printf(" -------------------------------- \n");
          printf("\n");
          printf("Opção escolhida: ");

          scanf("%d", &selected_option);

          switch (selected_option)
          {
          case 1:
            update_event_by_field(&events[index], EVENT_DATE_DAY, events, event_count);
            break;
          case 2:
            update_event_by_field(&events[index], EVENT_DATE_MONTH, events, event_count);
            break;
          case 3:
            update_event_by_field(&events[index], EVENT_DATE_YEAR, events, event_count);
            break;
          case 4:
            update_event_by_field(&events[index], EVENT_START_HOUR, events, event_count);
            break;
          case 5:
            update_event_by_field(&events[index], EVENT_END_HOUR, events, event_count);
            break;
          case 6:
            update_event_by_field(&events[index], TEAM_1, events, event_count);
            break;
          case 7:
            update_event_by_field(&events[index], TEAM_2, events, event_count);
            break;
          case 8:
            update_event_by_field(&events[index], DESCRIPTION, events, event_count);
            break;
          case 9:
            update_event_by_field(&events[index], LOCAL, events, event_count);
            break;
          case 10:
            selected_option = 10;
            break;
          
          default:
            break;
          }
        }
    } else {
        printf("Evento com ID %d não encontrado.\n", search_id);
    }
}

#endif // UPDATE_EVENT_H