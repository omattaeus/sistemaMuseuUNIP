#ifndef PESQUISAR_H_INCLUDED
#define PESQUISAR_H_INCLUDED

#include "dados.h"
#include "menu.h"

void pesquisar() {

    int encontrado = 0;
    int codigo;

    FILE *arquivo;
    arquivo = fopen("cadastro.txt", "rb");

    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return;
    }

    printf("=====PESQUISAR VISITANTE=====\n");
    printf("Digite o código do cliente: ");
    scanf("%d", &codigo);

    while (fread(&dadoscliente, sizeof(struct dados_cliente), 1, arquivo) == 1) {
        if (dadoscliente.codigo_cliente == codigo) {
            printf("Código: %d\nNome: %s\nEndereço: %s\nTelefone: %s\n\n",
                   dadoscliente.codigo_cliente, dadoscliente.nome_cliente, dadoscliente.endereco_cliente, dadoscliente.telefone_cliente);
            encontrado = 1;
            break;  // Parar a pesquisa após encontrar o cliente
        }
    }

    if (!encontrado) {
        printf("Nenhum cliente encontrado com o código: %d\n", codigo);
        printf("Retornando ao menu!\n");
        sleep(2);
        system("cls");
        menu();
        return;
    }

    fclose(arquivo);
}

#endif // PESQUISAR_H_INCLUDED
