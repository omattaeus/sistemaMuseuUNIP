#ifndef PESQUISAR_H_INCLUDED
#define PESQUISAR_H_INCLUDED

#include "dados.h"
#include "menu.h"

void pesquisar(){
    struct dados_cliente cliente;
    int encontrado = 0;
    int codigo;

    FILE *arquivo;
    arquivo = fopen("cadastro.txt", "rb");

    while(fread(&cliente, sizeof(struct dados_cliente), 1, arquivo) == 1){
        if(cliente.codigo_cliente == cliente.codigo_cliente){
            printf("Código: %d\nNome: %s\nEndereço: %s\nTelefone: %s\n\n", cliente.nome_cliente, cliente.endereco_cliente, cliente.telefone_cliente);
            encontrado = 1;
            break;  // Parar a pesquisa após encontrar o cliente
        }
    }

    if (!encontrado) {
        printf("Nenhum cliente encontrado com o código: %d", codigo);
        printf("\nRetornando ao menu!");
        sleep(2);
        system("cls");
        menu();
    }
    fclose(arquivo);
}

    /*
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
    */

#endif // PESQUISAR_H_INCLUDED
