#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "caso.h"

int opcao;

void menu(){ // OPCOES p/ USAR NO SISTEMA
		printf("==GERENCIAR MUSEU DREAM WITH==\n");
	    printf("[1] - CADASTRAR VISITANTES\n");
	    printf("[2] - ATUALIZAR DADOS DE VISITANTES\n");
	    printf("[3] - GERAR TICKET PARA VISITANTES\n");
	    printf("[4] - CONSULTAR POR TICKET");
	    printf("[5] - PESQUISAR POR VISITANTES CADASTRADO\n");
	    printf("[9] - SAIR DO SISTEMA!\n");
	    printf("Digite uma opção: ");
	    scanf("%d", &opcao);
	    system("cls");
}

#endif // MENU_H
