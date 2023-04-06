#include "carta.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct carta_{
    char naipe[10];
    int simbolo;
};

CARTA* carta_ler(){
    CARTA* carta = (CARTA*)malloc(sizeof(CARTA));
    if(carta == NULL) return NULL;
    char aux;
    int i=0;
    while(1){
        scanf("%c", &aux);
        if(aux==' ') break;
        carta->naipe[i]=aux;
        i++;
    }
    scanf("%c", &aux);
    if(aux >= '0' && aux <= '9'){
        ungetc(aux, stdin);
        scanf("%d", &carta->simbolo);
    }else{
        carta->simbolo = 10;
    }
    return carta;
}

boolean carta_apagar(CARTA* carta){
    if(carta != NULL){
        free(carta);
        return TRUE;
    }
    return FALSE;
}

int carta_valor(CARTA* carta){
    return carta->simbolo;
}