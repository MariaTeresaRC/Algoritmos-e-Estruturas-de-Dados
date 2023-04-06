#include "caminho.h"

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define ERRO (-32000)

struct caminho_{
    int tamanho;
    int indice;
    PONTO** pontos;
};

CAMINHO* caminho_criar(int N){
    CAMINHO *caminho = (CAMINHO*)malloc(sizeof(CAMINHO));
    if(caminho == NULL){
        return NULL;
    }
    caminho->tamanho = N;
    caminho->indice = 0;
    caminho->pontos = (PONTO**)malloc(N*sizeof(PONTO*));
    if (caminho->pontos == NULL){
        return NULL;
    }
    return caminho;
}

int caminho_cheio(CAMINHO* caminho){
    if(caminho->indice == caminho->tamanho){
        return TRUE;
    }
    return FALSE;
}

int caminho_adicionar_ponto (CAMINHO* caminho, PONTO* ponto){
    if(caminho_cheio(caminho) || caminho == NULL){
        return ERRO;
    }
    caminho->pontos[caminho->indice] = ponto;
    caminho->indice++;
    return TRUE;
}

void caminho_apagar(CAMINHO* caminho){
    if(caminho != NULL){
        for(int i=0; i<caminho->indice; i++){
            ponto_apagar(caminho->pontos[i]);
        }
        free(caminho);
    }
    
}

float caminho_distancia(CAMINHO* caminho){
    float distancia = 0;
    for(int i=1; i<caminho->indice; i++){
        distancia += ponto_distancia(caminho->pontos[i], caminho->pontos[i-1]);
    }
    return distancia;
}