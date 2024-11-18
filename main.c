#include <stdio.h>
#include <stdlib.h>
#include "structs/event_struct.h"
#include "create/create_event.h"
#include "delete/delete_event.h"
#include "read/find_event_by_date.h"
#include "read/find_event_by_string.h"
#include "read/find_event_by_id.h"
#include "read/find_event.h"
#include "update/update_event.h"
#include "utils/restore_event.h"
#include "events/save_events.h"
#include "events/load_predefined_events.h"

int main() {
    int selected_option = 0;
    struct EventStruct *events = NULL;
    int event_count = 0;

    while (selected_option != 10) {
        printf("\n Tabela de jogos do Campeonato de VÔLEI \n");
        printf(" -------------------------------- \n");
        printf("( 1 ) Cadastro de um novo evento. \n");
        printf("( 2 ) Apresentação de todos os eventos. \n");
        printf("( 3 ) Apresentação de um determinado evento, considerando seu ID. \n");
        printf("( 4 ) Apresentação de todos os eventos, considerando uma data específica. \n");
        printf("( 5 ) Apresentação de todos os eventos, considerando um texto que tenha relação com a descrição do evento (string exata). \n");
        printf("( 6 ) Editar um evento com base no seu ID \n");
        printf("( 7 ) Remover um evento com base no seu ID \n");
        printf("( 8 ) Restaurar eventos pré-cadastrados. \n");
        printf("( 9 ) Salvar eventos atuais. \n");
        printf("( 10 ) Sair do programa. \n");
        printf(" -------------------------------- \n");
        printf("\n");
        printf("Opção escolhida: ");

        scanf("%d", &selected_option);

        switch (selected_option) {
        case 1:
            create_event(&events, &event_count);
            break;
        case 2:
            find_event(events, event_count);
            break;
        case 3:
            find_event_by_id(events, event_count);
            break;
        case 4:
            find_event_by_date(events, event_count);
            break;
        case 5:
            find_event_by_string(events, event_count);
            break;
        case 6:
            update_event(events, event_count);
            break;
        case 7:
            delete_event(events, &event_count);
            break;
        case 8:
            #ifdef _WIN32
                load_predefined_events("events.txt", &events, &event_count);
            #else
                load_predefined_events("./events.txt", &events, &event_count);
            #endif
            break;
        case 9:
            save_events(events, event_count);
            break;
        case 10:
            printf("Saindo do programa.\n");
            break;
        default:
            printf("Escolha Inválida\n");
            break;
        }
    }

    free(events);
    return 0;
}