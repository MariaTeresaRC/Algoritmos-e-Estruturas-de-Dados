#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "arvore.h"

int main(){

    int num;
    scanf(" %d", &num);
    CLIENTE* cliente;
    ARVORE* arvore = arvore_criar();

    for(int i=0; i<num; i++){
        cliente = cliente_ler();
        arvore_insercao(arvore, cliente);
    }

    arvore_em_ordem(arvore);
    arvore_pre_ordem(arvore);
    arvore_pos_ordem(arvore);

    arvore_apagar(&arvore);

    return 0;
}