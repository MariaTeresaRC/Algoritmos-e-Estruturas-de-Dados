#ifndef CAMINHO_H
#define CAMINHO_H

#include "ponto.h"

typedef struct caminho_ CAMINHO;

CAMINHO* caminho_criar(int N);
int caminho_cheio(CAMINHO* caminho);
int caminho_adicionar_ponto (CAMINHO* caminho, PONTO* ponto);
void caminho_apagar(CAMINHO* caminho);
float caminho_distancia(CAMINHO* caminho);

#endif