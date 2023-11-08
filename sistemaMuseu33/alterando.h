#ifndef ALTERANDO_H_INCLUDED
#define ALTERANDO_H_INCLUDED

#include "menu.h"
#include "dados.h"

int atualizarDados(){
    FILE *arquivo, *temp;
    struct dados_cliente cliente;
    int atualizado = 0;
    int opcaoalt;
    const char *nomeArquivo = "cadastro.txt";
    const char *codigo;
    const char *novoNome;
    const char *novoEndereco;
    const char *novoTelefone;

    arquivo = fopen(nomeArquivo, "r");
    temp = fopen("cadastro.txt", "w");

    if (arquivo == NULL || temp == NULL) {
        perror("Erro ao abrir arquivos");
        return 0;
    }

    while (fscanf(arquivo, "%49[^,], %199[^,], %9[^\n]\n", cliente.nome_cliente, cliente.endereco_cliente, cliente.telefone_cliente) == 3) {
        if (strstr(cliente.nome_cliente, codigo) || strstr(cliente.endereco_cliente, codigo) || strstr(cliente.telefone_cliente, codigo)) {
            // Se encontrarmos o registro que corresponde ao termo de pesquisa, atualize os dados
            strcpy(cliente.nome_cliente, novoNome);
            strcpy(cliente.endereco_cliente, novoEndereco);
            strcpy(cliente.telefone_cliente, novoTelefone);
            atualizado = 1;
        }
        fprintf(temp, "%s\n,%s\n, %s\n", cliente.nome_cliente, cliente.endereco_cliente, cliente.telefone_cliente);
    }

    if (atualizado) {
        remove("cadastro.txt");
        rename("cadastroatt.txt", nomeArquivo);
    } else {
        remove("cadastroatt.txt");
    }

    return atualizado;

    printf("Digite o código de pesquisa: ");
    scanf("%s", &codigo);

    printf("Digite o novo nome: ");
    scanf("%s", &novoNome);

    printf("Digite o novo endereço: ");
    scanf("%s", &novoEndereco);

    printf("Digite o novo telefone: ");
    scanf("%s", &novoTelefone);

    atualizado = atualizarDados(nomeArquivo, codigo, novoNome, novoEndereco, novoTelefone);

    if (atualizado) {
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
