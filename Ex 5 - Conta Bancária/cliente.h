#ifndef CLIENTE_H
#define CLIENTE_H


#define ERRO (-32000)
#define TRUE 1
#define FALSE 0
typedef int boolean;

typedef struct cliente_ CLIENTE;

CLIENTE* cliente_ler();
boolean cliente_apagar(CLIENTE** cliente);
void cliente_printa_cpf(CLIENTE* cliente);
void cliente_printa_nome(CLIENTE* cliente);
void cliente_mostra_saldo(CLIENTE* cliente);
int cliente_compara_cpf(CLIENTE* c1, CLIENTE* c2);

#endif