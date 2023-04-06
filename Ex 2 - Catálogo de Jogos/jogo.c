#include "jogo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct jogo_{
    char nome[30];
    char empresa[30];
    int ano;
};

JOGO* jogo_criar(const char *nome, const char *empresa, int ano){
    JOGO* jogo = (JOGO*)malloc(sizeof(JOGO));
    if(jogo == NULL) return NULL;
    strcpy(jogo->nome, nome);
    strcpy(jogo->empresa, empresa);
    jogo->ano = ano;
    return jogo;
}

boolean jogo_apagar(JOGO* jogo){
    if(jogo != NULL){
        free(jogo);
        return TRUE;
    }
    return FALSE;
}

void jogo_print(JOGO* jogo){
    if(jogo != NULL){
        printf("%s\n", jogo->nome);
    }
}

int jogo_ano(JOGO* jogo){
    return jogo->ano;
}

char* jogo_empresa(JOGO* jogo){
    return jogo->empresa;
}