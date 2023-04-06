#include "jogo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct jogo_{
    char* nome;
    char* empresa;
    int ano;
};

JOGO* jogo_criar(const char *nome, const char *empresa, int ano){
    JOGO* jogo = (JOGO*)malloc(sizeof(JOGO));
    if(jogo == NULL) return NULL;
    jogo->nome = (char*)malloc(sizeof(char)*(strlen(nome)+1));
    strcpy(jogo->nome, nome);
    jogo->empresa = (char*)malloc(sizeof(char)*(strlen(empresa)+1));
    strcpy(jogo->empresa, empresa);
    jogo->ano = ano;
    return jogo;
}

boolean jogo_apagar(JOGO** jogo){
    if(jogo != NULL){
        free((*jogo)->nome);
        free((*jogo)->empresa);
        free(*jogo);
        *jogo = NULL;
        return TRUE;
    }
    return FALSE;
}

void jogo_print(JOGO* jogo){
    if(jogo != NULL){
        printf("%s\n", jogo->nome);
    }
}

char* jogo_nome(JOGO* jogo){
    return jogo->nome;
}

int jogo_ano(JOGO* jogo){
    return jogo->ano;
}

char* jogo_empresa(JOGO* jogo){
    return jogo->empresa;
}

int jogo_compare(JOGO* j1, JOGO* j2){           // compara dois jogos, usada na insercao da arvore
    int out;                                    // compara primeiro os anos, mas se forem iguais 
    if(j1->ano > j2->ano){                      // leva em conta a ordem alfabetica
        out = 1;
    }else if(j1->ano < j2->ano){
        out = -1;
    }else out = strcmp(j1->nome, j2->nome);
    return out;
}