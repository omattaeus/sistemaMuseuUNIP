#ifndef DADOS_H_INCLUDED
#define DADOS_H_INCLUDED

#define TAM 50
#define TEL 10
#define SIZE 200
#define CPF 11
#define COD 20
#define CARDN 16
#define CARDC 3
#define CARDV 5

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

/*
typedef struct dados_funcionarios // ESTRUTURA PARA SALVAR OS DADOS DO FUNCIONÁRIO
{
    char nome_func[TAM];
    char endereco_func[SIZE];
    int cpf_func;
    int telefone_func;
    char codigo_func[20];
    float salario_func;
    int vazio_func;
}dados_funcionarios;
*/

typedef struct pag_dados
{
    char card_nome[TAM][SIZE];
    int card_number[CARDN][SIZE];
    int card_codigo[CARDC][SIZE];
    float card_validade[CARDV][SIZE];
}pag_dados;

typedef struct senha_usuario {
    char login[50];
    char senha[50];
}senha_usuario;

/*
typedef struct dados_cliente dados_cliente;
typedef struct dados_funcionarios dados_funcionarios;
typedef struct pag_dados pag_dados;
*/

dados_cliente dadoscliente;
pag_dados pagdados;
senha_usuario senhausuario;

#endif //DADOS_H
