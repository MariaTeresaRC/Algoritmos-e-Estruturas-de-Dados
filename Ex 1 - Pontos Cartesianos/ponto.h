#ifndef PONTO_H
#define PONTO_H

typedef struct ponto_ PONTO;

PONTO* ponto_criar(float x, float y);
void ponto_apagar(PONTO *ponto);
float ponto_distancia(PONTO* ponto1, PONTO* ponto2);

#endif