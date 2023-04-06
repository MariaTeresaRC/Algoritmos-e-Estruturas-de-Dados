#ifndef ARVORE_H
#define ARVORE_H

#include "cliente.h"

typedef struct node_ NODE;
typedef struct arvore_ ARVORE;

ARVORE* arvore_criar();
boolean arvore_insercao(ARVORE* arvore, CLIENTE* cliente);
void arvore_apagar(ARVORE** arvore);
void arvore_em_ordem(ARVORE* arvore);
void arvore_pre_ordem(ARVORE* arvore);
void arvore_pos_ordem(ARVORE* arvore);
CLIENTE* arvore_busca(ARVORE* arvore, char* cpf);
boolean arvore_remocao(ARVORE* arvore, char* cpf);

#endif