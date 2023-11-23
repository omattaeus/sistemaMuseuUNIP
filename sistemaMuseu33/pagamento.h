#ifndef PAGAMENTO_H_INCLUDED
#define PAGAMENTO_H_INCLUDED

#include "caso.h"
#include "secoes.h"

#define NOME_RELAT 50
#define EMAIL_RELAT 100

int opcao_pag;
int aprovado;
int pix_number;
int ticket_visitante;
int pag_confirmado;
int op_continue;
int sairfinal;
int continueobra;
int opcaoconfirm;
int opcaoentrada;
float ent_entrada = 20.00;
float meia_entrada;
float notaimpacto, notaexpre, notaint, notaconex, notainov, medianota;

void secao();
void notas_secao();

void pagamentos(){

        printf("=====TICKET DREAM WITH=====\n");
        printf("QUAL SEÇÃO GOSTARIA DE ASSISTIR?\n");
        printf("[1] - MANIFESTO ANTROPÓFAGO DE OSWALD DE ANDRADE\n");
        printf("[2] - ABAPORU DE TARSILA DE AMARAL\n");
        printf("[3] - OPERÁRIOS DE ANITA MALFATTI\n");
        printf("Qual seção gostaria de assistir: ");
        scanf("%d", &ticket.secao);

        system("cls");
        printf("=====SELECIONE O INGRESSO=====\n");
        printf("[1] - ENTRADA INTEIRA\n");
        printf("[2] - MEIA ENTRADA\n");
        printf("[3] - ISENTO\n");
        printf("Digite a opção: ");
        scanf("%d", &opcaoentrada);

        if(opcaoentrada == 1){
            ent_entrada = 20.00;
            system("cls");
            printf("=====SELECIONE A FORMA DE PAGAMENTO=====\n");
            printf("VALOR DA ENTRADA: R$%.2f\n", ent_entrada);
            printf("[1] - CRÉDITO\n");
            printf("[2] - DÉBITO\n");
            printf("[3] - PIX\n");
            printf("Digite a opção de pagamento: ");
            scanf("%d", &opcao_pag);
        } else if(opcaoentrada == 2){
            meia_entrada = ent_entrada/2;
            system("cls");
            printf("=====SELECIONE A FORMA DE PAGAMENTO=====\n");
            printf("VALOR DA ENTRADA: R$%.2f\n", meia_entrada);
            printf("[1] - CRÉDITO\n");
            printf("[2] - DÉBITO\n");
            printf("[3] - PIX\n");
            printf("Digite a opção de pagamento: ");
            scanf("%d", &opcao_pag);
        } else if(opcaoentrada == 3){
            system("cls");
            printf("=====SELECIONE A FORMA DE PAGAMENTO=====\n");
            printf("ENTRADA GRATUITA\n");
            printf("[1] - CRÉDITO\n");
            printf("[2] - DÉBITO\n");
            printf("[3] - PIX\n");
            printf("Digite a opção de pagamento: ");
        } else{
            printf("OPÇÃO INVÁLIDA!\nRETORNANDO AO MENU!");
            sleep(2);
            system("cls");
            menu();
        }

        FILE *p_arq;
        FILE *p_ticket;

        p_arq = fopen("cadastro.txt", "a+");
        p_ticket = fopen("tickets.txt", "a+");

        switch(opcao_pag){
            case 1:
                system("cls");
                printf("====CRÉDITO SELECIONADO=====\n");
                printf("Número do cartão: ");
                scanf("%d", &pag.card_number);
                fflush(stdin);
                printf("Nome: ");
                scanf("%s", &pag.card_nome);
                fflush(stdin);
                printf("Validade: ");
                scanf("%s", &pag.card_validade);
                fflush(stdin);
                printf("CVV: ");
                scanf("%d", &pag.card_codigo);
                fflush(stdin);
                fprintf(p_arq, "%d\n %s\n %f\n %d\n", pag.card_number, pag.card_nome, pag.card_validade, pag.card_codigo);
                printf("\n[1] - PAGAR\n[2] - RETORNAR AO MENU\n[3] - SAIR");
                printf("\nDigite a opçao: ");
                scanf("%d", &opcaoconfirm);
                fflush(stdin);

                if(opcaoconfirm == 1){
                    system("cls");
                    printf("=====GERANDO TICKET=====\n");
                    ticket.codigo[MAX_TAM_TICKET] = 1 + (rand() % 10000);
                    printf("NOME: %s\n", dadoscliente.nome_cliente);
                    printf("SEÇÃO: %d\n", ticket.secao);
                    printf("NÚMERO TICKET: %d\n" , ticket.codigo);
                    fprintf(p_ticket, "%s\n %d\n %d\n", dadoscliente.nome_cliente, ticket.secao, ticket.codigo);
                } else if(opcaoconfirm == 2){
                    printf("RETORNANDO AO MENU!");
                    sleep(2);
                    system("cls");
                    menu();
                    break;
                } else if(opcaoconfirm == 3){
                    system("taskkill /f /im sistemaMuseu33.exe");
                    break;
                } else {
                    printf("\nOPÇÃO INCORRETA!");
                    printf("\nRETORNANDO AO MENU!");
                    sleep(2);
                    system("cls");
                    menu();
                    break;
                }

                fclose(p_arq);

                printf("\n[1] - IR PARA SEÇÃO");
                printf("\n[2] - RETORNAR AO MENU");
                printf("\nDigite a opção: ");
                scanf("%d", &op_continue);
                sleep(2);

                if(op_continue == 1){
                    printf("\n====VISITANDO SEÇÃO====");
                    sleep(2);
                    system("cls");
                    secao();
                }else if(op_continue == 2){
                    printf("\n====RETORNANDO AO MENU=====");
                    sleep(2);
                    menu();
                    break;
                }else{
                    printf("\nOPÇÃO INCORRETA!\nRETORNANDO AO MENU!");
                    sleep(2);
                    menu();
                    break;
                }
                break;

            case 2:
                system("cls");
                printf("====DÉBITO SELECIONADO=====\n");
                printf("Número do cartão: ");
                scanf("%d", &pag.card_number);
                fflush(stdin);
                printf("Nome: ");
                scanf("%s", &pag.card_nome);
                fflush(stdin);
                printf("Validade: ");
                scanf("%s", &pag.card_validade);
                fflush(stdin);
                printf("CVV: ");
                scanf("%d", &pag.card_codigo);
                fflush(stdin);
                fprintf(p_arq, "%d\n %s\n %f\n %d\n", pag.card_number, pag.card_nome, pag.card_validade, pag.card_codigo);
                printf("\n[1] - PAGAR\n[2] - RETORNAR AO MENU\n[3] - SAIR");
                printf("\nDigite a opçao: ");
                scanf("%d", &opcaoconfirm);
                fflush(stdin);
                fclose(p_arq);


                if(opcaoconfirm == 1){
                    system("cls");
                    printf("=====GERANDO TICKET=====\n");
                    ticket.codigo[MAX_TAM_TICKET] = 1 + (rand() % 10000);
                    printf("NOME: %s\n", dadoscliente.nome_cliente);
                    printf("SEÇÃO: %d\n", ticket.secao);
                    printf("NÚMERO TICKET: %d\n" , ticket.codigo);
                    fprintf(p_ticket, "%s\n %d\n %d\n", dadoscliente.nome_cliente, ticket.secao, ticket.codigo);
                } else if(opcaoconfirm == 2){
                    printf("RETORNANDO AO MENU!");
                    sleep(2);
                    system("cls");
                    menu();
                    break;
                } else if(opcaoconfirm == 3){
                    system("taskkill /f /im sistemaMuseu33.exe");
                    break;
                } else {
                    printf("\nOPÇÃO INCORRETA!");
                    printf("\nRETORNANDO AO MENU!");
                    sleep(2);
                    system("cls");
                    menu();
                    break;
                }
                printf("\n[1] - IR PARA SEÇÃO");
                printf("\n[2] - RETORNAR AO MENU");
                printf("Digite a opção: ");
                scanf("%d", &op_continue);

                if(op_continue == 1){
                    printf("\n====VISITANDO SEÇÃO====");
                    sleep(2);
                    system("cls");
                    secao();
                }else if(op_continue == 2){
                    printf("\n====RETORNANDO AO MENU=====");
                    sleep(2);
                    menu();
                    break;
                }else{
                    printf("\nOPÇÃO INCORRETA!\nRETORNANDO AO MENU!");
                    sleep(2);
                    menu();
                    break;
                }
                break;

            case 3:
                system("cls");
                printf("=====PIX SELECIONADO=====\n");
                pix_number = 1 + (rand() % 10000);
                printf("CHAVE PIX: %d", pix_number);
                printf("\n[1] - JÁ PAGUEI");
                printf("\n[2] - TROCAR FORMA DE PAGAMENTO\n");
                printf("Digite a opção: ");
                scanf("%d", &pag_confirmado);

                if(pag_confirmado = 1){
                    system("cls");
                    ticket.codigo[MAX_TAM_TICKET] = 1 + (rand() % 10000);
                    printf("NOME: %s\n", dadoscliente.nome_cliente);
                    printf("SEÇÃO: %d\n", ticket.secao);
                    printf("NÚMERO TICKET: %d\n" , ticket.codigo);
                    fprintf(p_ticket, "%s\n %d\n %d\n", dadoscliente.nome_cliente, ticket.secao, ticket.codigo);
                } else if(pag_confirmado == 2){
                    printf("\n====RETORNANDO AO MENU=====");
                    sleep(2);
                    menu();
                    break;
                } else{
                    printf("OPÇÃO INCORRETA!\nRETORNANDO AO MENU!");
                    sleep(2);
                    menu();
                    break;
                }

                printf("\n[1] - IR PARA SEÇÃO");
                printf("\n[2] - RETORNAR AO MENU\n");
                printf("Digite a opção: ");
                scanf("%d", &op_continue);
                sleep(2);

                if(op_continue == 1){
                    printf("\n====VISITANDO SEÇÃO====");
                    sleep(2);
                    system("cls");
                    secao();
                } else if(op_continue == 2){
                    printf("\n====RETORNANDO AO MENU=====");
                    sleep(2);
                    menu();
                    break;
                } else{
                    printf("\nOPÇÃO INCORRETA!\nRETORNANDO AO MENU!");
                    sleep(2);
                    menu();
                    break;
                }
                break;
    }

    fclose(p_arq);
    fclose(p_ticket);
}

int pesquisarTicket(int numTicket) {
    FILE *p_ticket;
    struct ticket ticket;

    // Abre o arquivo no modo de leitura
    p_ticket = fopen("tickets.txt", "r");

    printf("Digite o número do ticket: ");
    scanf("%d", &numTicket);

    // Loop para ler cada ticket do arquivo
    while (fread(&ticket, sizeof(struct ticket), 1, p_ticket) == 1) {
        if (ticket.codigo == numTicket){
            // Ticket encontrado, imprime as informações
            printf("\n===== TICKET ENCONTRADO =====\n");
            printf("Número do Ticket: %d\n", ticket.codigo);
            printf("Nome do Cliente: %s\n", dadoscliente.nome_cliente);
            printf("Seção: %d\n", ticket.secao);
            printf("=============================\n");
            fclose(p_ticket);
            return 1;
        }
    }

    // Se o ticket não foi encontrado
    if(ticket.codigo != numTicket){
        printf("Ticket com número %d não encontrado.\n", numTicket);
        printf("Retornando ao menu!");
        sleep(2);
        system("cls");
        menu();
    }

    // Fecha o arquivo
    fclose(p_ticket);
    return 0;
}

void notas_secao(){

    char nomerelat[NOME_RELAT];
    char emailrelat[EMAIL_RELAT];

    FILE *arquivoCSV = fopen("relatorio.csv", "rb");

    fprintf(arquivoCSV, "RELATÓRIO DO MUSEU\n");

    system("cls");
    printf("=====NOTAS PARA A OBRA=====\n");
    printf("Digite o seu nome: ");
    scanf("%s", &nomerelat);
    printf("Digite o seu email: ");
    scanf("%s", &emailrelat);
    printf("\n");
    printf("DE 0 a 10\n");
    printf("Qual a nota para o Impacto Emocional: ");
    scanf("%f", &notaimpacto);
    fflush(stdin);
    printf("Qual a nota para a Expressividade Artística: ");
    scanf("%f", &notaexpre);
    fflush(stdin);
    printf("Qual a nota para a Interatividade: ");
    scanf("%f", &notaint);
    fflush(stdin);
    printf("Qual a nota para Conexão com o Museu da Semana da Arte Moderna: ");
    scanf("%f", &notaconex);
    fflush(stdin);
    printf("Qual a nota para Inovação na Experiência Imersiva: ");
    scanf("%f", &notainov);
    fflush(stdin);

    medianota = (notaimpacto + notaexpre + notaint + notaconex + notainov) / 5;

    printf("\nA média de nota é: %.2f", medianota);

    fprintf(arquivoCSV, "Nome: %s, Email: %s", nomerelat, emailrelat);
    fprintf(arquivoCSV, "Notas: %.2f %.2f %.2f %.2f %.2f\nMédia: %.2f", notaimpacto, notaexpre, notaint, notaconex, notainov, medianota);

    fclose(arquivoCSV);

    printf("\n[1] - RETORNAR AO MENU\n[2] - SAIR\n");
    printf("Digite a opção: ");
    scanf("%d", &sairfinal);
    fflush(stdin);

    switch(sairfinal){
    case 1:
        printf("RETORNANDO AO MENU!");
        sleep(2);
        system("cls");
        menu();
        break;
    case 2:
        system("taskkill /f /im sistemaMuseu33.exe");
        break;
    default:
        printf("OPÇÃO INCORRETA!\n");
        printf("RETORNANDO AO MENU!");
        sleep(2);
        system("cls");
        menu();
    }
}

void secao(){
    int continueobra;

    struct ticket ticket;

    switch(ticket.secao[0]){
        case 1:
            printf("====SEMANA DA ARTE MODERNA====\n\n");
            printf("Manifesto Antropófago de Oswald de Andrade: Embora não seja uma obra visual,\no Manifesto Antropófago de Oswald de Andrade é uma peça literária\nque desafiou as normas culturais e propôs a ideia de devorar elementos estrangeiros\n para criar uma arte verdadeiramente brasileira.\nA imersividade aqui está na provocação intelectual e na proposta\nde uma abordagem cultural única.");
            printf("Digite [1] - Continuar: ");
            scanf("%d", &continueobra);
            system("pause");
            notas_secao();
            break;
        case 2:
            printf("====SEMANA DA ARTE MODERNA====\n\n");
            printf("Abaporu de Tarsila do Amaral:\nCriada em 1928, essa obra icônica de Tarsila do Amaral representa\num homem com uma cabeça gigante e um corpo alongado, deitado em um cenário surreal.\n A imersividade reside na estilização da figura, criando um ambiente onírico que desafia\n as convenções artísticas da época.");
            printf("Digite [1] - Continuar: ");
            scanf("%d", &continueobra);
            system("pause");
            notas_secao();
            break;
        case 3:
            printf("====SEMANA DA ARTE MODERNA====\n\n");
            printf("Operários de Anita Malfatti:\nAnita Malfatti, uma das artistas mais influentes da Semana de Arte Moderna,\napresentou Operários, uma pintura que retrata a força e a dignidade dos trabalhadores industriais.\nA obra é imersiva na medida em que destaca a importância da classe trabalhadora na construção da identidade nacional brasileira.");
            printf("Digite [1] - Continuar: ");
            scanf("%d", &continueobra);
            system("pause");
            notas_secao();
    }
}

#endif // PAGAMENTO_H
