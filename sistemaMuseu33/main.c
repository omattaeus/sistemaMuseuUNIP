#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#include "dados.h"
#include "caso.h"
#include "menu.h"
#include "telalogin.h"
#include "pagamento.h"
#include "secoes.h"

void telalogin();
void menu();
void cadastro();
void secao();
void ticket();
void pagamentos();
void alterando();

int main(){
    setlocale(LC_ALL, "Portuguese");

    telalogin();
    menu();
	cadastro();
	ticket();
    pagamentos();
	secao();

    return 0;
}
