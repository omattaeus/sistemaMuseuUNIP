#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

#include "dados.h"
#include "caso.h"
#include "menu.h"
#include "telalogin.h"
#include "pagamento.h"
#include "secoes.h"

void telalogin();
void menu();
void cadastro();
void pagamentos();
void secao();
void notas_secao();
void alterando();
int atualizarDados();
void pesquisar();


int main(){
    setlocale(LC_ALL, "Portuguese");

    telalogin();
    menu();
	cadastro();
    pagamentos();
    secao();
    notas_secao();
    atualizarDados();
    pesquisar();

    return 0;
}
