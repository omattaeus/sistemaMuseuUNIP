#ifndef TELALOGIN_H_INCLUDED
#define TELALOGIN_H_INCLUDED

#include "dados.h"

void telalogin(){
    /*
    char login_cadastro[15];
    char login_teste[15];
    char senha_cadastro[15];
    char senha_teste[15];
    int cadastro_sucesso;
    */

    char login[50], senha[50];
    int verificar_cadastro;

    FILE *p_login;
    p_login = fopen("login.txt", "a");

    printf("----------------------------\n");
    printf("   DreamWith - SISTEMA\n"      );
    printf("----------------------------\n");
    printf("1 - JÁ SOU CADASTRADO\n");
    printf("2 - CADASTRAR\n");
    printf("Digite a opção: ");
    scanf("%d", &verificar_cadastro);

    if (verificar_cadastro == 1){
        system("cls");
        printf("----------------------------\n");
        printf("   DreamWith - SISTEMA\n"      );
        printf("----------------------------\n");
        printf("Digite o Login: ");
        scanf("%s", &login);
        fflush(stdin);

        printf("Digite a Senha: ");
        scanf("%s", &senha);
        fflush(stdin);

        while(fscanf(p_login, "%s\n %s\n", senha_usuario.login, senha_usuario.senha) == 2) {
            if (strcmp(senha_usuario.login, login) == 0 && strcmp(senha_usuario.senha, senha) == 0) {
                printf("\nBem-vindo(a) ao Dream With!!\n");
                sleep(2);
                system("cls");
                menu();
            }
        }
        return 0; // Credenciais inválidas

        if(verificar_cadastro == 2){
            printf("Digite o nome de usuário: ");
            scanf("%s", &senha_usuario.login);
            printf("Digite a senha: ");
            scanf("%s", &senha_usuario.senha);
            fprintf(p_login, "%s\n %s\n", senha_usuario.login, senha_usuario.senha);
            printf("Usuário registrado com sucesso!\n\n");
            printf("Retornando ao menu de login!");
            sleep(2);
            system("cls");
            telalogin();
        }

        /*
            if (strcmp(login_cadastro, login_teste) == 0 && strcmp(senha_cadastro, senha_teste) == 0){
                printf("\nBem-vindo(a) ao Dream With!!\n");
                sleep(2);
                system("cls");
                menu();
            }else{
                printf("\nDADOS INVALIDOS!\n");
                printf("DIGITE O LOGIN E A SENHA NOVAMENTE!");
                sleep(2);
                system("cls");
                telalogin();
            }

    }else{
    */
}
#endif // TELALOGIN_H
