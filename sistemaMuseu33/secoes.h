/*
#ifndef SECOES_H_INCLUDED
#define SECOES_H_INCLUDED

#include "pagamento.h"
#include "dados.h"

void notas_secao();
void pagamentos();

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

#include "pagamento.h"
#endif // SECOES_H

*/
