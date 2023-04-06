#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>

typedef struct node_ NODE;

struct node_{
    CARTA* carta;
    NODE* anterior;
};

struct pilha_{
    NODE* topo;
    int tamanho;
};

PILHA *pilha_criar(){
    PILHA *pilha = (PILHA*) malloc(sizeof(PILHA));
    if(pilha != NULL){
        pilha->topo = NULL;
        pilha->tamanho = 0;
    }
    return pilha;
}

boolean pilha_vazia(PILHA* pilha){
    if(pilha != NULL){
        return pilha->tamanho == 0;
    }
    return ERRO;
}

boolean pilha_empilhar(PILHA* pilha, CARTA* carta){
    if(pilha != NULL){
        NODE* novo_node = (NODE*)malloc(sizeof(NODE));
        if(novo_node != NULL){
            novo_node->carta = carta;
            novo_node->anterior = pilha->topo;
            pilha->topo = novo_node;
            pilha->tamanho++;
            return TRUE;
        }
        return FALSE;
    }
    return ERRO;
}

CARTA* pilha_desempilhar(PILHA* pilha){
    if(pilha != NULL && !(pilha_vazia(pilha))){
        NODE* desempilhado = pilha->topo;
        CARTA* carta = desempilhado->carta;
        pilha->topo = desempilhado->anterior;
        free(desempilhado);
        pilha->tamanho--;
        return carta;
    }
    return NULL;
}

void pilha_remove_topo(PILHA* pilha){
    NODE* node_temporario;
    node_temporario = pilha->topo;
    pilha->topo = node_temporario->anterior;
    carta_apagar(node_temporario->carta);
    node_temporario->anterior = NULL;
    free(node_temporario);
}

void pilha_remove(PILHA* pilha){
    while (pilha->topo != NULL){
        pilha_remove_topo(pilha);
    }
    
}

boolean pilha_apagar(PILHA* pilha){
    if(pilha != NULL && !(pilha_vazia(pilha))){
        pilha_remove(pilha);
        free(pilha);
        return TRUE;
    }
    return FALSE;
}