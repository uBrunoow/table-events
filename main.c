#include <stdio.h>
#include "structs/event_struct.h"
#include "create/create_event.h"
#include "delete/delete_event.h"
#include "read/find_event_by_date.h"
#include "read/find_event_by_string.h"
#include "read/find_event.h"
#include "update/update_event.h"
#include "utils/restore_event.h"
#include "utils/save_events.h"

int main() {
    int selected_option = 0;
    struct EventStruct Event;

    printf("\n Tabela de jogos do Campeonato de VÔLEI \n");
    printf(" -------------------------------- \n");
    printf("( 1 ) Cadastro de um novo evento. \n");
    printf("( 2 ) Apresentação de todos os eventos. \n");
    printf("( 3 ) Apresentação de todos os eventos, considerando uma data específica. \n");
    printf("( 4 ) Apresentação de todos os eventos, considerando um texto que tenha relação com a descrição do evento (string exata). \n");
    printf("( 5 ) Editar um evento com base no seu ID \n");
    printf("( 6 ) Remover um evento com base no seu ID \n");
    printf("( 7 ) Restaurar eventos pré-cadastrados. \n");
    printf("( 8 ) Salvar eventos atuais. \n");
    printf("( 9 ) Sair do programa. \n");
    printf(" -------------------------------- \n");
    printf("\n");
    printf("Opção escolhida: ");

    scanf("%d", &selected_option);

    switch (selected_option) {
    case 1:
        printf("Escolha 1\n");
        create_event(Event);
        break;
    case 2:
        printf("Escolha 2\n");
        break;
    case 3:
        printf("Escolha 3\n");
        break;
    case 4:
        printf("Escolha 4\n");
        break;
    case 5:
        printf("Escolha 5\n");
        break;
    case 6:
        printf("Escolha 6\n");
        break;
    case 7:
        printf("Escolha 7\n");
        break;
    default:
        printf("Escolha Inválida\n");
        break;
    }

    return 0;
}