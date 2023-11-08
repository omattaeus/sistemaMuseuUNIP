#ifndef PAGAMENTO_H_INCLUDED
#define PAGAMENTO_H_INCLUDED

#include "dados.h"
#include "tickets.h"
#include "secoes.h"

#define SIZE_TAM 1000

int i;
int opcao_pag;
int aprovado;
int pix_number;
int ticket_visitante[SIZE_TAM];
int pag_confirmado;
int op_continue;

void pagamentos(){
        ticket();

        printf("=====SELECIONE A FORMA DE PAGAMENTO=====\n");
        printf("[1] - CRÉDITO\n");
        printf("[2] - DÉBITO\n");
        printf("[3] - PIX");
        scanf("%d", &opcao_pag);


        FILE *p_arq;
        FILE *p_ticket;

        p_arq = fopen("cadastro.txt", "a");
        p_ticket = fopen("tickets.txt", "a");

        if(p_arq == NULL){
            printf("ERRO AO ABRIR O ARQUIVO!\nRETORNANDO AO MENU!");
            sleep(2);
            system("cls");
            menu();
        }else{
            switch(opcao_pag){
            case 1:
                printf("====CRÉDITO SELECIONADO=====\n");
                printf("Número do cartão: ");
                scanf("%d", &pagdados.card_number);
                fprintf(p_arq, "%s \n", pagdados.card_number);
                printf("Nome: ");
                scanf("%[^\n]", &pagdados.card_nome);
                fprintf(p_arq, "%s \n", pagdados.card_nome);
                printf("Validade: ");
                scanf("%f", &pagdados.card_validade);
                fprintf(p_arq, "%f \n", pagdados.card_validade);
                printf("CVV: ");
                scanf("%d", &pagdados.card_codigo);
                fprintf(p_arq, "%d \n", pagdados.card_codigo);
                aprovado = 1;
                fclose(p_arq);

            if(aprovado=1){
                system("cls");
                printf("=====GERANDO TICKET=====");
                ticket_visitante[i] = 1 + (rand() % 10000);
                printf("NOME: %s", dadoscliente.nome_cliente);
                fprintf(p_ticket, "%s \n", dadoscliente.nome_cliente);
                printf("NÚMERO: %d", ticket_visitante);
                fprintf(p_ticket, "%d \n", ticket_visitante);
                printf("SEÇÃO: %s", opcao_secao);
                fprintf(p_ticket, "%s \n", opcao_secao);
                fclose(p_ticket);
            }else{
                printf("====PAGAMENTO RECUSADO===");
                sleep(2);
                system("cls");
                pagamentos();
            }
            printf("\n[1] - IR PARA SEÇÃO");
            printf("\n[2] - RETORNAR AO MENU");
            scanf("%d", &op_continue);

            if(op_continue == 1){
                printf("\n====VISITANDO SEÇÃO====");
                sleep(2);
                system("cls");
                secao();
            }else{
                printf("====RETORNANDO AO MENU=====");
                sleep(2);
                menu();
            }
            break;

        case 2:
            printf("====DÉBITO SELECIONADO=====\n");
            printf("Número do cartão: ");
            scanf("%d", &pagdados.card_number);
            printf("Nome: ");
            scanf("%[^\n]", &pagdados.card_nome);
            printf("Validade: ");
            scanf("%f", &pagdados.card_validade);
            printf("CVV: ");
            scanf("%d", &pagdados.card_codigo);
            aprovado = 1;

            if(aprovado=1){
                system("cls");
                printf("=====GERANDO TICKET=====");
                ticket_visitante[i] = 1 + (rand() % 10000);
                printf("NOME: %s", dadoscliente.nome_cliente);
                printf("NÚMERO: %d", ticket_visitante);
                printf("SEÇÃO: %s", opcao_secao);
                sleep(2);
                secao();
            }else{
                printf("====PAGAMENTO RECUSADO===");
                sleep(2);
                system("cls");
                pagamentos();
            }
            printf("\n1 - IR PARA SEÇÃO");
            printf("\n2 - RETORNAR AO MENU");
            scanf("%d", &op_continue);

            if(op_continue == 1){
                printf("\n====VISITANDO SEÇÃO====");
                sleep(2);
                system("cls");
                secao();
            }else{
                printf("====RETORNANDO AO MENU=====");
                sleep(2);
                menu();
            }
            break;

        case 3:
            printf("=====PIX SELECIONADO=====\n");
            pix_number = 1 + (rand() % 10000);
            printf("CHAVE PIX: %d", pix_number);
            printf("[1] - JÁ PAGUEI\n");
            printf("[2] - TROCAR FORMA DE PAGAMENTO");
            scanf("%d", &pag_confirmado);

            if(pag_confirmado = 1){
                system("cls");
                printf("=====GERANDO TICKET=====");
                ticket_visitante[i] = 1 + (rand() % 10000);
                printf("NOME: %s", dadoscliente.nome_cliente);
                fprintf(p_ticket, "%s \n", dadoscliente.nome_cliente);
                printf("NÚMERO: %d", ticket_visitante);
                fprintf(p_ticket, "%d \n", ticket_visitante);
                printf("SEÇÃO: %s", opcao_secao);
                fprintf(p_ticket, "%s \n", opcao_secao);
                fclose(p_ticket);
                sleep(2);
                secao();
            }else{
                printf("=====RETORNANDO AO MENU DE PAGAMENTOS=====");
                sleep(2);
                system("cls");
                pagamentos();
            }

            printf("\n[1] - IR PARA SEÇÃO");
            printf("\n[2] - RETORNAR AO MENU");
            scanf("%d", &op_continue);

            if(op_continue == 1){
                printf("\n====VISITANDO SEÇÃO====");
                sleep(2);
                system("cls");
                secao();
            }else{
                printf("====RETORNANDO AO MENU=====");
                sleep(2);
                menu();
            }
        }
        }
}

#endif // PAGAMENTO_H
