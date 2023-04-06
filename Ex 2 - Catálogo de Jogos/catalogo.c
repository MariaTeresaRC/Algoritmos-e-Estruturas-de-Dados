#include "catalogo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct catalogo_{
    JOGO** jogos;
    int indice;
};

CATALOGO* catalogo_criar(){
    CATALOGO *catalogo = (CATALOGO*)malloc(sizeof(CATALOGO));
    if(catalogo == NULL) return NULL;
    catalogo->indice = 0;
    catalogo->jogos = (JOGO**)malloc(5*sizeof(JOGO*));
    if(catalogo->jogos == NULL) return NULL;
    return catalogo;
}

boolean catalogo_apagar(CATALOGO* catalogo){
    if(catalogo != NULL){
        for(int i=0; i<catalogo->indice; i++){
            jogo_apagar(catalogo->jogos[i]);
        }
        free(catalogo);
        return TRUE;
    }
    return FALSE;
    
}

boolean catalogo_adicionarjogo(CATALOGO* catalogo, JOGO* jogo){
    if(catalogo == NULL || jogo == NULL) return FALSE;
    catalogo->jogos[catalogo->indice] = jogo;
    catalogo->indice++;
    if((catalogo->indice)%5 == 0){      //aumenta o vetor de jogos se necessário
        catalogo->jogos = (JOGO**)realloc(catalogo->jogos, ((catalogo->indice)/5 + 1)*5*sizeof(JOGO*));
    }
    return TRUE;
}

boolean catalogo_busca_ano(CATALOGO* catalogo, int ano){
    boolean found = FALSE;
    for(int i=0; i<catalogo->indice; i++){
        if (jogo_ano(catalogo->jogos[i]) == ano){
            jogo_print(catalogo->jogos[i]);
            found = TRUE;
        }
    }
    return found;
}

boolean catalogo_busca_empresa(CATALOGO* catalogo, const char* empresa){
    boolean found = FALSE;
    for(int i=0; i<catalogo->indice; i++){
        if(!(strcmp(jogo_empresa(catalogo->jogos[i]), empresa))){
            jogo_print(catalogo->jogos[i]);
            found = TRUE;
        }
    }
    return found;
}

int catalogo_indice(CATALOGO* catalogo){
    return catalogo->indice;
}

JOGO** catalogo_jogos(CATALOGO* catalogo){
    return catalogo->jogos;
}