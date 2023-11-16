#ifndef DADOS_H_INCLUDED
#define DADOS_H_INCLUDED

#define TAM 50
#define TEL 10
#define SIZE 200
#define CPF 11
#define COD 20

typedef struct dados_cliente // ESTRUTURA PARA SALVAR OS DADOS DO CLIENTE
{
    char nome_cliente[TAM][SIZE];
    char endereco_cliente[SIZE][SIZE];
    int cpf_cliente[CPF][SIZE];
    char telefone_cliente[TEL][SIZE];
    char codigo_cliente[COD][SIZE];
    int ticket_cliente;
    int vazio_cliente;
}dados_cliente;

dados_cliente dadoscliente;

#endif //DADOS_H
