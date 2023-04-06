#ifndef JOGO_H
#define JOGO_H

#define ERRO (-32000)
#define TRUE 1
#define FALSE 0
typedef int boolean;

typedef struct jogo_ JOGO;

JOGO* jogo_criar(const char *nome, const char *empresa, int ano);
boolean jogo_apagar(JOGO* jogo);
void jogo_print(JOGO* jogo);
int jogo_ano(JOGO* jogo);
char* jogo_empresa(JOGO* jogo);

#endif 