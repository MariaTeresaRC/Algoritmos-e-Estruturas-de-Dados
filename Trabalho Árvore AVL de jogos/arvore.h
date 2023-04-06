#ifndef ARVORE_H
#define ARVORE_H

#include "util.h"
#include "jogo.h"

typedef struct node_ NODE;
typedef struct arvore_ ARVORE;

ARVORE* arvore_criar();
int arvore_altura_node(NODE* node);
boolean arvore_inserir(ARVORE* arvore, JOGO* jogo);
ARVORE* ler_CSV();
boolean arvore_remocao(ARVORE* arvore, int ano);
void arvore_em_ordem(ARVORE* arvore);
void arvore_pre_ordem(ARVORE* arvore);
void arvore_pos_ordem(ARVORE* arvore);
void arvore_apagar(ARVORE** arvore);

#endif