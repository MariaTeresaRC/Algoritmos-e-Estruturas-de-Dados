#ifndef JOGO_H
#define JOGO_H

#include "util.h"

typedef struct jogo_ JOGO;

JOGO* jogo_criar(const char *nome, const char *empresa, int ano);
boolean jogo_apagar(JOGO** jogo);
void jogo_print(JOGO* jogo);
char* jogo_nome(JOGO* jogo);
int jogo_ano(JOGO* jogo);
char* jogo_empresa(JOGO* jogo);
int jogo_compare(JOGO* j1, JOGO* j2);

#endif 