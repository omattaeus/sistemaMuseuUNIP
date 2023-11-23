#ifndef ALTERANDO_H_INCLUDED
#define ALTERANDO_H_INCLUDED

#include "menu.h"
#include "dados.h"
#include "caso.h"

#define TAM 50
#define TELE 10
#define SIZE 200

int atualizarDados(){
    FILE *arquivo, *temp;

    int atualizado = 1;
    int opcaoalt;

    const char *nomeArquivo = "cadastro.txt";
    const char *codigo;
    const char *novoNome[TAM];
    const char *novoEndereco[SIZE];
    const char *novoTelefone[TELE];

    arquivo = fopen(nomeArquivo, "r");
    temp = fopen("cadastro.txt", "w");

    while (fscanf(arquivo, "%49[^,], %199[^,], %9[^\n]\n", dadoscliente.nome_cliente, dadoscliente.endereco_cliente, dadoscliente.telefone_cliente) == 3) {
        if (strstr(dadoscliente.nome_cliente, codigo) || strstr(dadoscliente.endereco_cliente, codigo) || strstr(dadoscliente.telefone_cliente, codigo)) {
            // Se encontrarmos o registro que corresponde ao termo de pesquisa, atualize os dados
            strcpy(dadoscliente.nome_cliente, novoNome);
            strcpy(dadoscliente.endereco_cliente, novoEndereco);
            strcpy(dadoscliente.telefone_cliente, novoTelefone);
            atualizado = 1;
        }
        fprintf(temp, "%s\n,%s\n, %s\n", dadoscliente.nome_cliente, dadoscliente.endereco_cliente, dadoscliente.telefone_cliente);
    }

    if (atualizado == 1) {
        remove("cadastro.txt");
        rename("cadastroatt.txt", nomeArquivo);
    } else {
        remove("cadastroatt.txt");
    }

    printf("Digite o código de pesquisa: ");
    scanf("%s", &codigo);
    fflush(stdin);
    printf("Digite o novo nome: ");
    scanf("%s", &novoNome);
    fflush(stdin);
    printf("Digite o novo endereço: ");
    scanf("%s", &novoEndereco);
    fflush(stdin);
    printf("Digite o novo telefone: ");
    scanf("%s", &novoEndereco);
    fflush(stdin);
    atualizado = 1;

    atualizado = atualizarDados(nomeArquivo, codigo, novoNome, novoEndereco, novoTelefone);

    if (atualizado == 1) {
        printf("Dados atualizados com sucesso!\n\n");
        printf("Deseja retornar ao menu? \n[1] - RETORNAR\n[2] - SAIR DO SISTEMA\n");
        scanf("%d", &opcaoalt);

        switch(opcaoalt){
        case 1:
            printf("=====RETORNANDO AO MENU=====");
            sleep(2);
            system("cls");
            menu();
            break;
        case 2:
            printf("=====FECHANDO O SISTEMA=====");
            sleep(2);
            system("cls");
            system("taskkill /f /im sistemaMuseu33.exe");
            break;
        default:
            printf("=====OPÇÃO INCORRETA=====");
            printf("RETORNANDO AO MENU");
            sleep(2);
            system("cls");
            menu();
            break;
        }
    }else {
        printf("Nenhum registro encontrado para o código de pesquisa.\n");
    }

    return 0;

    fclose(arquivo);
    fclose(temp);
}


#endif // ALTERANDO_H_INCLUDED
