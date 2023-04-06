#ifndef PILHA_H
#define PILHA_H

#include "carta.h"

typedef struct pilha_ PILHA;

PILHA *pilha_criar();
boolean pilha_vazia(PILHA* pilha);
boolean pilha_empilhar(PILHA* pilha, CARTA* carta);
CARTA* pilha_desempilhar(PILHA* pilha);
boolean pilha_apagar(PILHA* pilha);

#endif