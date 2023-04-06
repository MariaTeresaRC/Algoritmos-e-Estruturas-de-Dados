#ifndef CATALOGO_H
#define CATALOGO_H

#include "jogo.h"

typedef struct catalogo_ CATALOGO;

CATALOGO* catalogo_criar();
boolean catalogo_apagar(CATALOGO* catalogo);
boolean catalogo_adicionarjogo(CATALOGO* catalogo, JOGO* jogo);
boolean catalogo_busca_ano(CATALOGO* catalogo, int ano);
boolean catalogo_busca_empresa(CATALOGO* catalogo, const char* empresa);
int catalogo_indice(CATALOGO* catalogo);
JOGO** catalogo_jogos(CATALOGO* catalogo);

#endif