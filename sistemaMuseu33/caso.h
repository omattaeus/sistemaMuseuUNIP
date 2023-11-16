#ifndef CASO_H_INCLUDED
#define CASO_H_INCLUDED

#include "dados.h"
#include "menu.h"
#include "pagamento.h"
#include "alterando.h"
#include "pesquisar.h"

#define TAM 50
#define TEL 10
#define SIZE 200
#define CPF 11
#define COD 20

void pesquisar();
void alterando();
int pesquisarTicket(int numTicket);

int op;
char codFuncPesq[20];
int numvisitantes, ticketnum;

void cadastro(){

        FILE *p_arq;
        p_arq = fopen("cadastro.txt", "a+");

        do{
			switch(opcao){
            	case 1:
	            	printf("=======CADASTRAR VISITANTES=======\n");
	            	printf("Quantos visitantes deseja cadastrar? ");
	            	scanf("%d", &numvisitantes);
	            	for(i = 0; i < numvisitantes; i++){
                        printf("\n");
                        printf("Digite o nome do visitante: ");
                        scanf("%s", &dadoscliente.nome_cliente[i]);
                        fflush(stdin);
                        printf("Digite o endereço do visitante: ");
                        scanf("%s", &dadoscliente.endereco_cliente[i]);
                        fflush(stdin);
                        printf("Digite o CPF do visitante: ");
                        scanf("%d", &dadoscliente.cpf_cliente[i]);
                        fflush(stdin);
                        printf("Digite o Telefone do cliente: ");
                        scanf("%s", &dadoscliente.telefone_cliente[i]);
                        fflush(stdin);
                        printf("Digite o código do visitante: ");
                        scanf("%s", &dadoscliente.codigo_cliente[i]);
                        fflush(stdin);
                        fprintf(p_arq, "%s\n %s\n %d\n %s\n %s\n", dadoscliente.nome_cliente[i], dadoscliente.endereco_cliente[i], dadoscliente.cpf_cliente[i], dadoscliente.telefone_cliente[i], dadoscliente.codigo_cliente[i]);
                    }
	            	printf("\nCadastro Realizado com Sucesso!\n");
                    printf("Digite 8 para retornar ao menu: ");
                    scanf("%d", &op);
                    fflush(stdin);
                    system("cls");
                    if(op == 8){
                        menu();
                    }
                    getchar();
					break;
	            case 2:
	                atualizarDados();
	                break;
                case 3:
                    pagamentos();
                    break;
                case 4:
                    printf("Digite o número do ticket: ");
                    scanf("%d", &ticketnum);
                    pesquisarTicket(ticketnum);
                    break;
	            case 5:
	                pesquisar();
	                break;
	            case '9':
	        		system("taskkill /f /im sistemaMuseu33.exe");
	        		break;
	            default:
					printf("OPÇÃO INVÁLIDA!\nRETORNANDO AO MENU!");
	            	sleep(2);
	            	system("cls");
	            	menu();
	            	break;
        }
        getchar();
        fclose(p_arq);
    }while(op==0);
}

#endif //CASO_H
