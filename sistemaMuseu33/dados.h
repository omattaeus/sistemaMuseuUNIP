#ifndef DADOS_H_INCLUDED
#define DADOS_H_INCLUDED

#define TAM 50
#define TEL 10
#define SIZE 200
#define CPF 11
#define COD 20
#define TAM 50
#define SIZE_TAM 100
#define CARDN 16
#define CARDC 3
#define CARDV 5
#define MAX_TAM_TICKET 50


typedef struct dados_cliente // ESTRUTURA PARA SALVAR OS DADOS DO CLIENTE
{
    char nome_cliente[TAM];
    char endereco_cliente[SIZE];
    int cpf_cliente[CPF];
    char telefone_cliente[TEL];
    char codigo_cliente[COD];
    int ticket_cliente;
    int vazio_cliente;
}dados_cliente;

typedef struct ticket{
    char codigo[MAX_TAM_TICKET];
    int secao[MAX_TAM_TICKET];
    float preco;
};

typedef struct pag_dados
{
    char card_nome[TAM];
    int card_number[CARDN];
    int card_codigo[CARDC];
    char card_validade[CARDV];
}pag_dados;

struct ticket ticket;
struct pag_dados pag;

struct dados_cliente dadoscliente;

#endif //DADOS_H
