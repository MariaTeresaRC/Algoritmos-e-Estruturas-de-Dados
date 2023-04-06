#include "ponto.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ponto_{
    float coord_x;
    float coord_y;
};

PONTO* ponto_criar(float x, float y){
    PONTO *ponto = (PONTO*)malloc(sizeof(PONTO));
    if(ponto == NULL){
        return NULL;
    }
    ponto->coord_x = x;
    ponto->coord_y = y;
    return ponto;
}

void ponto_apagar(PONTO *ponto){
    if(ponto != NULL){
        free(ponto);
    }
}

float ponto_distancia(PONTO* ponto1, PONTO* ponto2){
    float distancia = sqrt(pow((ponto1->coord_x - ponto2->coord_x),2) + pow((ponto1->coord_y - ponto2->coord_y),2));
    return distancia;
}