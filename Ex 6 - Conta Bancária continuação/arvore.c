#include "arvore.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node_{
    CLIENTE* cliente;
    NODE* direita;
    NODE* esquerda;
};

struct arvore_{
    NODE* raiz;
    int profundidade;
};

ARVORE* arvore_criar(){
    ARVORE* arvore = (ARVORE*)malloc(sizeof(ARVORE));
    if(arvore != NULL){
        arvore->raiz = NULL;
        arvore->profundidade = -1;
    }
    return arvore;
}

NODE* cria_no(CLIENTE* cliente){
    NODE* newNode = (NODE*)malloc(sizeof(NODE));
    if(newNode != NULL){
        newNode->cliente = cliente;
        newNode->direita = NULL;
        newNode->esquerda = NULL;
    }
    return newNode;
}

NODE* arvore_inserir_no(NODE* raiz, CLIENTE* cliente){
    if(raiz == NULL) raiz = cria_no(cliente);
    else if(cliente_compara_cpf(cliente, raiz->cliente)>0) raiz->direita = arvore_inserir_no(raiz->direita, cliente);
    else if(cliente_compara_cpf(raiz->cliente, cliente)>0) raiz->esquerda = arvore_inserir_no(raiz->esquerda, cliente);
    return raiz;
}

boolean arvore_insercao(ARVORE* arvore, CLIENTE* cliente){
    return ((arvore->raiz = arvore_inserir_no(arvore->raiz, cliente)) != NULL);
}

void arvore_apagar_aux(NODE** raiz){
    if(*raiz != NULL){
        arvore_apagar_aux(&(*raiz)->esquerda);
        arvore_apagar_aux(&(*raiz)->direita);
        cliente_apagar(&(*raiz)->cliente);
        free(*raiz);
        *raiz = NULL;
    }
}

void arvore_apagar(ARVORE** arvore){
    arvore_apagar_aux(&(*arvore)->raiz);
    free(*arvore);
    *arvore = NULL;
}

void em_ordem_aux(NODE* raiz){
    if(raiz != NULL){
        em_ordem_aux(raiz->esquerda);
        cliente_printa_cpf(raiz->cliente);
        em_ordem_aux(raiz->direita);
    }
}

void arvore_em_ordem(ARVORE* arvore){
    printf("Inorder\n");
    if(arvore != NULL) em_ordem_aux(arvore->raiz);
    printf("\n");
}

void pre_ordem_aux(NODE* raiz){
    if(raiz != NULL){
        cliente_printa_cpf(raiz->cliente);
        pre_ordem_aux(raiz->esquerda);
        pre_ordem_aux(raiz->direita);
    }
}

void arvore_pre_ordem(ARVORE* arvore){
    printf("Preorder\n");
    if(arvore != NULL) pre_ordem_aux(arvore->raiz);
    printf("\n");
}

void pos_ordem_aux(NODE* raiz){
    if(raiz != NULL){
        pos_ordem_aux(raiz->esquerda);
        pos_ordem_aux(raiz->direita);
        cliente_printa_cpf(raiz->cliente);
    }
}

void arvore_pos_ordem(ARVORE* arvore){
    printf("Postorder\n");
    if(arvore != NULL) pos_ordem_aux(arvore->raiz);
    printf("\n");
}

CLIENTE* arvore_busca_no(NODE* raiz, char* cpf){
    if(raiz == NULL) return NULL;
    if(strcmp(cpf, cliente_get_cpf(raiz->cliente))==0) return raiz->cliente;
    if(strcmp(cpf, cliente_get_cpf(raiz->cliente))<0) return (arvore_busca_no(raiz->esquerda, cpf));
    else return (arvore_busca_no(raiz->direita, cpf));
}

CLIENTE* arvore_busca(ARVORE* arvore, char* cpf){
    return (arvore_busca_no(arvore->raiz, cpf));
}

void troca_menor_dir(NODE* troca, NODE* raiz, NODE* ant){
    if(troca->esquerda != NULL){
        troca_menor_dir(troca->esquerda, raiz, troca);
        return;
    }
    if(raiz == ant) ant->direita = troca->direita;
    else ant->esquerda = troca->direita;
    cliente_print(raiz->cliente);
    raiz->cliente = troca->cliente;
    free(troca);
    troca = NULL;
}

static boolean arvore_remocao_aux(NODE** raiz, char* cpf){
    NODE* noRemovido;
    if(*raiz == NULL) return FALSE;

    if(strcmp(cpf, cliente_get_cpf((*raiz)->cliente))==0){
        if((*raiz)->esquerda == NULL || (*raiz)->direita == NULL){ //nó a ser removido tem um filho ou nenhum
            noRemovido = (*raiz);
            if((*raiz)->esquerda == NULL) *raiz = (*raiz)->direita;
            else *raiz = (*raiz)->esquerda;

            cliente_print(noRemovido->cliente);
            free(noRemovido);
            noRemovido = NULL;
        }else{ //nó a ser removido possui os dois filhos
            troca_menor_dir((*raiz)->direita, (*raiz), (*raiz));
        }
        return TRUE;
    }else{
        if(strcmp(cpf, cliente_get_cpf((*raiz)->cliente))<0) return arvore_remocao_aux(&(*raiz)->esquerda, cpf);
        else return arvore_remocao_aux(&(*raiz)->direita, cpf);
    }
}

boolean arvore_remocao(ARVORE* arvore, char* cpf){
    if(arvore != NULL){
        return arvore_remocao_aux(&arvore->raiz, cpf);
    }else return FALSE;
}