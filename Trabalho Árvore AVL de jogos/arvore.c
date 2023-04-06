#include "arvore.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node_{
    JOGO* jogo;
    NODE* esquerda;
    NODE* direita;
    int altura;
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

int arvore_altura_node(NODE* node){
    if(node == NULL) return 0;
    else return node->altura;
}

NODE* arvore_criar_node(JOGO* jogo){
    NODE* node = (NODE*)malloc(sizeof(NODE));
    if(node != NULL){
        node->altura = 0;
        node->esquerda = NULL;
        node->direita = NULL;
        node->jogo = jogo;
    }
    return node;
}

NODE* rotacao_direita(NODE* a){
    NODE* b = a->esquerda;
    a->esquerda = b->direita;
    b->direita = a;
    a->altura = max(arvore_altura_node(a->esquerda), arvore_altura_node(a->direita)) + 1;
    b->altura = max(arvore_altura_node(b->esquerda), a->altura) + 1;
    return b;
}

NODE* rotacao_esquerda(NODE* a){
    NODE* b = a->direita;
    a->direita = b->esquerda;
    b->esquerda = a;

    a->altura = max(arvore_altura_node(a->esquerda), arvore_altura_node(a->direita)) + 1;
    b->altura = max(arvore_altura_node(b->direita), a->altura) + 1;
    return b;
}

NODE* rotacao_esquerda_direita(NODE *node)   {
    node->esquerda = rotacao_esquerda(node->esquerda);
    return rotacao_direita(node);
}

NODE* rotacao_direita_esquerda(NODE *node)   {
    node->direita = rotacao_direita(node->direita);
    return rotacao_esquerda(node);
}

NODE* checa_balanceamento(NODE* raiz){
    if(raiz != NULL){
        if(arvore_altura_node(raiz->esquerda)-arvore_altura_node(raiz->direita) == -2){
            if(arvore_altura_node(raiz->direita->esquerda)-arvore_altura_node(raiz->direita->direita) <= 0){
                raiz = rotacao_esquerda(raiz);
            }else{
                raiz = rotacao_direita_esquerda(raiz);
            }
        }
        if(arvore_altura_node(raiz->esquerda)-arvore_altura_node(raiz->direita) == 2){
            if(arvore_altura_node(raiz->esquerda->esquerda)-arvore_altura_node(raiz->esquerda->direita) >= 0){
                raiz = rotacao_direita(raiz);
            }else{
                raiz = rotacao_esquerda_direita(raiz);
            }
        }
    }
    return raiz;
}

NODE* arvore_inserir_node(NODE* raiz, JOGO* jogo){
    if(raiz == NULL){
        raiz = arvore_criar_node(jogo);
    }else if(jogo_compare(jogo, raiz->jogo) > 0){
        raiz->direita = arvore_inserir_node(raiz->direita, jogo);
    }else if(jogo_compare(jogo, raiz->jogo) < 0){
        raiz->esquerda = arvore_inserir_node(raiz->esquerda, jogo);
    }

    raiz->altura = max(arvore_altura_node(raiz->esquerda), arvore_altura_node(raiz->direita)) + 1;
    
    if(arvore_altura_node(raiz->esquerda)-arvore_altura_node(raiz->direita) == -2){
        if(jogo_ano(jogo) > jogo_ano(raiz->direita->jogo)){
            raiz = rotacao_esquerda(raiz);
        }else{
            raiz = rotacao_direita_esquerda(raiz);
        }
    }
    if(arvore_altura_node(raiz->esquerda)-arvore_altura_node(raiz->direita) == 2){
        if(jogo_ano(jogo) < jogo_ano(raiz->esquerda->jogo)){
            raiz = rotacao_direita(raiz);
        }else{
            raiz = rotacao_esquerda_direita(raiz);
        }
    }

    return raiz;
}

boolean arvore_inserir(ARVORE* arvore, JOGO* jogo){
    arvore->raiz = arvore_inserir_node(arvore->raiz, jogo);
    if(arvore->raiz != NULL){
        arvore->profundidade = arvore_altura_node(arvore->raiz);
        return TRUE;
    }
    return FALSE;
}

ARVORE* ler_CSV(){
    FILE* fp = fopen("CSV.csv", "r+");
    fseek(fp, 3, SEEK_SET);
    char* linha = (char*)malloc(sizeof(char)*50);
    char* nome;
    int ano;
    char* empresa;
    ARVORE* arvore = arvore_criar();
    JOGO* jogo;
    while (fscanf(fp, " %[^(\r|\n)]", linha)>0){
        char* token = strtok(linha, ";");
        nome = (char*)malloc(sizeof(char)*(strlen(token)+1));
        strcpy(nome, token);
        token = strtok(NULL, ";");
        ano = ano_char_to_int(token);
        token = strtok(NULL, ";");
        empresa = (char*)malloc(sizeof(char)*(strlen(token)+1));
        strcpy(empresa, token);
        jogo = jogo_criar(nome, empresa, ano);
        free(nome);
        free(empresa);
        arvore_inserir(arvore, jogo);
    }
    free(linha);
    fclose(fp);
    return arvore;
}

void troca_maior_esq(NODE* troca, NODE* raiz, NODE* ant){
    if(troca->direita != NULL){
        troca_maior_esq(troca->direita, raiz, troca);
        return;
    }
    if(raiz == ant) ant->esquerda = troca->esquerda;
    else ant->direita = troca->esquerda;
    raiz->jogo = troca->jogo;
    free(troca);
    troca = NULL;
}

static boolean arvore_remocao_aux(NODE** raiz, int ano){
    NODE* noRemovido;
    if(*raiz == NULL) return FALSE;

    if(ano <= jogo_ano((*raiz)->jogo)) arvore_remocao_aux(&(*raiz)->esquerda, ano);
    if(ano >= jogo_ano((*raiz)->jogo)) arvore_remocao_aux(&(*raiz)->direita, ano);

    if(jogo_ano((*raiz)->jogo) == ano){
        if((*raiz)->esquerda == NULL || (*raiz)->direita == NULL){ //nó a ser removido tem um filho ou nenhum
            noRemovido = (*raiz);
            if((*raiz)->esquerda == NULL) *raiz = (*raiz)->direita;
            else *raiz = (*raiz)->esquerda;

            free(noRemovido);
            noRemovido = NULL;
        }else{ //nó a ser removido possui os dois filhos
            troca_maior_esq((*raiz)->esquerda, (*raiz), (*raiz));
        }
    }

    if(*raiz != NULL){
        (*raiz)->altura = max(arvore_altura_node((*raiz)->esquerda), arvore_altura_node((*raiz)->direita)) + 1;
        
        (*raiz)->esquerda = checa_balanceamento((*raiz)->esquerda);
        (*raiz)->direita = checa_balanceamento((*raiz)->direita);
        *raiz = checa_balanceamento(*raiz);
    }

    return TRUE;
}

boolean arvore_remocao(ARVORE* arvore, int ano){
    if(arvore != NULL){
        return arvore_remocao_aux(&arvore->raiz, ano);
    }else return FALSE;
}

void em_ordem_aux(NODE* raiz){
    if(raiz != NULL){
        em_ordem_aux(raiz->esquerda);
        jogo_print(raiz->jogo);
        em_ordem_aux(raiz->direita);
    }
}

void arvore_em_ordem(ARVORE* arvore){
    if(arvore != NULL) em_ordem_aux(arvore->raiz);
}

void pre_ordem_aux(NODE* raiz){
    if(raiz != NULL){
        jogo_print(raiz->jogo);
        pre_ordem_aux(raiz->esquerda);
        pre_ordem_aux(raiz->direita);
    }
}

void arvore_pre_ordem(ARVORE* arvore){
    if(arvore != NULL) pre_ordem_aux(arvore->raiz);
}

void pos_ordem_aux(NODE* raiz){
    if(raiz != NULL){
        pos_ordem_aux(raiz->esquerda);
        pos_ordem_aux(raiz->direita);
        jogo_print(raiz->jogo);
    }
}

void arvore_pos_ordem(ARVORE* arvore){
    if(arvore != NULL) pos_ordem_aux(arvore->raiz);
}

void arvore_apagar_aux(NODE** raiz){
    if(*raiz != NULL){
        arvore_apagar_aux(&(*raiz)->esquerda);
        arvore_apagar_aux(&(*raiz)->direita);
        jogo_apagar(&(*raiz)->jogo);
        free(*raiz);
        *raiz = NULL;
    }
}

void arvore_apagar(ARVORE** arvore){
    arvore_apagar_aux(&(*arvore)->raiz);
    free(*arvore);
    *arvore = NULL;
}