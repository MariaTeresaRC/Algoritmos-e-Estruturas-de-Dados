#include "carta.h"
#include "pilha.h"

#include <stdio.h>
#include <stdlib.h>

int soma_cartas(PILHA* pilha){
    int soma = 0;
    while(soma<21){
        soma += carta_valor(pilha_desempilhar(pilha));
    }
    return soma;
}

int main(){

    PILHA *pilha = pilha_criar();
    for(int i=0; i<52; i++){
        pilha_empilhar(pilha, carta_ler());
    }
    int soma = soma_cartas(pilha);
    if(soma==21){
        printf("Ganhou ;)\n");
    }
    if(soma>21){
        printf("Perdeu :(\nSoma :: %d", soma);
    }

    return 0;
}