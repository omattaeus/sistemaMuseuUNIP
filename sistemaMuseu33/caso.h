#ifndef CASO_H_INCLUDED
#define CASO_H_INCLUDED

#include "dados.h"
#include "menu.h"
#include "pagamento.h"
#include "secoes.h"
#include "alterando.h"
#include "pesquisar.h"

void pesquisar();
void alterando();

int op;
char codFuncPesq[20];

void cadastro(){

        FILE *p_arq;
        p_arq = fopen("cadastro.txt", "a");

        do{
			switch(opcao){
            	case 1:
	            	printf("=======CADASTRAR VISITANTES=======\n");
	            	printf("Digite o nome do visitante: ");
	            	gets(dadoscliente.nome_cliente);
	            	fprintf(p_arq, "%s \n", dadoscliente.nome_cliente);
	            	fflush(stdin);
	            	printf("Digite o endereço do visitante: ");
	            	gets(dadoscliente.endereco_cliente);
	            	fprintf(p_arq, "%s \n", dadoscliente.endereco_cliente);
	            	fflush(stdin);
	            	printf("Digite o CPF do visitante: ");
	            	scanf("%d", &dadoscliente.cpf_cliente);
	            	fprintf(p_arq, "%d \n", dadoscliente.cpf_cliente);
	            	fflush(stdin);
	            	printf("Digite o Telefone do cliente: ");
	            	scanf("%d", &dadoscliente.telefone_cliente);
	            	fprintf(p_arq, "%d \n", dadoscliente.telefone_cliente);
	            	fflush(stdin);
	            	printf("Digite o código do visitante: ");
	            	gets(dadoscliente.codigo_cliente);
	            	fprintf(p_arq, "%s \n", dadoscliente.codigo_cliente);
					fflush(stdin);
          			printf("\nCadastro Realizado com Sucesso!\n");
          			fclose(p_arq);
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
                /*
	            	printf("====ATUALIZAR DADOS DO VISITANTE====\n");
	            	printf("Digite o código do cliente: ");
	            	gets(codClientePesq);
	            	if(dadoscliente.codigo_cliente==codClientePesq){
       						if (dados_cliente.vazio_cliente ==1){
       							printf("Digite o novo código do visitante: ");
       							gets(dadoscliente.codigo_cliente);
       							fprintf(p_arq, "%s \n", dadoscliente.codigo_cliente);
       							fflush(stdin);
       							printf("Digite o endereço atualizado do visitante: ");
       							gets(dadoscliente.endereco_cliente);
       							fprintf(p_arq, "%s \n", dadoscliente.endereco_cliente);
	            				fflush(stdin);
	            				printf("Digite o Telefone atualizado do visitante: ");
	            				scanf("%d", &dadoscliente.telefone_cliente);
	            				fprintf(p_arq, "%d \n", dadoscliente.telefone_cliente);
	            				fflush(stdin);
	            				printf("Digite 8 para retornar ao menu: ");
	            				scanf("%d", &op);
	            				fclose(p_arq);
       						}else if (dadoscliente.codigo_cliente!=codClientePesq){
       							printf("\nVISITANTE NÃO CADASTRADO!\n");
       							sleep(2);
       							system("cls");
       							menu();
       						}
       						if(op == 8){
       							system("cls");
	            				menu();
      						}
      						getchar();
       				}
	            	break;
                */
                case 3:
					printf("====GERAR TICKET PARA VISITANTES====");
					ticket();
					pagamentos();
					secao();
					break;

                /*
                case '4';

                    printf("=====PESQUISAR POR TICKET=====");
                    printf("DIGITE SEU CPF: ");
                    scanf("%d", &cpfticket);
                    if(cpfticket == )
                */

	            case 5:
	                pesquisar();
	                break;
                /*
	            	printf("====PESQUISAR VISITANTES CADASTRADOS====\n");
					printf("Digite o Código do Visitante: ");
					gets(codClientePesq);
                    int cont = 0;
					while(cont<100){
    					if(dadoscliente.codigo_cliente == codClientePesq){
       						if (dados_cliente.vazio_cliente == 1){
                                printf("======VISITANTE CADASTRADO======");
          						printf("\nNome: %s", dadoscliente.nome_cliente);
          						printf("\nEndereco: %s", dadoscliente.endereco_cliente);
          						printf("\nTelefone: %d", dadoscliente.telefone_cliente);
          						printf("\n\nDigite 8 para retornar ao menu: ");
	            				scanf("%d", &op);
	            				fflush(stdin);
	            				system("cls");
	            				if(op == 8){
	            					menu();
      						 	}
    						}
       					}else if(cont>100){
       						printf("\nVISITANTE NÃO CADASTRADO!\n");
       						sleep(2);
       						menu();
						}
						cont++;
					}
					break;
                */

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
    }while(op==0);
}

#endif //CASO_H
